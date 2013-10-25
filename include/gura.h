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
#include "gura/CustomClass.h"
#include "gura/CustomFunction.h"
#include "gura/Directory.h"
#include "gura/Expr.h"
#include "gura/Formatter.h"
#include "gura/Image.h"
#include "gura/Iterator.h"
#include "gura/Matrix.h"
#include "gura/Memory.h"
#include "gura/Module.h"
#include "gura/Operator.h"
#include "gura/Option.h"
#include "gura/PackedNumber.h"
#include "gura/Palette.h"
#include "gura/Parser.h"
#include "gura/PathManager.h"
#include "gura/PrimitiveClass.h"
#include "gura/Processor.h"
#include "gura/String.h"
#include "gura/StructObject.h"
#include "gura/TemplateEngine.h"

#include "gura/Object_args.h"
#include "gura/Object_audio.h"
#include "gura/Object_binary.h"
#include "gura/Object_codec.h"
#include "gura/Object_color.h"
#include "gura/Object_datetime.h"
#include "gura/Object_declaration.h"
#include "gura/Object_dict.h"
#include "gura/Object_directory.h"
#include "gura/Object_environment.h"
#include "gura/Object_error.h"
#include "gura/Object_expr.h"
#include "gura/Object_function.h"
#include "gura/Object_help.h"
#include "gura/Object_image.h"
#include "gura/Object_iterator.h"
#include "gura/Object_list.h"
#include "gura/Object_matrix.h"
#include "gura/Object_operator.h"
#include "gura/Object_palette.h"
#include "gura/Object_pointer.h"
#include "gura/Object_semaphore.h"
#include "gura/Object_stream.h"
#include "gura/Object_timedelta.h"
#include "gura/Object_uri.h"

#endif
