//-----------------------------------------------------------------------------
// Gura gzip module
//-----------------------------------------------------------------------------
#ifndef __MODULE_GZIP_H__
#define __MODULE_GZIP_H__
#include <gura.h>
#include <gura/helper/ZLibHelper.h>

Gura_BeginModuleHeader(gzip, gzip)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Signal sig,
								Stream *pStreamSrc, int windowBits);
Object_stream *GenerateCompressor(Environment &env, Signal sig,
								Stream *pStreamDst, int level, int windowBits);

Gura_EndModuleHeader(gzip, gzip)

#endif
