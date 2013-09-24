#ifndef __CONV_JAPANESE_H__
#define __CONV_JAPANESE_H__

#include <gura.h>

namespace Gura {

//-----------------------------------------------------------------------------
// Simple converter functions
//-----------------------------------------------------------------------------
GURA_DLLDECLARE UShort CP932ToUTF16(UShort codeCP932);
GURA_DLLDECLARE UShort UTF16ToCP932(UShort codeUTF16);
GURA_DLLDECLARE UShort CP932ToJIS(UShort codeCP932);
GURA_DLLDECLARE UShort JISToCP932(UShort codeJIS);
GURA_DLLDECLARE UShort CP932ToEUCJP(UShort codeCP932);
GURA_DLLDECLARE UShort EUCJPToCP932(UShort codeEUCJP);

}

#endif
