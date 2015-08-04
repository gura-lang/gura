//-----------------------------------------------------------------------------
// Gura module: bzip2
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BZIP2_H__
#define __GURA_MODULE_BZIP2_H__
#include <gura.h>
#include <gura/helper/BZLibHelper.h>

Gura_BeginModuleHeader(bzip2)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Stream &stream);
Object_stream *GenerateCompressor(Environment &env, Stream &stream, int blockSize100k);

Gura_EndModuleHeader(bzip2)

#endif
