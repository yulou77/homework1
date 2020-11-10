# homework1


题目：根据经纬度坐标计算两车距离、方位角，并将计算结果进行传输。  
要求：  
一、Simulink原型搭建：用Simulink模块实现根据两车的经纬度坐标计算两车之间的距离、计算前车的方位角，通过Simulink仿真验证算法。  
二、C代码生成及功能实现：  
1.基于Simulink原型生成C代码，在Linux环境进行编译运行。  
2.将航向角、距离生成ASN.1格式的数据，利用ASN.1编译工具（有开源工具）生成C代码。  
3.将步骤2生成的C代码集成到（步骤1）C程序中，通过UDP方式实现计算结果（距离、方位角）自发、自收。  

开发语言：C++  
开发工具：VSCode  
编译管理：CMake  
代码管理：Git  
提交时间：2020.11.10  
提交方式：在 https://github.com/ 注册账号并上传提交  

[matlab下载安装教程](http://www.360doc.com/content/16/1005/11/27698033_595899862.shtml)  
[vscode 环境搭建](https://www.cnblogs.com/baihualiaoluan/p/10661669.html)  
[haversin算法 根据经纬度计算距离](https://www.cnblogs.com/zhoug2020/p/8993750.html)  
[GPS轨迹拟合--根据经纬度计算距离和方向角](https://blog.csdn.net/qq_39609900/article/details/85109265)  
[方位角的计算](https://wenku.baidu.com/view/ceec18c303768e9951e79b89680203d8cf2f6ac0.html)  
[算法参考--c++](https://blog.csdn.net/yugemengjing/article/details/96708834)  
[simulink自动代码生成](https://blog.csdn.net/weixin_41695564/article/details/80751543)  

# 运行方式

Windows的运行方式
打开文件夹TEST11111中的TEST11111.sln文件，ert_main.cpp为主函数，运行。
输入为（经度，纬度）
（104.628601，29.380394）;
（104.728602，29.380394）;

结果如下：![avatar](https://github.com/yulou77/homework1/blob/main/TEST11111/res.jpg)


Linux

