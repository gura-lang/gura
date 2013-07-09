#ifndef __SOUNDFONT_H__
#define __SOUNDFONT_H__
#include <gura.h>

Gura_BeginModule(midi)

bool ReadSF2(Environment &env, Signal sig, Stream &stream);

}}

#endif
