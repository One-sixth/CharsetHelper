#include <iostream>
#include <string>
#include <CharsetHelper.h>
#include <stdexcept>

using namespace std;


void printU8(u8string s)
{
	cout << "U8_OUT " << CharsetHelper::tr_utf8_to_local(s) << endl;
}


void printU16(u16string s)
{
	auto s2 = CharsetHelper::conv_utf16_to_utf8(s);
	cout << "U16_OUT " << CharsetHelper::tr_utf8_to_local(s2) << endl;
}


void printU32(u32string s)
{
	auto s2 = CharsetHelper::conv_utf32_to_utf8(s);
	cout << "U32_OUT " << CharsetHelper::tr_utf8_to_local(s2) << endl;
}


int main()
{
	const u8string s = u8"ni好，世界！";
	const u16string us = u"ni好，世界！";

	//-------------------------------------------------------
	cout << "测试获取系统代码页" << endl;
	{
		string local_name = CharsetHelper::get_local_name();
		cout << "local charset " << local_name << endl;
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试系统代码页与UTF8互转" << endl;
	{
		string s2 = CharsetHelper::tr_utf8_to_local(s);
		cout << s2 << endl;

		auto s3 = CharsetHelper::tr_local_to_utf8(s2);

		printU8(s3);

		if (s3 != s)
			throw runtime_error("Error!");

	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF8页与GBK互转" << endl;
	{
		string s2 = CharsetHelper::tr_utf8_to_gbk(s);

		u8string s3 = CharsetHelper::tr_gbk_to_utf8(s2);

		printU8(s3);

		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF8页与SHIFTJIS互转" << endl;
	{
		string s2 = CharsetHelper::tr_utf8_to_shiftjis(s);

		u8string s3 = CharsetHelper::tr_shiftjis_to_utf8(s2);

		printU8(s3);

		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF8页与BIG5互转" << endl;
	{
		string s2 = CharsetHelper::tr_utf8_to_big5(s);

		u8string s3 = CharsetHelper::tr_big5_to_utf8(s2);

		printU8(s3);

		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试tr函数" << endl;
	{
		string s2 = CharsetHelper::tr(CharsetHelper::cast_string(s), "Big5", "Utf8");

		u8string s3 = CharsetHelper::cast_u8string(CharsetHelper::tr(s2, "Utf8", "Big5"));

		printU8(s3);

		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试字符集异常" << endl;
	{
		try
		{
			CharsetHelper::tr(CharsetHelper::cast_string(s), "Big51", "Utf81");
			cout << "Failure Oh no..." << endl;
			return -1;
		}
		catch (const runtime_error e)
		{
			cout << "Catch error" << e.what() << endl;
		}
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试坏字符异常" << endl;
	{
		try
		{
			CharsetHelper::tr_utf8_to_shiftjis(u8"你好", CharsetHelper::stop);
			cout << "Failure! Oh no..." << endl;
			return -1;
		}
		catch (const runtime_error e)
		{
			cout << "Catch error" << e.what() << endl;
		}
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF8与UTF16互转" << endl;
	{
		auto s2 = CharsetHelper::conv_utf8_to_utf16(s);

		printU16(s2);

		u8string s3 = CharsetHelper::conv_utf16_to_utf8(s2);

		printU8(s3);
		
		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF32与UTF16互转" << endl;
	{
		auto s2 = CharsetHelper::conv_utf16_to_utf32(us);

		printU32(s2);

		u16string s3 = CharsetHelper::conv_utf32_to_utf16(s2);

		printU16(s3);

		if (s3 != us)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------
	cout << "测试UTF32与UTF8互转" << endl;
	{
		auto s2 = CharsetHelper::conv_utf8_to_utf32(s);
		u8string s3 = CharsetHelper::conv_utf32_to_utf8(s2);

		printU32(s2);

		if (s3 != s)
			throw runtime_error("Error!");
	}
	cout << "Success" << endl << endl;

	//-------------------------------------------------------

	return 0;
}
