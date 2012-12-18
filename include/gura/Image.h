#ifndef __GURA_IMAGE_H__
#define __GURA_IMAGE_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Image
//-----------------------------------------------------------------------------
class Image {
public:
	enum {
		OffsetRed	= 2,
		OffsetGreen	= 1,
		OffsetBlue	= 0,
		OffsetAlpha	= 3,
	};
	enum Format {
		FORMAT_None,
		FORMAT_RGB, FORMAT_RGBA,
	};
	enum ScanDir {
		SCAN_LeftTopHorz, SCAN_LeftTopVert,
		SCAN_RightTopHorz, SCAN_RightTopVert,
		SCAN_LeftBottomHorz, SCAN_LeftBottomVert,
		SCAN_RightBottomHorz, SCAN_RightBottomVert,
	};
};

}

#endif
