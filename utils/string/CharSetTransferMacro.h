
#if !defined(AFX_CHARSET_TRANSFER_H__B74FFB0C_5199_4DE8_BC36_D49A9EBA4575__INCLUDED_)
#define AFX_CHARSET_TRANSFER_H__B74FFB0C_5199_4DE8_BC36_D49A9EBA4575__INCLUDED_
//CharSetTransferMacro.h, by wyb
#include "AfxPriv.h"
//default ansi codepage is GBK, returned by GetACP()
#define CP_GBK			936
#define CP_GB2312		20936
#define CP_BIG5			950
#define CP_ISO8859_1	28591

#define USES_MYCP_CONVERSION int _convert = 0; _convert; UINT _acp = CP_ACP; _acp; \
	LPCWSTR _lpw = NULL; _lpw; LPCSTR _lpa = NULL; _lpa;\
	LPWSTR _lpw2 = NULL; _lpw2; LPSTR _lpa2 = NULL; _lpa2;int nMul = 2

//UTF-8 encodes each Unicode character as a variable number of 1 to 6 octets, 
//so if use utf-8 in conversion, you must use this macro after USES_MYCP_CONVERSION;
#define USES_CP_UTF8 nMul = 6

/*About utf-8
UTF-8 stands for Unicode Transformation Format-8. 
It is an octet (8-bit) lossless encoding of Unicode characters.
UTF-8 encodes each Unicode character as a variable number of 1 to 6 octets, 
where the number of octets depends on the integer value assigned to the Unicode character.
It is an efficient encoding of Unicode documents that use US-ASCII characters 
because it represents each character in the range U+0000 through U+007F as a single octet.
*/  
//unicode(UTF_16LE) to codepage
#define W2CP(lpw,cp) (\
	((_lpw = lpw) == NULL) ? NULL : (\
	_convert = (lstrlenW(_lpw)+1)*nMul,\
AtlW2AHelper((LPSTR) alloca(_convert), _lpw, _convert, cp)))

//code page to unicode
#define CP2W(lpa,cp) (\
	((_lpa = lpa) == NULL) ? NULL : (\
	_convert = (lstrlenA(_lpa)+1),\
AtlA2WHelper((LPWSTR) alloca(_convert*2), _lpa, _convert, cp)))

//default ansi codepage to another codepage, need transfer twice
#define A2CP(lpa,cp) (_lpw2 = A2W(lpa),W2CP(_lpw2,cp))

//another codepage to default ansi codepage , need transfer twice
#define CP2A(lpa,cp) (_lpw2 = CP2W(lpa,cp),W2A(_lpw2))

//codepage1 to codepage 2, need transfer twice
#define CP2CP(lpa,cp1,cp2) (_lpw2 = CP2W(lpa,cp1),W2CP(_lpw2,cp2))


#endif
