//-----------------------------------------------------------------------------
// Gura bzip2 module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BZIP2_H__
#define __GURA_MODULE_BZIP2_H__
#include <gura.h>
#include <gura/helper/BZLibHelper.h>

Gura_BeginModuleHeader(bzip2)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Signal sig, Stream &stream);
Object_stream *GenerateCompressor(Environment &env, Signal sig, Stream &stream);

Gura_EndModuleHeader(bzip2)

#endif
