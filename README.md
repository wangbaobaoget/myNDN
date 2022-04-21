# myNDN
1.先介绍一些git加速的方法
1）这里提供两个最常用的镜像地址：
https://github.com.cnpmjs.org
https://hub.fastgit.org
也就是说上面的镜像就是一个克隆版的 GitHub，你可以访问上面的镜像网站，网站的内容跟 GitHub 是完整同步的镜像，然后在这个网站里面进行下载克隆等操作。
2）https模式：使用如下命令配置用户级代理：（在命令行输入如下两个命令）
git config --global http.proxy http://127.0.0.1:1235
git config --global https.proxy http://127.0.0.1:1235
后面的1235为自己的端口号，该方法适用于使用虚拟机并且本地电脑可以科学上网的情况，用自己科学上网的端口号替换1235即可
3）将校园网换成数据流量，校园网访问github比较慢
 
2.SUMO工具
1）SUMO快速入门可阅读下面两个帖子
 https://blog.csdn.net/sxsj333/article/details/22855555
   https://blog.csdn.net/iteye_11495/article/details/82575046
 一个简单的道路模型，在SUMO 中街道模型采用结点（Nodes）和线段（Edges）进行描述，例如一条街道至少需要两个结点和一条线段描述。
2）SUMO使用流程
①编写nodes文件 基础信息： 节点id, x, y,
<nodes> 
<node id="node1" x="100.0" y="100.0" type="traffic_light"/> 
<node id="node2" x="400.0" y="100.0" type="priority"/> 
<node id="node3" x="700.0" y="100.0" type="traffic_light"/> 
</nodes>
保存为ex_NODE.nod.xml
②编写edges文件 基础信息：边id，源节点id，目标节点id
<edges> 
<edge id="edgeR-0-0" from="node1" to="node2" /> 
<edge id="edgeR-0-1" from="node2" to="node3" /> 
</edges>
③将node和edges 生成网络地图MySUMONet.net.xml
netconvert --node-files=ex_NODE.nod.xml --edge-files=ex_EDGE.edg.xml --output-file=MySUMONet.net.xml
这样就生成了MySUMONet.net.xml的地图文件
在terminal中输入sumo-gui，File->Open Network 可查看网络地图
④使用node文件与edges文件创建flow文件（车辆数量、开始时间、结束时间等）
<flows> 
<flow id="flow0" from="edgeD-2-0" to="edgeD-0-2" begin="0" end="1000" 
number="100" /> 
</flows>
保存为ex_FLOW.flow.xml
⑤编写线路文件route
duarouter -n MySUMONet.net.xml -f ex_FLOW.flow.xml -o ex_ROU.rou.xml
⑥在创建网络道路的基础上，生成能在ns3中运行的文件
生成xxx.sumo.xml
sudo sumo -c xxx.sumocfg –fcd –output xxx.sumo.xml
生成config.tcl、mobility.tcl 、activity.tcl  
sudo python  ./traceExporte.py –fcd-input xxxsumo.xml –ns2config-output config.tcl –ns2mobility-output mobility.tcl –ns2activity-out activity.tcl
其中mobility.tcl是ns3中所需文件
⑦ 在ns3中使用
sudo ./waf –run “scratch/ns2-mobolity-trace –traceFile= mobility.tcl –nodeNum = xxx  -duration=xxx –logFile=ns2-mobility-trace.log”

3.同态加密环境
1）需要先安装依赖
Clang++ (>= 5.0) or GNU G++ (>= 6.0), CMake (>= 3.12)
2）安装SEAL库
git clone https://github.com/microsoft/SEAL.git
cmake -S . -B build
cmake --build build
sudo cmake --install build
3）安装NB-Classify_SEAL
git clone https://github.com/yamanalab/NB-Classify_SEAL.git
$ cmake .
$ make
$ mkdir keys
$ bin/setup
$ mkdir model
$ bin/encryptModel
4)功能介绍
每个查询对单个数据的分类，没有进行任何优化： bin/classifySingle
每个查询对单个数据的分类，并对每个数据集进行优化： bin/classifySingleOpt
每个查询的多个数据分类： bin/classifyMulti
通过运行以下命令对训练有素的分类模型进行加密，然后输入要加密的数据集的名称。
$ mkdir model
$ bin/encryptModel
 
（dataset_name）_info.csv的格式
第一行包含类标签的名称。
从第二行开始，它包含每个属性的名称或特征值的值，每行一个属性。
下面给出示例，其中N是类数，m是属性j的特征值数。
2,4
9,6,8,5,7,10,4,1,3,2
9,8,5,6,7,10,4,1,3,2
9,8,5,6,7,10,4,1,3,2
9,8,5,6,7,10,4,1,3,2
9,6,5,8,7,10,4,2,3,1
9,5,8,6,7,?,10,4,1,3,2
9,5,8,6,7,10,4,1,3,2
9,5,6,8,7,10,4,1,3,2
5,8,6,7,10,4,1,3,2
 
（dataset_name）_model.csv的格式
第一行包含类概率。然后，用空行分隔，它包含一系列条件概率，其中每行包含每个要素值和属性的条件概率。下面给出示例，其中N是类数，m是属性j的特征值数。
（dataset_name）_test.csv和（dataset_name）_train.csv的格式
每行包含用于分类的数据，其中每个值是属性的特征值，最后一个值是实际标签。

4 ndnSIM环境安装
原版ndnSIM代码库
https://github.com/named-data-ndnSIM/ndnSIM.git
环境安装访问ndn官网网址，按照官网文件安装
https://ndnsim.net/current/getting-started.html
mkdir ndnSIM
cd ndnSIM
git clone https://github.com/named-data-ndnSIM/ns-3-dev.git ns-3
git clone https://github.com/named-data-ndnSIM/pybindgen.git pybindgen
git clone --recursive https://github.com/named-data-ndnSIM/ndnSIM.git ns-3/src/ndnSIM
git submodule update –init
编译和运行 ndnSIM
cd <ns-3-folder>
./waf configure --enable-examples
./waf
示例运行
./waf --run=ndn-simple
myNDN项目运行：
cd myNDN/ndnSIM/ns3
./waf configure --enable-examples
./waf
sudo ./waf --run " scratch/sumo-ns-trace --traceFile=/home/wbb/new/ndnSIM/ns-3/scratch/30nodes.tcl --nodeNum=30 --duration=100.0 --logFile=ns2-mobility-trace.log" >bayes.log
其中traceFile为SUMO生成的网络拓扑文件
nodeNum为拓扑文件中节点个数
duration为仿真时间（s）
logFile为生成的日志文件
sumo-ns-trace为仿真脚本文件，从这个文件开始执行

