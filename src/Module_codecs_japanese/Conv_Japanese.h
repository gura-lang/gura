#ifndef __CONV_JAPANESE_H__
#define __CONV_JAPANESE_H__

#include <gura.h>

namespace Gura {

//-----------------------------------------------------------------------------
// Simple converter functions
//-----------------------------------------------------------------------------
unsigned short CP932ToUTF16(unsigned short codeCP932);
unsigned short UTF16ToCP932(unsigned short codeUTF16);
unsigned short CP932ToJIS(unsigned short codeCP932);
unsigned short JISToCP932(unsigned short codeJIS);
unsigned short CP932ToEUCJP(unsigned short codeCP932);
unsigned short EUCJPToCP932(unsigned short codeEUCJP);

}

#endif
