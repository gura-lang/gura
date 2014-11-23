#include "stdafx.h"

Gura_BeginModuleScope(glut)

void AssignValues(Environment &env)
{
#if defined(GLUT_APIENTRY_DEFINED)
	Gura_AssignValue(GLUT_APIENTRY_DEFINED, Value(GLUT_APIENTRY_DEFINED));
#endif
#if defined(GLUT_API_VERSION)
	Gura_AssignValue(GLUT_API_VERSION, Value(GLUT_API_VERSION));
#endif
#if defined(GLUT_XLIB_IMPLEMENTATION)
	Gura_AssignValue(GLUT_XLIB_IMPLEMENTATION, Value(GLUT_XLIB_IMPLEMENTATION));
#endif
#if defined(GLUT_MACOSX_IMPLEMENTATION)
	Gura_AssignValue(GLUT_MACOSX_IMPLEMENTATION, Value(GLUT_MACOSX_IMPLEMENTATION));
#endif
#if defined(GLUT_RGB)
	Gura_AssignValue(GLUT_RGB, Value(GLUT_RGB));
#endif
#if defined(GLUT_RGBA)
	Gura_AssignValue(GLUT_RGBA, Value(GLUT_RGBA));
#endif
#if defined(GLUT_INDEX)
	Gura_AssignValue(GLUT_INDEX, Value(GLUT_INDEX));
#endif
#if defined(GLUT_SINGLE)
	Gura_AssignValue(GLUT_SINGLE, Value(GLUT_SINGLE));
#endif
#if defined(GLUT_DOUBLE)
	Gura_AssignValue(GLUT_DOUBLE, Value(GLUT_DOUBLE));
#endif
#if defined(GLUT_ACCUM)
	Gura_AssignValue(GLUT_ACCUM, Value(GLUT_ACCUM));
#endif
#if defined(GLUT_ALPHA)
	Gura_AssignValue(GLUT_ALPHA, Value(GLUT_ALPHA));
#endif
#if defined(GLUT_DEPTH)
	Gura_AssignValue(GLUT_DEPTH, Value(GLUT_DEPTH));
#endif
#if defined(GLUT_STENCIL)
	Gura_AssignValue(GLUT_STENCIL, Value(GLUT_STENCIL));
#endif
#if defined(GLUT_MULTISAMPLE)
	Gura_AssignValue(GLUT_MULTISAMPLE, Value(GLUT_MULTISAMPLE));
#endif
#if defined(GLUT_STEREO)
	Gura_AssignValue(GLUT_STEREO, Value(GLUT_STEREO));
#endif
#if defined(GLUT_LUMINANCE)
	Gura_AssignValue(GLUT_LUMINANCE, Value(GLUT_LUMINANCE));
#endif
#if defined(GLUT_NO_RECOVERY)
	Gura_AssignValue(GLUT_NO_RECOVERY, Value(GLUT_NO_RECOVERY));
#endif
#if defined(GLUT_3_2_CORE_PROFILE)
	Gura_AssignValue(GLUT_3_2_CORE_PROFILE, Value(GLUT_3_2_CORE_PROFILE));
#endif
#if defined(GLUT_LEFT_BUTTON)
	Gura_AssignValue(GLUT_LEFT_BUTTON, Value(GLUT_LEFT_BUTTON));
#endif
#if defined(GLUT_MIDDLE_BUTTON)
	Gura_AssignValue(GLUT_MIDDLE_BUTTON, Value(GLUT_MIDDLE_BUTTON));
#endif
#if defined(GLUT_RIGHT_BUTTON)
	Gura_AssignValue(GLUT_RIGHT_BUTTON, Value(GLUT_RIGHT_BUTTON));
#endif
#if defined(GLUT_DOWN)
	Gura_AssignValue(GLUT_DOWN, Value(GLUT_DOWN));
#endif
#if defined(GLUT_UP)
	Gura_AssignValue(GLUT_UP, Value(GLUT_UP));
#endif
#if defined(GLUT_KEY_F1)
	Gura_AssignValue(GLUT_KEY_F1, Value(GLUT_KEY_F1));
#endif
#if defined(GLUT_KEY_F2)
	Gura_AssignValue(GLUT_KEY_F2, Value(GLUT_KEY_F2));
#endif
#if defined(GLUT_KEY_F3)
	Gura_AssignValue(GLUT_KEY_F3, Value(GLUT_KEY_F3));
#endif
#if defined(GLUT_KEY_F4)
	Gura_AssignValue(GLUT_KEY_F4, Value(GLUT_KEY_F4));
#endif
#if defined(GLUT_KEY_F5)
	Gura_AssignValue(GLUT_KEY_F5, Value(GLUT_KEY_F5));
#endif
#if defined(GLUT_KEY_F6)
	Gura_AssignValue(GLUT_KEY_F6, Value(GLUT_KEY_F6));
#endif
#if defined(GLUT_KEY_F7)
	Gura_AssignValue(GLUT_KEY_F7, Value(GLUT_KEY_F7));
#endif
#if defined(GLUT_KEY_F8)
	Gura_AssignValue(GLUT_KEY_F8, Value(GLUT_KEY_F8));
#endif
#if defined(GLUT_KEY_F9)
	Gura_AssignValue(GLUT_KEY_F9, Value(GLUT_KEY_F9));
#endif
#if defined(GLUT_KEY_F10)
	Gura_AssignValue(GLUT_KEY_F10, Value(GLUT_KEY_F10));
#endif
#if defined(GLUT_KEY_F11)
	Gura_AssignValue(GLUT_KEY_F11, Value(GLUT_KEY_F11));
#endif
#if defined(GLUT_KEY_F12)
	Gura_AssignValue(GLUT_KEY_F12, Value(GLUT_KEY_F12));
#endif
#if defined(GLUT_KEY_LEFT)
	Gura_AssignValue(GLUT_KEY_LEFT, Value(GLUT_KEY_LEFT));
#endif
#if defined(GLUT_KEY_UP)
	Gura_AssignValue(GLUT_KEY_UP, Value(GLUT_KEY_UP));
#endif
#if defined(GLUT_KEY_RIGHT)
	Gura_AssignValue(GLUT_KEY_RIGHT, Value(GLUT_KEY_RIGHT));
#endif
#if defined(GLUT_KEY_DOWN)
	Gura_AssignValue(GLUT_KEY_DOWN, Value(GLUT_KEY_DOWN));
#endif
#if defined(GLUT_KEY_PAGE_UP)
	Gura_AssignValue(GLUT_KEY_PAGE_UP, Value(GLUT_KEY_PAGE_UP));
#endif
#if defined(GLUT_KEY_PAGE_DOWN)
	Gura_AssignValue(GLUT_KEY_PAGE_DOWN, Value(GLUT_KEY_PAGE_DOWN));
#endif
#if defined(GLUT_KEY_HOME)
	Gura_AssignValue(GLUT_KEY_HOME, Value(GLUT_KEY_HOME));
#endif
#if defined(GLUT_KEY_END)
	Gura_AssignValue(GLUT_KEY_END, Value(GLUT_KEY_END));
#endif
#if defined(GLUT_KEY_INSERT)
	Gura_AssignValue(GLUT_KEY_INSERT, Value(GLUT_KEY_INSERT));
#endif
#if defined(GLUT_LEFT)
	Gura_AssignValue(GLUT_LEFT, Value(GLUT_LEFT));
#endif
#if defined(GLUT_ENTERED)
	Gura_AssignValue(GLUT_ENTERED, Value(GLUT_ENTERED));
#endif
#if defined(GLUT_MENU_NOT_IN_USE)
	Gura_AssignValue(GLUT_MENU_NOT_IN_USE, Value(GLUT_MENU_NOT_IN_USE));
#endif
#if defined(GLUT_MENU_IN_USE)
	Gura_AssignValue(GLUT_MENU_IN_USE, Value(GLUT_MENU_IN_USE));
#endif
#if defined(GLUT_NOT_VISIBLE)
	Gura_AssignValue(GLUT_NOT_VISIBLE, Value(GLUT_NOT_VISIBLE));
#endif
#if defined(GLUT_VISIBLE)
	Gura_AssignValue(GLUT_VISIBLE, Value(GLUT_VISIBLE));
#endif
#if defined(GLUT_HIDDEN)
	Gura_AssignValue(GLUT_HIDDEN, Value(GLUT_HIDDEN));
#endif
#if defined(GLUT_FULLY_RETAINED)
	Gura_AssignValue(GLUT_FULLY_RETAINED, Value(GLUT_FULLY_RETAINED));
#endif
#if defined(GLUT_PARTIALLY_RETAINED)
	Gura_AssignValue(GLUT_PARTIALLY_RETAINED, Value(GLUT_PARTIALLY_RETAINED));
#endif
#if defined(GLUT_FULLY_COVERED)
	Gura_AssignValue(GLUT_FULLY_COVERED, Value(GLUT_FULLY_COVERED));
#endif
#if defined(GLUT_RED)
	Gura_AssignValue(GLUT_RED, Value(GLUT_RED));
#endif
#if defined(GLUT_GREEN)
	Gura_AssignValue(GLUT_GREEN, Value(GLUT_GREEN));
#endif
#if defined(GLUT_BLUE)
	Gura_AssignValue(GLUT_BLUE, Value(GLUT_BLUE));
#endif
#if defined(GLUT_NORMAL)
	Gura_AssignValue(GLUT_NORMAL, Value(GLUT_NORMAL));
#endif
#if defined(GLUT_OVERLAY)
	Gura_AssignValue(GLUT_OVERLAY, Value(GLUT_OVERLAY));
#endif
#if defined(GLUT_STROKE_ROMAN)
	Gura_AssignValue(GLUT_STROKE_ROMAN, Value(GLUT_STROKE_ROMAN));
#endif
#if defined(GLUT_STROKE_MONO_ROMAN)
	Gura_AssignValue(GLUT_STROKE_MONO_ROMAN, Value(GLUT_STROKE_MONO_ROMAN));
#endif
#if defined(GLUT_BITMAP_9_BY_15)
	Gura_AssignValue(GLUT_BITMAP_9_BY_15, Value(GLUT_BITMAP_9_BY_15));
#endif
#if defined(GLUT_BITMAP_8_BY_13)
	Gura_AssignValue(GLUT_BITMAP_8_BY_13, Value(GLUT_BITMAP_8_BY_13));
#endif
#if defined(GLUT_BITMAP_TIMES_ROMAN_10)
	Gura_AssignValue(GLUT_BITMAP_TIMES_ROMAN_10, Value(GLUT_BITMAP_TIMES_ROMAN_10));
#endif
#if defined(GLUT_BITMAP_TIMES_ROMAN_24)
	Gura_AssignValue(GLUT_BITMAP_TIMES_ROMAN_24, Value(GLUT_BITMAP_TIMES_ROMAN_24));
#endif
#if defined(GLUT_BITMAP_HELVETICA_10)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_10, Value(GLUT_BITMAP_HELVETICA_10));
#endif
#if defined(GLUT_BITMAP_HELVETICA_12)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_12, Value(GLUT_BITMAP_HELVETICA_12));
#endif
#if defined(GLUT_BITMAP_HELVETICA_18)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_18, Value(GLUT_BITMAP_HELVETICA_18));
#endif
#if defined(GLUT_STROKE_ROMAN)
	Gura_AssignValue(GLUT_STROKE_ROMAN, Value(GLUT_STROKE_ROMAN));
#endif
#if defined(GLUT_STROKE_MONO_ROMAN)
	Gura_AssignValue(GLUT_STROKE_MONO_ROMAN, Value(GLUT_STROKE_MONO_ROMAN));
#endif
#if defined(GLUT_BITMAP_9_BY_15)
	Gura_AssignValue(GLUT_BITMAP_9_BY_15, Value(GLUT_BITMAP_9_BY_15));
#endif
#if defined(GLUT_BITMAP_8_BY_13)
	Gura_AssignValue(GLUT_BITMAP_8_BY_13, Value(GLUT_BITMAP_8_BY_13));
#endif
#if defined(GLUT_BITMAP_TIMES_ROMAN_10)
	Gura_AssignValue(GLUT_BITMAP_TIMES_ROMAN_10, Value(GLUT_BITMAP_TIMES_ROMAN_10));
#endif
#if defined(GLUT_BITMAP_TIMES_ROMAN_24)
	Gura_AssignValue(GLUT_BITMAP_TIMES_ROMAN_24, Value(GLUT_BITMAP_TIMES_ROMAN_24));
#endif
#if defined(GLUT_BITMAP_HELVETICA_10)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_10, Value(GLUT_BITMAP_HELVETICA_10));
#endif
#if defined(GLUT_BITMAP_HELVETICA_12)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_12, Value(GLUT_BITMAP_HELVETICA_12));
#endif
#if defined(GLUT_BITMAP_HELVETICA_18)
	Gura_AssignValue(GLUT_BITMAP_HELVETICA_18, Value(GLUT_BITMAP_HELVETICA_18));
#endif
#if defined(GLUT_WINDOW_X)
	Gura_AssignValue(GLUT_WINDOW_X, Value(GLUT_WINDOW_X));
#endif
#if defined(GLUT_WINDOW_Y)
	Gura_AssignValue(GLUT_WINDOW_Y, Value(GLUT_WINDOW_Y));
#endif
#if defined(GLUT_WINDOW_WIDTH)
	Gura_AssignValue(GLUT_WINDOW_WIDTH, Value(GLUT_WINDOW_WIDTH));
#endif
#if defined(GLUT_WINDOW_HEIGHT)
	Gura_AssignValue(GLUT_WINDOW_HEIGHT, Value(GLUT_WINDOW_HEIGHT));
#endif
#if defined(GLUT_WINDOW_BUFFER_SIZE)
	Gura_AssignValue(GLUT_WINDOW_BUFFER_SIZE, Value(GLUT_WINDOW_BUFFER_SIZE));
#endif
#if defined(GLUT_WINDOW_STENCIL_SIZE)
	Gura_AssignValue(GLUT_WINDOW_STENCIL_SIZE, Value(GLUT_WINDOW_STENCIL_SIZE));
#endif
#if defined(GLUT_WINDOW_DEPTH_SIZE)
	Gura_AssignValue(GLUT_WINDOW_DEPTH_SIZE, Value(GLUT_WINDOW_DEPTH_SIZE));
#endif
#if defined(GLUT_WINDOW_RED_SIZE)
	Gura_AssignValue(GLUT_WINDOW_RED_SIZE, Value(GLUT_WINDOW_RED_SIZE));
#endif
#if defined(GLUT_WINDOW_GREEN_SIZE)
	Gura_AssignValue(GLUT_WINDOW_GREEN_SIZE, Value(GLUT_WINDOW_GREEN_SIZE));
#endif
#if defined(GLUT_WINDOW_BLUE_SIZE)
	Gura_AssignValue(GLUT_WINDOW_BLUE_SIZE, Value(GLUT_WINDOW_BLUE_SIZE));
#endif
#if defined(GLUT_WINDOW_ALPHA_SIZE)
	Gura_AssignValue(GLUT_WINDOW_ALPHA_SIZE, Value(GLUT_WINDOW_ALPHA_SIZE));
#endif
#if defined(GLUT_WINDOW_ACCUM_RED_SIZE)
	Gura_AssignValue(GLUT_WINDOW_ACCUM_RED_SIZE, Value(GLUT_WINDOW_ACCUM_RED_SIZE));
#endif
#if defined(GLUT_WINDOW_ACCUM_GREEN_SIZE)
	Gura_AssignValue(GLUT_WINDOW_ACCUM_GREEN_SIZE, Value(GLUT_WINDOW_ACCUM_GREEN_SIZE));
#endif
#if defined(GLUT_WINDOW_ACCUM_BLUE_SIZE)
	Gura_AssignValue(GLUT_WINDOW_ACCUM_BLUE_SIZE, Value(GLUT_WINDOW_ACCUM_BLUE_SIZE));
#endif
#if defined(GLUT_WINDOW_ACCUM_ALPHA_SIZE)
	Gura_AssignValue(GLUT_WINDOW_ACCUM_ALPHA_SIZE, Value(GLUT_WINDOW_ACCUM_ALPHA_SIZE));
#endif
#if defined(GLUT_WINDOW_DOUBLEBUFFER)
	Gura_AssignValue(GLUT_WINDOW_DOUBLEBUFFER, Value(GLUT_WINDOW_DOUBLEBUFFER));
#endif
#if defined(GLUT_WINDOW_RGBA)
	Gura_AssignValue(GLUT_WINDOW_RGBA, Value(GLUT_WINDOW_RGBA));
#endif
#if defined(GLUT_WINDOW_PARENT)
	Gura_AssignValue(GLUT_WINDOW_PARENT, Value(GLUT_WINDOW_PARENT));
#endif
#if defined(GLUT_WINDOW_NUM_CHILDREN)
	Gura_AssignValue(GLUT_WINDOW_NUM_CHILDREN, Value(GLUT_WINDOW_NUM_CHILDREN));
#endif
#if defined(GLUT_WINDOW_COLORMAP_SIZE)
	Gura_AssignValue(GLUT_WINDOW_COLORMAP_SIZE, Value(GLUT_WINDOW_COLORMAP_SIZE));
#endif
#if defined(GLUT_WINDOW_NUM_SAMPLES)
	Gura_AssignValue(GLUT_WINDOW_NUM_SAMPLES, Value(GLUT_WINDOW_NUM_SAMPLES));
#endif
#if defined(GLUT_WINDOW_STEREO)
	Gura_AssignValue(GLUT_WINDOW_STEREO, Value(GLUT_WINDOW_STEREO));
#endif
#if defined(GLUT_WINDOW_CURSOR)
	Gura_AssignValue(GLUT_WINDOW_CURSOR, Value(GLUT_WINDOW_CURSOR));
#endif
#if defined(GLUT_SCREEN_WIDTH)
	Gura_AssignValue(GLUT_SCREEN_WIDTH, Value(GLUT_SCREEN_WIDTH));
#endif
#if defined(GLUT_SCREEN_HEIGHT)
	Gura_AssignValue(GLUT_SCREEN_HEIGHT, Value(GLUT_SCREEN_HEIGHT));
#endif
#if defined(GLUT_SCREEN_WIDTH_MM)
	Gura_AssignValue(GLUT_SCREEN_WIDTH_MM, Value(GLUT_SCREEN_WIDTH_MM));
#endif
#if defined(GLUT_SCREEN_HEIGHT_MM)
	Gura_AssignValue(GLUT_SCREEN_HEIGHT_MM, Value(GLUT_SCREEN_HEIGHT_MM));
#endif
#if defined(GLUT_MENU_NUM_ITEMS)
	Gura_AssignValue(GLUT_MENU_NUM_ITEMS, Value(GLUT_MENU_NUM_ITEMS));
#endif
#if defined(GLUT_DISPLAY_MODE_POSSIBLE)
	Gura_AssignValue(GLUT_DISPLAY_MODE_POSSIBLE, Value(GLUT_DISPLAY_MODE_POSSIBLE));
#endif
#if defined(GLUT_INIT_WINDOW_X)
	Gura_AssignValue(GLUT_INIT_WINDOW_X, Value(GLUT_INIT_WINDOW_X));
#endif
#if defined(GLUT_INIT_WINDOW_Y)
	Gura_AssignValue(GLUT_INIT_WINDOW_Y, Value(GLUT_INIT_WINDOW_Y));
#endif
#if defined(GLUT_INIT_WINDOW_WIDTH)
	Gura_AssignValue(GLUT_INIT_WINDOW_WIDTH, Value(GLUT_INIT_WINDOW_WIDTH));
#endif
#if defined(GLUT_INIT_WINDOW_HEIGHT)
	Gura_AssignValue(GLUT_INIT_WINDOW_HEIGHT, Value(GLUT_INIT_WINDOW_HEIGHT));
#endif
#if defined(GLUT_INIT_DISPLAY_MODE)
	Gura_AssignValue(GLUT_INIT_DISPLAY_MODE, Value(GLUT_INIT_DISPLAY_MODE));
#endif
#if defined(GLUT_ELAPSED_TIME)
	Gura_AssignValue(GLUT_ELAPSED_TIME, Value(GLUT_ELAPSED_TIME));
#endif
#if defined(GLUT_WINDOW_FORMAT_ID)
	Gura_AssignValue(GLUT_WINDOW_FORMAT_ID, Value(GLUT_WINDOW_FORMAT_ID));
#endif
#if defined(GLUT_HAS_KEYBOARD)
	Gura_AssignValue(GLUT_HAS_KEYBOARD, Value(GLUT_HAS_KEYBOARD));
#endif
#if defined(GLUT_HAS_MOUSE)
	Gura_AssignValue(GLUT_HAS_MOUSE, Value(GLUT_HAS_MOUSE));
#endif
#if defined(GLUT_HAS_SPACEBALL)
	Gura_AssignValue(GLUT_HAS_SPACEBALL, Value(GLUT_HAS_SPACEBALL));
#endif
#if defined(GLUT_HAS_DIAL_AND_BUTTON_BOX)
	Gura_AssignValue(GLUT_HAS_DIAL_AND_BUTTON_BOX, Value(GLUT_HAS_DIAL_AND_BUTTON_BOX));
#endif
#if defined(GLUT_HAS_TABLET)
	Gura_AssignValue(GLUT_HAS_TABLET, Value(GLUT_HAS_TABLET));
#endif
#if defined(GLUT_NUM_MOUSE_BUTTONS)
	Gura_AssignValue(GLUT_NUM_MOUSE_BUTTONS, Value(GLUT_NUM_MOUSE_BUTTONS));
#endif
#if defined(GLUT_NUM_SPACEBALL_BUTTONS)
	Gura_AssignValue(GLUT_NUM_SPACEBALL_BUTTONS, Value(GLUT_NUM_SPACEBALL_BUTTONS));
#endif
#if defined(GLUT_NUM_BUTTON_BOX_BUTTONS)
	Gura_AssignValue(GLUT_NUM_BUTTON_BOX_BUTTONS, Value(GLUT_NUM_BUTTON_BOX_BUTTONS));
#endif
#if defined(GLUT_NUM_DIALS)
	Gura_AssignValue(GLUT_NUM_DIALS, Value(GLUT_NUM_DIALS));
#endif
#if defined(GLUT_NUM_TABLET_BUTTONS)
	Gura_AssignValue(GLUT_NUM_TABLET_BUTTONS, Value(GLUT_NUM_TABLET_BUTTONS));
#endif
#if defined(GLUT_DEVICE_IGNORE_KEY_REPEAT)
	Gura_AssignValue(GLUT_DEVICE_IGNORE_KEY_REPEAT, Value(GLUT_DEVICE_IGNORE_KEY_REPEAT));
#endif
#if defined(GLUT_DEVICE_KEY_REPEAT)
	Gura_AssignValue(GLUT_DEVICE_KEY_REPEAT, Value(GLUT_DEVICE_KEY_REPEAT));
#endif
#if defined(GLUT_HAS_JOYSTICK)
	Gura_AssignValue(GLUT_HAS_JOYSTICK, Value(GLUT_HAS_JOYSTICK));
#endif
#if defined(GLUT_OWNS_JOYSTICK)
	Gura_AssignValue(GLUT_OWNS_JOYSTICK, Value(GLUT_OWNS_JOYSTICK));
#endif
#if defined(GLUT_JOYSTICK_BUTTONS)
	Gura_AssignValue(GLUT_JOYSTICK_BUTTONS, Value(GLUT_JOYSTICK_BUTTONS));
#endif
#if defined(GLUT_JOYSTICK_AXES)
	Gura_AssignValue(GLUT_JOYSTICK_AXES, Value(GLUT_JOYSTICK_AXES));
#endif
#if defined(GLUT_JOYSTICK_POLL_RATE)
	Gura_AssignValue(GLUT_JOYSTICK_POLL_RATE, Value(GLUT_JOYSTICK_POLL_RATE));
#endif
#if defined(GLUT_OVERLAY_POSSIBLE)
	Gura_AssignValue(GLUT_OVERLAY_POSSIBLE, Value(GLUT_OVERLAY_POSSIBLE));
#endif
#if defined(GLUT_LAYER_IN_USE)
	Gura_AssignValue(GLUT_LAYER_IN_USE, Value(GLUT_LAYER_IN_USE));
#endif
#if defined(GLUT_HAS_OVERLAY)
	Gura_AssignValue(GLUT_HAS_OVERLAY, Value(GLUT_HAS_OVERLAY));
#endif
#if defined(GLUT_TRANSPARENT_INDEX)
	Gura_AssignValue(GLUT_TRANSPARENT_INDEX, Value(GLUT_TRANSPARENT_INDEX));
#endif
#if defined(GLUT_NORMAL_DAMAGED)
	Gura_AssignValue(GLUT_NORMAL_DAMAGED, Value(GLUT_NORMAL_DAMAGED));
#endif
#if defined(GLUT_OVERLAY_DAMAGED)
	Gura_AssignValue(GLUT_OVERLAY_DAMAGED, Value(GLUT_OVERLAY_DAMAGED));
#endif
#if defined(GLUT_VIDEO_RESIZE_POSSIBLE)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_POSSIBLE, Value(GLUT_VIDEO_RESIZE_POSSIBLE));
#endif
#if defined(GLUT_VIDEO_RESIZE_IN_USE)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_IN_USE, Value(GLUT_VIDEO_RESIZE_IN_USE));
#endif
#if defined(GLUT_VIDEO_RESIZE_X_DELTA)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_X_DELTA, Value(GLUT_VIDEO_RESIZE_X_DELTA));
#endif
#if defined(GLUT_VIDEO_RESIZE_Y_DELTA)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_Y_DELTA, Value(GLUT_VIDEO_RESIZE_Y_DELTA));
#endif
#if defined(GLUT_VIDEO_RESIZE_WIDTH_DELTA)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_WIDTH_DELTA, Value(GLUT_VIDEO_RESIZE_WIDTH_DELTA));
#endif
#if defined(GLUT_VIDEO_RESIZE_HEIGHT_DELTA)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_HEIGHT_DELTA, Value(GLUT_VIDEO_RESIZE_HEIGHT_DELTA));
#endif
#if defined(GLUT_VIDEO_RESIZE_X)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_X, Value(GLUT_VIDEO_RESIZE_X));
#endif
#if defined(GLUT_VIDEO_RESIZE_Y)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_Y, Value(GLUT_VIDEO_RESIZE_Y));
#endif
#if defined(GLUT_VIDEO_RESIZE_WIDTH)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_WIDTH, Value(GLUT_VIDEO_RESIZE_WIDTH));
#endif
#if defined(GLUT_VIDEO_RESIZE_HEIGHT)
	Gura_AssignValue(GLUT_VIDEO_RESIZE_HEIGHT, Value(GLUT_VIDEO_RESIZE_HEIGHT));
#endif
#if defined(GLUT_NORMAL)
	Gura_AssignValue(GLUT_NORMAL, Value(GLUT_NORMAL));
#endif
#if defined(GLUT_OVERLAY)
	Gura_AssignValue(GLUT_OVERLAY, Value(GLUT_OVERLAY));
#endif
#if defined(GLUT_ACTIVE_SHIFT)
	Gura_AssignValue(GLUT_ACTIVE_SHIFT, Value(GLUT_ACTIVE_SHIFT));
#endif
#if defined(GLUT_ACTIVE_CTRL)
	Gura_AssignValue(GLUT_ACTIVE_CTRL, Value(GLUT_ACTIVE_CTRL));
#endif
#if defined(GLUT_ACTIVE_ALT)
	Gura_AssignValue(GLUT_ACTIVE_ALT, Value(GLUT_ACTIVE_ALT));
#endif
#if defined(GLUT_CURSOR_RIGHT_ARROW)
	Gura_AssignValue(GLUT_CURSOR_RIGHT_ARROW, Value(GLUT_CURSOR_RIGHT_ARROW));
#endif
#if defined(GLUT_CURSOR_LEFT_ARROW)
	Gura_AssignValue(GLUT_CURSOR_LEFT_ARROW, Value(GLUT_CURSOR_LEFT_ARROW));
#endif
#if defined(GLUT_CURSOR_INFO)
	Gura_AssignValue(GLUT_CURSOR_INFO, Value(GLUT_CURSOR_INFO));
#endif
#if defined(GLUT_CURSOR_DESTROY)
	Gura_AssignValue(GLUT_CURSOR_DESTROY, Value(GLUT_CURSOR_DESTROY));
#endif
#if defined(GLUT_CURSOR_HELP)
	Gura_AssignValue(GLUT_CURSOR_HELP, Value(GLUT_CURSOR_HELP));
#endif
#if defined(GLUT_CURSOR_CYCLE)
	Gura_AssignValue(GLUT_CURSOR_CYCLE, Value(GLUT_CURSOR_CYCLE));
#endif
#if defined(GLUT_CURSOR_SPRAY)
	Gura_AssignValue(GLUT_CURSOR_SPRAY, Value(GLUT_CURSOR_SPRAY));
#endif
#if defined(GLUT_CURSOR_WAIT)
	Gura_AssignValue(GLUT_CURSOR_WAIT, Value(GLUT_CURSOR_WAIT));
#endif
#if defined(GLUT_CURSOR_TEXT)
	Gura_AssignValue(GLUT_CURSOR_TEXT, Value(GLUT_CURSOR_TEXT));
#endif
#if defined(GLUT_CURSOR_CROSSHAIR)
	Gura_AssignValue(GLUT_CURSOR_CROSSHAIR, Value(GLUT_CURSOR_CROSSHAIR));
#endif
#if defined(GLUT_CURSOR_UP_DOWN)
	Gura_AssignValue(GLUT_CURSOR_UP_DOWN, Value(GLUT_CURSOR_UP_DOWN));
#endif
#if defined(GLUT_CURSOR_LEFT_RIGHT)
	Gura_AssignValue(GLUT_CURSOR_LEFT_RIGHT, Value(GLUT_CURSOR_LEFT_RIGHT));
#endif
#if defined(GLUT_CURSOR_TOP_SIDE)
	Gura_AssignValue(GLUT_CURSOR_TOP_SIDE, Value(GLUT_CURSOR_TOP_SIDE));
#endif
#if defined(GLUT_CURSOR_BOTTOM_SIDE)
	Gura_AssignValue(GLUT_CURSOR_BOTTOM_SIDE, Value(GLUT_CURSOR_BOTTOM_SIDE));
#endif
#if defined(GLUT_CURSOR_LEFT_SIDE)
	Gura_AssignValue(GLUT_CURSOR_LEFT_SIDE, Value(GLUT_CURSOR_LEFT_SIDE));
#endif
#if defined(GLUT_CURSOR_RIGHT_SIDE)
	Gura_AssignValue(GLUT_CURSOR_RIGHT_SIDE, Value(GLUT_CURSOR_RIGHT_SIDE));
#endif
#if defined(GLUT_CURSOR_TOP_LEFT_CORNER)
	Gura_AssignValue(GLUT_CURSOR_TOP_LEFT_CORNER, Value(GLUT_CURSOR_TOP_LEFT_CORNER));
#endif
#if defined(GLUT_CURSOR_TOP_RIGHT_CORNER)
	Gura_AssignValue(GLUT_CURSOR_TOP_RIGHT_CORNER, Value(GLUT_CURSOR_TOP_RIGHT_CORNER));
#endif
#if defined(GLUT_CURSOR_BOTTOM_RIGHT_CORNER)
	Gura_AssignValue(GLUT_CURSOR_BOTTOM_RIGHT_CORNER, Value(GLUT_CURSOR_BOTTOM_RIGHT_CORNER));
#endif
#if defined(GLUT_CURSOR_BOTTOM_LEFT_CORNER)
	Gura_AssignValue(GLUT_CURSOR_BOTTOM_LEFT_CORNER, Value(GLUT_CURSOR_BOTTOM_LEFT_CORNER));
#endif
#if defined(GLUT_CURSOR_INHERIT)
	Gura_AssignValue(GLUT_CURSOR_INHERIT, Value(GLUT_CURSOR_INHERIT));
#endif
#if defined(GLUT_CURSOR_NONE)
	Gura_AssignValue(GLUT_CURSOR_NONE, Value(GLUT_CURSOR_NONE));
#endif
#if defined(GLUT_CURSOR_FULL_CROSSHAIR)
	Gura_AssignValue(GLUT_CURSOR_FULL_CROSSHAIR, Value(GLUT_CURSOR_FULL_CROSSHAIR));
#endif
#if defined(GLUT_KEY_REPEAT_OFF)
	Gura_AssignValue(GLUT_KEY_REPEAT_OFF, Value(GLUT_KEY_REPEAT_OFF));
#endif
#if defined(GLUT_KEY_REPEAT_ON)
	Gura_AssignValue(GLUT_KEY_REPEAT_ON, Value(GLUT_KEY_REPEAT_ON));
#endif
#if defined(GLUT_KEY_REPEAT_DEFAULT)
	Gura_AssignValue(GLUT_KEY_REPEAT_DEFAULT, Value(GLUT_KEY_REPEAT_DEFAULT));
#endif
#if defined(GLUT_JOYSTICK_BUTTON_A)
	Gura_AssignValue(GLUT_JOYSTICK_BUTTON_A, Value(GLUT_JOYSTICK_BUTTON_A));
#endif
#if defined(GLUT_JOYSTICK_BUTTON_B)
	Gura_AssignValue(GLUT_JOYSTICK_BUTTON_B, Value(GLUT_JOYSTICK_BUTTON_B));
#endif
#if defined(GLUT_JOYSTICK_BUTTON_C)
	Gura_AssignValue(GLUT_JOYSTICK_BUTTON_C, Value(GLUT_JOYSTICK_BUTTON_C));
#endif
#if defined(GLUT_JOYSTICK_BUTTON_D)
	Gura_AssignValue(GLUT_JOYSTICK_BUTTON_D, Value(GLUT_JOYSTICK_BUTTON_D));
#endif
#if defined(GLUT_GAME_MODE_ACTIVE)
	Gura_AssignValue(GLUT_GAME_MODE_ACTIVE, Value(GLUT_GAME_MODE_ACTIVE));
#endif
#if defined(GLUT_GAME_MODE_POSSIBLE)
	Gura_AssignValue(GLUT_GAME_MODE_POSSIBLE, Value(GLUT_GAME_MODE_POSSIBLE));
#endif
#if defined(GLUT_GAME_MODE_WIDTH)
	Gura_AssignValue(GLUT_GAME_MODE_WIDTH, Value(GLUT_GAME_MODE_WIDTH));
#endif
#if defined(GLUT_GAME_MODE_HEIGHT)
	Gura_AssignValue(GLUT_GAME_MODE_HEIGHT, Value(GLUT_GAME_MODE_HEIGHT));
#endif
#if defined(GLUT_GAME_MODE_PIXEL_DEPTH)
	Gura_AssignValue(GLUT_GAME_MODE_PIXEL_DEPTH, Value(GLUT_GAME_MODE_PIXEL_DEPTH));
#endif
#if defined(GLUT_GAME_MODE_REFRESH_RATE)
	Gura_AssignValue(GLUT_GAME_MODE_REFRESH_RATE, Value(GLUT_GAME_MODE_REFRESH_RATE));
#endif
#if defined(GLUT_GAME_MODE_DISPLAY_CHANGED)
	Gura_AssignValue(GLUT_GAME_MODE_DISPLAY_CHANGED, Value(GLUT_GAME_MODE_DISPLAY_CHANGED));
#endif
}

Gura_EndModuleScope(glut)
