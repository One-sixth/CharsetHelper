#define _CHARSETHELPER_EXPORT 1
#include "CharsetHelper.h"

//#define BOOST_ALL_NO_LIB 1
#include <boost/locale.hpp>

using namespace std;


static inline boost::locale::conv::method_type _how(CharsetHelper::Error e)
{
	switch (e)
	{
	case CharsetHelper::stop:
		return boost::locale::conv::method_type::stop;
	case CharsetHelper::skip:
	default:
		return boost::locale::conv::method_type::skip;
	}
}


string CharsetHelper::get_local_name()
{
	string strCodePage = boost::locale::util::get_system_locale();
	locale loc = boost::locale::generator().generate(strCodePage);
	return use_facet<boost::locale::info>(loc).encoding();
}

string CharsetHelper::tr_utf8_to_local(u8string s, Error e)
{
	const static string local_cp = get_local_name();
	return tr(cast_string(s), local_cp, "UTF8", e);
}

u8string CharsetHelper::tr_local_to_utf8(string s, Error e)
{
	const static string local_cp = get_local_name();
	return cast_u8string(tr(s, "UTF8", local_cp, e));
}

string CharsetHelper::tr_utf8_to_gbk(u8string s, Error e)
{
	return tr(cast_string(s), "GBK", "UTF8", e);
}

u8string CharsetHelper::tr_gbk_to_utf8(string s, Error e)
{
	return cast_u8string(tr(s, "UTF8", "GBK", e));
}

string CharsetHelper::tr_utf8_to_shiftjis(u8string s, Error e)
{
	return tr(cast_string(s), "SHIFT-JIS", "UTF8", e);
}

u8string CharsetHelper::tr_shiftjis_to_utf8(string s, Error e)
{
	return cast_u8string(tr(s, "UTF8", "SHIFT-JIS", e));
}

string CharsetHelper::tr_utf8_to_big5(u8string s, Error e)
{
	return tr(cast_string(s), "BIG5", "UTF8", e);
}

u8string CharsetHelper::tr_big5_to_utf8(string s, Error e)
{
	return cast_u8string(tr(s, "UTF8", "BIG5", e));
}

string CharsetHelper::tr(string s, string to_code, string from_code, Error e)
{
	return boost::locale::conv::between(s, to_code, from_code, _how(e));
}

u8string CharsetHelper::conv_utf16_to_utf8(u16string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char8_t>(s.c_str(), _how(e));
}

u16string CharsetHelper::conv_utf8_to_utf16(u8string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char16_t>(s.c_str(), _how(e));
}

u32string CharsetHelper::conv_utf16_to_utf32(u16string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char32_t>(s.c_str(), _how(e));
}

u16string CharsetHelper::conv_utf32_to_utf16(u32string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char16_t>(s.c_str(), _how(e));
}

u32string CharsetHelper::conv_utf8_to_utf32(u8string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char32_t>(s.c_str(), _how(e));
}

u8string CharsetHelper::conv_utf32_to_utf8(u32string s, Error e)
{
	return boost::locale::conv::utf_to_utf<char8_t>(s.c_str(), _how(e));
}

u8string CharsetHelper::cast_u8string(string s)
{
	return u8string((char8_t*)s.data(), s.size());
}

string CharsetHelper::cast_string(u8string s)
{
	return string((char*)s.data(), s.size());
}

u16string CharsetHelper::cast_u16string(wstring s)
{
	return u16string((char16_t*)s.data(), s.size());
}

wstring CharsetHelper::cast_wstring(u16string s)
{
	return wstring((wchar_t*)s.data(), s.size());
}
