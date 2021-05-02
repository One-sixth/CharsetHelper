#pragma once
#ifndef __CHARSETHELPER_H__

#include <string>


#ifdef _WIN32					// 仅Windows才需要，Linux不需要
#ifdef _CHARSETHELPER_EXPORT	// 定义了该宏的才为导出，否则均为导入
#define DLL_INTERFACE_API __declspec(dllexport)
#else
#define DLL_INTERFACE_API __declspec(dllimport)
#endif
#endif


class CharsetHelper
{
	using string	= std::string;
	using wstring	= std::wstring;
	using u8string	= std::u8string;
	using u16string	= std::u16string;
	using u32string	= std::u32string;

public:
	// Copy from boost
	enum Error
	{
		skip = 0,    ///< Skip illegal/unconvertable characters
		stop = 1,    ///< Stop conversion and throw conversion_error
	};

public:

	// 获得本地字符集的名称
	DLL_INTERFACE_API static string		get_local_name();


	// 常见字符集转换

	// UTF8与本地字符集互相转换
	DLL_INTERFACE_API static string		tr_utf8_to_local(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_local_to_utf8(string s, Error e=skip);

	// UTF8与GBK互相转换
	DLL_INTERFACE_API static string		tr_utf8_to_gbk(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_gbk_to_utf8(string s, Error e=skip);

	// UTF8与SHIFT-JIS互相转换
	DLL_INTERFACE_API static string		tr_utf8_to_shiftjis(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_shiftjis_to_utf8(string s, Error e=skip);

	// UTF8与BIG5互相转换
	DLL_INTERFACE_API static string		tr_utf8_to_big5(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_big5_to_utf8(string s, Error e=skip);

	// 任意字符集与任意字符集互相转换，当不支持该种转换时，会抛出错误
	DLL_INTERFACE_API static string		tr(string s, string to_code, string from_code, Error e=skip);


	// UTF 不同字符集互相转换
	// 因为使用了不同的boost locale的接口，所以不使用tr作为函数头，以示区别

	// UTF8与UTF16互相转换
	DLL_INTERFACE_API static u16string	conv_utf8_to_utf16(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	conv_utf16_to_utf8(u16string s, Error e=skip);

	// UTF16与UTF32互相转换
	DLL_INTERFACE_API static u32string	conv_utf16_to_utf32(u16string s, Error e=skip);
	DLL_INTERFACE_API static u16string	conv_utf32_to_utf16(u32string s, Error e=skip);

	// UTF8与UTF32互相转换
	DLL_INTERFACE_API static u32string	conv_utf8_to_utf32(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	conv_utf32_to_utf8(u32string s, Error e=skip);


	// 同类型不同类型名强制转换

	// 如果明确知道string内容为UTF8字符集，使用该函数将其强制转换为u8string
	DLL_INTERFACE_API static u8string	cast_u8string(string s);
	DLL_INTERFACE_API static string		cast_string(u8string s);

	// 如果明确知道wstring内容为UTF16字符集，使用该函数将其强制转换为wstring
	DLL_INTERFACE_API static u16string	cast_u16string(wstring s);
	DLL_INTERFACE_API static wstring	cast_wstring(u16string s);

};


#endif // !__CHARSETHELPER_H__
