# CharsetHelper
A c++20 gbk big5 shiftjis local utf8 utf16 utf32 charset convert helper.  
一个基于C++20编写的 GBK BIG5 SHIFTJIS local utf8 utf16 utf32 的编码转换助手库。  

This library further encapsulates the Boost locale library, making it easier to use daily. And there is no need for any Boost dependencies or other dependencies when using this library.  
这个库进一步封装了Boost locale库，使其更易于日常使用。并且使用该库时不需要任何Boost依赖和其他依赖。  

Welcome issue.  
欢迎提问。  


# Dependent / 依赖

The use and compilation requires a compiler that supports C++20, because u8string, u16string, u32string are used.  
Compiling this library requires a library above Boost 1.70.  
If it is used, there is no dependency.  

使用和编译需要支持 C++20 的编译器，因为使用了u8string, u16string, u32string。  
编译这个库需要 Boost 1.70 以上的库。  
单纯使用则没有任何外部依赖。  


# Note
The code was written and tested on Windows10 VS2019. Built by CMake. The code can also be built on Linux, but I haven't tested it.  
该代码在Windows10 VS2019上编写并测试。由CMake构建。该代码也可以在Linux上构建，但我没有测试过。  

I originally wanted to construct a static library, but found that there is no easy way to package additional dependent libraries.  
In order to cut off the dependency of Boost, I built it as a dynamic link library.  
I originally wanted to add the ICU library to the build, but found that the ICU library did not have an easy way to build a static library, because I didn't want to introduce the many DLL files of the ICU library, so I excluded it.  

我原本想构造静态库，但发现没有一个简单的方法打包附加依赖库。  
为了斩断Boost的依赖关系，我将其构建为一个动态链接库。  
我原本也想把ICU库加入构建，但发现ICU库没有一个简单的方法构建静态库，因为不想引入ICU库众多的DLL文件，所以也排除在外了。  


# Release / 发行版本
You can find the windows build version in [Release](https://github.com/One-sixth/CharsetHelper/releases).  
The Linux version currently needs to be built by yourself.  

你可以在[Release](https://github.com/One-sixth/CharsetHelper/releases)找到windows构建版本。  
Linux版本目前需要自行构建。  


# How to use / 如何使用
This is a very simple example.  
这是一个非常简单的示例。  

[Example Code](/example/main.cpp)

Some API Show
```C++
#include <string>
#include <iostream>
#include <CharsetHelper.h>

using namespace std;


// Easy tr utf8 to gbk and invert it.
// 你可以轻松地将GBK编码与UTF8编码互相转换
u8string s = u8"你好";
string gbk_str = CharsetHelper::tr_utf8_to_gbk(s);
u8string u8_str = CharsetHelper::tr_gbk_to_utf8(gbk_str);

// You also can easy tr utf8 to your system codepage or invert it.
// 你也可以轻松地将系统编码与UTF8编码互相转换
u8string s = u8"你好";
string local_str = CharsetHelper::tr_utf8_to_local(s);
cout << local_str << endl;
u8string u8_str = CharsetHelper::tr_local_to_utf8(local_str);

// Easy tr utf8 to utf16/utf32 and invert it.
// 轻松地在u8 u16 u32字符串间互相转换。
u8string s = u8"你好";
u16string u16s = CharsetHelper::conv_utf8_to_utf16(s);
u32string u32s = CharsetHelper::conv_utf8_to_utf32(s);
u8string u8s_1 = CharsetHelper::conv_utf16_to_utf8(u16s);
u8string u8s_2 = CharsetHelper::conv_utt32_to_utf8(u32s);

// If you can know the real encoding of the string, you can easily convert it to the target string.
// 如果你知道字符串的真实编码，你还可以轻松转换为目标字符串
string s = "\xE4\xBD\xA0\xE5\xA5\xBD";  // u8"你好"
u8string u8s = CharsetHelper::cast_u8string(s);
cout << CharsetHelper::tr_utf8_to_local(u8s) << endl;
```


