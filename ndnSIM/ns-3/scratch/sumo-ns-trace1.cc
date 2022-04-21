#include <iostream>
#include <fstream>
#include <sstream>
#include "ns3/ns2-mobility-helper.h"

#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/ndnSIM-module.h"


using namespace ns3;

static void
CourseChange (std::ostream *os, std::string foo, Ptr<const MobilityModel> mobility)
{
  Vector pos = mobility->GetPosition (); // Get position
  Vector vel = mobility->GetVelocity (); // Get velocity

  // Prints position and velocities
  *os << Simulator::Now () << " POS: x=" << pos.x << ", y=" << pos.y
      << ", z=" << pos.z << "; VEL:" << vel.x << ", y=" << vel.y
      << ", z=" << vel.z << std::endl;
      // std::cout<<"coutrsechange"<<std::endl;
      // std::cout<< Simulator::Now ()<<"POS:x="<<pos.x<<", y=" << pos.y
      // << ", z=" << pos.z << "; VEL:" << vel.x << ", y=" << vel.y
      // << ", z=" << vel.z << std::endl;
      // std::cout<<"node============================="<<Simulator::NodePrinter(os) <<"==============="<<std::endl;
}



 
using namespace std; 

namespace ns3
{
	NS_LOG_COMPONENT_DEFINE ("TEST1");

	int
	main (int argc, char *argv[])
	{
		
      std::string traceFile;
      std::string logFile;

      int    nodeNum;
      double duration;
      LogComponentEnable ("Ns2MobilityHelper",LOG_LEVEL_DEBUG);
     
		//Time::SetResolution (Time::NS);
           
		 CommandLine cmd;
		 cmd.AddValue ("traceFile", "Ns2 movement trace file", traceFile);
         cmd.AddValue ("nodeNum", "Number of nodes", nodeNum);
         cmd.AddValue ("duration", "Duration of Simulation", duration);
         cmd.AddValue ("logFile", "Log file", logFile);
		 cmd.Parse(argc, argv);
         

      if (traceFile.empty () || nodeNum <= 0 || duration <= 0 )//|| logFile.empty ())
    {
      std::cout << "Usage of " << argv[0] << " :\n\n"
      "./waf --run \"ns2-mobility-trace"
      " --traceFile=src/mobility/examples/default.ns_movements"
      " --nodeNum=2 --duration=100.0 --logFile=ns2-mob.log\" \n\n"
      "NOTE: ns2-traces-file could be an absolute or relative path. You could use the file default.ns_movements\n"
      "      included in the same directory of this example file.\n\n"
      "NOTE 2: Number of nodes present in the trace file must match with the command line argument and must\n"
      "        be a positive number. Note that you must know it before to be able to load it.\n\n"
      "NOTE 3: Duration must be a positive number. Note that you must know it before to be able to load it.\n\n";

      return 0;
    }
     Ns2MobilityHelper ns2 = Ns2MobilityHelper (traceFile);

  // open log file for output
     std::ofstream os;
     os.open (logFile.c_str ());



         NS_LOG_INFO ("Create nodes.");

        
         
         NodeContainer stas;
         stas.Create (nodeNum);
         ns2.Install (); 

     YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();   //使用默认的信道模型
     channel.SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel");
     // channel.AddPropagationLoss("ns3::RangePropagationLossModel","MaxRange",DoubleValue(100));
		 YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();  //使用默认的PHY模型
		 phy.SetChannel (channel.Create ());  //创建通道对象并把他关联到物理层对象管理器
		   
      //配置Mac类型以及基础设置SSI
		 WifiHelper wifi;
		 wifi.SetRemoteStationManager ("ns3::AarfWifiManager");  //设置wifi助手用AARF速率控制算法 
		 
		  
		 WifiMacHelper mac; 
		 Ssid ssid = Ssid ("ns-3-aqiao");  //设置SSID的名字为ns-3-aqiao
		 mac.SetType ("ns3::StaWifiMac",    //指定mac层指定为ns3::StaWifiMac
		               "Ssid", SsidValue (ssid),   //设置默认AP是ssid对象
		               "ActiveProbing", BooleanValue (false));  //设置不会发出主动探测AP的指令，默认AP是ssid
 
      NetDeviceContainer staDevices;
      staDevices = wifi.Install (phy, mac, stas); 
        
      mac.SetType ("ns3::ApWifiMac",   //指定为AP
               "Ssid", SsidValue (ssid)); 

      NetDeviceContainer apDevices;
      apDevices = wifi.Install (phy,mac, stas.Get(3));  
    

     //second way 
    // WifiHelper wifi;
    // wifi.SetStandard(WIFI_PHY_STANDARD_80211a); //设置标准
    // wifi.SetRemoteStationManager("ns3::ConstantRateWifiManager","DataMode",StringValue("OfdmRate6Mbps"));
    
    //    NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
    //    mac.SetType ("ns3::AdhocWifiMac",
    //                "Slot", StringValue ("16us"));
    // // // WifiMacHelper mac;
    // // // mac.SetType("ns3::AdhocWifiMac");

    // NetDeviceContainer AdHocDevices;
    // AdHocDevices = wifi.Install(phy,mac,stas);




  	NS_LOG_INFO("Installing NDN stack");
  	ndn::StackHelper ndnHelper;
  	ndnHelper.SetDefaultRoutes(true);
  	ndnHelper.InstallAll();
    
  	ndn::StrategyChoiceHelper::InstallAll( "/prefix", "/localhost/nfd/strategy/bayes");//multicast  bayes

  	NS_LOG_INFO("Installing Applications");

  	ndn::AppHelper helloHelper("ns3::ndn::ConsumerCbr");
		helloHelper.SetPrefix("/prefix");
		helloHelper.SetAttribute("Frequency", StringValue("2")); 
		helloHelper.Install(stas);

    // ndn::AppHelper helloHelper1("ns3::ndn::ConsumerCbr");
    // helloHelper1.SetPrefix("/prefix2");
    // helloHelper1.SetAttribute("Frequency", StringValue("2")); 
    // helloHelper1.Install(stas);
  //   ApplicationContainer helloApps = helloHelper.Install(stas);
		// helloApps.Start(Seconds (1.0));
  //   helloApps.Stop(Seconds (4.0));

		ndn::AppHelper producerHelper("ns3::ndn::Producer");
		producerHelper.SetPrefix("/prefix");
		producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
	  producerHelper.Install(stas.Get(4)); 
     producerHelper.Install(stas.Get(19));//nodes.Get(3)    wifiapnode
  //   ApplicationContainer producerApp = producerHelper.Install(stas.Get(0)); 
		// producerApp.Start(Seconds (1.0));
  //   producerApp.Stop(Seconds (4.0)); 
        // phy.EnablePcapAll("mytestone");
		//phy.EnablePcap ("wifiwifi", wifiapnode.Get (0));
		// AsciiTraceHelper ascii;
		// phy.EnableAsciiAll(ascii.CreateFileStream("mytestone.tr"));

        

        Config::Connect ("/NodeList/*/$ns3::MobilityModel/CourseChange",
                   MakeBoundCallback (&CourseChange, &os));

		Simulator::Stop (Seconds (duration)); 
		Simulator::Run ();
		Simulator::Destroy ();
		return 0;
         
	}
}

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}