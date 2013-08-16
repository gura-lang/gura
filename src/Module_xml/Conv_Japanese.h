#ifndef __CONV_JAPANESE_H__
#define __CONV_JAPANESE_H__

#include <gura.h>

namespace Gura {

//-----------------------------------------------------------------------------
// Simple converter functions
//-----------------------------------------------------------------------------
UShort CP932ToUTF16(UShort codeCP932);
UShort UTF16ToCP932(UShort codeUTF16);
UShort CP932ToJIS(UShort codeCP932);
UShort JISToCP932(UShort codeJIS);
UShort CP932ToEUCJP(UShort codeCP932);
UShort EUCJPToCP932(UShort codeEUCJP);

}

#endif
