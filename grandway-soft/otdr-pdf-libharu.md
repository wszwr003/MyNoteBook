# otdr mfc 上位机软件集成 libharu pdf 库

光维 OTDR 上位机软件采用 VisualStudio2013 MFC 开发。

## 集成 libharu pdf 功能

在 windows 下 vs 中集成 libharu 主要用到了 cmake 工具进行本地化的编译生成 sln，libharu 编译时依赖 LibPNG 库，LibPNG 又依赖于 Zlib，因此需要先对 Zlib 进行本地化编译，再将生成的 sln 进行 build；将相关库文件和头文件导入用 Cmake 生成的 LibPNG 的 sln，进行 build；将`ZLib和LibPNG`的相关库文件和头文件导入到用 Cmake 生成的 LibPNG 的 sln，进行编译生成相关 Windows 环境下的 libharu-LIB 库。

- [大致过程:](https://github.com/libharu/libharu/issues/135)  
  ![windows下libharu库使用方式](./assets/libharu1.png)
- 遇到问题 1：将生成的 libharu 库导入到 otdr 项目后编译报错  
  hpdf.h 和 hpdf-types.h 两个头文件中一个 c 命名的变量报错，将变量名改成 cc 后解决？

## SOR 文件

# OTDR
