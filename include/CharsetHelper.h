#pragma once
#ifndef __CHARSETHELPER_H__

#include <string>


#ifdef _WIN32					// ��Windows����Ҫ��Linux����Ҫ
#ifdef _CHARSETHELPER_EXPORT	// �����˸ú�Ĳ�Ϊ�����������Ϊ����
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

	// ��ñ����ַ���������
	DLL_INTERFACE_API static string		get_local_name();


	// �����ַ���ת��

	// UTF8�뱾���ַ�������ת��
	DLL_INTERFACE_API static string		tr_utf8_to_local(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_local_to_utf8(string s, Error e=skip);

	// UTF8��GBK����ת��
	DLL_INTERFACE_API static string		tr_utf8_to_gbk(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_gbk_to_utf8(string s, Error e=skip);

	// UTF8��SHIFT-JIS����ת��
	DLL_INTERFACE_API static string		tr_utf8_to_shiftjis(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_shiftjis_to_utf8(string s, Error e=skip);

	// UTF8��BIG5����ת��
	DLL_INTERFACE_API static string		tr_utf8_to_big5(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	tr_big5_to_utf8(string s, Error e=skip);

	// �����ַ����������ַ�������ת��������֧�ָ���ת��ʱ�����׳�����
	DLL_INTERFACE_API static string		tr(string s, string to_code, string from_code, Error e=skip);


	// UTF ��ͬ�ַ�������ת��
	// ��Ϊʹ���˲�ͬ��boost locale�Ľӿڣ����Բ�ʹ��tr��Ϊ����ͷ����ʾ����

	// UTF8��UTF16����ת��
	DLL_INTERFACE_API static u16string	conv_utf8_to_utf16(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	conv_utf16_to_utf8(u16string s, Error e=skip);

	// UTF16��UTF32����ת��
	DLL_INTERFACE_API static u32string	conv_utf16_to_utf32(u16string s, Error e=skip);
	DLL_INTERFACE_API static u16string	conv_utf32_to_utf16(u32string s, Error e=skip);

	// UTF8��UTF32����ת��
	DLL_INTERFACE_API static u32string	conv_utf8_to_utf32(u8string s, Error e=skip);
	DLL_INTERFACE_API static u8string	conv_utf32_to_utf8(u32string s, Error e=skip);


	// ͬ���Ͳ�ͬ������ǿ��ת��

	// �����ȷ֪��string����ΪUTF8�ַ�����ʹ�øú�������ǿ��ת��Ϊu8string
	DLL_INTERFACE_API static u8string	cast_u8string(string s);
	DLL_INTERFACE_API static string		cast_string(u8string s);

	// �����ȷ֪��wstring����ΪUTF16�ַ�����ʹ�øú�������ǿ��ת��Ϊwstring
	DLL_INTERFACE_API static u16string	cast_u16string(wstring s);
	DLL_INTERFACE_API static wstring	cast_wstring(u16string s);

};


#endif // !__CHARSETHELPER_H__
