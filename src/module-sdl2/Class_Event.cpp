#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

const char *GetEventTypeName(Uint32 type);
const char *GetWindowEventName(Uint8 event);

//-----------------------------------------------------------------------------
// Object_Event implementation
//-----------------------------------------------------------------------------
Object_Event::~Object_Event()
{
}

Object *Object_Event::Clone() const
{
	return NULL;
}

String Object_Event::ToString(bool exprFlag)
{
	String str;
	str += "<sdl.Event:";
	str += GetEventTypeName(_event.type);
	char buff[256];
	if (_event.type == SDL_QUIT) {
		const SDL_QuitEvent &event = _event.quit;
		::sprintf(buff, "(timestamp=%d)",
				  event.timestamp);
		str += buff;
	} else if (_event.type == SDL_APP_TERMINATING) {
		// nothing to do
	} else if (_event.type == SDL_APP_LOWMEMORY) {
		// nothing to do
	} else if (_event.type == SDL_APP_WILLENTERBACKGROUND) {
		// nothing to do
	} else if (_event.type == SDL_APP_DIDENTERBACKGROUND) {
		// nothing to do
	} else if (_event.type == SDL_APP_WILLENTERFOREGROUND) {
		// nothing to do
	} else if (_event.type == SDL_APP_DIDENTERFOREGROUND) {
		// nothing to do
	} else if (_event.type == SDL_WINDOWEVENT) {
		const SDL_WindowEvent &event = _event.window;
		if (event.event == SDL_WINDOWEVENT_MOVED) {
			::sprintf(buff, "(timestamp=%d, windowID=%d, event=%s, x=%d, y=%d)",
					  event.timestamp, event.windowID,
					  GetWindowEventName(event.event), event.data1, event.data2);
		} else if (event.event == SDL_WINDOWEVENT_RESIZED) {
			::sprintf(buff, "(timestamp=%d, windowID=%d, event=%s, w=%d, h=%d)",
					  event.timestamp, event.windowID,
					  GetWindowEventName(event.event), event.data1, event.data2);
		} else if (event.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			::sprintf(buff, "(timestamp=%d, windowID=%d, event=%s, w=%d, h=%d)",
					  event.timestamp, event.windowID,
					  GetWindowEventName(event.event), event.data1, event.data2);
		} else {
			::sprintf(buff, "(timestamp=%d, windowID=%d, event=%s, data1=%d, data2=%d)",
					  event.timestamp, event.windowID,
					  GetWindowEventName(event.event), event.data1, event.data2);
		}
		str += buff;
	} else if (_event.type == SDL_SYSWMEVENT) {
		const SDL_SysWMEvent &event = _event.syswm;
		::sprintf(buff, "(timestamp=%d)",
				  event.timestamp);
		str += buff;
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		const SDL_KeyboardEvent &event = _event.key;
		::sprintf(buff, "(timestamp=%d, windowID=%d, state=%d, repeat=%d, scancode=%d, sym=%d, mod=0x%04x)",
				  event.timestamp, event.windowID,
				  event.state, event.repeat,
				  event.keysym.scancode, event.keysym.sym, event.keysym.mod);
		str += buff;
	} else if (_event.type == SDL_TEXTEDITING) {
		const SDL_TextEditingEvent &event = _event.edit;
		::sprintf(buff, "(timestamp=%d, windowID=%d, text=\"%s\", start=%d, length=%d)",
				  event.timestamp, event.windowID,
				  event.text, event.start, event.length);
	} else if (_event.type == SDL_TEXTINPUT) {
		const SDL_TextInputEvent &event = _event.text;
		::sprintf(buff, "(timestamp=%d, windowID=%d, text=\"%s\")",
				  event.timestamp, event.windowID, event.text);
	} else if (_event.type == SDL_MOUSEMOTION) {
		const SDL_MouseMotionEvent &event = _event.motion;
		::sprintf(buff, "(timestamp=%d, windowID=%d, which=%d, state=%d, x=%d, y=%d, xrel=%d, yrel=%d)",
				  event.timestamp, event.windowID, event.which,
				  event.state, event.x, event.y, event.xrel, event.yrel);
		str += buff;
	} else if (_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) {
		const SDL_MouseButtonEvent &event = _event.button;
		::sprintf(buff, "(timestamp=%d, windowID=%d, which=%d, button=%d, state=%d, clicks=%d, x=%d, y=%d)",
				  event.timestamp, event.windowID, event.which,
				  event.button, event.state, event.clicks, event.x, event.y);
		str += buff;
	} else if (_event.type == SDL_MOUSEWHEEL) {
		const SDL_MouseWheelEvent &event = _event.wheel;
		::sprintf(buff, "(timestamp=%d, windowID=%d, which=%d, x=%d, y=%d",
				  event.timestamp, event.windowID, event.which,
				  event.x, event.y);
		str += buff;
	} else if (_event.type == SDL_JOYAXISMOTION) {
		const SDL_JoyAxisEvent &event = _event.jaxis;
		::sprintf(buff, "(timestamp=%d, which=%d, axis=%d, value=%d)",
				  event.timestamp, event.which, event.axis, event.value);
		str += buff;
	} else if (_event.type == SDL_JOYBALLMOTION) {
		const SDL_JoyBallEvent &event = _event.jball;
		::sprintf(buff, "(timestamp=%d, which=%d, ball=%d, xrel=%d, yrel=%d)",
				  event.timestamp, event.which, event.ball, event.xrel, event.yrel);
		str += buff;
	} else if (_event.type == SDL_JOYHATMOTION) {
		const SDL_JoyHatEvent &event = _event.jhat;
		::sprintf(buff, "(timestamp=%d, which=%d, hat=%d, value=%d)",
				  event.timestamp, event.which, event.hat, event.value);
		str += buff;
	} else if (_event.type == SDL_JOYBUTTONDOWN ||
			   _event.type == SDL_JOYBUTTONUP) {
		const SDL_JoyButtonEvent &event = _event.jbutton;
		::sprintf(buff, "(timestamp=%d, which=%d, button=%d, state=%d)",
				  event.timestamp, event.which, event.button, event.state);
		str += buff;
	} else if (_event.type == SDL_JOYDEVICEADDED ||
			   _event.type == SDL_JOYDEVICEREMOVED) {
		const SDL_JoyDeviceEvent &event = _event.jdevice;
		::sprintf(buff, "(timestamp=%d, which=%d)",
				  event.timestamp, event.which);
		str += buff;
	} else if (_event.type == SDL_CONTROLLERAXISMOTION) {
		const SDL_ControllerAxisEvent &event = _event.caxis;
		::sprintf(buff, "(timestamp=%d, which=%d, axis=%d, value=%d)",
				  event.timestamp, event.which, event.axis, event.value);
		str += buff;
	} else if (_event.type == SDL_CONTROLLERBUTTONDOWN ||
			   _event.type == SDL_CONTROLLERBUTTONUP) {
		const SDL_ControllerButtonEvent &event = _event.cbutton;
		::sprintf(buff, "(timestamp=%d, which=%d, button=%d, state=%d)",
				  event.timestamp, event.which, event.button, event.state);
		str += buff;
	} else if (_event.type == SDL_CONTROLLERDEVICEADDED ||
			   _event.type == SDL_CONTROLLERDEVICEREMOVED ||
			   _event.type == SDL_CONTROLLERDEVICEREMAPPED) {
		const SDL_ControllerDeviceEvent &event = _event.cdevice;
		::sprintf(buff, "(timestamp=%d, which=%d)",
				  event.timestamp, event.which);
		str += buff;
	} else if (_event.type == SDL_FINGERDOWN ||
			   _event.type == SDL_FINGERUP ||
			   _event.type == SDL_FINGERMOTION) {
		const SDL_TouchFingerEvent &event = _event.tfinger;
		::sprintf(buff, "(timestamp=%d, fingerId=%lld, x=%f, y=%f, dx=%f, dy=%f, pressure=%f)",
				  event.timestamp, event.fingerId,
				  event.x, event.y, event.dx, event.dy, event.pressure);
		str += buff;
	} else if (_event.type == SDL_DOLLARGESTURE || _event.type == SDL_DOLLARRECORD) {
		const SDL_DollarGestureEvent &event = _event.dgesture;
		::sprintf(buff, "(timestamp=%d, touchId=%lld, gestureId=%lld, numFingers=%d, error=%f, x=%f, y=%f)",
				  event.timestamp, event.touchId, event.gestureId,
				  event.numFingers, event.error, event.x, event.y);
		str += buff;
	} else if (_event.type == SDL_MULTIGESTURE) {
		const SDL_MultiGestureEvent &event = _event.mgesture;
		::sprintf(buff, "(timestamp=%d, touchId=%lld, dTheta=%f, dDist=%f, x=%f, y=%f, numFingers=%d)",
				  event.timestamp, event.touchId,
				  event.dTheta, event.dDist, event.x, event.y, event.numFingers);
		str += buff;
	} else if (_event.type == SDL_CLIPBOARDUPDATE) {
		// nothing to do
	} else if (_event.type == SDL_DROPFILE) {
		const SDL_DropEvent &event = _event.drop;
		::sprintf(buff, "(timestamp=%d, file=\"%s\")",
				  event.timestamp, event.file);
	} else if (_event.type == SDL_RENDER_TARGETS_RESET) {
		// nothing to do
	} else if (_event.type == SDL_USEREVENT) {
		const SDL_UserEvent &event = _event.user;
		::sprintf(buff, "(timestamp=%d, windowID=%d, code=%d, data1=0x%p, data2=0x%p)",
				  event.timestamp, event.windowID,
				  event.code, event.data1, event.data2);
		str += buff;
	}
	str += ">";
	return str;
}

bool Object_Event::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	if (_event.type == SDL_QUIT) {
		symbols.insert(Gura_UserSymbol(timestamp));
	} else if (_event.type == SDL_APP_TERMINATING) {

	} else if (_event.type == SDL_APP_LOWMEMORY) {

	} else if (_event.type == SDL_APP_WILLENTERBACKGROUND) {

	} else if (_event.type == SDL_APP_DIDENTERBACKGROUND) {

	} else if (_event.type == SDL_APP_WILLENTERFOREGROUND) {

	} else if (_event.type == SDL_APP_DIDENTERFOREGROUND) {

	} else if (_event.type == SDL_WINDOWEVENT) {
		const SDL_WindowEvent &event = _event.window;
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(event));
		symbols.insert(Gura_UserSymbol(data1));
		symbols.insert(Gura_UserSymbol(data2));
		if (event.event == SDL_WINDOWEVENT_MOVED) {
			symbols.insert(Gura_UserSymbol(x));
			symbols.insert(Gura_UserSymbol(y));
		} else if (event.event == SDL_WINDOWEVENT_RESIZED) {
			symbols.insert(Gura_UserSymbol(w));
			symbols.insert(Gura_UserSymbol(h));
		} else if (event.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			symbols.insert(Gura_UserSymbol(w));
			symbols.insert(Gura_UserSymbol(h));
		}
	} else if (_event.type == SDL_SYSWMEVENT) {
		symbols.insert(Gura_UserSymbol(timestamp));
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(repeat));
		symbols.insert(Gura_UserSymbol(scancode));
		symbols.insert(Gura_UserSymbol(sym));
		symbols.insert(Gura_UserSymbol(mod));
	} else if (_event.type == SDL_TEXTEDITING) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(text));
		symbols.insert(Gura_UserSymbol(start));
		symbols.insert(Gura_UserSymbol(length));
	} else if (_event.type == SDL_TEXTINPUT) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(text));
	} else if (_event.type == SDL_MOUSEMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
		symbols.insert(Gura_UserSymbol(xrel));
		symbols.insert(Gura_UserSymbol(yrel));
	} else if (_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(button));
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(clicks));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
	} else if (_event.type == SDL_MOUSEWHEEL) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
	} else if (_event.type == SDL_JOYAXISMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(axis));
		symbols.insert(Gura_UserSymbol(value));
	} else if (_event.type == SDL_JOYBALLMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(ball));
		symbols.insert(Gura_UserSymbol(xrel));
		symbols.insert(Gura_UserSymbol(yrel));
	} else if (_event.type == SDL_JOYHATMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(hat));
		symbols.insert(Gura_UserSymbol(value));
	} else if (_event.type == SDL_JOYBUTTONDOWN ||
			   _event.type == SDL_JOYBUTTONUP) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(button));
		symbols.insert(Gura_UserSymbol(state));
	} else if (_event.type == SDL_JOYDEVICEADDED ||
			   _event.type == SDL_JOYDEVICEREMOVED) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
	} else if (_event.type == SDL_CONTROLLERAXISMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(axis));
		symbols.insert(Gura_UserSymbol(value));
	} else if (_event.type == SDL_CONTROLLERBUTTONDOWN ||
			   _event.type == SDL_CONTROLLERBUTTONUP) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(button));
		symbols.insert(Gura_UserSymbol(state));
	} else if (_event.type == SDL_CONTROLLERDEVICEADDED ||
			   _event.type == SDL_CONTROLLERDEVICEREMOVED ||
			   _event.type == SDL_CONTROLLERDEVICEREMAPPED) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(which));
	} else if (_event.type == SDL_FINGERDOWN ||
			   _event.type == SDL_FINGERUP ||
			   _event.type == SDL_FINGERMOTION) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(fingerId));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
		symbols.insert(Gura_UserSymbol(dx));
		symbols.insert(Gura_UserSymbol(dy));
		symbols.insert(Gura_UserSymbol(pressure));
	} else if (_event.type == SDL_DOLLARGESTURE || _event.type == SDL_DOLLARRECORD) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(touchId));
		symbols.insert(Gura_UserSymbol(gestureId));
		symbols.insert(Gura_UserSymbol(numFingers));
		symbols.insert(Gura_UserSymbol(error));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
	} else if (_event.type == SDL_MULTIGESTURE) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(touchId));
		symbols.insert(Gura_UserSymbol(dTheta));
		symbols.insert(Gura_UserSymbol(dDist));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
		symbols.insert(Gura_UserSymbol(numFingers));
	} else if (_event.type == SDL_CLIPBOARDUPDATE) {

	} else if (_event.type == SDL_DROPFILE) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(file));
	} else if (_event.type == SDL_RENDER_TARGETS_RESET) {

	} else if (_event.type == SDL_USEREVENT) {
		symbols.insert(Gura_UserSymbol(timestamp));
		symbols.insert(Gura_UserSymbol(windowID));
		symbols.insert(Gura_UserSymbol(code));
		symbols.insert(Gura_UserSymbol(data1));
		symbols.insert(Gura_UserSymbol(data2));
	}
	return true;
}

Value Object_Event::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(_event.type);
	}
	if (_event.type == SDL_QUIT) {
		const SDL_QuitEvent &event = _event.quit;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		}
	} else if (_event.type == SDL_APP_TERMINATING) {

	} else if (_event.type == SDL_APP_LOWMEMORY) {

	} else if (_event.type == SDL_APP_WILLENTERBACKGROUND) {

	} else if (_event.type == SDL_APP_DIDENTERBACKGROUND) {

	} else if (_event.type == SDL_APP_WILLENTERFOREGROUND) {

	} else if (_event.type == SDL_APP_DIDENTERFOREGROUND) {

	} else if (_event.type == SDL_WINDOWEVENT) {
		const SDL_WindowEvent &event = _event.window;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(event))) {
			return Value(event.event);
		}
		if (event.event == SDL_WINDOWEVENT_MOVED) {
			if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
				return Value(event.data1);
			} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
				return Value(event.data2);
			}
		} else if (event.event == SDL_WINDOWEVENT_RESIZED) {
			if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
				return Value(event.data1);
			} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
				return Value(event.data2);
			}
		} else if (event.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
				return Value(event.data1);
			} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
				return Value(event.data2);
			}
		}
		if (pSymbol->IsIdentical(Gura_UserSymbol(data1))) {
			return Value(event.data1);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(data2))) {
			return Value(event.data2);
		}
	} else if (_event.type == SDL_SYSWMEVENT) {
		const SDL_SysWMEvent &event = _event.syswm;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		}
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		const SDL_KeyboardEvent &event = _event.key;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(repeat))) {
			return Value(event.repeat);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(scancode))) {
			return Value(event.keysym.scancode);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(sym))) {
			return Value(static_cast<int>(event.keysym.sym));
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(mod))) {
			return Value(static_cast<int>(event.keysym.mod));
		}
	} else if (_event.type == SDL_TEXTEDITING) {
		const SDL_TextEditingEvent &event = _event.edit;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(text))) {
			return Value(event.text);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(start))) {
			return Value(event.start);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(length))) {
			return Value(event.length);
		}
	} else if (_event.type == SDL_TEXTINPUT) {
		const SDL_TextInputEvent &event = _event.text;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(text))) {
			return Value(event.text);
		}
	} else if (_event.type == SDL_MOUSEMOTION) {
		const SDL_MouseMotionEvent &event = _event.motion;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(xrel))) {
			return Value(event.xrel);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(yrel))) {
			return Value(event.yrel);
		}
	} else if (_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) {
		const SDL_MouseButtonEvent &event = _event.button;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(button))) {
			return Value(event.button);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(clicks))) {
			return Value(event.clicks);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		}
	} else if (_event.type == SDL_MOUSEWHEEL) {
		const SDL_MouseWheelEvent &event = _event.wheel;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		}
	} else if (_event.type == SDL_JOYAXISMOTION) {
		const SDL_JoyAxisEvent &event = _event.jaxis;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(axis))) {
			return Value(event.axis);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
			return Value(event.value);
		}
	} else if (_event.type == SDL_JOYBALLMOTION) {
		const SDL_JoyBallEvent &event = _event.jball;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(ball))) {
			return Value(event.ball);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(xrel))) {
			return Value(event.xrel);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(yrel))) {
			return Value(event.yrel);
		}
	} else if (_event.type == SDL_JOYHATMOTION) {
		const SDL_JoyHatEvent &event = _event.jhat;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(hat))) {
			return Value(event.hat);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
			return Value(event.value);
		}
	} else if (_event.type == SDL_JOYBUTTONDOWN ||
			   _event.type == SDL_JOYBUTTONUP) {
		const SDL_JoyButtonEvent &event = _event.jbutton;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(button))) {
			return Value(event.button);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		}
	} else if (_event.type == SDL_JOYDEVICEADDED ||
			   _event.type == SDL_JOYDEVICEREMOVED) {
		const SDL_JoyDeviceEvent &event = _event.jdevice;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		}
	} else if (_event.type == SDL_CONTROLLERAXISMOTION) {
		const SDL_ControllerAxisEvent &event = _event.caxis;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(axis))) {
			return Value(event.axis);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
			return Value(event.value);
		}
	} else if (_event.type == SDL_CONTROLLERBUTTONDOWN ||
			   _event.type == SDL_CONTROLLERBUTTONUP) {
		const SDL_ControllerButtonEvent &event = _event.cbutton;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(button))) {
			return Value(event.button);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		}
	} else if (_event.type == SDL_CONTROLLERDEVICEADDED ||
			   _event.type == SDL_CONTROLLERDEVICEREMOVED ||
			   _event.type == SDL_CONTROLLERDEVICEREMAPPED) {
		const SDL_ControllerDeviceEvent &event = _event.cdevice;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		}
	} else if (_event.type == SDL_FINGERDOWN ||
			   _event.type == SDL_FINGERUP ||
			   _event.type == SDL_FINGERMOTION) {
		const SDL_TouchFingerEvent &event = _event.tfinger;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(touchId))) {
			return Value(event.touchId);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(fingerId))) {
			return Value(event.fingerId);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(dx))) {
			return Value(event.dx);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(dy))) {
			return Value(event.dy);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(pressure))) {
			return Value(event.pressure);
		}
	} else if (_event.type == SDL_DOLLARGESTURE || _event.type == SDL_DOLLARRECORD) {
		const SDL_DollarGestureEvent &event = _event.dgesture;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(touchId))) {
			return Value(event.touchId);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(gestureId))) {
			return Value(event.gestureId);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(numFingers))) {
			return Value(event.numFingers);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(error))) {
			return Value(event.error);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		}
	} else if (_event.type == SDL_MULTIGESTURE) {
		const SDL_MultiGestureEvent &event = _event.mgesture;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(touchId))) {
			return Value(event.touchId);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(dTheta))) {
			return Value(event.dTheta);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(dDist))) {
			return Value(event.dDist);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(numFingers))) {
			return Value(event.numFingers);
		}
	} else if (_event.type == SDL_CLIPBOARDUPDATE) {

	} else if (_event.type == SDL_DROPFILE) {
		const SDL_DropEvent &event = _event.drop;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(file))) {
			return Value(event.file);
		}
	} else if (_event.type == SDL_RENDER_TARGETS_RESET) {

	} else if (_event.type == SDL_USEREVENT) {
		const SDL_UserEvent &event = _event.user;
		if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
			return Value(event.timestamp);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(windowID))) {
			return Value(event.windowID);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(code))) {
			return Value(event.code);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(data1))) {
			return Value(event.data1);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(data2))) {
			return Value(event.data2);
		}
	}
	evaluatedFlag = false;
	return Value::Null;
}

const char *GetEventTypeName(Uint32 type)
{
	static const struct {
		Uint32 type;
		const char *name;
	} tbl[] = {
		{ SDL_WINDOWEVENT,				"WindowEvent",				},
		{ SDL_KEYDOWN,					"KeyDown",					},
		{ SDL_KEYUP,					"KeyUp",					},
		{ SDL_TEXTEDITING,				"TextEditing",				},
		{ SDL_TEXTINPUT,				"TextInput",				},
		{ SDL_MOUSEMOTION,				"MouseMotion",				},
		{ SDL_MOUSEBUTTONDOWN,			"MouseButtonDown",			},
		{ SDL_MOUSEBUTTONUP,			"MouseButtonUp",			},
		{ SDL_MOUSEWHEEL,				"MouseWheel",				},
		{ SDL_JOYAXISMOTION,			"JoyAxisMotion",			},
		{ SDL_JOYBALLMOTION,			"JoyBallMotion",			},
		{ SDL_JOYHATMOTION,				"JoyHatMotion",				},
		{ SDL_JOYBUTTONDOWN,			"JoyButtonDown",			},
		{ SDL_JOYBUTTONUP,				"JoyButtonUp",				},
		{ SDL_JOYDEVICEADDED,			"JoyDeviceAdded",			},
		{ SDL_JOYDEVICEREMOVED,			"JoyDeviceRemoved",			},
		{ SDL_CONTROLLERAXISMOTION,		"ControllerAxisMotion",		},
		{ SDL_CONTROLLERBUTTONDOWN,		"ControllerButtonDown",		},
		{ SDL_CONTROLLERBUTTONUP,		"ControllerButtonUp",		},
		{ SDL_CONTROLLERDEVICEADDED,	"ControllerDeviceAdded",	},
		{ SDL_CONTROLLERDEVICEREMOVED,	"ControllerDeviceRemoved",	},
		{ SDL_CONTROLLERDEVICEREMAPPED,	"ControllerDeviceRemapped",	},
		{ SDL_QUIT,						"Quit",						},
		{ SDL_USEREVENT,				"UserEvent",				},
		{ SDL_SYSWMEVENT,				"SysWMEvent",				},
		{ SDL_FINGERMOTION,				"FingerMotion",				},
		{ SDL_FINGERDOWN,				"FingerDown",				},
		{ SDL_FINGERUP,					"FingerUp",					},
		{ SDL_MULTIGESTURE,				"MultiGesture",				},
		{ SDL_DOLLARGESTURE,			"DollarGesture",			},
		{ SDL_DROPFILE,					"DropFile",					},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].type == type) return tbl[i].name;
	}
	return "(unknown)";
}

const char *GetWindowEventName(Uint8 event)
{
	static const struct {
		Uint8 event;
		const char *name;
	} tbl[] = {
		{ SDL_WINDOWEVENT_NONE,			"NONE",			},
		{ SDL_WINDOWEVENT_SHOWN,		"SHOWN",		},
		{ SDL_WINDOWEVENT_HIDDEN,		"HIDDEN",		},
		{ SDL_WINDOWEVENT_EXPOSED,		"EXPOSED",		},
		{ SDL_WINDOWEVENT_MOVED,		"MOVED",		},
		{ SDL_WINDOWEVENT_RESIZED,		"RESIZED",		},
		{ SDL_WINDOWEVENT_SIZE_CHANGED,	"SIZE_CHANGED",	},
		{ SDL_WINDOWEVENT_MINIMIZED,	"MINIMIZED",	},
		{ SDL_WINDOWEVENT_MAXIMIZED,	"MAXIMIZED",	},
		{ SDL_WINDOWEVENT_RESTORED,		"RESTORED",		},
		{ SDL_WINDOWEVENT_ENTER,		"ENTER",		},
		{ SDL_WINDOWEVENT_LEAVE,		"LEAVE",		},
		{ SDL_WINDOWEVENT_FOCUS_GAINED,	"FOCUS_GAINED",	},
		{ SDL_WINDOWEVENT_FOCUS_LOST,	"FOCUS_LOST",	},
		{ SDL_WINDOWEVENT_CLOSE,		"CLOSE",		},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].event == event) return tbl[i].name;
	}
	return "(unknown)";
}

//-----------------------------------------------------------------------------
// Gura interfaces for Event
//-----------------------------------------------------------------------------
// implementation of class Event
Gura_ImplementUserClass(Event)
{
	Gura_AssignValue(Event, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
