#ifndef __GURA_MODULE_CONIO_STDAFX_H__
#define __GURA_MODULE_CONIO_STDAFX_H__
#include "module-conio.h"
#if defined(GURA_ON_MSWIN)
#include <conio.h>
#elif defined(GURA_ON_LINUX)
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#else
#error unsupported platform
#endif

#endif
