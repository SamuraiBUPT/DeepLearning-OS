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

# 项目成品部署方案
1. 将文件编译为`.bin`二进制文件
2. 利用`Grub`工具，构建`.iso`磁盘文件。
3. 启动虚拟机，input编译好的`.iso`磁盘文件即可。

# 有关branch
已设置`debug`分支为default branch，因为主要是在这里进行开发，而不是在`master` branch。

这么做的目的是方便查看代码，不用每次都switch到`debug`分支来。

项目成熟以后，考虑与`master` branch合并。



---

### Con - version:

Develop - Env:

Windows + VSCode + Docker(Linux - Ubuntu20.04)



Possible Solutions:

Use Multiboot to boot the OS.

Use LD Script to do that how does the specified linker combine object files and library files into an executable or shared library.

---

*To be continued, modified at any time...*
