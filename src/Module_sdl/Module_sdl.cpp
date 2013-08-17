//-----------------------------------------------------------------------------
// Gura sdl module
//-----------------------------------------------------------------------------
#include "Module_sdl.h"

Gura_BeginModule(sdl)

//-----------------------------------------------------------------------------
// Object_Cursor implementation
//-----------------------------------------------------------------------------
Object_Cursor::~Object_Cursor()
{
	//::SDL_FreeCursor(_pCursor);
}

Object *Object_Cursor::Clone() const
{
	return NULL;
}

void Object_Cursor::FreeCursor()
{
	if (_pCursor != NULL) ::SDL_FreeCursor(_pCursor);
	_pCursor = NULL;
}

String Object_Cursor::ToString(Signal sig, bool exprFlag)
{
	return String("<Cursor>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Cursor
//-----------------------------------------------------------------------------
// sdl.Cursor#FreeCursor():void
Gura_DeclareMethod(Cursor, FreeCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	"Frees a sdl.Cursor that was created using sdl.CreateCursor.\n"
	);
}

Gura_ImplementMethod(Cursor, FreeCursor)
{
	Object_Cursor *pObj = Object_Cursor::GetThisObj(args);
	pObj->FreeCursor();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Cursor
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Cursor)
{
	Gura_AssignMethod(Cursor, FreeCursor);
}

//-----------------------------------------------------------------------------
// Object_Timer implementation
//-----------------------------------------------------------------------------
Object_Timer::~Object_Timer()
{
	::SDL_RemoveTimer(_timerID);
	Object::Delete(_pObjFunc);
}

Object *Object_Timer::Clone() const
{
	return NULL;
}

String Object_Timer::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.timer>");
}

bool Object_Timer::AddTimer(Uint32 interval)
{
	_contFlag = true;
	_timerID = ::SDL_AddTimer(interval, CallbackStub, this);
	return _timerID != NULL;
}

bool Object_Timer::RemoveTimer()
{
	_contFlag = false;
	SDL_bool rtn = ::SDL_RemoveTimer(_timerID);
	_timerID = NULL;
	return rtn? true : false;
}

bool Object_Timer::DoHandle()
{
	if (!_contFlag) return false;
	Function *pFunc = _pObjFunc->GetFunction();
	Environment &env = pFunc->GetEnvScope();
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(this, VFLAG_NoOwner));
	Value result = _pObjFunc->Eval(env, _sig, valListArg);
	if (_sig.IsSignalled()) {
		SDL_QuitEvent event;
		event.type = SDL_QUIT;
		::SDL_PushEvent(reinterpret_cast<SDL_Event *>(&event));
		return false;
	}
	_contFlag = result.GetBoolean();
	return _contFlag;
}

Uint32 Object_Timer::CallbackStub(Uint32 interval, void *param)
{
	Object_Timer *pThis = reinterpret_cast<Object_Timer *>(param);
	if (pThis->IsThread()) {
		return pThis->DoHandle()? interval : 0;
	} else {
		SDL_UserEvent event;
		event.type = SDL_USEREVENT_Timer;
		event.code = 0;
		event.data1 = Object::Reference(pThis); // decremented in PollEvent or WaitEvent
		event.data2 = NULL;
		::SDL_PushEvent(reinterpret_cast<SDL_Event *>(&event));
		return interval;
	}
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Timer
//-----------------------------------------------------------------------------
// sdl.Timer#RemoveTimer()
Gura_DeclareMethod(Timer, RemoveTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Timer, RemoveTimer)
{
	Object_Timer *pObj = Object_Timer::GetThisObj(args);
	return Value(pObj->RemoveTimer());
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Timer
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Timer)
{
	Gura_AssignMethod(Timer, RemoveTimer);
}

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

String Object_Event::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<sdl.Event:";
	str += GetEventTypeName(_event.type);
	char buff[80];
	if (_event.type == SDL_ACTIVEEVENT) {
		const SDL_ActiveEvent &event = _event.active;
		::sprintf(buff, "(gain=%d, state=%d)", event.gain, event.state);
		str += buff;
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		const SDL_KeyboardEvent &event = _event.key;
		::sprintf(buff, "(state=%d, scancode=%d, sym=%d, mod=0x%04x, unicode=%d)",
				event.state, event.keysym.scancode, event.keysym.sym,
				event.keysym.mod, event.keysym.unicode);
		str += buff;
	} else if (_event.type == SDL_MOUSEMOTION) {
		const SDL_MouseMotionEvent &event = _event.motion;
		::sprintf(buff, "(state=%d, x=%d, y=%d, xrel=%d, yrel=%d)",
			event.state, event.x, event.y, event.xrel, event.yrel);
		str += buff;
	} else if (_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) {
		const SDL_MouseButtonEvent &event = _event.button;
		::sprintf(buff, "(button=%d, state=%d, x=%d, y=%d)",
			event.button, event.state, event.x, event.y);
		str += buff;
	} else if (_event.type == SDL_JOYAXISMOTION) {
		const SDL_JoyAxisEvent &event = _event.jaxis;
		::sprintf(buff, "(which=%d, axis=%d, value=%d)",
			event.which, event.axis, event.value);
		str += buff;
	} else if (_event.type == SDL_JOYBUTTONDOWN || _event.type == SDL_JOYBUTTONUP) {
		const SDL_JoyButtonEvent &event = _event.jbutton;
		::sprintf(buff, "(which=%d, button=%d, state=%d)",
			event.which, event.button, event.state);
		str += buff;
	} else if (_event.type == SDL_JOYHATMOTION) {
		const SDL_JoyHatEvent &event = _event.jhat;
		::sprintf(buff, "(which=%d, hat=%d, value=%d)",
			event.which, event.hat, event.value);
		str += buff;
	} else if (_event.type == SDL_JOYBALLMOTION) {
		const SDL_JoyBallEvent &event = _event.jball;
		::sprintf(buff, "(which=%d, ball=%d, xrel=%d, yrel=%d)",
			event.which, event.ball, event.xrel, event.yrel);
		str += buff;
	} else if (_event.type == SDL_VIDEORESIZE) {
		const SDL_ResizeEvent &event = _event.resize;
		::sprintf(buff, "(w=%d, h=%d)", event.w, event.h);
		str += buff;
	} else if (_event.type == SDL_VIDEOEXPOSE) {
		//const SDL_ExposeEvent &event = _event.expose;
		// nothing to do
	} else if (_event.type == SDL_QUIT) {
		//const SDL_QuitEvent &event = _event.quit;
		// nothing to do
	} else if (_event.type == SDL_USEREVENT) {
		//const SDL_UserEvent &event = _event.user;
		// nothing to do
	} else if (_event.type == SDL_SYSWMEVENT) {
		//const SDL_SysWMEvent &event = _event.syswm;
		// nothing to do
	}
	str += ">";
	return str;
}

bool Object_Event::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	if (_event.type == SDL_ACTIVEEVENT) {
		symbols.insert(Gura_UserSymbol(gain));
		symbols.insert(Gura_UserSymbol(state));
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(scancode));
		symbols.insert(Gura_UserSymbol(sym));
		symbols.insert(Gura_UserSymbol(mod));
		symbols.insert(Gura_UserSymbol(unicode));
	} else if (_event.type == SDL_MOUSEMOTION) {
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
		symbols.insert(Gura_UserSymbol(xrel));
		symbols.insert(Gura_UserSymbol(yrel));
	} else if (_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) {
		symbols.insert(Gura_UserSymbol(button));
		symbols.insert(Gura_UserSymbol(state));
		symbols.insert(Gura_UserSymbol(x));
		symbols.insert(Gura_UserSymbol(y));
	} else if (_event.type == SDL_JOYAXISMOTION) {
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(axis));
		symbols.insert(Gura_UserSymbol(value));
	} else if (_event.type == SDL_JOYBUTTONDOWN || _event.type == SDL_JOYBUTTONUP) {
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(button));
		symbols.insert(Gura_UserSymbol(state));
	} else if (_event.type == SDL_JOYHATMOTION) {
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(hat));
		symbols.insert(Gura_UserSymbol(value));
	} else if (_event.type == SDL_JOYBALLMOTION) {
		symbols.insert(Gura_UserSymbol(which));
		symbols.insert(Gura_UserSymbol(ball));
		symbols.insert(Gura_UserSymbol(xrel));
		symbols.insert(Gura_UserSymbol(yrel));
	} else if (_event.type == SDL_VIDEORESIZE) {
		symbols.insert(Gura_UserSymbol(w));
		symbols.insert(Gura_UserSymbol(h));
	} else if (_event.type == SDL_VIDEOEXPOSE) {
		//const SDL_ExposeEvent &event = _event.expose;
		// nothing to do
	} else if (_event.type == SDL_QUIT) {
		//const SDL_QuitEvent &event = _event.quit;
		// nothing to do
	} else if (_event.type == SDL_USEREVENT) {
		//const SDL_UserEvent &event = _event.user;
		// nothing to do
	} else if (_event.type == SDL_SYSWMEVENT) {
		//const SDL_SysWMEvent &event = _event.syswm;
		// nothing to do
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
	if (_event.type == SDL_ACTIVEEVENT) {
		const SDL_ActiveEvent &event = _event.active;
		if (pSymbol->IsIdentical(Gura_UserSymbol(gain))) {
			return Value(event.gain);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		}
	} else if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {
		const SDL_KeyboardEvent &event = _event.key;
		if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(scancode))) {
			return Value(event.keysym.scancode);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(sym))) {
			return Value(static_cast<int>(event.keysym.sym));
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(mod))) {
			return Value(static_cast<int>(event.keysym.mod));
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(unicode))) {
			return Value(event.keysym.unicode);
		}
	} else if (_event.type == SDL_MOUSEMOTION) {
		const SDL_MouseMotionEvent &event = _event.motion;
		if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
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
		if (pSymbol->IsIdentical(Gura_UserSymbol(button))) {
			return Value(event.button);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
			return Value(event.x);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
			return Value(event.y);
		}
	} else if (_event.type == SDL_JOYAXISMOTION) {
		const SDL_JoyAxisEvent &event = _event.jaxis;
		if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(axis))) {
			return Value(event.axis);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
			return Value(event.value);
		}
	} else if (_event.type == SDL_JOYBUTTONDOWN || _event.type == SDL_JOYBUTTONUP) {
		const SDL_JoyButtonEvent &event = _event.jbutton;
		if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(button))) {
			return Value(event.button);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(state))) {
			return Value(event.state);
		}
	} else if (_event.type == SDL_JOYHATMOTION) {
		const SDL_JoyHatEvent &event = _event.jhat;
		if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(hat))) {
			return Value(event.hat);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
			return Value(event.value);
		}
	} else if (_event.type == SDL_JOYBALLMOTION) {
		const SDL_JoyBallEvent &event = _event.jball;
		if (pSymbol->IsIdentical(Gura_UserSymbol(which))) {
			return Value(event.which);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(ball))) {
			return Value(event.ball);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(xrel))) {
			return Value(event.xrel);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(yrel))) {
			return Value(event.yrel);
		}
	} else if (_event.type == SDL_VIDEORESIZE) {
		const SDL_ResizeEvent &event = _event.resize;
		if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
			return Value(event.w);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
			return Value(event.h);
		}
	} else if (_event.type == SDL_VIDEOEXPOSE) {
		//const SDL_ExposeEvent &event = _event.expose;
		// nothing to do
	} else if (_event.type == SDL_QUIT) {
		//const SDL_QuitEvent &event = _event.quit;
		// nothing to do
	} else if (_event.type == SDL_USEREVENT) {
		//const SDL_UserEvent &event = _event.user;
		// nothing to do
	} else if (_event.type == SDL_SYSWMEVENT) {
		//const SDL_SysWMEvent &event = _event.syswm;
		// nothing to do
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Event
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Event)
{
	//Gura_AssignMethod(Match, group);
}

//-----------------------------------------------------------------------------
// Object_Rect implementation
//-----------------------------------------------------------------------------
Object_Rect::~Object_Rect()
{
}

Object *Object_Rect::Clone() const
{
	return NULL;
}

String Object_Rect::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Rect:x=%d,y=%d,w=%d,h=%d>", _rect.x, _rect.y, _rect.w, _rect.h);
	return String(buff);
}

bool Object_Rect::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	return true;
}

Value Object_Rect::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		return Value(_rect.x);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		return Value(_rect.y);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_rect.w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_rect.h);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Rect::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rect.x = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rect.y = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rect.w = static_cast<Uint16>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rect.h = static_cast<Uint16>(value.GetUInt());
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Rect
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Rect)
{
}

//-----------------------------------------------------------------------------
// Object_Color implementation
//-----------------------------------------------------------------------------
Object_Color::~Object_Color()
{
}

Object *Object_Color::Clone() const
{
	return NULL;
}

String Object_Color::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Color:r=%d,g=%d,b=%d>", _color.r, _color.g, _color.b);
	return String(buff);
}

bool Object_Color::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(r));
	symbols.insert(Gura_UserSymbol(g));
	symbols.insert(Gura_UserSymbol(b));
	return true;
}

Value Object_Color::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(r))) {
		return Value(_color.r);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(g))) {
		return Value(_color.g);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(b))) {
		return Value(_color.b);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Color::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(r))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_color.r = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(g))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_color.g = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(b))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_color.b = static_cast<Uint8>(value.GetUInt());
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Color
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Color)
{
}

Gura_ImplementCastFrom(Color)
{
	if (value.IsType(VTYPE_color)) {
		Gura::Object_color *pObjColor = Object_color::GetObject(value);
		SDL_Color color;
		color.r = pObjColor->GetRed();
		color.g = pObjColor->GetGreen();
		color.b = pObjColor->GetBlue();
		color.unused = 0;
		value = Value(new Object_Color(color));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Color)
{
	if (decl.IsType(VTYPE_color)) {
		SDL_Color &color = dynamic_cast<Object_Color *>(value.GetObject())->GetColor();
		value = Value(new Gura::Object_color(env, color.r, color.g, color.b, 255));
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Object_Palette implementation
//-----------------------------------------------------------------------------
Object_Palette::~Object_Palette()
{
}

Object *Object_Palette::Clone() const
{
	return NULL;
}

String Object_Palette::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.Palette>");
}

bool Object_Palette::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(red));
	return true;
}

Value Object_Palette::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Palette
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Palette)
{
}

//-----------------------------------------------------------------------------
// Object_PixelFormat implementation
//-----------------------------------------------------------------------------
Object_PixelFormat::Object_PixelFormat(const SDL_PixelFormat &pixelFormat) :
			Object(Gura_UserClass(PixelFormat)), _pixelFormat(pixelFormat)
{
	if (pixelFormat.palette != NULL) {
		_pixelFormat.palette = new SDL_Palette;
		int ncolors = pixelFormat.palette->ncolors;
		_pixelFormat.palette->ncolors = ncolors;
		_pixelFormat.palette->colors = new SDL_Color[ncolors];
		for (int i = 0; i < ncolors; i++) {
			_pixelFormat.palette->colors[i] = pixelFormat.palette->colors[i];
		}
	}
}

Object_PixelFormat::~Object_PixelFormat()
{
	if (_pixelFormat.palette != NULL) {
		delete[] _pixelFormat.palette->colors;
		delete _pixelFormat.palette;
	}
}

Object *Object_PixelFormat::Clone() const
{
	return NULL;
}

String Object_PixelFormat::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.PixelFormat>");
}

bool Object_PixelFormat::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(palette));
	symbols.insert(Gura_UserSymbol(BitsPerPixel));
	symbols.insert(Gura_UserSymbol(BytesPerPixel));
	symbols.insert(Gura_UserSymbol(Rloss));
	symbols.insert(Gura_UserSymbol(Gloss));
	symbols.insert(Gura_UserSymbol(Bloss));
	symbols.insert(Gura_UserSymbol(Aloss));
	symbols.insert(Gura_UserSymbol(Rshift));
	symbols.insert(Gura_UserSymbol(Gshift));
	symbols.insert(Gura_UserSymbol(Bshift));
	symbols.insert(Gura_UserSymbol(Ashift));
	symbols.insert(Gura_UserSymbol(Rmask));
	symbols.insert(Gura_UserSymbol(Gmask));
	symbols.insert(Gura_UserSymbol(Bmask));
	symbols.insert(Gura_UserSymbol(Amask));
	symbols.insert(Gura_UserSymbol(colorkey));
	symbols.insert(Gura_UserSymbol(alpha));
	return true;
}

Value Object_PixelFormat::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(palette))) {
		return Object_Palette::CreateValue(_pixelFormat.palette);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BitsPerPixel))) {
		return Value(_pixelFormat.BitsPerPixel);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BytesPerPixel))) {
		return Value(_pixelFormat.BytesPerPixel);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Rloss))) {
		return Value(_pixelFormat.Rloss);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Gloss))) {
		return Value(_pixelFormat.Gloss);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Bloss))) {
		return Value(_pixelFormat.Bloss);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Aloss))) {
		return Value(_pixelFormat.Aloss);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Rshift))) {
		return Value(_pixelFormat.Rshift);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Gshift))) {
		return Value(_pixelFormat.Gshift);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Bshift))) {
		return Value(_pixelFormat.Bshift);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Ashift))) {
		return Value(_pixelFormat.Ashift);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Rmask))) {
		return Value(_pixelFormat.Rmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Gmask))) {
		return Value(_pixelFormat.Gmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Bmask))) {
		return Value(_pixelFormat.Bmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Amask))) {
		return Value(_pixelFormat.Amask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(colorkey))) {
		return Value(_pixelFormat.colorkey);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(alpha))) {
		return Value(_pixelFormat.alpha);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_PixelFormat
//-----------------------------------------------------------------------------
// sdl.PixelFormat#MapRGB(r:number, g:number, b:number)
Gura_DeclareMethod(PixelFormat, MapRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(PixelFormat, MapRGB)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	return Value(::SDL_MapRGB(fmt,
				args.GetUChar(0), args.GetUChar(1), args.GetUChar(2)));
}

// sdl.PixelFormat#MapRGBA(r:number, g:number, b:number, a:number)
Gura_DeclareMethod(PixelFormat, MapRGBA)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	DeclareArg(env, "a", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(PixelFormat, MapRGBA)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	return Value(::SDL_MapRGBA(fmt,
				args.GetUChar(0), args.GetUChar(1),
				args.GetUChar(2), args.GetUChar(3)));
}

// sdl.PixelFormat#GetRGB(pixel:number)
Gura_DeclareMethod(PixelFormat, GetRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pixel", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(PixelFormat, GetRGB)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	Uint8 r, g, b;
	::SDL_GetRGB(args.GetULong(0), fmt, &r, &g, &b);
	return Value::CreateAsList(env, Value(r), Value(g), Value(b));
}

// sdl.PixelFormat#GetRGBA(pixel:number):void
Gura_DeclareMethod(PixelFormat, GetRGBA)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pixel", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(PixelFormat, GetRGBA)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	Uint8 r, g, b, a;
	::SDL_GetRGBA(args.GetULong(0), fmt, &r, &g, &b, &a);
	return Value::CreateAsList(env, Value(r), Value(g), Value(b), Value(a));
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.PixelFormat
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(PixelFormat)
{
	Gura_AssignMethod(PixelFormat, MapRGB);
	Gura_AssignMethod(PixelFormat, MapRGBA);
	Gura_AssignMethod(PixelFormat, GetRGB);
	Gura_AssignMethod(PixelFormat, GetRGBA);
}

//-----------------------------------------------------------------------------
// Object_PixelFormat implementation
//-----------------------------------------------------------------------------
Object_Surface::~Object_Surface()
{
	::SDL_FreeSurface(_pSurface);
}

Object *Object_Surface::Clone() const
{
	return NULL;
}

bool Object_Surface::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(flags));
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	symbols.insert(Gura_UserSymbol(pitch));
	symbols.insert(Gura_UserSymbol(pixels));
	symbols.insert(Gura_UserSymbol(clip_rect));
	symbols.insert(Gura_UserSymbol(refcount));
	return true;
}

Value Object_Surface::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(flags))) {
		return Value(_pSurface->flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Object_PixelFormat::CreateValue(*_pSurface->format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_pSurface->w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_pSurface->h);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pitch))) {
		return Value(_pSurface->pitch);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pixels))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(clip_rect))) {
		return Object_Rect::CreateValue(_pSurface->clip_rect);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refcount))) {
		return Value(_pSurface->refcount);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_Surface::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.Surface>");
}

Object_Surface *Object_Surface::CreateSurfaceFromImage(Signal sig, Image *pImage)
{
	void *pixels = pImage->GetBuffer();
	int width = static_cast<int>(pImage->GetWidth());
	int height = static_cast<int>(pImage->GetHeight());
	int depth = static_cast<int>(pImage->GetBitsPerPixel());
	int pitch = static_cast<int>(pImage->GetBytesPerLine());
	Uint32 Rmask, Gmask, Bmask, Amask;
	Image::Format fmt = pImage->GetFormat();
	if (fmt == Image::FORMAT_RGB) {
		Rmask = 0x00ff0000;
		Gmask = 0x0000ff00;
		Bmask = 0x000000ff;
		Amask = 0x00000000;
	} else if (fmt == Image::FORMAT_RGBA) {
		Rmask = 0x00ff0000;
		Gmask = 0x0000ff00;
		Bmask = 0x000000ff;
		Amask = 0xff000000;
	} else {
		sig.SetError(ERR_ValueError, "unsupported image type");
		return NULL;
	}
	SDL_Surface *pSurface = ::SDL_CreateRGBSurfaceFrom(
				pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask);
	Object_Surface *pObj = new Object_Surface(pSurface, Image::Reference(pImage));
	return pObj;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Surface
//-----------------------------------------------------------------------------
// sdl.Surface#UpdateRect(x:number => 0, y:number => 0, w:number => 0, h:number => 0):void
Gura_DeclareMethod(Surface, UpdateRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	AddHelp(Gura_Symbol(en),
	"Makes sure the given area is updated on the given screen.\n"
	"The rectangle must be confined within the screen boundaries (no clipping is done).\n"
	"\n"
	"If 'x', 'y', 'w' and 'h' are all 0, sdl.Surface#UpdateRect will update the entire screen.\n"
	"\n"
	"This function should not be called while the sdl.Surface instance is locked.\n"
	);
}

Gura_ImplementMethod(Surface, UpdateRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	::SDL_UpdateRect(pSurface,
		args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetInt(3));
	return Value::Null;
}

// sdl.Surface#UpdateRects(rects[]:sdl.Rect):void
Gura_DeclareMethod(Surface, UpdateRects)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en),
	"Makes sure the given list of rectangles is updated on the given screen.\n"
	"The rectangles must all be confined within the screen boundaries (no clipping is done).\n"
	"\n"
	"This function should not be called while the sdl.Surface instance is locked.\n"
	"\n"
	"*Note:* It is adviced to call this function only once per frame, since each call has some processing overhead.\n"
	"This is no restriction since you can pass any number of rectangles each time.\n"
	"\n"
    "The rectangles are not automatically merged or checked for overlap.\n"
    "In general, the programmer can use his knowledge about his particular rectangles to merge them in an efficient way, to avoid overdraw.\n"
	);
}

Gura_ImplementMethod(Surface, UpdateRects)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	const ValueList &valList = args.GetList(0);
	int numrects = static_cast<int>(valList.size());
	SDL_Rect *rects = new SDL_Rect[numrects];
	SDL_Rect *pRect = rects;
	foreach_const (ValueList, pValue, valList) {
		const Object_Rect *pObj =
					dynamic_cast<const Object_Rect *>(pValue->GetObject());
		*pRect = pObj->GetRect();
		pRect++;
	}
	::SDL_UpdateRects(pSurface, numrects, rects);
	delete[] rects;
	return Value::Null;
}

// sdl.Surface#Flip()
Gura_DeclareMethod(Surface, Flip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	"On hardware that supports double-buffering, this function sets up a flip and returns.\n"
	"The hardware will wait for vertical retrace, and then swap video buffers before the next video surface blit or lock will return.\n"
	"On hardware that doesn't support double-buffering, this is equivalent to calling screen.UpdateRect(0, 0, 0, 0)\n"
	"\n"
	"The sdl.DOUBLEBUF flag must have been passed to sdl.SetVideoMode, when setting the video mode for this function to perform hardware flipping.\n"
	"\n"
	"*Return Value* This function returns 0 if successful, or -1 if there was an error.\n"
	);
}

Gura_ImplementMethod(Surface, Flip)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_Flip(pSurface));
}

// sdl.Surface#SetColors(colors[]:Color, firstcolor:number => 0)
Gura_DeclareMethod(Surface, SetColors)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None,
															new Expr_Value(0));
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SetColors)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	const ValueList &valList = args.GetList(0);
	int firstcolor = args.GetInt(1);
	int ncolors = static_cast<int>(valList.size());
	SDL_Color *colors = new SDL_Color[ncolors];
	SDL_Color *pColor = colors;
	foreach_const (ValueList, pValue, valList) {
		const Object_Color *pObj =
					dynamic_cast<const Object_Color *>(pValue->GetObject());
		*pColor = pObj->GetColor();
		pColor++;
	}
	int rtn = ::SDL_SetColors(pSurface, colors, firstcolor, ncolors);
	delete[] colors;
	return Value(rtn);
}

// sdl.Surface#SetPalette(flags:number, colors[]:Color, firstcolor:number => 0)
Gura_DeclareMethod(Surface, SetPalette)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None,
															new Expr_Value(0));
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SetPalette)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	int flags = args.GetInt(0);
	const ValueList &valList = args.GetList(1);
	int firstcolor = args.GetInt(2);
	int ncolors = static_cast<int>(valList.size());
	SDL_Color *colors = new SDL_Color[ncolors];
	SDL_Color *pColor = colors;
	foreach_const (ValueList, pValue, valList) {
		const Object_Color *pObj =
					dynamic_cast<const Object_Color *>(pValue->GetObject());
		*pColor = pObj->GetColor();
		pColor++;
	}
	int rtn = ::SDL_SetPalette(pSurface, flags, colors, firstcolor, ncolors);
	delete[] colors;
	return Value(rtn);
}

// sdl.Surface#LockSurface()
Gura_DeclareMethod(Surface, LockSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, LockSurface)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_LockSurface(pSurface));
}

// sdl.Surface#UnlockSurface():void
Gura_DeclareMethod(Surface, UnlockSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, UnlockSurface)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	::SDL_UnlockSurface(pSurface);
	return Value::Null;
}

// sdl.Surface#SaveBMP(file:string):void
Gura_DeclareMethod(Surface, SaveBMP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SaveBMP)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SaveBMP(pSurface, args.GetString(0)));
}

// sdl.Surface#SetColorKey(flag:number, key:number)
Gura_DeclareMethod(Surface, SetColorKey)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SetColorKey)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SetColorKey(pSurface, args.GetULong(0), args.GetULong(1)));
}

// sdl.Surface#SetAlpha(flag:number, alpha:number)
Gura_DeclareMethod(Surface, SetAlpha)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SetAlpha)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SetAlpha(pSurface, args.GetULong(0), args.GetUChar(1)));
}

// sdl.Surface#SetClipRect(rect:sdl.Rect):map:void
Gura_DeclareMethod(Surface, SetClipRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_Rect);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, SetClipRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Rect &rect = dynamic_cast<Object_Rect *>(args.GetObject(0))->GetRect();
	::SDL_SetClipRect(pSurface, &rect);
	return Value::Null;
}

// sdl.Surface#GetClipRect()
Gura_DeclareMethod(Surface, GetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, GetClipRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Rect rect;
	::SDL_GetClipRect(pSurface, &rect);
	return Object_Rect::CreateValue(rect);
}

// sdl.Surface#ConvertSurface(fmt:sdl.PixelFormat, flags:number) {block?}
Gura_DeclareMethod(Surface, ConvertSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "fmt", VTYPE_PixelFormat);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, ConvertSurface)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	const SDL_PixelFormat *fmt =
		dynamic_cast<const Object_PixelFormat *>(args.GetObject(0))->GetPixelFormat();
	int flags = args.GetInt(1);
	SDL_Surface *pSurfaceConv = ::SDL_ConvertSurface(pSurface,
								const_cast<SDL_PixelFormat *>(fmt), flags);
	if (pSurfaceConv == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurfaceConv, NULL));
}

// sdl.Surface#FillRect(dstrect:sdl.Rect, color:Color):map:void
Gura_DeclareMethod(Surface, FillRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_Rect);
	DeclareArg(env, "color", VTYPE_Color);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, FillRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Rect &dstrect = dynamic_cast<Object_Rect *>(args.GetObject(0))->GetRect();
	SDL_Color &color = dynamic_cast<Object_Color *>(args.GetObject(1))->GetColor();
	Uint32 colorIdx = ::SDL_MapRGB(pSurface->format, color.r, color.g, color.b);
	return Value(::SDL_FillRect(pSurface, &dstrect, colorIdx));
}

// sdl.Surface#DisplayFormat() {block?}
Gura_DeclareMethod(Surface, DisplayFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, DisplayFormat)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Surface *pSurfaceConv = ::SDL_DisplayFormat(pSurface);
	if (pSurfaceConv == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurfaceConv, NULL));
}

// sdl.Surface#DisplayFormatAlpha() {block?}
Gura_DeclareMethod(Surface, DisplayFormatAlpha)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Surface, DisplayFormatAlpha)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Surface *pSurfaceConv = ::SDL_DisplayFormatAlpha(pSurface);
	if (pSurfaceConv == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurfaceConv, NULL));
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Surface)
{
	Gura_AssignMethod(Surface, UpdateRect);
	Gura_AssignMethod(Surface, UpdateRects);
	Gura_AssignMethod(Surface, Flip);
	Gura_AssignMethod(Surface, SetColors);
	Gura_AssignMethod(Surface, SetPalette);
	Gura_AssignMethod(Surface, LockSurface);
	Gura_AssignMethod(Surface, UnlockSurface);
	Gura_AssignMethod(Surface, SaveBMP);
	Gura_AssignMethod(Surface, SetColorKey);
	Gura_AssignMethod(Surface, SetAlpha);
	Gura_AssignMethod(Surface, SetClipRect);
	Gura_AssignMethod(Surface, GetClipRect);
	Gura_AssignMethod(Surface, ConvertSurface);
	Gura_AssignMethod(Surface, FillRect);
	Gura_AssignMethod(Surface, DisplayFormat);
	Gura_AssignMethod(Surface, DisplayFormatAlpha);
}

Gura_ImplementCastFrom(Surface)
{
	if (value.IsImage()) {
		Image *pImage = Object_image::GetObject(value)->GetImage();
		Object_Surface *pObjSurface =
					Object_Surface::CreateSurfaceFromImage(sig, pImage);
		if (sig.IsSignalled()) return false;
		value = Value(pObjSurface);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Surface)
{
	return false;
}

//-----------------------------------------------------------------------------
// Object_Overlay implementation
//-----------------------------------------------------------------------------
Object_Overlay::~Object_Overlay()
{
	::SDL_FreeYUVOverlay(_pOverlay);
}

Object *Object_Overlay::Clone() const
{
	return NULL;
}

String Object_Overlay::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.Overlay>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Overlay
//-----------------------------------------------------------------------------
// sdl.Overlay#LockYUVOverlay()
Gura_DeclareMethod(Overlay, LockYUVOverlay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Overlay, LockYUVOverlay)
{
	SDL_Overlay *pOverlay = Object_Overlay::GetThisObj(args)->GetOverlay();
	return Value(::SDL_LockYUVOverlay(pOverlay));
}

// sdl.Overlay#UnlockYUVOverlay():void
Gura_DeclareMethod(Overlay, UnlockYUVOverlay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Overlay, UnlockYUVOverlay)
{
	SDL_Overlay *pOverlay = Object_Overlay::GetThisObj(args)->GetOverlay();
	::SDL_UnlockYUVOverlay(pOverlay);
	return Value::Null;
}

// sdl.Overlay#DisplayYUVOverlay(dstrect:sdl.Rect)
Gura_DeclareMethod(Overlay, DisplayYUVOverlay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Overlay, DisplayYUVOverlay)
{
	SDL_Overlay *pOverlay = Object_Overlay::GetThisObj(args)->GetOverlay();
	SDL_Rect &dstrect = dynamic_cast<Object_Rect *>(args.GetObject(0))->GetRect();
	return Value(::SDL_DisplayYUVOverlay(pOverlay, &dstrect));
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Overlay
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Overlay)
{
	Gura_AssignMethod(Overlay, LockYUVOverlay);
	Gura_AssignMethod(Overlay, UnlockYUVOverlay);
	Gura_AssignMethod(Overlay, DisplayYUVOverlay);
}

//-----------------------------------------------------------------------------
// Object_VideoInfo implementation
//-----------------------------------------------------------------------------
Object_VideoInfo::~Object_VideoInfo()
{
}

Object *Object_VideoInfo::Clone() const
{
	return NULL;
}

String Object_VideoInfo::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.VideoInfo>");
}

bool Object_VideoInfo::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(hw_available));
	symbols.insert(Gura_UserSymbol(wm_available));
	symbols.insert(Gura_UserSymbol(blit_hw));
	symbols.insert(Gura_UserSymbol(blit_hw_CC));
	symbols.insert(Gura_UserSymbol(blit_hw_A));
	symbols.insert(Gura_UserSymbol(blit_sw));
	symbols.insert(Gura_UserSymbol(blit_sw_CC));
	symbols.insert(Gura_UserSymbol(blit_sw_A));
	symbols.insert(Gura_UserSymbol(blit_fill));
	symbols.insert(Gura_UserSymbol(video_mem));
	symbols.insert(Gura_UserSymbol(vfmt));
	return true;
}

Value Object_VideoInfo::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(hw_available))) {
		return Value(_pVideoInfo->hw_available? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(wm_available))) {
		return Value(_pVideoInfo->wm_available? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_hw))) {
		return Value(_pVideoInfo->blit_hw? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_hw_CC))) {
		return Value(_pVideoInfo->blit_hw_CC? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_hw_A))) {
		return Value(_pVideoInfo->blit_hw_A? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_sw))) {
		return Value(_pVideoInfo->blit_sw? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_sw_CC))) {
		return Value(_pVideoInfo->blit_sw_CC? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_sw_A))) {
		return Value(_pVideoInfo->blit_sw_A? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(blit_fill))) {
		return Value(_pVideoInfo->blit_fill? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(video_mem))) {
		return Value(_pVideoInfo->video_mem);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(vfmt))) {
		if (_pVideoInfo->vfmt == NULL) return Value::Null;
		return Object_PixelFormat::CreateValue(*_pVideoInfo->vfmt);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.VideoInfo
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(VideoInfo)
{
}

//-----------------------------------------------------------------------------
// Object_Joystick implementation
//-----------------------------------------------------------------------------
Object_Joystick::~Object_Joystick()
{
	::SDL_JoystickClose(_pJoystick);
}

Object *Object_Joystick::Clone() const
{
	return NULL;
}

String Object_Joystick::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.Joystick>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Joystick
//-----------------------------------------------------------------------------
// sdl.Joystick#JoystickIndex()
Gura_DeclareMethod(Joystick, JoystickIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickIndex)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickIndex(pJoystick));
}

// sdl.Joystick#JoystickNumAxes()
Gura_DeclareMethod(Joystick, JoystickNumAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickNumAxes)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumAxes(pJoystick));
}

// sdl.Joystick#JoystickNumBalls()
Gura_DeclareMethod(Joystick, JoystickNumBalls)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickNumBalls)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumBalls(pJoystick));
}

// sdl.Joystick#JoystickNumHats()
Gura_DeclareMethod(Joystick, JoystickNumHats)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickNumHats)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumHats(pJoystick));
}

// sdl.Joystick#JoystickNumButtons()
Gura_DeclareMethod(Joystick, JoystickNumButtons)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickNumButtons)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumButtons(pJoystick));
}

// sdl.Joystick#JoystickGetAxis(axis:number)
Gura_DeclareMethod(Joystick, JoystickGetAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickGetAxis)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetAxis(pJoystick, args.GetInt(0)));
}

// sdl.Joystick#JoystickGetHat(hat:number)
Gura_DeclareMethod(Joystick, JoystickGetHat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "hat", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickGetHat)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetHat(pJoystick, args.GetInt(0)));
}

// sdl.Joystick#JoystickGetButton(button:number)
Gura_DeclareMethod(Joystick, JoystickGetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "button", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickGetButton)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetButton(pJoystick, args.GetInt(0)));
}

// sdl.Joystick#JoystickGetBall(ball:number)
Gura_DeclareMethod(Joystick, JoystickGetBall)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "ball", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickGetBall)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	int dx, dy;
	if (::SDL_JoystickGetBall(pJoystick, args.GetInt(0), &dx, &dy) < 0) {
		return Value::Null;
	}
	return Value::CreateAsList(env, Value(dx), Value(dy));
}

// sdl.Joystick#JoystickClose():void
Gura_DeclareMethod(Joystick, JoystickClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(Joystick, JoystickClose)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	::SDL_JoystickClose(pJoystick);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.Joystick
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Joystick)
{
	Gura_AssignMethod(Joystick, JoystickIndex);
	Gura_AssignMethod(Joystick, JoystickNumAxes);
	Gura_AssignMethod(Joystick, JoystickNumBalls);
	Gura_AssignMethod(Joystick, JoystickNumHats);
	Gura_AssignMethod(Joystick, JoystickNumButtons);
	Gura_AssignMethod(Joystick, JoystickGetAxis);
	Gura_AssignMethod(Joystick, JoystickGetHat);
	Gura_AssignMethod(Joystick, JoystickGetButton);
	Gura_AssignMethod(Joystick, JoystickGetBall);
	Gura_AssignMethod(Joystick, JoystickClose);
}

//-----------------------------------------------------------------------------
// Object_AudioSpec implementation
//-----------------------------------------------------------------------------
Object_AudioSpec::~Object_AudioSpec()
{
	if (_audio_buf != NULL) ::SDL_FreeWAV(_audio_buf);
	::free(_pAudioSpec);
	Function::Delete(_pFuncCallback);
}

Object *Object_AudioSpec::Clone() const
{
	return NULL;
}

void Object_AudioSpec::Callback(Uint8 *stream, int len)
{
	if (_pFuncCallback == NULL) return;
	Environment &env = *this;
	Audio::Format fmt;
	if (_pAudioSpec->format == AUDIO_U16SYS) {
		fmt = IsBigEndian()? Audio::FORMAT_U16BE : Audio::FORMAT_U16LE;
	} else if (_pAudioSpec->format == AUDIO_S16SYS) {
		fmt = IsBigEndian()? Audio::FORMAT_S16BE : Audio::FORMAT_S16LE;
	} else {
		fmt =
			(_pAudioSpec->format == AUDIO_U8)? Audio::FORMAT_U8 :
			(_pAudioSpec->format == AUDIO_S8)? Audio::FORMAT_S8 :
			(_pAudioSpec->format == AUDIO_U16LSB)? Audio::FORMAT_U16LE :
			(_pAudioSpec->format == AUDIO_S16LSB)? Audio::FORMAT_S16LE :
			(_pAudioSpec->format == AUDIO_U16MSB)? Audio::FORMAT_U16BE :
			(_pAudioSpec->format == AUDIO_S16MSB)? Audio::FORMAT_S16BE :
			Audio::FORMAT_U8;
	}
	::SDL_LockAudio();
#if 0
	do {
		Uint8 *p = stream;
		for (int i = 0; i < len / 2; i++, p += 2) {
			UShort num = static_cast<UShort>(
								::sin(6.28 * i * 400 / _pAudioSpec->freq) * 3000);
			*(p + 0) = static_cast<UChar>(num);
			*(p + 1) = static_cast<UChar>(num >> 8);
		}
	} while (0);
#endif
#if 0
	do {
		AutoPtr<Object_audio> pObjAudio(new Object_audio(env,
										fmt, _pAudioSpec->channels));
		pObjAudio->ReferenceBuffer(NULL, stream, len);
		ValueList valList;
		valList.reserve(1);
		valList.push_back(Value(pObjAudio.release()));
		Args args(valList);
		_pFuncCallback->Eval(env, _sig, args);
	} while (0);
#endif
	::SDL_UnlockAudio();
}

void Object_AudioSpec::CallbackStub(void *userdata, Uint8 *stream, int len)
{
	if (userdata == NULL) return;
	Object_AudioSpec *pThis = reinterpret_cast<Object_AudioSpec *>(userdata);
	pThis->Callback(stream, len);
}

String Object_AudioSpec::ToString(Signal sig, bool exprFlag)
{
	char buff[64];
	String rtn;
	rtn += "<sdl.AudioSpec";
	do {
		rtn += ":";
		::sprintf(buff, "%dHz", _pAudioSpec->freq);
		rtn += buff;
	} while (0);
	do {
		rtn += ":";
		rtn +=
			(_pAudioSpec->format == AUDIO_U8)? "u8" :
			(_pAudioSpec->format == AUDIO_S8)? "s8" :
			(_pAudioSpec->format == AUDIO_U16LSB)? "u16lsb" :
			(_pAudioSpec->format == AUDIO_S16LSB)? "s16lsb" :
			(_pAudioSpec->format == AUDIO_U16MSB)? "u16msb" :
			(_pAudioSpec->format == AUDIO_S16MSB)? "s16msb" :
			(_pAudioSpec->format == AUDIO_U16SYS)? "u16sys" :
			(_pAudioSpec->format == AUDIO_S16SYS)? "s16sys" : "?";
	} while (0);
	do {
		rtn += ":";
		::sprintf(buff, "%dch", _pAudioSpec->channels);
		rtn += buff;
	} while (0);
	do {
		rtn += ":";
		::sprintf(buff, "%dsamples", _pAudioSpec->samples);
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_AudioSpec
//-----------------------------------------------------------------------------
// sdl.AudioSpec#MixAudio(src:AudioSpec, volume:number)
Gura_DeclareMethod(AudioSpec, MixAudio)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src", VTYPE_AudioSpec);
	DeclareArg(env, "volume", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(AudioSpec, MixAudio)
{
	Object_AudioSpec *pDst = Object_AudioSpec::GetThisObj(args);
	Object_AudioSpec *pSrc =dynamic_cast<Object_AudioSpec *>(args.GetObject(0));
	int volume = args.GetInt(1);
	if (pDst->GetAudioBuf() == NULL || pSrc->GetAudioBuf() == NULL) {
		sig.SetError(ERR_ValueError, "audio buffer is not prepared");
		return Value::Null;
	}
	if (pDst->GetAudioLen() != pSrc->GetAudioLen()) {
		sig.SetError(ERR_ValueError, "lengths of audio buffer are different");
		return Value::Null;
	}
	::SDL_MixAudio(pDst->GetAudioBuf(), pSrc->GetAudioBuf(),
											pDst->GetAudioLen(), volume);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.AudioSpec
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(AudioSpec)
{
	Gura_AssignMethod(AudioSpec, MixAudio);
}

//-----------------------------------------------------------------------------
// Object_AudioCVT implementation
//-----------------------------------------------------------------------------
Object_AudioCVT::~Object_AudioCVT()
{
	::free(_pAudioCVT);
}

Object *Object_AudioCVT::Clone() const
{
	return NULL;
}

String Object_AudioCVT::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.AudioCVT>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_AudioCVT
//-----------------------------------------------------------------------------
// sdl.AudioCVT#ConvertAudio()
Gura_DeclareMethod(AudioCVT, ConvertAudio)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(AudioCVT, ConvertAudio)
{
	SDL_AudioCVT *pAudioCVT = Object_AudioCVT::GetThisObj(args)->GetAudioCVT();
	return Value(::SDL_ConvertAudio(pAudioCVT));
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.AudioCVT
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(AudioCVT)
{
	Gura_AssignMethod(AudioCVT, ConvertAudio);
}

//-----------------------------------------------------------------------------
// Object_CDtrack implementation
//-----------------------------------------------------------------------------
Object_CDtrack::~Object_CDtrack()
{
}

Object *Object_CDtrack::Clone() const
{
	return NULL;
}

bool Object_CDtrack::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(length));
	symbols.insert(Gura_UserSymbol(offset));
	return true;
}

Value Object_CDtrack::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(static_cast<int>(_CDtrack.id));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(static_cast<int>(_CDtrack.type));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(length))) {
		return Value(static_cast<int>(_CDtrack.length));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(offset))) {
		return Value(static_cast<int>(_CDtrack.offset));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_CDtrack::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.CDtrack>");
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.CDtrack
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(CDtrack)
{
}

//-----------------------------------------------------------------------------
// Object_CD implementation
//-----------------------------------------------------------------------------
Object_CD::~Object_CD()
{
	::SDL_CDClose(_pCD);
}

Object *Object_CD::Clone() const
{
	return NULL;
}

bool Object_CD::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(status));
	symbols.insert(Gura_UserSymbol(numtracks));
	symbols.insert(Gura_UserSymbol(cur_track));
	symbols.insert(Gura_UserSymbol(cur_frame));
	return true;
}

Value Object_CD::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(status))) {
		return Value(static_cast<int>(_pCD->status));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(numtracks))) {
		return Value(_pCD->numtracks);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(cur_track))) {
		return Value(_pCD->cur_track);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(cur_frame))) {
		return Value(_pCD->cur_frame);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_CD::ToString(Signal sig, bool exprFlag)
{
	return String("<sdl.CD>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_CD
//-----------------------------------------------------------------------------
// sdl.CD#CDStatus()
Gura_DeclareMethod(CD, CDStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDStatus)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDStatus(pCD));
}

// sdl.CD#CDPlay(start:number, length:number)
Gura_DeclareMethod(CD, CDPlay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "start", VTYPE_number);
	DeclareArg(env, "length", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDPlay)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDPlay(pCD, args.GetInt(0), args.GetInt(1)));
}

// sdl.CD#CDPlayTracks(start_track:number, start_frame:number,
//                     ntracks:number, nframes:number)
Gura_DeclareMethod(CD, CDPlayTracks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "start_track", VTYPE_number);
	DeclareArg(env, "start_frame", VTYPE_number);
	DeclareArg(env, "ntracks", VTYPE_number);
	DeclareArg(env, "nframes", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDPlayTracks)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDPlayTracks(pCD, args.GetInt(0), args.GetInt(1),
										args.GetInt(2), args.GetInt(3)));
}

// sdl.CD#CDPause()
Gura_DeclareMethod(CD, CDPause)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDPause)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDPause(pCD));
}

// sdl.CD#CDResume()
Gura_DeclareMethod(CD, CDResume)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDResume)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDResume(pCD));
}

// sdl.CD#CDStop()
Gura_DeclareMethod(CD, CDStop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDStop)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDStop(pCD));
}

// sdl.CD#CDEject()
Gura_DeclareMethod(CD, CDEject)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDEject)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDEject(pCD));
}

// sdl.CD#CDClose():void
Gura_DeclareMethod(CD, CDClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, CDClose)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	::SDL_CDClose(pCD);
	return Value::Null;
}

// sdl.CD#GetTrack(n:number):map
Gura_DeclareMethod(CD, GetTrack)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementMethod(CD, GetTrack)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	int n = args.GetInt(0);
	if (n < 0 || n > pCD->numtracks) {
		sig.SetError(ERR_ValueError, "track index is out of range");
		return Value::Null;
	}
	return Object_CDtrack::CreateValue(pCD->track[n]);
}

//-----------------------------------------------------------------------------
// Class implementation for sdl.CD
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(CD)
{
	Gura_AssignMethod(CD, CDStatus);
	Gura_AssignMethod(CD, CDPlay);
	Gura_AssignMethod(CD, CDPlayTracks);
	Gura_AssignMethod(CD, CDPause);
	Gura_AssignMethod(CD, CDResume);
	Gura_AssignMethod(CD, CDStop);
	Gura_AssignMethod(CD, CDEject);
	Gura_AssignMethod(CD, CDClose);
	Gura_AssignMethod(CD, GetTrack);
}

//-----------------------------------------------------------------------------
// SDL functions: General
//-----------------------------------------------------------------------------
// sdl.Init(flags:number)
Gura_DeclareFunction(Init)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"Initializes SDL. This should be called before all other SDL functions.\n"
	"The flags parameter specifies what part(s) of SDL to initialize.\n"
	"\n"
	"  sdl.INIT_TIMER       Initializes the timer subsystem.\n"
	"  sdl.INIT_AUDIO       Initializes the audio subsystem.\n"
	"  sdl.INIT_VIDEO       Initializes the video subsystem.\n"
	"  sdl.INIT_CDROM       Initializes the cdrom subsystem.\n"
	"  sdl.INIT_JOYSTICK    Initializes the joystick subsystem.\n"
	"  sdl.INIT_EVERYTHING  Initialize all of the above.\n"
	"  sdl.INIT_NOPARACHUTE Prevents SDL from catching fatal signals.\n"
	"  sdl.INIT_EVENTTHREAD\n"
	"\n"
	"*Return Value* Returns -1 on an error or 0 on success.\n"
	);
}

Gura_ImplementFunction(Init)
{
	int rtn = ::SDL_Init(args.GetULong(0));
	if (rtn < 0) return Value(rtn);
	return Value(rtn);
}

// sdl.InitSubSystem(flags:number)
Gura_DeclareFunction(InitSubSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"After SDL has been initialized with sdl.Init you may initialize uninitialized subsystems with sdl.InitSubSystem.\n"
	"The flags parameter is the same as that used in sdl.Init.\n"
	"\n"
	"*Return Value* Returns -1 on an error or 0 on success.\n"
	);
}

Gura_ImplementFunction(InitSubSystem)
{
	return Value(::SDL_InitSubSystem(args.GetULong(0)));
}

// sdl.QuitSubSystem(flags:number):void
Gura_DeclareFunction(QuitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"sdl.QuitSubSystem allows you to shut down a subsystem that has been previously initialized by sdl.Init or sdl.InitSubSystem.\n"
	"The flags tells sdl.QuitSubSystem which subsystems to shut down, it uses the same values that are passed to sdl.Init.\n"
	);
}

Gura_ImplementFunction(QuitSubSystem)
{
	::SDL_QuitSubSystem(args.GetULong(0));
	return Value::Null;
}

// sdl.Quit():void
Gura_DeclareFunction(Quit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	"sdl.Quit shuts down all SDL subsystems and frees the resources allocated to them.\n"
	"This should always be called before you exit.\n"
	);
}

Gura_ImplementFunction(Quit)
{
	::SDL_Quit();
	return Value::Null;
}

// sdl.WasInit(flags:number)
Gura_DeclareFunction(WasInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"sdl.WasInit allows you to see which SDL subsytems have been initialized.\n"
	"flags is a bitwise OR'd combination of the subsystems you wish to check (see sdl.Init for a list of subsystem flags).\n"
	"\n"
	"*Return Value* sdl.WasInit returns a bitwised OR'd combination of the initialized subsystems.\n"
	);
}

Gura_ImplementFunction(WasInit)
{
	return Value(::SDL_WasInit(args.GetULong(0)));
}

// sdl.GetError()
Gura_DeclareFunction(GetError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	"sdl.GetError returns a string containing information about the last internal SDL error.\n"
	"\n"
	"*Return Value* sdl.GetError returns a string containing the last error.\n"
	);
}

Gura_ImplementFunction(GetError)
{
	//return Value(env, ::SDL_GetError());
	return Value(env, "");
}

//-----------------------------------------------------------------------------
// SDL functions: Video
//-----------------------------------------------------------------------------
// sdl.GetVideoSurface() {block?}
Gura_DeclareFunction(GetVideoSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetVideoSurface)
{
	SDL_Surface *pSurface = ::SDL_GetVideoSurface();
	if (pSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurface, NULL));
}

// sdl.GetVideoInfo()
Gura_DeclareFunction(GetVideoInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetVideoInfo)
{
	const SDL_VideoInfo *pVideoInfo = ::SDL_GetVideoInfo();
	if (pVideoInfo == NULL) return Value::Null;
	return Object_VideoInfo::CreateValue(pVideoInfo);
}

// sdl.VideoDriverName()
Gura_DeclareFunction(VideoDriverName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(VideoDriverName)
{
	char buff[64];
	char *p = ::SDL_VideoDriverName(buff, sizeof(buff));
	if (p == NULL) return Value::Null;
	return Value(env, p);
}

// sdl.ListModes(format:sdl.PixelFormat, flags:number)
Gura_DeclareFunction(ListModes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(ListModes)
{
	SDL_PixelFormat *format = args.IsValid(0)?
			Object_PixelFormat::GetObject(args, 0)->GetPixelFormat() : NULL;
	Uint32 flags = args.GetUInt(1);
	SDL_Rect **modes = ::SDL_ListModes(format, flags);
	if (modes == NULL) return Value::Null;
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (modes == reinterpret_cast<SDL_Rect **>(-1)) {
		// nothing to do
	} else {
		for (int i = 0; modes[i] != NULL; i++) {
			valList.push_back(Value(new Object_Rect(*modes[i])));
		}
	}
	return rtn;
}

// sdl.VideoModeOK(width:number, height:number, bpp:number, flags:number)
Gura_DeclareFunction(VideoModeOK)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "bpp", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(VideoModeOK)
{
	return Value(::SDL_VideoModeOK(
		args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetULong(3)));
}

// sdl.SetVideoMode(width:number, height:number, bpp:number, flags:number) {block?}
Gura_DeclareFunction(SetVideoMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "bpp", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(SetVideoMode)
{
	SDL_Surface *pSurface = ::SDL_SetVideoMode(
		args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetULong(3));
	if (pSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurface, NULL));
}

// sdl.SetGamma(redgamma:number, greengamma:number, bluegamma:number)
Gura_DeclareFunction(SetGamma)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "redgamma", VTYPE_number);
	DeclareArg(env, "greengamma", VTYPE_number);
	DeclareArg(env, "bluegamma", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(SetGamma)
{
	return Value(::SDL_SetGamma(static_cast<float>(args.GetNumber(0)),
		static_cast<float>(args.GetNumber(1)), static_cast<float>(args.GetNumber(2))));
}

// sdl.GetGammaRamp()
Gura_DeclareFunction(GetGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetGammaRamp)
{
	Uint16 redtable[256], greentable[256], bluetable[256];
	int rtn = ::SDL_GetGammaRamp(redtable, greentable, bluetable);
	if (rtn < 0) return Value::Null;
	Value result;
	ValueList &valList = result.InitAsList(env);
	do {
		Value valElem;
		ValueList &valElemList = valElem.InitAsList(env);
		valList.push_back(valElem);
		for (int i = 0; i < 256; i++) {
			valElemList.push_back(Value(redtable[i]));
		}
	} while (0);
	do {
		Value valElem;
		ValueList &valElemList = valElem.InitAsList(env);
		valList.push_back(valElem);
		for (int i = 0; i < 256; i++) {
			valElemList.push_back(Value(greentable[i]));
		}
	} while (0);
	do {
		Value valElem;
		ValueList &valElemList = valElem.InitAsList(env);
		valList.push_back(valElem);
		for (int i = 0; i < 256; i++) {
			valElemList.push_back(Value(bluetable[i]));
		}
	} while (0);
	return result;
}

// sdl.SetGammaRamp(redtable[]:number, greentable[]:number, bluetable[]:number)
Gura_DeclareFunction(SetGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "redtable", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "greentable", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "bluetable", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(SetGammaRamp)
{
	Uint16 redtable[256], greentable[256], bluetable[256];
	::memset(redtable, 0, sizeof(redtable));
	::memset(redtable, 0, sizeof(greentable));
	::memset(redtable, 0, sizeof(bluetable));
	do {
		int i = 0;
		foreach_const (ValueList, pValue, args.GetList(0)) {
			if (i > 255) break;
			redtable[i++] = pValue->GetUShort();
		}
	} while (0);
	do {
		int i = 0;
		foreach_const (ValueList, pValue, args.GetList(1)) {
			if (i > 255) break;
			greentable[i++] = pValue->GetUShort();
		}
	} while (0);
	do {
		int i = 0;
		foreach_const (ValueList, pValue, args.GetList(2)) {
			if (i > 255) break;
			bluetable[i++] = pValue->GetUShort();
		}
	} while (0);
	int rtn = ::SDL_SetGammaRamp(redtable, greentable, bluetable);
	return Value(rtn);
}

// sdl.CreateRGBSurface(flags:number, width:number, height:number, depth:number,
//              Rmask:number, Gmask:number, Bmask:number, Amask:number) {block?}
Gura_DeclareFunction(CreateRGBSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "depth", VTYPE_number);
	DeclareArg(env, "Rmask", VTYPE_number);
	DeclareArg(env, "Gmask", VTYPE_number);
	DeclareArg(env, "Bmask", VTYPE_number);
	DeclareArg(env, "Amask", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CreateRGBSurface)
{
	SDL_Surface *pSurface = ::SDL_CreateRGBSurface(
		args.GetULong(0), args.GetInt(1), args.GetInt(2), args.GetInt(3),
		args.GetULong(4), args.GetULong(5), args.GetULong(6), args.GetULong(7));
	if (pSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurface, NULL));
}

// sdl.CreateRGBSurfaceFrom(image:image) {block?}
Gura_DeclareFunction(CreateRGBSurfaceFrom)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CreateRGBSurfaceFrom)
{
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	Object_Surface *pObj = Object_Surface::CreateSurfaceFromImage(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObj));
}

// sdl.LoadBMP(file:string) {block?}
Gura_DeclareFunction(LoadBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(LoadBMP)
{
	const char *file = args.GetString(0);
	SDL_Surface *pSurface = ::SDL_LoadBMP(file);
	if (pSurface == NULL) {
		sig.SetError(ERR_RuntimeError, "failed to load an image %s", file);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Object_Surface::CreateValue(pSurface, NULL));
}

// sdl.BlitSurface(src:sdl.Surface, srcrect, dst:sdl.Surface, dstrect)
Gura_DeclareFunction(BlitSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src",		VTYPE_Surface);
	DeclareArg(env, "srcrect",	VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst",		VTYPE_Surface);
	DeclareArg(env, "dstrect",	VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(BlitSurface)
{
	SDL_Surface *src =
		dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	SDL_Surface *dst =
		dynamic_cast<Object_Surface *>(args.GetObject(2))->GetSurface();
	SDL_Rect *srcrect = NULL, *dstrect = NULL;
	if (args.IsValid(1)) {
		srcrect = &dynamic_cast<Object_Rect *>(args.GetObject(1))->GetRect();
	}
	if (args.IsValid(3)) {
		dstrect = &dynamic_cast<Object_Rect *>(args.GetObject(3))->GetRect();
	}
	return Value(::SDL_BlitSurface(src, srcrect, dst, dstrect));
}

// sdl.WarpMouse(x:number, y:number):void
Gura_DeclareFunction(WarpMouse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WarpMouse)
{
	::SDL_WarpMouse(args.GetUShort(0), args.GetUShort(1));
	return Value::Null;
}

// sdl.CreateCursor(data:binary, mask:binary,
//                  w:number, h:number, hot_x:number, hot_y:number)
Gura_DeclareFunction(CreateCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "data", VTYPE_binary);
	DeclareArg(env, "mask", VTYPE_binary);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	DeclareArg(env, "hot_x", VTYPE_number);
	DeclareArg(env, "hot_y", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"Create a cursor using the specified data and mask (in MSB format). The cursor width must be a multiple of 8 bits.\n"
	"\n"
	"The cursor is created in black and white according to the following:\n"
	"\n"
	"  Data / Mask Resulting pixel on screen\n"
	"  0 / 1       White\n"
	"  1 / 1       Black\n"
	"  0 / 0       Transparent\n"
	"  1 / 0       Inverted color if possible, black if not.\n"
	);
}

Gura_ImplementFunction(CreateCursor)
{
	const Binary &data = args.GetBinary(0);
	const Binary &mask = args.GetBinary(1);
	int w = args.GetInt(2), h = args.GetInt(3);
	int hot_x = args.GetInt(4), hot_y = args.GetInt(5);
	if (w <= 0 || w % 8 != 0) {
		sig.SetError(ERR_ValueError, "width must be a multiple of eight");
		return Value::Null;
	}
	int bytesExpect = w / 8 * h;
	if (data.size() < bytesExpect) {
		sig.SetError(ERR_ValueError, "size of data is too small");
		return Value::Null;
	}
	if (mask.size() < bytesExpect) {
		sig.SetError(ERR_ValueError, "size of mask is too small");
		return Value::Null;
	}
	SDL_Cursor *pCursor = ::SDL_CreateCursor(
			const_cast<Uint8 *>(reinterpret_cast<const Uint8 *>(data.data())),
			const_cast<Uint8 *>(reinterpret_cast<const Uint8 *>(mask.data())),
			w, h, hot_x, hot_y);
	return Object_Cursor::CreateValue(pCursor);
}

// sdl.SetCursor(cursor:sdl.Cursor):void
Gura_DeclareFunction(SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor);
	AddHelp(Gura_Symbol(en),
	"Sets the currently active cursor to the specified one.\n"
	"If the cursor is currently visible, the change will be immediately represented on the display.\n"
	);
}

Gura_ImplementFunction(SetCursor)
{
	SDL_Cursor *pCursor =
			dynamic_cast<Object_Cursor *>(args.GetObject(0))->GetCursor();
	if (pCursor == NULL) {
		sig.SetError(ERR_ValueError, "invalid cursor instance");
		return Value::Null;
	}
	::SDL_SetCursor(pCursor);
	return Value::Null;
}

// sdl.GetCursor()
Gura_DeclareFunction(GetCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	"Returns the currently active mouse cursor.\n"
	);
}

Gura_ImplementFunction(GetCursor)
{
	SDL_Cursor *pCursor = ::SDL_GetCursor();
	return Object_Cursor::CreateValue(pCursor);
}

// sdl.ShowCursor(toggle:number)
Gura_DeclareFunction(ShowCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "toggle", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	"Toggle whether or not the cursor is shown on the screen.\n"
	"Passing sdl.ENABLE displays the cursor and passing sdl.DISABLE hides it.\n"
	"The current state of the mouse cursor can be queried by passing sdl.QUERY, either sdl.DISABLE or sdl.ENABLE will be returned.\n"
	"The cursor starts off displayed, but can be turned off.\n"
	"\n"
	"*Return Value* Returns the current state of the cursor.\n"
	);
}

Gura_ImplementFunction(ShowCursor)
{
	return Value(::SDL_ShowCursor(args.GetInt(0)));
}

// sdl.GL_GetAttribute(attr:number)
Gura_DeclareFunction(GL_GetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GL_GetAttribute)
{
	int value;
	int rtn = ::SDL_GL_GetAttribute(
				static_cast<SDL_GLattr>(args.GetInt(0)), &value);
	if (rtn < 0) return Value::Null;
	return Value(value);
}

// sdl.GL_SetAttribute(attr:number, value:number)
Gura_DeclareFunction(GL_SetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GL_SetAttribute)
{
	int rtn = ::SDL_GL_SetAttribute(
				static_cast<SDL_GLattr>(args.GetInt(0)), args.GetInt(1));
	return Value(rtn);
}

// sdl.GL_SwapBuffers():void
Gura_DeclareFunction(GL_SwapBuffers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GL_SwapBuffers)
{
	::SDL_GL_SwapBuffers();
	return Value::Null;
}

// sdl.CreateYUVOverlay()
Gura_DeclareFunction(CreateYUVOverlay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "display", VTYPE_Surface);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CreateYUVOverlay)
{
	SDL_Surface *pSurface =
		dynamic_cast<Object_Surface *>(args.GetObject(3))->GetSurface();
	SDL_Overlay *pOverlay = ::SDL_CreateYUVOverlay(
			args.GetInt(0), args.GetInt(1), args.GetULong(2), pSurface);
	if (pOverlay == NULL) return Value::Null;
	return Object_Overlay::CreateValue(pOverlay);
}

//-----------------------------------------------------------------------------
// SDL functions: Window Management
//-----------------------------------------------------------------------------
// sdl.WM_SetCaption(title:string, icon:string):void
Gura_DeclareFunction(WM_SetCaption)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "title", VTYPE_string);
	DeclareArg(env, "icon", VTYPE_string);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_SetCaption)
{
	::SDL_WM_SetCaption(args.GetString(0), args.GetString(1));
	return Value::Null;
}

// sdl.WM_GetCaption()
Gura_DeclareFunction(WM_GetCaption)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_GetCaption)
{
	char *title = NULL, *icon = NULL;
	::SDL_WM_GetCaption(&title, &icon);
	Value valTitle, valIcon;
	if (title != NULL) valTitle = Value(env, title);
	if (icon != NULL) valIcon = Value(env, icon);
	return Value::CreateAsList(env, valTitle, valIcon);
}

// sdl.WM_SetIcon(icon:sdl.Surface, mask?:binary)
Gura_DeclareFunction(WM_SetIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface);
	DeclareArg(env, "mask", VTYPE_binary, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_SetIcon)
{
	SDL_Surface *pSurface = dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	const char *mask = args.IsBinary(1)? args.GetBinary(1).data() : NULL;
	::SDL_WM_SetIcon(pSurface,
				const_cast<Uint8 *>(reinterpret_cast<const Uint8 *>(mask)));
	return Value::Null;
}

// sdl.WM_IconifyWindow()
Gura_DeclareFunction(WM_IconifyWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_IconifyWindow)
{
	return Value(::SDL_WM_IconifyWindow());
}

// sdl.WM_ToggleFullScreen(surface:sdl.Surface)
Gura_DeclareFunction(WM_ToggleFullScreen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_ToggleFullScreen)
{
	SDL_Surface *pSurface = dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	return Value(::SDL_WM_ToggleFullScreen(pSurface));
}

// sdl.WM_GrabInput(mode:number)
Gura_DeclareFunction(WM_GrabInput)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WM_GrabInput)
{
	SDL_GrabMode mode = static_cast<SDL_GrabMode>(args.GetInt(0));
	return Value(static_cast<int>(::SDL_WM_GrabInput(mode)));
}

//-----------------------------------------------------------------------------
// SDL functions: Events
//-----------------------------------------------------------------------------
// sdl.PumpEvents():void
Gura_DeclareFunction(PumpEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(PumpEvents)
{
	::SDL_PumpEvents();
	return Value::Null;
}

// sdl.AddEvents(events[]:Event, mask:number)
Gura_DeclareFunction(AddEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "events", VTYPE_Event, OCCUR_Once, FLAG_List);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(AddEvents)
{
	int numevents = static_cast<int>(args.GetList(0).size());
	Uint32 mask = args.GetULong(1);
	int i = 0;
	SDL_Event *events = new SDL_Event[numevents];
	foreach_const (ValueList, pValue, args.GetList(0)) {
		events[i++] =
				dynamic_cast<const Object_Event *>(pValue->GetObject())->GetEvent();
	}
	int rtn = ::SDL_PeepEvents(events, numevents, SDL_ADDEVENT, mask);
	delete[] events;
	return Value(rtn);
}

// sdl.PeekEvents(numevents:number, mask:number)
Gura_DeclareFunction(PeekEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numevents", VTYPE_number);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(PeekEvents)
{
	int numevents = args.GetInt(0);
	Uint32 mask = args.GetULong(1);
	SDL_Event *events = new SDL_Event[numevents];
	int rtn = ::SDL_PeepEvents(events, numevents, SDL_PEEKEVENT, mask);
	if (rtn < 0) {
		delete[] events;
		return Value::Null;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	for (int i = 0; i < numevents; i++) {
		valList.push_back(Object_Event::CreateValue(events[i]));
	}
	delete[] events;
	return result;
}

// sdl.GetEvents(numevents:number, mask:number)
Gura_DeclareFunction(GetEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numevents", VTYPE_number);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetEvents)
{
	int numevents = args.GetInt(0);
	Uint32 mask = args.GetULong(1);
	SDL_Event *events = new SDL_Event[numevents];
	int rtn = ::SDL_PeepEvents(events, numevents, SDL_GETEVENT, mask);
	if (rtn < 0) {
		delete[] events;
		return Value::Null;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	for (int i = 0; i < numevents; i++) {
		valList.push_back(Object_Event::CreateValue(events[i]));
	}
	delete[] events;
	return result;
}

// sdl.PollEvent()
Gura_DeclareFunction(PollEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(PollEvent)
{
	SDL_Event event;
	if (::SDL_PollEvent(&event) == 0) return Value::Null;
	if (event.type == SDL_USEREVENT_Timer) {
		Object_Timer *pObjTimer = reinterpret_cast<Object_Timer *>(event.user.data1);
		pObjTimer->DoHandle();
		Object::Delete(pObjTimer);
		return Value::Null;
	}
	return Object_Event::CreateValue(event);
}

// sdl.WaitEvent()
Gura_DeclareFunction(WaitEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(WaitEvent)
{
	SDL_Event event;
	for (;;) {
		if (::SDL_WaitEvent(&event) == 0) return Value::Null;
		if (event.type == SDL_USEREVENT_Timer) {
			Object_Timer *pObjTimer = reinterpret_cast<Object_Timer *>(event.user.data1);
			pObjTimer->DoHandle();
			Object::Delete(pObjTimer);
		} else {
			break;
		}
	}
	return Object_Event::CreateValue(event);
}

// sdl.PushEvent(event:Event)
Gura_DeclareFunction(PushEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "event", VTYPE_Event);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(PushEvent)
{
	SDL_Event *event = &dynamic_cast<Object_Event *>(args.GetObject(0))->GetEvent();
	return Value(::SDL_PushEvent(event));
}

// sdl.SetEventFilter(filter:function)
static Function *_pFuncEventFilter = NULL;
static int EventFilter(const SDL_Event *event)
{
	if (_pFuncEventFilter == NULL) return 1;
	Signal sig;
	Environment &env = _pFuncEventFilter->GetEnvScope();
	ValueList valList;
	valList.push_back(Object_Event::CreateValue(*event));
	Args args(valList);
	Value result = _pFuncEventFilter->Eval(env, sig, args);
	if (sig.IsSignalled()) return 0;
	return result.GetBoolean()? 1 : 0;
}

Gura_DeclareFunction(SetEventFilter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filter", VTYPE_function);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(SetEventFilter)
{
	Function::Delete(_pFuncEventFilter);
	_pFuncEventFilter = Function::Reference(args.GetFunction(0));
	::SDL_SetEventFilter(EventFilter);
	return Value::Null;
}

// sdl.GetEventFilter()
Gura_DeclareFunction(GetEventFilter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetEventFilter)
{
	if (_pFuncEventFilter == NULL) return Value::Null;
	return Value(env, _pFuncEventFilter, Value::Null);
}

// sdl.EventState(type:number, state:number)
Gura_DeclareFunction(EventState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_number);
	DeclareArg(env, "state", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(EventState)
{
	return Value(::SDL_EventState(args.GetUChar(0), args.GetInt(1)));
}

// sdl.CheckKeyState(key:number):map
Gura_DeclareFunction(CheckKeyState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CheckKeyState)
{
	int key = args.GetInt(0);
	int numkeys = 0;
	Uint8 *keystate = ::SDL_GetKeyState(&numkeys);
	return Value(0 <= key && key < numkeys && keystate[key] != 0);
}

// sdl.GetModState()
Gura_DeclareFunction(GetModState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetModState)
{
	return Value(static_cast<int>(::SDL_GetModState()));
}

// sdl.SetModState(modstate:number):void
Gura_DeclareFunction(SetModState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modstate", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(SetModState)
{
	::SDL_SetModState(static_cast<SDLMod>(args.GetInt(0)));
	return Value::Null;
}

// sdl.GetKeyName(key:number)
Gura_DeclareFunction(GetKeyName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetKeyName)
{
	return Value(env, ::SDL_GetKeyName(static_cast<SDLKey>(args.GetInt(0))));
}

// sdl.EnableUNICODE(enable:number)
Gura_DeclareFunction(EnableUNICODE)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "enable", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(EnableUNICODE)
{
	return Value(::SDL_EnableUNICODE(args.GetInt(0)));
}

// sdl.EnableKeyRepeat(delay:number, interval:number)
Gura_DeclareFunction(EnableKeyRepeat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "delay", VTYPE_number);
	DeclareArg(env, "interval", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(EnableKeyRepeat)
{
	return Value(::SDL_EnableKeyRepeat(args.GetInt(0), args.GetInt(1)));
}

// sdl.GetMouseState()
Gura_DeclareFunction(GetMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetMouseState)
{
	int x, y;
	Uint8 state = ::SDL_GetMouseState(&x, &y);
	return Value::CreateAsList(env, Value(state), Value(x), Value(y));
}

// sdl.GetRelativeMouseState()
Gura_DeclareFunction(GetRelativeMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetRelativeMouseState)
{
	int x, y;
	Uint8 state = ::SDL_GetRelativeMouseState(&x, &y);
	return Value::CreateAsList(env, Value(state), Value(x), Value(y));
}

// sdl.GetAppState()
Gura_DeclareFunction(GetAppState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetAppState)
{
	return Value(::SDL_GetAppState());
}

// sdl.JoystickEventState(state:number)
Gura_DeclareFunction(JoystickEventState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "state", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(JoystickEventState)
{
	return Value(::SDL_JoystickEventState(args.GetInt(0)));
}

//-----------------------------------------------------------------------------
// SDL functions: Joystick
//-----------------------------------------------------------------------------
// sdl.NumJoysticks()
Gura_DeclareFunction(NumJoysticks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(NumJoysticks)
{
	return Value(::SDL_NumJoysticks());
}

// sdl.JoystickName(index:number):map
Gura_DeclareFunction(JoystickName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(JoystickName)
{
	return Value(env, ::SDL_JoystickName(args.GetInt(0)));
}

// sdl.JoystickOpen(index:number):map
Gura_DeclareFunction(JoystickOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(JoystickOpen)
{
	SDL_Joystick *pJoystick = ::SDL_JoystickOpen(args.GetInt(0));
	if (pJoystick == NULL) return Value::Null;
	return Object_Joystick::CreateValue(pJoystick);
}

// sdl.JoystickOpened(index:number):map
Gura_DeclareFunction(JoystickOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(JoystickOpened)
{
	return Value(::SDL_JoystickOpened(args.GetInt(0))? true : false);
}

// sdl.JoystickUpdate():void
Gura_DeclareFunction(JoystickUpdate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(JoystickUpdate)
{
	::SDL_JoystickUpdate();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// SDL functions: Audio
//-----------------------------------------------------------------------------
// sdl.OpenAudio(desired:AudioSpec)
Gura_DeclareFunction(OpenAudio)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "desired", VTYPE_AudioSpec);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(OpenAudio)
{
	SDL_AudioSpec *desired =
		dynamic_cast<Object_AudioSpec *>(args.GetObject(0))->GetAudioSpec();
	SDL_AudioSpec *obtained =
		reinterpret_cast<SDL_AudioSpec *>(::malloc(sizeof(SDL_AudioSpec)));
	if (::SDL_OpenAudio(desired, obtained) < 0) {
		sig.SetError(ERR_RuntimeError, "failed to open audio device");
		::free(obtained);
		return Value::Null;
	}
	return Object_AudioSpec::CreateValue(obtained, sig, NULL, NULL, 0);
}

// sdl.PauseAudio(pause_on:number):void
Gura_DeclareFunction(PauseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(PauseAudio)
{
	::SDL_PauseAudio(args.GetInt(0));
	return Value::Null;
}

// sdl.GetAudioStatus()
Gura_DeclareFunction(GetAudioStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetAudioStatus)
{
	return Value(static_cast<int>(::SDL_GetAudioStatus()));
}

// sdl.LoadWAV(file:string)
Gura_DeclareFunction(LoadWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(LoadWAV)
{
	SDL_AudioSpec *pAudioSpec =
		reinterpret_cast<SDL_AudioSpec *>(::malloc(sizeof(SDL_AudioSpec)));
	Uint8 *audio_buf = NULL;
	Uint32 audio_len = 0;
	if (::SDL_LoadWAV(args.GetString(0), pAudioSpec, &audio_buf, &audio_len) == NULL) {
		sig.SetError(ERR_RuntimeError, "failed to load WAV data");
		return Value::Null;
	}
	pAudioSpec->callback = Object_AudioSpec::CallbackStub;
	pAudioSpec->userdata = NULL;
	return Object_AudioSpec::CreateValue(pAudioSpec, sig, NULL, audio_buf, audio_len);
}

// sdl.BuildAudioCVT(src_format:number, src_channels:number, src_rate:number,
//                   dst_format:number, dst_channels:number, dst_rate:number)
Gura_DeclareFunction(BuildAudioCVT)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number);
	DeclareArg(env, "src_channels", VTYPE_number);
	DeclareArg(env, "src_rate", VTYPE_number);
	DeclareArg(env, "dst_format", VTYPE_number);
	DeclareArg(env, "dst_channels", VTYPE_number);
	DeclareArg(env, "dst_rate", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(BuildAudioCVT)
{
	SDL_AudioCVT *cvt =
			reinterpret_cast<SDL_AudioCVT *>(::malloc(sizeof(SDL_AudioCVT)));
	Uint16 src_format = args.GetUShort(0);
	Uint8 src_channels = args.GetUChar(1);
	int src_rate = args.GetInt(2);
	Uint16 dst_format = args.GetUShort(3);
	Uint8 dst_channels = args.GetUChar(4);
	int dst_rate = args.GetInt(5);
	int rtn = ::SDL_BuildAudioCVT(cvt, src_format, src_channels, src_rate,
									dst_format, dst_channels, dst_rate);
	if (rtn < 0) return Value::Null;
	return Object_AudioCVT::CreateValue(cvt);
}

// sdl.LockAudio():void
Gura_DeclareFunction(LockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(LockAudio)
{
	::SDL_LockAudio();
	return Value::Null;
}

// sdl.UnlockAudio():void
Gura_DeclareFunction(UnlockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(UnlockAudio)
{
	::SDL_LockAudio();
	return Value::Null;
}

// sdl.CloseAudio():void
Gura_DeclareFunction(CloseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CloseAudio)
{
	::SDL_LockAudio();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// SDL functions: CD-ROM
//-----------------------------------------------------------------------------
// sdl.CDNumDrives()
Gura_DeclareFunction(CDNumDrives)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CDNumDrives)
{
	return Value(::SDL_CDNumDrives());
}

// sdl.CDName(drive:number):map
Gura_DeclareFunction(CDName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "drive", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CDName)
{
	return Value(env, ::SDL_CDName(args.GetInt(0)));
}

// sdl.CDOpen(drive:number)
Gura_DeclareFunction(CDOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "drive", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(CDOpen)
{
	SDL_CD *pCD = ::SDL_CDOpen(args.GetInt(0));
	if (pCD == NULL) {
		sig.SetError(ERR_IOError, "can't open CD drive #%d", args.GetInt(0));
		return Value::Null;
	}
	return Object_CD::CreateValue(pCD);
}

//-----------------------------------------------------------------------------
// SDL functions: Multi-threaded Programming
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SDL functions: Time
//-----------------------------------------------------------------------------
// sdl.GetTicks()
Gura_DeclareFunction(GetTicks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(GetTicks)
{
	return Value(::SDL_GetTicks());
}

// sdl.Delay(ms:number):void
Gura_DeclareFunction(Delay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "ms", VTYPE_number);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(Delay)
{
	::SDL_Delay(args.GetULong(0));
	return Value::Null;
}

// sdl.AddTimer(interval:number, callback?:function):[thread] {block?}
Gura_DeclareFunction(AddTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number);
	DeclareArg(env, "callback", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(thread_));
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(AddTimer)
{
	Object_function *pObjFunc;
	if (args.IsFunction(1)) {
		pObjFunc = Object_function::Reference(Object_function::GetObject(args, 1));
	} else if (args.IsBlockSpecified()) {
		const Function *pFunc = args.GetBlockFunc(env, sig, GetSymbolForBlock());
		if (sig.IsSignalled()) return Value::Null;
		pObjFunc = new Object_function(env, Function::Reference(pFunc), Value::Null);
	} else {
		sig.SetError(ERR_ValueError, "function or block must be specified");
		return Value::Null;
	}
	bool threadFlag = args.IsSet(Gura_UserSymbol(thread_));
	Object_Timer *pObj = new Object_Timer(sig, pObjFunc, threadFlag);
	pObj->AddTimer(args.GetULong(0));
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Object constructors
//-----------------------------------------------------------------------------
// sdl.Rect(x:number, y:number, w:number, h:number):map {block?}
Gura_DeclareFunction(Rect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(Rect)
{
	SDL_Rect rect;
	rect.x = args.GetInt(0);
	rect.y = args.GetInt(1);
	rect.w = args.GetInt(2);
	rect.h = args.GetInt(3);
	return ReturnValue(env, sig, args, Object_Rect::CreateValue(rect));
}

// sdl.Color(r:number, g:number, b:number):map {block?}
Gura_DeclareFunction(Color)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Color));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(Color)
{
	SDL_Color color;
	color.r = args.GetUChar(0);
	color.g = args.GetUChar(1);
	color.b = args.GetUChar(2);
	color.unused = 0;
	return ReturnValue(env, sig, args, Object_Color::CreateValue(color));
}

// sdl.AudioSpec(freq:number => 22050, format:number => AUDIO_S16,
//     channels:number => 1, samples:number => 8192, callback?:function) {block?}
Gura_DeclareFunction(AudioSpec)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "freq",		VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(22050));
	DeclareArg(env, "format",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(AUDIO_S16));
	DeclareArg(env, "channels",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(1));
	DeclareArg(env, "samples",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(8192));
	DeclareArg(env, "callback",	VTYPE_function, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), 
	"It passes an audio object to the callback that is supposed to fill it\n"
	"with audio data.");
	SetClassToConstruct(Gura_UserClass(AudioSpec));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(AudioSpec)
{
	SDL_AudioSpec *pAudioSpec =
			reinterpret_cast<SDL_AudioSpec *>(::malloc(sizeof(SDL_AudioSpec)));
	::memset(pAudioSpec, 0, sizeof(SDL_AudioSpec));
	pAudioSpec->freq		= args.GetInt(0);
	pAudioSpec->format		= args.GetUShort(1);
	pAudioSpec->channels	= args.GetUChar(2);
	pAudioSpec->samples		= args.GetUShort(3);
	pAudioSpec->callback	= Object_AudioSpec::CallbackStub;
	pAudioSpec->userdata	= NULL;
	Function *pFuncCallback = NULL;
	if (args.IsFunction(4)) {
		pFuncCallback = Function::Reference(args.GetFunction(4));
	}
	Object_AudioSpec *pObj =
			new Object_AudioSpec(pAudioSpec, sig, pFuncCallback, NULL, 0);
	pAudioSpec->userdata = pObj;
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// SDL functions
//-----------------------------------------------------------------------------
// sdl.test()
void callback(void *userdata, Uint8 *stream, int len)
{
	SDL_AudioSpec &specObtained = *reinterpret_cast<SDL_AudioSpec *>(userdata);
	Uint8 *p = stream;
	for (int i = 0; i < len / 2; i++, p += 2) {
		UShort num = static_cast<UShort>(
							::sin(6.28 * i * 400 / specObtained.freq) * 3000);
		*(p + 0) = static_cast<UChar>(num);
		*(p + 1) = static_cast<UChar>(num >> 8);
	}
}

Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(test)
{
	SDL_AudioSpec specDesired;
	SDL_AudioSpec specObtained;
	specDesired.freq		= 22050;
	specDesired.format		= AUDIO_S16LSB;
	specDesired.channels	= 0;
	specDesired.samples		= 8192;
	specDesired.callback	= callback;
	specDesired.userdata	= &specObtained;
	::SDL_Init(SDL_INIT_AUDIO);
	::SDL_OpenAudio(&specDesired, &specObtained);
	::SDL_PauseAudio(0);
	//::SDL_Delay(1000);
	OAL::Sleep(1);
	::SDL_Quit();
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// symbols in SDL_Event
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(gain);
	Gura_RealizeUserSymbol(state);
	Gura_RealizeUserSymbol(scancode);
	Gura_RealizeUserSymbol(sym);
	Gura_RealizeUserSymbol(mod);
	Gura_RealizeUserSymbol(unicode);
	Gura_RealizeUserSymbol(x);
	Gura_RealizeUserSymbol(y);
	Gura_RealizeUserSymbol(xrel);
	Gura_RealizeUserSymbol(yrel);
	Gura_RealizeUserSymbol(axis);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(button);
	Gura_RealizeUserSymbol(which);
	Gura_RealizeUserSymbol(hat);
	Gura_RealizeUserSymbol(ball);
	Gura_RealizeUserSymbol(w);
	Gura_RealizeUserSymbol(h);
	// symbols in SDL_Color
	Gura_RealizeUserSymbol(r)
	Gura_RealizeUserSymbol(g)
	Gura_RealizeUserSymbol(b)
	// symbols in SDL_PixelFormat
	Gura_RealizeUserSymbol(palette);
	Gura_RealizeUserSymbol(BitsPerPixel);
	Gura_RealizeUserSymbol(BytesPerPixel);
	Gura_RealizeUserSymbol(Rloss);
	Gura_RealizeUserSymbol(Gloss);
	Gura_RealizeUserSymbol(Bloss);
	Gura_RealizeUserSymbol(Aloss);
	Gura_RealizeUserSymbol(Rshift);
	Gura_RealizeUserSymbol(Gshift);
	Gura_RealizeUserSymbol(Bshift);
	Gura_RealizeUserSymbol(Ashift);
	Gura_RealizeUserSymbol(Rmask);
	Gura_RealizeUserSymbol(Gmask);
	Gura_RealizeUserSymbol(Bmask);
	Gura_RealizeUserSymbol(Amask);
	Gura_RealizeUserSymbol(colorkey);
	Gura_RealizeUserSymbol(alpha);
	// symbols in SDL_Surface
	Gura_RealizeUserSymbol(flags)
	Gura_RealizeUserSymbol(format)
	Gura_RealizeUserSymbol(pitch)
	Gura_RealizeUserSymbol(pixels)
	Gura_RealizeUserSymbol(clip_rect)
	Gura_RealizeUserSymbol(refcount)
	// symbols in SDL_VideoInfo
	Gura_RealizeUserSymbol(hw_available);
	Gura_RealizeUserSymbol(wm_available);
	Gura_RealizeUserSymbol(blit_hw);
	Gura_RealizeUserSymbol(blit_hw_CC);
	Gura_RealizeUserSymbol(blit_hw_A);
	Gura_RealizeUserSymbol(blit_sw);
	Gura_RealizeUserSymbol(blit_sw_CC);
	Gura_RealizeUserSymbol(blit_sw_A);
	Gura_RealizeUserSymbol(blit_fill);
	Gura_RealizeUserSymbol(video_mem);
	Gura_RealizeUserSymbol(vfmt);
	// symbols in SDL_CDtrack
	Gura_RealizeUserSymbol(id)
	Gura_RealizeUserSymbol(length)
	Gura_RealizeUserSymbol(offset)
	// symbols in SDL_CD
	Gura_RealizeUserSymbol(status)
	Gura_RealizeUserSymbol(numtracks)
	Gura_RealizeUserSymbol(cur_track)
	Gura_RealizeUserSymbol(cur_frame)
	// symbols for other purposes
	Gura_RealizeUserSymbolAlias(thread_, "thread")
	// class realization
	Gura_RealizeUserClass(Cursor,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Timer,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Event,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Rect,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Color,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Palette,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(PixelFormat,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Surface,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Overlay,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(VideoInfo,	env.LookupClass(VTYPE_object));
	//Gura_RealizeUserClass(Font,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Joystick,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(AudioSpec,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(AudioCVT,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(CDtrack,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(CD,			env.LookupClass(VTYPE_object));
	// value assignment
	Gura_AssignValue(ACTIVEEVENT,		Value(SDL_ACTIVEEVENT));
	Gura_AssignValue(KEYDOWN,			Value(SDL_KEYDOWN));
	Gura_AssignValue(KEYUP,				Value(SDL_KEYUP));
	Gura_AssignValue(MOUSEMOTION,		Value(SDL_MOUSEMOTION));
	Gura_AssignValue(MOUSEBUTTONDOWN,	Value(SDL_MOUSEBUTTONDOWN));
	Gura_AssignValue(MOUSEBUTTONUP,		Value(SDL_MOUSEBUTTONUP));
	Gura_AssignValue(JOYAXISMOTION,		Value(SDL_JOYAXISMOTION));
	Gura_AssignValue(JOYBALLMOTION,		Value(SDL_JOYBALLMOTION));
	Gura_AssignValue(JOYHATMOTION,		Value(SDL_JOYHATMOTION));
	Gura_AssignValue(JOYBUTTONDOWN,		Value(SDL_JOYBUTTONDOWN));
	Gura_AssignValue(JOYBUTTONUP,		Value(SDL_JOYBUTTONUP));
	Gura_AssignValue(QUIT,				Value(SDL_QUIT));
	Gura_AssignValue(SYSWMEVENT,		Value(SDL_SYSWMEVENT));
	Gura_AssignValue(VIDEORESIZE,		Value(SDL_VIDEORESIZE));
	Gura_AssignValue(VIDEOEXPOSE,		Value(SDL_VIDEOEXPOSE));
	Gura_AssignValue(USEREVENT,			Value(SDL_USEREVENT));
	Gura_AssignValue(INIT_TIMER,		Value(SDL_INIT_TIMER));
	Gura_AssignValue(INIT_AUDIO,		Value(SDL_INIT_AUDIO));
	Gura_AssignValue(INIT_VIDEO,		Value(SDL_INIT_VIDEO));
	Gura_AssignValue(INIT_CDROM,		Value(SDL_INIT_CDROM));
	Gura_AssignValue(INIT_JOYSTICK,		Value(SDL_INIT_JOYSTICK));
	Gura_AssignValue(INIT_EVERYTHING,	Value(SDL_INIT_EVERYTHING));
	Gura_AssignValue(INIT_NOPARACHUTE,	Value(SDL_INIT_NOPARACHUTE));
	Gura_AssignValue(INIT_EVENTTHREAD,	Value(SDL_INIT_EVENTTHREAD));
	Gura_AssignValue(SWSURFACE,			Value(SDL_SWSURFACE));
	Gura_AssignValue(HWSURFACE,			Value(SDL_HWSURFACE));
	Gura_AssignValue(ASYNCBLIT,			Value(SDL_ASYNCBLIT));
	Gura_AssignValue(ANYFORMAT,			Value(SDL_ANYFORMAT));
	Gura_AssignValue(HWPALETTE,			Value(SDL_HWPALETTE));
	Gura_AssignValue(DOUBLEBUF,			Value(SDL_DOUBLEBUF));
	Gura_AssignValue(FULLSCREEN,		Value(SDL_FULLSCREEN));
	Gura_AssignValue(OPENGL,			Value(SDL_OPENGL));
	Gura_AssignValue(OPENGLBLIT,		Value(SDL_OPENGLBLIT));
	Gura_AssignValue(RESIZABLE,			Value(SDL_RESIZABLE));
	Gura_AssignValue(NOFRAME,			Value(SDL_NOFRAME));
	Gura_AssignValue(SRCCOLORKEY,		Value(SDL_SRCCOLORKEY));
	Gura_AssignValue(SRCALPHA,			Value(SDL_SRCALPHA));
	Gura_AssignValue(RLEACCEL,			Value(SDL_RLEACCEL));
	Gura_AssignValue(GRAB_QUERY,		Value(SDL_GRAB_QUERY));
	Gura_AssignValue(GRAB_OFF,			Value(SDL_GRAB_OFF));
	Gura_AssignValue(GRAB_ON,			Value(SDL_GRAB_ON));
	Gura_AssignValue(K_BACKSPACE,		Value(SDLK_BACKSPACE));
	Gura_AssignValue(K_TAB,				Value(SDLK_TAB));
	Gura_AssignValue(K_CLEAR,			Value(SDLK_CLEAR));
	Gura_AssignValue(K_RETURN,			Value(SDLK_RETURN));
	Gura_AssignValue(K_PAUSE,			Value(SDLK_PAUSE));
	Gura_AssignValue(K_ESCAPE,			Value(SDLK_ESCAPE));
	Gura_AssignValue(K_SPACE,			Value(SDLK_SPACE));
	Gura_AssignValue(K_EXCLAIM,			Value(SDLK_EXCLAIM));
	Gura_AssignValue(K_QUOTEDBL,		Value(SDLK_QUOTEDBL));
	Gura_AssignValue(K_HASH,			Value(SDLK_HASH));
	Gura_AssignValue(K_DOLLAR,			Value(SDLK_DOLLAR));
	Gura_AssignValue(K_AMPERSAND,		Value(SDLK_AMPERSAND));
	Gura_AssignValue(K_QUOTE,			Value(SDLK_QUOTE));
	Gura_AssignValue(K_LEFTPAREN,		Value(SDLK_LEFTPAREN));
	Gura_AssignValue(K_RIGHTPAREN,		Value(SDLK_RIGHTPAREN));
	Gura_AssignValue(K_ASTERISK,		Value(SDLK_ASTERISK));
	Gura_AssignValue(K_PLUS,			Value(SDLK_PLUS));
	Gura_AssignValue(K_COMMA,			Value(SDLK_COMMA));
	Gura_AssignValue(K_MINUS,			Value(SDLK_MINUS));
	Gura_AssignValue(K_PERIOD,			Value(SDLK_PERIOD));
	Gura_AssignValue(K_SLASH,			Value(SDLK_SLASH));
	Gura_AssignValue(K_0,				Value(SDLK_0));
	Gura_AssignValue(K_1,				Value(SDLK_1));
	Gura_AssignValue(K_2,				Value(SDLK_2));
	Gura_AssignValue(K_3,				Value(SDLK_3));
	Gura_AssignValue(K_4,				Value(SDLK_4));
	Gura_AssignValue(K_5,				Value(SDLK_5));
	Gura_AssignValue(K_6,				Value(SDLK_6));
	Gura_AssignValue(K_7,				Value(SDLK_7));
	Gura_AssignValue(K_8,				Value(SDLK_8));
	Gura_AssignValue(K_9,				Value(SDLK_9));
	Gura_AssignValue(K_COLON,			Value(SDLK_COLON));
	Gura_AssignValue(K_SEMICOLON,		Value(SDLK_SEMICOLON));
	Gura_AssignValue(K_LESS,			Value(SDLK_LESS));
	Gura_AssignValue(K_EQUALS,			Value(SDLK_EQUALS));
	Gura_AssignValue(K_GREATER,			Value(SDLK_GREATER));
	Gura_AssignValue(K_QUESTION,		Value(SDLK_QUESTION));
	Gura_AssignValue(K_AT,				Value(SDLK_AT));
	Gura_AssignValue(K_LEFTBRACKET,		Value(SDLK_LEFTBRACKET));
	Gura_AssignValue(K_BACKSLASH,		Value(SDLK_BACKSLASH));
	Gura_AssignValue(K_RIGHTBRACKET,	Value(SDLK_RIGHTBRACKET));
	Gura_AssignValue(K_CARET,			Value(SDLK_CARET));
	Gura_AssignValue(K_UNDERSCORE,		Value(SDLK_UNDERSCORE));
	Gura_AssignValue(K_BACKQUOTE,		Value(SDLK_BACKQUOTE));
	Gura_AssignValue(K_a,				Value(SDLK_a));
	Gura_AssignValue(K_b,				Value(SDLK_b));
	Gura_AssignValue(K_c,				Value(SDLK_c));
	Gura_AssignValue(K_d,				Value(SDLK_d));
	Gura_AssignValue(K_e,				Value(SDLK_e));
	Gura_AssignValue(K_f,				Value(SDLK_f));
	Gura_AssignValue(K_g,				Value(SDLK_g));
	Gura_AssignValue(K_h,				Value(SDLK_h));
	Gura_AssignValue(K_i,				Value(SDLK_i));
	Gura_AssignValue(K_j,				Value(SDLK_j));
	Gura_AssignValue(K_k,				Value(SDLK_k));
	Gura_AssignValue(K_l,				Value(SDLK_l));
	Gura_AssignValue(K_m,				Value(SDLK_m));
	Gura_AssignValue(K_n,				Value(SDLK_n));
	Gura_AssignValue(K_o,				Value(SDLK_o));
	Gura_AssignValue(K_p,				Value(SDLK_p));
	Gura_AssignValue(K_q,				Value(SDLK_q));
	Gura_AssignValue(K_r,				Value(SDLK_r));
	Gura_AssignValue(K_s,				Value(SDLK_s));
	Gura_AssignValue(K_t,				Value(SDLK_t));
	Gura_AssignValue(K_u,				Value(SDLK_u));
	Gura_AssignValue(K_v,				Value(SDLK_v));
	Gura_AssignValue(K_w,				Value(SDLK_w));
	Gura_AssignValue(K_x,				Value(SDLK_x));
	Gura_AssignValue(K_y,				Value(SDLK_y));
	Gura_AssignValue(K_z,				Value(SDLK_z));
	Gura_AssignValue(K_DELETE,			Value(SDLK_DELETE));
	Gura_AssignValue(K_KP0,				Value(SDLK_KP0));
	Gura_AssignValue(K_KP1,				Value(SDLK_KP1));
	Gura_AssignValue(K_KP2,				Value(SDLK_KP2));
	Gura_AssignValue(K_KP3,				Value(SDLK_KP3));
	Gura_AssignValue(K_KP4,				Value(SDLK_KP4));
	Gura_AssignValue(K_KP5,				Value(SDLK_KP5));
	Gura_AssignValue(K_KP6,				Value(SDLK_KP6));
	Gura_AssignValue(K_KP7,				Value(SDLK_KP7));
	Gura_AssignValue(K_KP8,				Value(SDLK_KP8));
	Gura_AssignValue(K_KP9,				Value(SDLK_KP9));
	Gura_AssignValue(K_KP_PERIOD,		Value(SDLK_KP_PERIOD));
	Gura_AssignValue(K_KP_DIVIDE,		Value(SDLK_KP_DIVIDE));
	Gura_AssignValue(K_KP_MULTIPLY,		Value(SDLK_KP_MULTIPLY));
	Gura_AssignValue(K_KP_MINUS,		Value(SDLK_KP_MINUS));
	Gura_AssignValue(K_KP_PLUS,			Value(SDLK_KP_PLUS));
	Gura_AssignValue(K_KP_ENTER,		Value(SDLK_KP_ENTER));
	Gura_AssignValue(K_KP_EQUALS,		Value(SDLK_KP_EQUALS));
	Gura_AssignValue(K_UP,				Value(SDLK_UP));
	Gura_AssignValue(K_DOWN,			Value(SDLK_DOWN));
	Gura_AssignValue(K_RIGHT,			Value(SDLK_RIGHT));
	Gura_AssignValue(K_LEFT,			Value(SDLK_LEFT));
	Gura_AssignValue(K_INSERT,			Value(SDLK_INSERT));
	Gura_AssignValue(K_HOME,			Value(SDLK_HOME));
	Gura_AssignValue(K_END,				Value(SDLK_END));
	Gura_AssignValue(K_PAGEUP,			Value(SDLK_PAGEUP));
	Gura_AssignValue(K_PAGEDOWN,		Value(SDLK_PAGEDOWN));
	Gura_AssignValue(K_F1,				Value(SDLK_F1));
	Gura_AssignValue(K_F2,				Value(SDLK_F2));
	Gura_AssignValue(K_F3,				Value(SDLK_F3));
	Gura_AssignValue(K_F4,				Value(SDLK_F4));
	Gura_AssignValue(K_F5,				Value(SDLK_F5));
	Gura_AssignValue(K_F6,				Value(SDLK_F6));
	Gura_AssignValue(K_F7,				Value(SDLK_F7));
	Gura_AssignValue(K_F8,				Value(SDLK_F8));
	Gura_AssignValue(K_F9,				Value(SDLK_F9));
	Gura_AssignValue(K_F10,				Value(SDLK_F10));
	Gura_AssignValue(K_F11,				Value(SDLK_F11));
	Gura_AssignValue(K_F12,				Value(SDLK_F12));
	Gura_AssignValue(K_F13,				Value(SDLK_F13));
	Gura_AssignValue(K_F14,				Value(SDLK_F14));
	Gura_AssignValue(K_F15,				Value(SDLK_F15));
	Gura_AssignValue(K_NUMLOCK,			Value(SDLK_NUMLOCK));
	Gura_AssignValue(K_CAPSLOCK,		Value(SDLK_CAPSLOCK));
	Gura_AssignValue(K_SCROLLOCK,		Value(SDLK_SCROLLOCK));
	Gura_AssignValue(K_RSHIFT,			Value(SDLK_RSHIFT));
	Gura_AssignValue(K_LSHIFT,			Value(SDLK_LSHIFT));
	Gura_AssignValue(K_RCTRL,			Value(SDLK_RCTRL));
	Gura_AssignValue(K_LCTRL,			Value(SDLK_LCTRL));
	Gura_AssignValue(K_RALT,			Value(SDLK_RALT));
	Gura_AssignValue(K_LALT,			Value(SDLK_LALT));
	Gura_AssignValue(K_RMETA,			Value(SDLK_RMETA));
	Gura_AssignValue(K_LMETA,			Value(SDLK_LMETA));
	Gura_AssignValue(K_LSUPER,			Value(SDLK_LSUPER));
	Gura_AssignValue(K_RSUPER,			Value(SDLK_RSUPER));
	Gura_AssignValue(K_MODE,			Value(SDLK_MODE));
	Gura_AssignValue(K_HELP,			Value(SDLK_HELP));
	Gura_AssignValue(K_PRINT,			Value(SDLK_PRINT));
	Gura_AssignValue(K_SYSREQ,			Value(SDLK_SYSREQ));
	Gura_AssignValue(K_BREAK,			Value(SDLK_BREAK));
	Gura_AssignValue(K_MENU,			Value(SDLK_MENU));
	Gura_AssignValue(K_POWER,			Value(SDLK_POWER));
	Gura_AssignValue(K_EURO,			Value(SDLK_EURO));
	Gura_AssignValue(KMOD_NONE,			Value(KMOD_NONE));
	Gura_AssignValue(KMOD_NUM,			Value(KMOD_NUM));
	Gura_AssignValue(KMOD_CAPS,			Value(KMOD_CAPS));
	Gura_AssignValue(KMOD_LCTRL,		Value(KMOD_LCTRL));
	Gura_AssignValue(KMOD_RCTRL,		Value(KMOD_RCTRL));
	Gura_AssignValue(KMOD_RSHIFT,		Value(KMOD_RSHIFT));
	Gura_AssignValue(KMOD_LSHIFT,		Value(KMOD_LSHIFT));
	Gura_AssignValue(KMOD_RALT,			Value(KMOD_RALT));
	Gura_AssignValue(KMOD_LALT,			Value(KMOD_LALT));
	Gura_AssignValue(KMOD_CTRL,			Value(KMOD_CTRL));
	Gura_AssignValue(KMOD_SHIFT,		Value(KMOD_SHIFT));
	Gura_AssignValue(KMOD_ALT,			Value(KMOD_ALT));
	Gura_AssignValue(APPMOUSEFOCUS,		Value(SDL_APPMOUSEFOCUS));
	Gura_AssignValue(APPINPUTFOCUS,		Value(SDL_APPINPUTFOCUS));
	Gura_AssignValue(APPACTIVE,			Value(SDL_APPACTIVE));
	Gura_AssignValue(QUERY,				Value(SDL_QUERY));
	Gura_AssignValue(ENABLE,			Value(SDL_ENABLE));
	Gura_AssignValue(IGNORE,			Value(SDL_IGNORE));
	Gura_AssignValue(AUDIO_STOPPED,		Value(SDL_AUDIO_STOPPED));
	Gura_AssignValue(AUDIO_PAUSED,		Value(SDL_AUDIO_PAUSED));
	Gura_AssignValue(AUDIO_PLAYING,		Value(SDL_AUDIO_PLAYING));
	Gura_AssignValue(AUDIO_U8,			Value(AUDIO_U8));
	Gura_AssignValue(AUDIO_S8,			Value(AUDIO_S8));
	Gura_AssignValue(AUDIO_U16,			Value(AUDIO_U16));
	Gura_AssignValue(AUDIO_U16LSB,		Value(AUDIO_U16LSB));
	Gura_AssignValue(AUDIO_S16,			Value(AUDIO_S16));
	Gura_AssignValue(AUDIO_S16LSB,		Value(AUDIO_S16LSB));
	Gura_AssignValue(AUDIO_U16MSB,		Value(AUDIO_U16MSB));
	Gura_AssignValue(AUDIO_S16MSB,		Value(AUDIO_S16MSB));
	Gura_AssignValue(AUDIO_U16SYS,		Value(AUDIO_U16SYS));
	Gura_AssignValue(AUDIO_S16SYS,		Value(AUDIO_S16SYS));
	Gura_AssignValue(CD_TRAYEMPTY,		Value(CD_TRAYEMPTY));
	Gura_AssignValue(CD_STOPPED,		Value(CD_STOPPED));
	Gura_AssignValue(CD_PLAYING,		Value(CD_PLAYING));
	Gura_AssignValue(CD_PAUSED,			Value(CD_PAUSED));
	Gura_AssignValue(CD_ERROR,			Value(CD_ERROR));
	// SDL GL Attributes
	Gura_AssignValue(GL_RED_SIZE,		Value(SDL_GL_RED_SIZE));
	Gura_AssignValue(GL_GREEN_SIZE,		Value(SDL_GL_GREEN_SIZE));
	Gura_AssignValue(GL_BLUE_SIZE,		Value(SDL_GL_BLUE_SIZE));
	Gura_AssignValue(GL_ALPHA_SIZE,		Value(SDL_GL_ALPHA_SIZE));
	Gura_AssignValue(GL_DOUBLEBUFFER,	Value(SDL_GL_DOUBLEBUFFER));
	Gura_AssignValue(GL_BUFFER_SIZE,	Value(SDL_GL_BUFFER_SIZE));
	Gura_AssignValue(GL_DEPTH_SIZE,		Value(SDL_GL_DEPTH_SIZE));
	Gura_AssignValue(GL_STENCIL_SIZE,	Value(SDL_GL_STENCIL_SIZE));
	Gura_AssignValue(GL_ACCUM_RED_SIZE,	Value(SDL_GL_ACCUM_RED_SIZE));
	Gura_AssignValue(GL_ACCUM_GREEN_SIZE,Value(SDL_GL_ACCUM_GREEN_SIZE));
	Gura_AssignValue(GL_ACCUM_BLUE_SIZE,Value(SDL_GL_ACCUM_BLUE_SIZE));
	Gura_AssignValue(GL_ACCUM_ALPHA_SIZE,Value(SDL_GL_ACCUM_ALPHA_SIZE));
	// SDL functions: General
	Gura_AssignFunction(Init);
	Gura_AssignFunction(InitSubSystem);
	Gura_AssignFunction(QuitSubSystem);
	Gura_AssignFunction(Quit);
	Gura_AssignFunction(WasInit);
	Gura_AssignFunction(GetError);
	// SDL functions: Video
	Gura_AssignFunction(GetVideoSurface);
	Gura_AssignFunction(GetVideoInfo);
	Gura_AssignFunction(VideoDriverName);
	Gura_AssignFunction(ListModes);
	Gura_AssignFunction(VideoModeOK);
	Gura_AssignFunction(SetVideoMode);
	Gura_AssignFunction(SetGamma);
	Gura_AssignFunction(GetGammaRamp);
	Gura_AssignFunction(SetGammaRamp);
	Gura_AssignFunction(CreateRGBSurface);
	Gura_AssignFunction(CreateRGBSurfaceFrom);
	Gura_AssignFunction(LoadBMP);
	Gura_AssignFunction(BlitSurface);
	Gura_AssignFunction(WarpMouse);
	Gura_AssignFunction(CreateCursor);
	Gura_AssignFunction(SetCursor);
	Gura_AssignFunction(GetCursor);
	Gura_AssignFunction(ShowCursor);
	Gura_AssignFunction(GL_GetAttribute);
	Gura_AssignFunction(GL_SetAttribute);
	Gura_AssignFunction(GL_SwapBuffers);
	Gura_AssignFunction(CreateYUVOverlay);
	// SDL functions: Window Management
	Gura_AssignFunction(WM_SetCaption);
	Gura_AssignFunction(WM_GetCaption);
	Gura_AssignFunction(WM_SetIcon);
	Gura_AssignFunction(WM_IconifyWindow);
	Gura_AssignFunction(WM_ToggleFullScreen);
	Gura_AssignFunction(WM_GrabInput);
	// SDL functions: Events
	Gura_AssignFunction(PumpEvents);
	Gura_AssignFunction(AddEvents);		// SDL_PeepEvents(SDL_ADDEVENT)
	Gura_AssignFunction(PeekEvents);	// SDL_PeepEvents(SDL_PEEKEVENT)
	Gura_AssignFunction(GetEvents);		// SDL_PeepEvents(SDL_GETEVENT)
	Gura_AssignFunction(PollEvent);
	Gura_AssignFunction(WaitEvent);
	Gura_AssignFunction(PushEvent);
	Gura_AssignFunction(SetEventFilter);
	Gura_AssignFunction(GetEventFilter);
	Gura_AssignFunction(EventState);
	Gura_AssignFunction(CheckKeyState);	// SDL_GetKeyState()
	Gura_AssignFunction(GetModState);
	Gura_AssignFunction(SetModState);
	Gura_AssignFunction(GetKeyName);
	Gura_AssignFunction(EnableUNICODE);
	Gura_AssignFunction(EnableKeyRepeat);
	Gura_AssignFunction(GetMouseState);
	Gura_AssignFunction(GetRelativeMouseState);
	Gura_AssignFunction(GetAppState);
	Gura_AssignFunction(JoystickEventState);
	// SDL functions: Joystick
	Gura_AssignFunction(NumJoysticks);
	Gura_AssignFunction(JoystickName);
	Gura_AssignFunction(JoystickOpen);
	Gura_AssignFunction(JoystickOpened);
	Gura_AssignFunction(JoystickUpdate);
	// SDL functions: Audio
	Gura_AssignFunction(OpenAudio);
	Gura_AssignFunction(PauseAudio);
	Gura_AssignFunction(GetAudioStatus);
	Gura_AssignFunction(LoadWAV);
	Gura_AssignFunction(BuildAudioCVT);
	Gura_AssignFunction(LockAudio);
	Gura_AssignFunction(UnlockAudio);
	Gura_AssignFunction(CloseAudio);
	// SDL functions: CD-ROM
	Gura_AssignFunction(CDNumDrives);
	Gura_AssignFunction(CDName);
	Gura_AssignFunction(CDOpen);
	// SDL functions: Multi-threaded Programming
	// SDL functions: Time
	Gura_AssignFunction(GetTicks);
	Gura_AssignFunction(Delay);
	Gura_AssignFunction(AddTimer);
	// SDL functions: TTF
	//Gura_AssignFunction(OpenFont);
	// Object constructors
	Gura_AssignFunction(Color);
	Gura_AssignFunction(Rect);
	Gura_AssignFunction(AudioSpec);
	Gura_AssignFunctionEx(BuildAudioCVT, "AudioCVT");
	// test function
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

const char *GetEventTypeName(Uint8 type)
{
	static const struct {
		Uint8 type;
		const char *name;
	} tbl[] = {
		{ SDL_ACTIVEEVENT,		"ActiveEvent",		},
		{ SDL_KEYDOWN,			"KeyDown",			},
		{ SDL_KEYUP,			"KeyUp",			},
		{ SDL_MOUSEMOTION,		"MouseMotion",		},
		{ SDL_MOUSEBUTTONDOWN,	"MouseButtonDown",	},
		{ SDL_MOUSEBUTTONUP,	"MouseButtonUp",	},
		{ SDL_JOYAXISMOTION,	"JoyAxisMotion",	},
		{ SDL_JOYBALLMOTION,	"JoyBallMotion",	},
		{ SDL_JOYHATMOTION,		"JoyHatMotion",		},
		{ SDL_JOYBUTTONDOWN,	"JoyButtonDown",	},
		{ SDL_JOYBUTTONUP,		"JoyButtonUp",		},
		{ SDL_QUIT,				"Quit",				},
		{ SDL_SYSWMEVENT,		"SysWMEvent",		},
		{ SDL_VIDEORESIZE,		"VideoResize",		},
		{ SDL_VIDEOEXPOSE,		"VideoExpose",		},
		{ SDL_USEREVENT,		"UserEvent",		},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].type == type) return tbl[i].name;
	}
	return "(unknown)";
}

Gura_EndModule(sdl, sdl)

Gura_RegisterModule(sdl)
