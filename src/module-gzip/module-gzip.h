//-----------------------------------------------------------------------------
// Gura module: gzip
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_GZIP_H__
#define __GURA_MODULE_GZIP_H__
#include <gura.h>
#include <gura/helper/ZLibHelper.h>

Gura_BeginModuleHeader(gzip)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env,
								Stream *pStreamSrc, int windowBits);
Object_stream *GenerateCompressor(Environment &env,
								Stream *pStreamDst, int level, int windowBits);

Gura_EndModuleHeader(gzip)

#endif
