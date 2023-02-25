# 开发环境
+ 操作系统：Ubuntu 20.04 LTS
+ 开发工具：VSCode
+ 项目构建工具：Makefile

# 开发环境部署方案-Samurai方案
1. 启用虚拟机，在虚拟机上运行Ubuntu系统
2. Ubuntu系统下载openssh: `sudo apt-get install openssh`
3. 进行系列设置，configuration之类（权限设置、ssh远程连接设置）。开启openssh server。
4. 电脑本机VSCode进行远程ssh连接至虚拟机的Ubuntu系统
5. 通过VSCode + 连接虚拟机的方式，实现在Linux环境下开发C++项目的目的。
6. 通过`sftp` - VSCode工具进行虚拟机与实体机的文件交互传输。（代码完成后拷贝至本机，完成push操作）
