//=============================================================================
// Gura Programming Language
// Copyright (C) 2011-2014 ypsitau
//=============================================================================
#ifndef __GURA_H__
#define __GURA_H__

#if defined(_MSC_VER)
#include <windows.h>
#include <direct.h>		// getcwd()
#endif

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <complex>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <algorithm>

#include "gura/Algorithm.h"
#include "gura/Audio.h"
#include "gura/Binary.h"
#include "gura/Class.h"
#include "gura/ClassBasic.h"
#include "gura/ClassCustom.h"
#include "gura/ClassOfStruct.h"
#include "gura/Color.h"
#include "gura/Complex.h"
#include "gura/Directory.h"
#include "gura/Expr.h"
#include "gura/Formatter.h"
#include "gura/FunctionCustom.h"
#include "gura/Image.h"
#include "gura/Iterator.h"
#include "gura/IteratorBasic.h"
#include "gura/Matrix.h"
#include "gura/Memory.h"
#include "gura/Module.h"
#include "gura/Operator.h"
#include "gura/Option.h"
#include "gura/PackedNumber.h"
#include "gura/Palette.h"
#include "gura/Parser.h"
#include "gura/PathMgr.h"
#include "gura/Processor.h"
#include "gura/Random.h"
#include "gura/Rational.h"
#include "gura/Stream.h"
#include "gura/StreamBasic.h"
#include "gura/String.h"
#include "gura/SuffixMgr.h"
#include "gura/Template.h"
#include "gura/Unicode-CP932.h"
#include "gura/Unicode-CP936.h"
#include "gura/Unicode-CP949.h"
#include "gura/Unicode-CP950.h"
#include "gura/Uri.h"

#include "gura/Class_args.h"
#include "gura/Class_audio.h"
#include "gura/Class_binary.h"
#include "gura/Class_codec.h"
#include "gura/Class_color.h"
#include "gura/Class_datetime.h"
#include "gura/Class_declaration.h"
#include "gura/Class_dict.h"
#include "gura/Class_directory.h"
#include "gura/Class_environment.h"
#include "gura/Class_error.h"
#include "gura/Class_expr.h"
#include "gura/Class_function.h"
#include "gura/Class_help.h"
#include "gura/Class_image.h"
#include "gura/Class_iterator.h"
#include "gura/Class_list.h"
#include "gura/Class_matrix.h"
#include "gura/Class_operator.h"
#include "gura/Class_palette.h"
#include "gura/Class_pointer.h"
#include "gura/Class_semaphore.h"
#include "gura/Class_stream.h"
#include "gura/Class_suffixmgr.h"
#include "gura/Class_template.h"
#include "gura/Class_timedelta.h"
#include "gura/Class_uri.h"

#endif
