# otdr mfc上位机软件集成libharu pdf库
光维OTDR上位机软件采用VisualStudio2013 MFC开发。
## 集成libharu pdf功能
在windows下vs中集成libharu主要用到了cmake工具进行本地化的编译生成sln，libharu编译时依赖LibPNG库，LibPNG又依赖于Zlib，因此需要先对Zlib进行本地化编译，再将生成的sln进行build；将相关库文件和头文件导入用Cmake生成的LibPNG的sln，进行build；将``ZLib和LibPNG``的相关库文件和头文件导入到用Cmake生成的LibPNG的sln，进行编译生成相关Windows环境下的libharu-LIB库。
* [大致过程:](https://github.com/libharu/libharu/issues/135)  
![windows下libharu库使用方式](./src/libharu1.png)
* 遇到问题1：将生成的libharu库导入到otdr项目后编译报错  
hpdf.h和hpdf-types.h两个头文件中一个c命名的变量报错，将变量名改成cc后解决？
## SOR文件