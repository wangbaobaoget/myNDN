/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2006 Georgia Tech Research Corporation, INRIA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: George F. Riley<riley@ece.gatech.edu>
 *          Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#include "node.h"
#include "node-list.h"
#include "net-device.h"
#include "application.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/object-vector.h"
#include "ns3/uinteger.h"
#include "ns3/log.h"
#include "ns3/assert.h"
#include "ns3/global-value.h"
#include "ns3/boolean.h"
#include "ns3/simulator.h"
#include <iostream>
#include <fstream> 
using namespace std;
int nodestatus[50][6]={
                         {122,23,33,20,5,1},
                         {22,45,0,46,7,0},
                         {67,78,88,3,0,1},
                         {111,132,44,56,7,1},
                         {56,67,100,5,4,0},
                         {33,23,1,34,5,0},
                         {110,0,23,10,0,0},
                         {23,23,4,0,3,1},
                         {67,56,3,2,2,1},

                         {122,23,33,20,5,1},
                         {22,45,0,46,7,0},
                         {67,78,88,3,0,1},
                         {111,132,44,56,7,1},
                         {56,67,100,5,4,0},
                         {33,23,1,34,5,0},
                         {110,0,23,10,0,0},
                         {23,23,4,0,3,1},
                         {67,56,3,2,2,1},

                         {122,23,33,20,5,1},
                         {22,45,0,46,7,0},
                         {67,78,88,3,0,1},
                         {111,132,44,56,7,1},
                         {56,67,100,3,4,0},
                         {33,23,1,34,5,0},
                         {110,0,23,1,0,0},
                         {23,23,4,45,3,1},
                         {67,56,3,2,2,1},

                         {122,23,33,20,5,1},
                         {22,45,0,46,7,0},
                         {67,78,88,3,0,1},
                         {111,132,44,56,7,1},
                         {56,67,100,5,4,0},
                         {33,23,1,34,5,0},
                         {110,0,23,10,0,0},
                         {23,23,4,0,3,1},
                         {67,56,3,2,2,1},

                         {122,23,33,20,5,1},
                         {22,45,0,46,7,0},
                         {67,78,88,3,0,1},
                         {111,132,44,56,7,1},
                         {56,67,100,3,4,0},
                         {33,23,1,34,5,0},
                         {110,0,23,1,0,0},
                         {23,23,4,45,3,1},
                         {67,56,3,2,2,1}
                       };
namespace ns3 {

 // uint32_t nodestatus[5][6]={{122,23,33,45,5,1},
 //                         {22,45,0,46,7,1},
 //                         {67,78,66,3,0,1},
 //                         {111,132,44,56,7,0},
 //                         {56,67,100,3,4,0}};//id ,x,y,speed,dis,num,d,

void read()
{//TODO'WRITE FROM FILE TO NODESTATUS
}

NS_LOG_COMPONENT_DEFINE ("Node");

NS_OBJECT_ENSURE_REGISTERED (Node);

/**
 * \brief A global switch to enable all checksums for all protocols.
 */
static GlobalValue g_checksumEnabled  = GlobalValue ("ChecksumEnabled",
                                                     "A global switch to enable all checksums for all protocols",
                                                     BooleanValue (false),
                                                     MakeBooleanChecker ());

TypeId 
Node::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::Node")
    .SetParent<Object> ()
    .SetGroupName("Network")
    .AddConstructor<Node> ()
    .AddAttribute ("DeviceList", "The list of devices associated to this Node.",
                   ObjectVectorValue (),
                   MakeObjectVectorAccessor (&Node::m_devices),
                   MakeObjectVectorChecker<NetDevice> ())
    .AddAttribute ("ApplicationList", "The list of applications associated to this Node.",
                   ObjectVectorValue (),
                   MakeObjectVectorAccessor (&Node::m_applications),
                   MakeObjectVectorChecker<Application> ())
    .AddAttribute ("Id", "The id (unique integer) of this Node.",
                   TypeId::ATTR_GET, // allow only getting it.
                   UintegerValue (0),
                   MakeUintegerAccessor (&Node::m_id),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("SystemId", "The systemId of this node: a unique integer used for parallel simulations.",
                   TypeId::ATTR_GET | TypeId::ATTR_SET,
                   UintegerValue (0),
                   MakeUintegerAccessor (&Node::m_sid),
                   MakeUintegerChecker<uint32_t> ())
  ;
  return tid;
}

Node::Node()
  : m_id (0),
    m_sid (0)
{
  NS_LOG_FUNCTION (this);
  Construct ();
}

Node::Node(uint32_t sid)
  : m_id (0),
    m_sid (sid)
{ 
  NS_LOG_FUNCTION (this << sid);
  Construct ();
}

void
Node::Construct (void)
{
  NS_LOG_FUNCTION (this);
  m_id = NodeList::Add (this);
}

Node::~Node ()
{
  NS_LOG_FUNCTION (this);
}

uint32_t
Node::GetX (int cnode) 
{
//  if (cnode>node_max||cnode<0)
//  {cout<<"WORNG CNODE!!!!!!"<<endl;
//    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETX!!!!");
//    cout<<" am  eva!"<<endl;
//  }
//  else{
//    NS_LOG_FUNCTION (this);
//    cout<<"cnode is :"<<cnode<<endl;
//    cout<<"nodestatus[cnode][0] is "<<nodestatus[cnode][0]<<endl;
//    uint32_t n_x = this->nodestatus[cnode][0];
//    cout<<"getX,nodestatus[cnode][0]..................."<<endl;
//    return n_x;}
//    return 0;
      if(0<=cnode&&cnode<node_max)
      {
        NS_LOG_FUNCTION (this);
        cout<<"cnode   is   "<<cnode<<endl;
        cout<<"nodestatus[cnode][0] is "<<nodestatus[cnode][0]<<endl;
         uint32_t n_x = nodestatus[cnode][0];
         return n_x;
      }
      else
      {NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETX!!!!");}
      return 0;

}

uint32_t
Node::GetY (int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETY!!!!");
    cout<<" am  eva!"<<endl;
  }
  else{
  NS_LOG_FUNCTION (this);
  uint32_t  n_y = nodestatus[cnode][1];
  return n_y;}
  return 0;
}


uint32_t
Node::GetSPEED (int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETSPEDD!!!!");
    cout<<" am  eva!"<<endl;
  }
  else{
  NS_LOG_FUNCTION (this);
   uint32_t  n_speed = nodestatus[cnode][2];
  return n_speed;}
  return 0;
}

uint32_t
Node::GetDIS (int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETDIS!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
  NS_LOG_FUNCTION (this);
  uint32_t  n_dis = nodestatus[cnode][3];
  return n_dis;}
  return 0;
}

uint32_t
Node::GetNUM (int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETNUM!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
  NS_LOG_FUNCTION (this);
  uint32_t n_num = nodestatus[cnode][4];
  return n_num;}
  return 0;
}

uint32_t
Node::GetD (int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::GETD!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
  NS_LOG_FUNCTION (this);
  uint  n_d = nodestatus[cnode][5];
  return n_d;}
  return 0;
}
//===========================================//

uint32_t
Node::SetX (uint32_t x,int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETX!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
 nodestatus[cnode][0]=x; }
  return 0;
}

uint32_t
Node::SetY (uint32_t y,int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETY!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
 nodestatus[cnode][1]=y;
  }
  return 0;
}

uint32_t
Node::SetSPEED (uint32_t speed,int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETSPEED!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
 nodestatus[cnode][2]=speed;
  }
  return 0;
}

uint32_t
Node::SetDIS (uint32_t dis,int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETDIS!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
 nodestatus[cnode][3]=dis;
  }
  return 0;
}

uint32_t
Node::SetNUM (uint32_t num,int cnode) 
{
  if (cnode>node_max||cnode<0)
  {cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETNUM!!!!");
    cout<<"am  eva!"<<endl;
  }
  else{
 nodestatus[cnode][4]=num;
  }
  return 0;
}

uint32_t
Node::SetD (uint32_t d,int cnode) 
{if (cnode>node_max||cnode<0)
  { cout<<"WORNG CNODE!!!!!!"<<endl;
    NS_LOG_DEBUG("NS_LOG_DEBUG::NODE::SETD!!!!");
    cout<<"am eva!"<<endl;
  }
  else{
 nodestatus[cnode][5]=d;
 }
  return 0;
}





//////////////////////////////////////////
uint32_t
Node::GetId (void) const
{
  NS_LOG_FUNCTION (this);
  return m_id;
}

Time
Node::GetLocalTime (void) const
{
  NS_LOG_FUNCTION (this);
  return Simulator::Now ();
}

uint32_t
Node::GetSystemId (void) const
{
  NS_LOG_FUNCTION (this);
  return m_sid;
}

uint32_t
Node::AddDevice (Ptr<NetDevice> device)
{
  NS_LOG_FUNCTION (this << device);
  uint32_t index = m_devices.size ();
  m_devices.push_back (device);
  device->SetNode (this);
  device->SetIfIndex (index);
  device->SetReceiveCallback (MakeCallback (&Node::NonPromiscReceiveFromDevice, this));
  Simulator::ScheduleWithContext (GetId (), Seconds (0.0), 
                                  &NetDevice::Initialize, device);
  NotifyDeviceAdded (device);
  return index;
}
Ptr<NetDevice>
Node::GetDevice (uint32_t index) const
{
  NS_LOG_FUNCTION (this << index);
  NS_ASSERT_MSG (index < m_devices.size (), "Device index " << index <<
                 " is out of range (only have " << m_devices.size () << " devices).");
  return m_devices[index];
}
uint32_t 
Node::GetNDevices (void) const
{
  NS_LOG_FUNCTION (this);
  return m_devices.size ();
}

uint32_t 
Node::AddApplication (Ptr<Application> application)
{
  NS_LOG_FUNCTION (this << application);
  uint32_t index = m_applications.size ();
  m_applications.push_back (application);
  application->SetNode (this);
  Simulator::ScheduleWithContext (GetId (), Seconds (0.0), 
                                  &Application::Initialize, application);
  return index;
}
Ptr<Application> 
Node::GetApplication (uint32_t index) const
{
  NS_LOG_FUNCTION (this << index);
  NS_ASSERT_MSG (index < m_applications.size (), "Application index " << index <<
                 " is out of range (only have " << m_applications.size () << " applications).");
  return m_applications[index];
}
uint32_t 
Node::GetNApplications (void) const
{
  NS_LOG_FUNCTION (this);
  return m_applications.size ();
}

void 
Node::DoDispose ()
{
  NS_LOG_FUNCTION (this);
  m_deviceAdditionListeners.clear ();
  m_handlers.clear ();
  for (std::vector<Ptr<NetDevice> >::iterator i = m_devices.begin ();
       i != m_devices.end (); i++)
    {
      Ptr<NetDevice> device = *i;
      device->Dispose ();
      *i = 0;
    }
  m_devices.clear ();
  for (std::vector<Ptr<Application> >::iterator i = m_applications.begin ();
       i != m_applications.end (); i++)
    {
      Ptr<Application> application = *i;
      application->Dispose ();
      *i = 0;
    }
  m_applications.clear ();
  Object::DoDispose ();
}
void 
Node::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
  for (std::vector<Ptr<NetDevice> >::iterator i = m_devices.begin ();
       i != m_devices.end (); i++)
    {
      Ptr<NetDevice> device = *i;
      device->Initialize ();
    }
  for (std::vector<Ptr<Application> >::iterator i = m_applications.begin ();
       i != m_applications.end (); i++)
    {
      Ptr<Application> application = *i;
      application->Initialize ();
    }

  Object::DoInitialize ();
}

void
Node::RegisterProtocolHandler (ProtocolHandler handler, 
                               uint16_t protocolType,
                               Ptr<NetDevice> device,
                               bool promiscuous)
{
  NS_LOG_FUNCTION (this << &handler << protocolType << device << promiscuous);
  struct Node::ProtocolHandlerEntry entry;
  entry.handler = handler;
  entry.protocol = protocolType;
  entry.device = device;
  entry.promiscuous = promiscuous;

  // On demand enable promiscuous mode in netdevices
  if (promiscuous)
    {
      if (device == 0)
        {
          for (std::vector<Ptr<NetDevice> >::iterator i = m_devices.begin ();
               i != m_devices.end (); i++)
            {
              Ptr<NetDevice> dev = *i;
              dev->SetPromiscReceiveCallback (MakeCallback (&Node::PromiscReceiveFromDevice, this));
            }
        }
      else
        {
          device->SetPromiscReceiveCallback (MakeCallback (&Node::PromiscReceiveFromDevice, this));
        }
    }

  m_handlers.push_back (entry);
}

void
Node::UnregisterProtocolHandler (ProtocolHandler handler)
{
  NS_LOG_FUNCTION (this << &handler);
  for (ProtocolHandlerList::iterator i = m_handlers.begin ();
       i != m_handlers.end (); i++)
    {
      if (i->handler.IsEqual (handler))
        {
          m_handlers.erase (i);
          break;
        }
    }
}

bool
Node::ChecksumEnabled (void)
{
  NS_LOG_FUNCTION_NOARGS ();
  BooleanValue val;
  g_checksumEnabled.GetValue (val);
  return val.Get ();
}

bool
Node::PromiscReceiveFromDevice (Ptr<NetDevice> device, Ptr<const Packet> packet, uint16_t protocol,
                                const Address &from, const Address &to, NetDevice::PacketType packetType)
{
  NS_LOG_FUNCTION (this << device << packet << protocol << &from << &to << packetType);
  return ReceiveFromDevice (device, packet, protocol, from, to, packetType, true);
}

bool
Node::NonPromiscReceiveFromDevice (Ptr<NetDevice> device, Ptr<const Packet> packet, uint16_t protocol,
                                   const Address &from)
{
  NS_LOG_FUNCTION (this << device << packet << protocol << &from);
  return ReceiveFromDevice (device, packet, protocol, from, device->GetAddress (), NetDevice::PacketType (0), false);
}

bool
Node::ReceiveFromDevice (Ptr<NetDevice> device, Ptr<const Packet> packet, uint16_t protocol,
                         const Address &from, const Address &to, NetDevice::PacketType packetType, bool promiscuous)
{
  NS_LOG_FUNCTION (this << device << packet << protocol << &from << &to << packetType << promiscuous);
  NS_ASSERT_MSG (Simulator::GetContext () == GetId (), "Received packet with erroneous context ; " <<
                 "make sure the channels in use are correctly updating events context " <<
                 "when transfering events from one node to another.");
  NS_LOG_DEBUG ("Node " << GetId () << " ReceiveFromDevice:  dev "
                        << device->GetIfIndex () << " (type=" << device->GetInstanceTypeId ().GetName ()
                        << ") Packet UID " << packet->GetUid ());
  bool found = false;

  for (ProtocolHandlerList::iterator i = m_handlers.begin ();
       i != m_handlers.end (); i++)
    {
      if (i->device == 0 ||
          (i->device != 0 && i->device == device))
        {
          if (i->protocol == 0 || 
              i->protocol == protocol)
            {
              if (promiscuous == i->promiscuous)
                {
                  i->handler (device, packet, protocol, from, to, packetType);
                  found = true;
                }
            }
        }
    }
  return found;
}
void 
Node::RegisterDeviceAdditionListener (DeviceAdditionListener listener)
{
  NS_LOG_FUNCTION (this << &listener);
  m_deviceAdditionListeners.push_back (listener);
  // and, then, notify the new listener about all existing devices.
  for (std::vector<Ptr<NetDevice> >::const_iterator i = m_devices.begin ();
       i != m_devices.end (); ++i)
    {
      listener (*i);
    }
}
void 
Node::UnregisterDeviceAdditionListener (DeviceAdditionListener listener)
{
  NS_LOG_FUNCTION (this << &listener);
  for (DeviceAdditionListenerList::iterator i = m_deviceAdditionListeners.begin ();
       i != m_deviceAdditionListeners.end (); i++)
    {
      if ((*i).IsEqual (listener))
        {
          m_deviceAdditionListeners.erase (i);
          break;
         }
    }
}
 
void 
Node::NotifyDeviceAdded (Ptr<NetDevice> device)
{
  NS_LOG_FUNCTION (this << device);
  for (DeviceAdditionListenerList::iterator i = m_deviceAdditionListeners.begin ();
       i != m_deviceAdditionListeners.end (); i++)
    {
      (*i) (device);
    }  
}
 

} // namespace ns3

//changed.