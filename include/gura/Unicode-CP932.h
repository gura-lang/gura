//=============================================================================
// Unicode-CP932
//=============================================================================
#ifndef __GURA_UNICODE_CP932_H__
#define __GURA_UNICODE_CP932_H__
#include "Common.h"

namespace Gura {

GURA_DLLDECLARE UShort CP932ToUTF16(UShort codeCP932);
GURA_DLLDECLARE UShort UTF16ToCP932(UShort codeUTF16);
GURA_DLLDECLARE UShort CP932ToJIS(UShort codeCP932);
GURA_DLLDECLARE UShort JISToCP932(UShort codeJIS);
GURA_DLLDECLARE UShort CP932ToEUCJP(UShort codeCP932);
GURA_DLLDECLARE UShort EUCJPToCP932(UShort codeEUCJP);

}

#endif
