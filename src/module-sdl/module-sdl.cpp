//-----------------------------------------------------------------------------
// Gura module: sdl
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(sdl)

//-----------------------------------------------------------------------------
// Object_Cursor implementation
//-----------------------------------------------------------------------------
Object_Cursor::~Object_Cursor()
{
	//::SDL_FreeCursor(_pCursor);
}

Object *Object_Cursor::Clone() const
{
	return nullptr;
}

void Object_Cursor::FreeCursor()
{
	if (_pCursor != nullptr) ::SDL_FreeCursor(_pCursor);
	_pCursor = nullptr;
}

String Object_Cursor::ToString(bool exprFlag)
{
	return String("<Cursor>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Cursor
//-----------------------------------------------------------------------------
// sdl.Cursor#FreeCursor():void
Gura_DeclareMethod(Cursor, FreeCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Frees a `sdl.Cursor` that was created using `sdl.CreateCursor`.\n");
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
	return nullptr;
}

String Object_Timer::ToString(bool exprFlag)
{
	return String("<sdl.timer>");
}

bool Object_Timer::AddTimer(Uint32 interval)
{
	_contFlag = true;
	_timerID = ::SDL_AddTimer(interval, CallbackStub, this);
	return _timerID != nullptr;
}

bool Object_Timer::RemoveTimer()
{
	_contFlag = false;
	SDL_bool rtn = ::SDL_RemoveTimer(_timerID);
	_timerID = nullptr;
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
		event.data2 = nullptr;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Removes a timer callback previously added with `sdl.AddTimer`.\n"
		"\n"
		"**Return Value:** Returns a boolean value indicating success.\n");
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
	return nullptr;
}

String Object_Event::ToString(bool exprFlag)
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

bool Object_Event::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
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

Value Object_Event::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return nullptr;
}

String Object_Rect::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Rect:x=%d,y=%d,w=%d,h=%d>", _rect.x, _rect.y, _rect.w, _rect.h);
	return String(buff);
}

bool Object_Rect::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	return true;
}

Value Object_Rect::DoGetProp(Environment &env, const Symbol *pSymbol,
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

Value Object_Rect::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rect.x = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rect.y = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rect.w = static_cast<Uint16>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		if (!value.MustBe_number(sig)) return Value::Null;
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
	return nullptr;
}

String Object_Color::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Color:r=%d,g=%d,b=%d>", _color.r, _color.g, _color.b);
	return String(buff);
}

bool Object_Color::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(r));
	symbols.insert(Gura_UserSymbol(g));
	symbols.insert(Gura_UserSymbol(b));
	return true;
}

Value Object_Color::DoGetProp(Environment &env, const Symbol *pSymbol,
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

Value Object_Color::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(r))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_color.r = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(g))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_color.g = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(b))) {
		if (!value.MustBe_number(sig)) return Value::Null;
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
		const Color &colorGura = Object_color::GetObject(value)->GetColor();
		SDL_Color color;
		color.r = colorGura.GetR();
		color.g = colorGura.GetG();
		color.b = colorGura.GetB();
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
	return nullptr;
}

String Object_Palette::ToString(bool exprFlag)
{
	return String("<sdl.Palette>");
}

bool Object_Palette::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	//symbols.insert(Gura_Symbol(red));
	return true;
}

Value Object_Palette::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	if (pixelFormat.palette != nullptr) {
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
	if (_pixelFormat.palette != nullptr) {
		delete[] _pixelFormat.palette->colors;
		delete _pixelFormat.palette;
	}
}

Object *Object_PixelFormat::Clone() const
{
	return nullptr;
}

String Object_PixelFormat::ToString(bool exprFlag)
{
	return String("<sdl.PixelFormat>");
}

bool Object_PixelFormat::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
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

Value Object_PixelFormat::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Maps the RGB color value to the specified pixel format and returns the pixel value as a 32-bit int.\n"
		"\n"
		"If the format has a palette (8-bit) the index of the closest matching color in the palette will be returned.\n"
		"\n"
		"If the specified pixel format has an alpha component it will be returned as all 1 bits (fully opaque).\n"
		"\n"
		"**Return Value:** A pixel value best approximating the given RGB color value for a given pixel format.\n"
		"If the pixel format bpp (color depth) is less than 32-bpp then the unused upper bits of the return value can safely be ignored\n"
		"(e.g., with a 16-bpp format the return value can be assigned to a Uint16, and similarly a Uint8 for an 8-bpp format).\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	DeclareArg(env, "a", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Maps the RGBA color value to the specified pixel format and returns the pixel value as a 32-bit int.\n"
		"\n"
		"If the format has a palette (8-bit) the index of the closest matching color in the palette will be returned.\n"
		"\n"
		"If the specified pixel format has no alpha component the alpha value will be ignored (as it will be in formats with a palette).\n"
		"\n"
		"**Return Value:** A pixel value best approximating the given RGBA color value for a given pixel format.\n"
		"If the pixel format bpp (color depth) is less than 32-bpp then the unused upper bits of the return value can safely be ignored\n"
		"(e.g., with a 16-bpp format the return value can be assigned to a Uint16, and similarly a Uint8 for an 8-bpp format).\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pixel", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Get RGB component values from a pixel stored in the specified pixel format.\n"
		"\n"
		"This function uses the entire 8-bit [0..255] range when converting color components from pixel formats with less than 8-bits per RGB component\n"
		"(e.g., a completely white pixel in 16-bit RGB565 format would return `[0xff, 0xff, 0xff]` not `[0xf8, 0xfc, 0xf8]`).\n");
}

Gura_ImplementMethod(PixelFormat, GetRGB)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	Uint8 r, g, b;
	::SDL_GetRGB(args.GetULong(0), fmt, &r, &g, &b);
	return Value::CreateList(env, Value(r), Value(g), Value(b));
}

// sdl.PixelFormat#GetRGBA(pixel:number):void
Gura_DeclareMethod(PixelFormat, GetRGBA)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pixel", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Get RGBA component values from a pixel stored in the specified pixel format.\n"
		"\n"
		"This function uses the entire 8-bit [0..255] range when converting color components from pixel formats with less than 8-bits per RGB component\n"
		"(e.g., a completely white pixel in 16-bit RGB565 format would return `[0xff, 0xff, 0xff]` not `[0xf8, 0xfc, 0xf8]`).\n"
		"\n"
		"If the surface has no alpha component, the alpha will be returned as 0xff (100% opaque).\n");
}

Gura_ImplementMethod(PixelFormat, GetRGBA)
{
	SDL_PixelFormat *fmt = Object_PixelFormat::GetThisObj(args)->GetPixelFormat();
	Uint8 r, g, b, a;
	::SDL_GetRGBA(args.GetULong(0), fmt, &r, &g, &b, &a);
	return Value::CreateList(env, Value(r), Value(g), Value(b), Value(a));
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
	return nullptr;
}

bool Object_Surface::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
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

Value Object_Surface::DoGetProp(Environment &env, const Symbol *pSymbol,
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

String Object_Surface::ToString(bool exprFlag)
{
	return String("<sdl.Surface>");
}

Object_Surface *Object_Surface::CreateSurfaceFromImage(Signal &sig, Image *pImage)
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
		return nullptr;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Makes sure the given area is updated on the given screen.\n"
		"The rectangle must be confined within the screen boundaries (no clipping is done).\n"
		"\n"
		"If `x`, `y`, `w` and `h` are all 0, `sdl.Surface#UpdateRect` will update the entire screen.\n"
		"\n"
		"This function should not be called while the sdl.Surface instance is locked.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Makes sure the given list of rectangles is updated on the given screen.\n"
		"The rectangles must all be confined within the screen boundaries (no clipping is done).\n"
		"\n"
		"This function should not be called while the `sdl.Surface` instance is locked.\n"
		"\n"
		"**Note:** It is adviced to call this function only once per frame, since each call has some processing overhead.\n"
		"This is no restriction since you can pass any number of rectangles each time.\n"
		"\n"
		"The rectangles are not automatically merged or checked for overlap.\n"
		"In general, the programmer can use his knowledge about his particular rectangles to merge them in an efficient way, to avoid overdraw.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"On hardware that supports double-buffering, this function sets up a flip and returns.\n"
		"The hardware will wait for vertical retrace, and then swap video buffers before the next video surface blit or lock will return.\n"
		"On hardware that doesn't support double-buffering, this is equivalent to calling `screen.UpdateRect(0, 0, 0, 0)`\n"
		"\n"
		"The `sdl.DOUBLEBUF` flag must have been passed to `sdl.SetVideoMode`, when setting the video mode for this function to perform hardware flipping.\n"
		"\n"
		"**Return Value:** This function returns 0 if successful, or -1 if there was an error.\n");
}

Gura_ImplementMethod(Surface, Flip)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_Flip(pSurface));
}

// sdl.Surface#SetColors(colors[]:Color, firstcolor:number => 0)
Gura_DeclareMethod(Surface, SetColors)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None,
															new Expr_Value(0));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets a portion of the colormap for the given 8-bit surface.\n"
		"\n"
		"When surface is the surface associated with the current display, the display colormap will be updated with the requested colors.\n"
		"If `sdl.HWPALETTE` was set in `sdl.SetVideoMode` flags, `sdl.Surface#SetColors` will always return 1,\n"
		"and the palette is guaranteed to be set the way you desire, even if the window colormap has to be warped or run under emulation.\n"
		"\n"
		"The color components of a sdl.Color structure are 8-bits in size, giving you a total of 2563 =16777216 colors.\n"
		"\n"
		"Palettized (8-bit) screen surfaces with the `sdl.HWPALETTE` flag have two palettes, a logical palette that is used for mapping blits to/from the surface and a physical palette\n"
		"(that determines how the hardware will map the colors to the display).\n"
		"`sdl.Surface#SetColors` modifies both palettes (if present), and is equivalent to calling `sdl.Surface#SetPalette` with the flags set to `(sdl.LOGPAL | sdl.PHYSPAL)`.\n"
		"\n"
		"**Return Value:** If surface is not a palettized surface, this function does nothing, returning 0.\n"
		"If all of the colors were set as passed to `sdl.Surface#SetColors`, it will return 1.\n"
		"If not all the color entries were set exactly as given, it will return 0, and you should look at the surface palette to determine the actual color palette.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None,
															new Expr_Value(0));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets a portion of the palette for the given 8-bit surface.\n"
		"\n"
		"Palettized (8-bit) screen surfaces with the `sdl.HWPALETTE` flag have two palettes,\n"
		"a logical palette that is used for mapping blits to/from the surface and a physical palette (that determines how the hardware will map the colors to the display).\n"
		"`sdl.BlitSurface` always uses the logical palette when blitting surfaces (if it has to convert between surface pixel formats).\n"
		"Because of this, it is often useful to modify only one or the other palette to achieve various special color effects (e.g., screen fading, color flashes, screen dimming).\n"
		"\n"
		"This function can modify either the logical or physical palette by specifing `sdl.LOGPAL` or `sdl.PHYSPAL` in the flags parameter.\n"
		"\n"
		"When surface is the surface associated with the current display, the display colormap will be updated with the requested colors.\n"
		"If `sdl.HWPALETTE` was set in `sdl.SetVideoMode` flags, `sdl.Surface#SetPalette` will always return 1,\n"
		"and the palette is guaranteed to be set the way you desire, even if the window colormap has to be warped or run under emulation.\n"
		"\n"
		"The color components of a sdl.Color structure are 8-bits in size, giving you a total of 2563=16777216 colors.\n"
		"\n"
		"**Return Value:** If surface is not a palettized surface, this function does nothing, returning 0.\n"
		"If all of the colors were set as passed to `sdl.Surface#SetPalette`, it will return 1.\n"
		"If not all the color entries were set exactly as given, it will return 0, and you should look at the surface palette to determine the actual color palette.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.Surface#LockSurface` sets up a surface for directly accessing the pixels.\n"
		"Between calls to `sdl.Surface#LockSurface` and `sdl.Surface#UnlockSurface`, you can write to and read from surface.pixels, using the pixel format stored in surface.format.\n"
		"Once you are done accessing the surface, you should use `sdl.Surface#UnlockSurface` to release it.\n"
		"\n"
		"Not all surfaces require locking. If `sdl.MUSTLOCK(surface)` evaluates to 0, then you can read and write to the surface at any time, and the pixel format of the surface will not change.\n"
		"\n"
		"No operating system or library calls should be made between lock/unlock pairs, as critical system locks may be held during this time.\n"
		"\n"
		"It should be noted, that since SDL 1.1.8 surface locks are recursive. This means that you can lock a surface multiple times, but each lock must have a match unlock.\n");
}

Gura_ImplementMethod(Surface, LockSurface)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_LockSurface(pSurface));
}

// sdl.Surface#UnlockSurface():void
Gura_DeclareMethod(Surface, UnlockSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Surfaces that were previously locked using `sdl.Surface#LockSurface` must be unlocked with `sdl.Surface#UnlockSurface`.\n"
		"Surfaces should be unlocked as soon as possible.\n"
		"\n"
		"It should be noted that since 1.1.8, surface locks are recursive.\n"
		"See `sdl.Surface#LockSurface`.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Saves the sdl.Surface surface as a Windows BMP file named file.\n"
		"\n"
		"**Return Value:** Returns 0 if successful or -1 if there was an error.\n");
}

Gura_ImplementMethod(Surface, SaveBMP)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SaveBMP(pSurface, args.GetString(0)));
}

// sdl.Surface#SetColorKey(flag:number, key:number)
Gura_DeclareMethod(Surface, SetColorKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the color key (transparent pixel) in a blittable surface and enables or disables RLE blit acceleration.\n"
		"\n"
		"RLE acceleration can substantially speed up blitting of images with large horizontal runs of transparent pixels (i.e., pixels that match the key value).\n"
		"The key must be of the same pixel format as the surface, `sdl.Surface#MapRGB` is often useful for obtaining an acceptable value.\n"
		"\n"
		"If flag is `sdl.SRCCOLORKEY` then key is the transparent pixel value in the source image of a blit.\n"
		"\n"
		"If flag is OR'd with `sdl.RLEACCEL` then the surface will be draw using RLE acceleration when drawn with `sdl.BlitSurface`.\n"
		"The surface will actually be encoded for RLE acceleration the first time sdl.BlitSurface or `sdl.Surface#DisplayFormat` is called on the surface.\n"
		"\n"
		"If flag is 0, this function clears any current color key.\n"
		"\n"
		"**Return Value:** This function returns 0, or -1 if there was an error.\n");
}

Gura_ImplementMethod(Surface, SetColorKey)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SetColorKey(pSurface, args.GetULong(0), args.GetULong(1)));
}

// sdl.Surface#SetAlpha(flag:number, alpha:number)
Gura_DeclareMethod(Surface, SetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(Surface, SetAlpha)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	return Value(::SDL_SetAlpha(pSurface, args.GetULong(0), args.GetUChar(1)));
}

// sdl.Surface#SetClipRect(rect:sdl.Rect:nil):map:void
Gura_DeclareMethod(Surface, SetClipRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the clipping rectangle for a surface.\n"
		"When this surface is the destination of a blit, only the area within the clip rectangle will be drawn into.\n"
		"\n"
		"The rectangle pointed to by rect will be clipped to the edges of the surface so that the clip rectangle for a surface can never fall outside the edges of the surface.\n"
		"\n"
		"If rect is nil the clipping rectangle will be set to the full size of the surface.\n");
}

Gura_ImplementMethod(Surface, SetClipRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Rect *rect = nullptr;
	if (args.IsValid(0)) rect = &dynamic_cast<Object_Rect *>(args.GetObject(0))->GetRect();
	::SDL_SetClipRect(pSurface, rect);
	return Value::Null;
}

// sdl.Surface#GetClipRect()
Gura_DeclareMethod(Surface, GetClipRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Gets the clipping rectangle for a surface. When this surface is the destination of a blit, only the area within the clip rectangle is drawn into.\n"
		"\n"
		"This returns sdl.Rect instance filled with the clipping rectangle of the surface.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "fmt", VTYPE_PixelFormat);
	DeclareArg(env, "flag", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a new surface of the specified format, and then copies and maps the given surface to it.\n"
		"If this function fails, it returns nil.\n"
		"\n"
		"The flags parameter is passed to `sdl.CreateRGBSurface` and has those semantics.\n"
		"\n"
		"This function is used internally by `sdl.Surface#DisplayFormat`.\n"
		"\n"
		"This function can only be called after `sdl.Init`.\n"
		"\n"
		"**Return Value:** Returns either `sdl.Surface` instance of the new surface, or `nil` on error.\n");
}

Gura_ImplementMethod(Surface, ConvertSurface)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	const SDL_PixelFormat *fmt =
		dynamic_cast<const Object_PixelFormat *>(args.GetObject(0))->GetPixelFormat();
	int flags = args.GetInt(1);
	SDL_Surface *pSurfaceConv = ::SDL_ConvertSurface(pSurface,
								const_cast<SDL_PixelFormat *>(fmt), flags);
	if (pSurfaceConv == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurfaceConv, nullptr));
}

// sdl.Surface#FillRect(dstrect:sdl.Rect:nil, color:Color):map:void
Gura_DeclareMethod(Surface, FillRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "color", VTYPE_Color);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function performs a fast fill of the given rectangle with color.\n"
		"If dstrect is nil, the whole surface will be filled with color.\n"
		"\n"
		"The color should be a pixel of the format used by the surface, and can be generated by the `sdl.Surface#MapRGB` or `sdl.Surface#MapRGBA` functions.\n"
		"If the color value contains an alpha value then the destination is simply \"filled\" with that alpha information, no blending takes place.\n"
		"\n"
		"If there is a clip rectangle set on the destination (set via `sdl.Surface#SetClipRect`)\n"
		"then this function will clip based on the intersection of the clip rectangle and the dstrect rectangle\n"
		"and the dstrect rectangle will be modified to represent the area actually filled.\n"
		"\n"
		"**Return Value:** This function returns 0 on success, or -1 on error.\n");
}

Gura_ImplementMethod(Surface, FillRect)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Rect *dstrect = nullptr;
	if (args.IsValid(0)) dstrect = &dynamic_cast<Object_Rect *>(args.GetObject(0))->GetRect();
	SDL_Color &color = dynamic_cast<Object_Color *>(args.GetObject(1))->GetColor();
	Uint32 colorIdx = ::SDL_MapRGB(pSurface->format, color.r, color.g, color.b);
	return Value(::SDL_FillRect(pSurface, dstrect, colorIdx));
}

// sdl.Surface#DisplayFormat() {block?}
Gura_DeclareMethod(Surface, DisplayFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function takes a surface and copies it to a new surface of the pixel format and colors of the video framebuffer, suitable for fast blitting onto the display surface.\n"
		"It calls SDL_ConvertSurface.\n"
		"\n"
		"If you want to take advantage of hardware colorkey or alpha blit acceleration, you should set the colorkey and alpha value before calling this function.\n"
		"\n"
		"If you want an alpha channel, see `sdl.Surface#DisplayFormatAlpha`.\n"
		"\n"
		"**Return Value:** It returns sdl.Surface instance on success.\n"
		"If the conversion fails or runs out of memory, it returns `nil`.\n");
}

Gura_ImplementMethod(Surface, DisplayFormat)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Surface *pSurfaceConv = ::SDL_DisplayFormat(pSurface);
	if (pSurfaceConv == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurfaceConv, nullptr));
}

// sdl.Surface#DisplayFormatAlpha() {block?}
Gura_DeclareMethod(Surface, DisplayFormatAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function takes a surface and copies it to a new surface of the pixel format and colors of the video framebuffer plus an alpha channel, suitable for fast blitting onto the display surface.\n"
		"It calls `SDL_ConvertSurface`.\n"
		"\n"
		"If you want to take advantage of hardware colorkey or alpha blit acceleration, you should set the colorkey and alpha value before calling this function.\n"
		"\n"
		"This function can be used to convert a colourkey to an alpha channel, if the `sdl.SRCCOLORKEY` flag is set on the surface.\n"
		"The generated surface will then be transparent (alpha=0) where the pixels match the colourkey, and opaque (alpha=255) elsewhere.\n"
		"\n"
		"**Return Value:** It returns `sdl.Surface` instance on success.\n"
		"If the conversion fails or runs out of memory, it returns `nil`.\n");
}

Gura_ImplementMethod(Surface, DisplayFormatAlpha)
{
	SDL_Surface *pSurface = Object_Surface::GetThisObj(args)->GetSurface();
	SDL_Surface *pSurfaceConv = ::SDL_DisplayFormatAlpha(pSurface);
	if (pSurfaceConv == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurfaceConv, nullptr));
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
	Signal &sig = GetSignal();
	if (value.Is_image()) {
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
	return nullptr;
}

String Object_Overlay::ToString(bool exprFlag)
{
	return String("<sdl.Overlay>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Overlay
//-----------------------------------------------------------------------------
// sdl.Overlay#LockYUVOverlay()
Gura_DeclareMethod(Overlay, LockYUVOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Much the same as `sdl.Surface#LockSurface`, `sdl.Overlay#LockYUVOverlay` locks the overlay for direct access to pixel data.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
}

Gura_ImplementMethod(Overlay, LockYUVOverlay)
{
	SDL_Overlay *pOverlay = Object_Overlay::GetThisObj(args)->GetOverlay();
	return Value(::SDL_LockYUVOverlay(pOverlay));
}

// sdl.Overlay#UnlockYUVOverlay():void
Gura_DeclareMethod(Overlay, UnlockYUVOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The opposite to `sdl.Overlay#LockYUVOverlay`.\n"
		"Unlocks a previously locked overlay.\n"
		"An overlay must be unlocked before it can be displayed.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Blit the overlay to the surface specified when it was created.\n"
		"The sdl.Rect structure, dstrect, specifies the position and size of the destination.\n"
		"If the dstrect is a larger or smaller than the overlay then the overlay will be scaled, this is optimized for 2x scaling.\n"
		"\n"
		"**Return Value:** Returns 0 on success.");
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
	return nullptr;
}

String Object_VideoInfo::ToString(bool exprFlag)
{
	return String("<sdl.VideoInfo>");
}

bool Object_VideoInfo::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
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

Value Object_VideoInfo::DoGetProp(Environment &env, const Symbol *pSymbol,
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
		if (_pVideoInfo->vfmt == nullptr) return Value::Null;
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
	return nullptr;
}

String Object_Joystick::ToString(bool exprFlag)
{
	return String("<sdl.Joystick>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Joystick
//-----------------------------------------------------------------------------
// sdl.Joystick#JoystickIndex()
Gura_DeclareMethod(Joystick, JoystickIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the index of a given `sdl.Joystick` instance.\n"
		"\n"
		"**Return Value:** Index number of the joystick.\n");
}

Gura_ImplementMethod(Joystick, JoystickIndex)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickIndex(pJoystick));
}

// sdl.Joystick#JoystickNumAxes()
Gura_DeclareMethod(Joystick, JoystickNumAxes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return the number of axes available from a previously opened `sdl.Joystick`.\n"
		"\n"
		"**Return Value:** Number of axes.\n");
}

Gura_ImplementMethod(Joystick, JoystickNumAxes)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumAxes(pJoystick));
}

// sdl.Joystick#JoystickNumBalls()
Gura_DeclareMethod(Joystick, JoystickNumBalls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return the number of trackballs available from a previously opened `sdl.Joystick`.\n"
		"\n"
		"**Return Value:** Number of trackballs.\n");
}

Gura_ImplementMethod(Joystick, JoystickNumBalls)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumBalls(pJoystick));
}

// sdl.Joystick#JoystickNumHats()
Gura_DeclareMethod(Joystick, JoystickNumHats)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return the number of hats available from a previously opened `sdl.Joystick`.\n"
		"\n"
		"**Return Value:** Number of hats.\n");
}

Gura_ImplementMethod(Joystick, JoystickNumHats)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumHats(pJoystick));
}

// sdl.Joystick#JoystickNumButtons()
Gura_DeclareMethod(Joystick, JoystickNumButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return the number of buttons available from a previously opened `sdl.Joystick`.\n"
		"\n"
		"**Return Value:** Number of buttons.\n");
}

Gura_ImplementMethod(Joystick, JoystickNumButtons)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickNumButtons(pJoystick));
}

// sdl.Joystick#JoystickGetAxis(axis:number)
Gura_DeclareMethod(Joystick, JoystickGetAxis)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.Joystick#JoystickGetAxis` returns the current state of the given axis on the given joystick.\n"
		"\n"
		"On most modern joysticks the X axis is usually represented by axis 0 and the Y axis by axis 1.\n"
		"The value returned by sdl.Joystick#JoystickGetAxis is a signed integer (-32768 to 32768) representing the current position of the axis,\n"
		"it maybe necessary to impose certain tolerances on these values to account for jitter.\n"
		"It is worth noting that some joysticks use axes 2 and 3 for extra buttons.\n"
		"\n"
		"**Return Value:** Returns a 16-bit signed integer representing the current position of the axis.\n");
}

Gura_ImplementMethod(Joystick, JoystickGetAxis)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetAxis(pJoystick, args.GetInt(0)));
}

// sdl.Joystick#JoystickGetHat(hat:number)
Gura_DeclareMethod(Joystick, JoystickGetHat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "hat", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.Joystick#JoystickGetHat` returns the current state of the given hat on the given joystick.\n"
		"\n"
		"**Return Value:** The current state is returned as a Uint8 which is defined as an OR'd combination of one or more of the following\n\n"
		"- `SDL_HAT_CENTERED`\n"
		"- `SDL_HAT_UP`\n"
		"- `SDL_HAT_RIGHT`\n"
		"- `SDL_HAT_DOWN`\n"
		"- `SDL_HAT_LEFT`\n"
		"- `SDL_HAT_RIGHTUP`\n"
		"- `SDL_HAT_RIGHTDOWN`\n"
		"- `SDL_HAT_LEFTUP`\n"
		"- `SDL_HAT_LEFTDOWN`\n");
}

Gura_ImplementMethod(Joystick, JoystickGetHat)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetHat(pJoystick, args.GetInt(0)));
}

// sdl.Joystick#JoystickGetButton(button:number)
Gura_DeclareMethod(Joystick, JoystickGetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "button", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.Joystick#JoystickGetButton` returns the current state of the given button on the given joystick.\n"
		"\n"
		"**Return Value:** true if the button is pressed. Otherwise, false.\n");
}

Gura_ImplementMethod(Joystick, JoystickGetButton)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	return Value(::SDL_JoystickGetButton(pJoystick, args.GetInt(0))? true : false);
}

// sdl.Joystick#JoystickGetBall(ball:number)
Gura_DeclareMethod(Joystick, JoystickGetBall)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "ball", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Get the ball axis change.\n"
		"\n"
		"Trackballs can only return relative motion since the last call to `sdl.Joystick#JoystickGetBall`, these motion deltas a placed into dx and dy.\n"
		"\n"
		"**Return Value:** Returns `[dx,dy]` on success or `nil` on failure.\n");
}

Gura_ImplementMethod(Joystick, JoystickGetBall)
{
	SDL_Joystick *pJoystick = Object_Joystick::GetThisObj(args)->GetJoystick();
	int dx, dy;
	if (::SDL_JoystickGetBall(pJoystick, args.GetInt(0), &dx, &dy) < 0) {
		return Value::Null;
	}
	return Value::CreateList(env, Value(dx), Value(dy));
}

// sdl.Joystick#JoystickClose():void
Gura_DeclareMethod(Joystick, JoystickClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Close a joystick that was previously opened with `sdl.JoystickOpen`.\n");
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
	if (_audio_buf != nullptr) ::SDL_FreeWAV(_audio_buf);
	::free(_pAudioSpec);
	Function::Delete(_pFuncCallback);
}

Object *Object_AudioSpec::Clone() const
{
	return nullptr;
}

void Object_AudioSpec::Callback(Uint8 *stream, int len)
{
	if (_pFuncCallback == nullptr) return;
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
		pObjAudio->ReferenceBuffer(nullptr, stream, len);
		//ValueList valList;
		//valList.reserve(1);
		//valList.push_back(Value(pObjAudio.release()));
		AutoPtr<Args> pArgs(new Args());
		pArgs->AddValue(Value(pObjAudio.release()));
		_pFuncCallback->Eval(env, _sig, *pArgs);
	} while (0);
#endif
	::SDL_UnlockAudio();
}

void Object_AudioSpec::CallbackStub(void *userdata, Uint8 *stream, int len)
{
	if (userdata == nullptr) return;
	Object_AudioSpec *pThis = reinterpret_cast<Object_AudioSpec *>(userdata);
	pThis->Callback(stream, len);
}

String Object_AudioSpec::ToString(bool exprFlag)
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src", VTYPE_AudioSpec);
	DeclareArg(env, "volume", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(AudioSpec, MixAudio)
{
	Signal &sig = env.GetSignal();
	Object_AudioSpec *pDst = Object_AudioSpec::GetThisObj(args);
	Object_AudioSpec *pSrc =dynamic_cast<Object_AudioSpec *>(args.GetObject(0));
	int volume = args.GetInt(1);
	if (pDst->GetAudioBuf() == nullptr || pSrc->GetAudioBuf() == nullptr) {
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
	return nullptr;
}

String Object_AudioCVT::ToString(bool exprFlag)
{
	return String("<sdl.AudioCVT>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_AudioCVT
//-----------------------------------------------------------------------------
// sdl.AudioCVT#ConvertAudio()
Gura_DeclareMethod(AudioCVT, ConvertAudio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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
	return nullptr;
}

bool Object_CDtrack::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(length));
	symbols.insert(Gura_UserSymbol(offset));
	return true;
}

Value Object_CDtrack::DoGetProp(Environment &env, const Symbol *pSymbol,
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

String Object_CDtrack::ToString(bool exprFlag)
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
	return nullptr;
}

bool Object_CD::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(status));
	symbols.insert(Gura_UserSymbol(numtracks));
	symbols.insert(Gura_UserSymbol(cur_track));
	symbols.insert(Gura_UserSymbol(cur_frame));
	return true;
}

Value Object_CD::DoGetProp(Environment &env, const Symbol *pSymbol,
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

String Object_CD::ToString(bool exprFlag)
{
	return String("<sdl.CD>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_CD
//-----------------------------------------------------------------------------
// sdl.CD#CDStatus()
Gura_DeclareMethod(CD, CDStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function returns the current status of the given drive. Status is described like so:\n"
		"\n"
		"- `sdl.CD_TRAYEMPTY`\n"
		"- `sdl.CD_STOPPED`\n"
		"- `sdl.CD_PLAYING`\n"
		"- `sdl.CD_PAUSED`\n"
		"- `sdl.CD_ERROR`\n");
}

Gura_ImplementMethod(CD, CDStatus)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDStatus(pCD));
}

// sdl.CD#CDPlay(start:number, length:number)
Gura_DeclareMethod(CD, CDPlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "start", VTYPE_number);
	DeclareArg(env, "length", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Plays the given cdrom, starting a frame start for length frames.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "start_track", VTYPE_number);
	DeclareArg(env, "start_frame", VTYPE_number);
	DeclareArg(env, "ntracks", VTYPE_number);
	DeclareArg(env, "nframes", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"sdl.CD#CDPlayTracks plays the given CD starting at track `start_track`, for `ntracks` tracks.\n"
		"\n"
		"`start_frame` is the frame offset, from the beginning of the `start_track`, at which to start.\n"
		"`nframes` is the frame offset, from the beginning of the last track (`start_track`+`ntracks`), at which to end playing.\n"
		"\n"
		"`sdl.CD#CDPlayTracks` should only be called after calling `sdl.CD#CDStatus` to get track information about the CD.\n"
		"\n"
		"**Note:** Data tracks are ignored.\n"
		"\n"
		"**Return Value:** Returns 0, or -1 if there was an error.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Pauses play on the given cdrom.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
}

Gura_ImplementMethod(CD, CDPause)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDPause(pCD));
}

// sdl.CD#CDResume()
Gura_DeclareMethod(CD, CDResume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Resumes play on the given cdrom.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
}

Gura_ImplementMethod(CD, CDResume)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDResume(pCD));
}

// sdl.CD#CDStop()
Gura_DeclareMethod(CD, CDStop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Stops play on the given cdrom.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
}

Gura_ImplementMethod(CD, CDStop)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDStop(pCD));
}

// sdl.CD#CDEject()
Gura_DeclareMethod(CD, CDEject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Ejects the given cdrom.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on an error.\n");
}

Gura_ImplementMethod(CD, CDEject)
{
	SDL_CD *pCD = Object_CD::GetThisObj(args)->GetCD();
	return Value(::SDL_CDEject(pCD));
}

// sdl.CD#CDClose():void
Gura_DeclareMethod(CD, CDClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Closes the given cdrom handle.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(CD, GetTrack)
{
	Signal &sig = env.GetSignal();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Initializes SDL. This should be called before all other SDL functions.\n"
		"The flags parameter specifies what part(s) of SDL to initialize.\n"
		"\n"
		"- `sdl.INIT_TIMER` .. Initializes the timer subsystem.\n"
		"- `sdl.INIT_AUDIO` .. Initializes the audio subsystem.\n"
		"- `sdl.INIT_VIDEO` .. Initializes the video subsystem.\n"
		"- `sdl.INIT_CDROM` .. Initializes the cdrom subsystem.\n"
		"- `sdl.INIT_JOYSTICK` .. Initializes the joystick subsystem.\n"
		"- `sdl.INIT_EVERYTHING` .. Initialize all of the above.\n"
		"- `sdl.INIT_NOPARACHUTE` .. Prevents SDL from catching fatal signals.\n"
		"- `sdl.INIT_EVENTTHREAD`\n"
		"\n"
		"**Return Value:** Returns -1 on an error or 0 on success.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"After SDL has been initialized with sdl.Init you may initialize uninitialized subsystems with `sdl.InitSubSystem`.\n"
		"The flags parameter is the same as that used in `sdl.Init`.\n"
		"\n"
		"**Return Value:** Returns -1 on an error or 0 on success.\n");
}

Gura_ImplementFunction(InitSubSystem)
{
	return Value(::SDL_InitSubSystem(args.GetULong(0)));
}

// sdl.QuitSubSystem(flags:number):void
Gura_DeclareFunction(QuitSubSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.QuitSubSystem` allows you to shut down a subsystem that has been previously initialized by sdl.Init or `sdl.InitSubSystem`.\n"
		"The flags tells `sdl.QuitSubSystem` which subsystems to shut down, it uses the same values that are passed to `sdl.Init`.\n");
}

Gura_ImplementFunction(QuitSubSystem)
{
	::SDL_QuitSubSystem(args.GetULong(0));
	return Value::Null;
}

// sdl.Quit():void
Gura_DeclareFunction(Quit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.Quit` shuts down all SDL subsystems and frees the resources allocated to them.\n"
		"This should always be called before you exit.\n");
}

Gura_ImplementFunction(Quit)
{
	::SDL_Quit();
	return Value::Null;
}

// sdl.WasInit(flags:number)
Gura_DeclareFunction(WasInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.WasInit` allows you to see which SDL subsytems have been initialized.\n"
		"flags is a bitwise OR'd combination of the subsystems you wish to check (see sdl.Init for a list of subsystem flags).\n"
		"\n"
		"**Return Value:** `sdl.WasInit` returns a bitwised OR'd combination of the initialized subsystems.\n");
}

Gura_ImplementFunction(WasInit)
{
	return Value(::SDL_WasInit(args.GetULong(0)));
}

// sdl.GetError()
Gura_DeclareFunction(GetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.GetError` returns a string containing information about the last internal SDL error.\n"
		"\n"
		"**Return Value:** `sdl.GetError` returns a string containing the last error.\n");
}

Gura_ImplementFunction(GetError)
{
	//return Value(::SDL_GetError());
	return Value("");
}

//-----------------------------------------------------------------------------
// SDL functions: Video
//-----------------------------------------------------------------------------
// sdl.GetVideoSurface() {block?}
Gura_DeclareFunction(GetVideoSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function returns a `sdl.Surface` instance of the current display surface.\n"
		"If SDL is doing format conversion on the display surface, this function returns the publicly visible surface, not the real video surface.\n");
}

Gura_ImplementFunction(GetVideoSurface)
{
	SDL_Surface *pSurface = ::SDL_GetVideoSurface();
	if (pSurface == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurface, nullptr));
}

// sdl.GetVideoInfo()
Gura_DeclareFunction(GetVideoInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function returns a `sdl.VideoInfo` instance that contains information about the video hardware.\n"
		"If this is called before `sdl.SetVideoMode`, the vfmt member of the returned structure will contain the pixel format of the \"best\" video mode.\n");
}

Gura_ImplementFunction(GetVideoInfo)
{
	const SDL_VideoInfo *pVideoInfo = ::SDL_GetVideoInfo();
	if (pVideoInfo == nullptr) return Value::Null;
	return Object_VideoInfo::CreateValue(pVideoInfo);
}

// sdl.VideoDriverName()
Gura_DeclareFunction(VideoDriverName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a string of the name of the initialised video driver.\n"
		"The driver name is a simple one word identifier like \"x11\" or \"windib\".\n"
		"\n"
		"**Return Value:** Returns `nil` if video has not been initialised with `sdl.Init` or a string of the driver name otherwise.\n");
}

Gura_ImplementFunction(VideoDriverName)
{
	char buff[64];
	char *p = ::SDL_VideoDriverName(buff, sizeof(buff));
	if (p == nullptr) return Value::Null;
	return Value(p);
}

// sdl.ListModes(format:sdl.PixelFormat, flags:number)
Gura_DeclareFunction(ListModes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return a list of available screen dimensions for the given format and video flags, sorted largest to smallest.\n"
		"Returns nil if there are no dimensions available for a particular format or an empty list if any dimension is okay for the given format.\n");
}

Gura_ImplementFunction(ListModes)
{
	SDL_PixelFormat *format = args.IsValid(0)?
			Object_PixelFormat::GetObject(args, 0)->GetPixelFormat() : nullptr;
	Uint32 flags = args.GetUInt(1);
	SDL_Rect **modes = ::SDL_ListModes(format, flags);
	if (modes == nullptr) return Value::Null;
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (modes == reinterpret_cast<SDL_Rect **>(-1)) {
		// nothing to do
	} else {
		for (int i = 0; modes[i] != nullptr; i++) {
			valList.push_back(Value(new Object_Rect(*modes[i])));
		}
	}
	return rtn;
}

// sdl.VideoModeOK(width:number, height:number, bpp:number, flags:number)
Gura_DeclareFunction(VideoModeOK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "bpp", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.VideoModeOK` returns 0 if the requested mode is not supported under any bit depth,\n"
		"or returns the bits-per-pixel of the closest available mode with the given width, height and requested surface flags (see `sdl.SetVideoMode`).\n"
		"\n"
		"The bits-per-pixel value returned is only a suggested mode.\n"
		"You can usually request and bpp you want when setting the video mode and SDL will emulate that color depth with a shadow video surface.\n"
		"\n"
		"The arguments to `sdl.VideoModeOK` are the same ones you would pass to `sdl.SetVideoMode`.\n");
}

Gura_ImplementFunction(VideoModeOK)
{
	return Value(::SDL_VideoModeOK(
		args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetULong(3)));
}

// sdl.SetVideoMode(width:number, height:number, bpp:number, flags:number) {block?}
Gura_DeclareFunction(SetVideoMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "bpp", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Set up a video mode with the specified width, height and bits-per-pixel.\n"
		"\n"
		"If bpp is 0, it is treated as the current display bits per pixel.\n"
		"\n"
		"The flags parameter is the same as the flags field of the `sdl.Surface` structure.\n"
		"OR'd combinations of the following values are valid.\n"
		"\n"
		"- `sdl.SWSURFACE`\n"
		"- `sdl.HWSURFACE`\n"
		"- `sdl.ASYNCBLIT`\n"
		"- `sdl.ANYFORMAT`\n"
		"- `sdl.HWPALETTE`\n"
		"- `sdl.DOUBLEBUF`\n"
		"- `sdl.FULLSCREEN`\n"
		"- `sdl.OPENGL`\n"
		"- `sdl.OPENGLBLIT`\n"
		"- `sdl.RESIZABLE`\n"
		"- `sdl.NOFRAME`\n"
		"\n"
		"**Note:** Whatever flags `sdl.SetVideoMode` could satisfy are set in the flags member of the returned surface.\n"
		"\n"
		"**Note:** The bpp parameter is the number of bits per pixel, so a bpp of 24 uses the packed representation of 3 bytes/pixel.\n"
		"For the more common 4 bytes/pixel mode, use a bpp of 32. Somewhat oddly, both 15 and 16 will request a 2 bytes/pixel mode, but different pixel formats.\n"
		"\n"
		"**Return Value:** The framebuffer surface, or nil if it fails.\n"
		"The surface returned is freed by `sdl.Quit()` and should not be freed by the caller.\n");
}

Gura_ImplementFunction(SetVideoMode)
{
	SDL_Surface *pSurface = ::SDL_SetVideoMode(
		args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetULong(3));
	if (pSurface == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurface, nullptr));
}

// sdl.SetGamma(redgamma:number, greengamma:number, bluegamma:number)
Gura_DeclareFunction(SetGamma)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "redgamma", VTYPE_number);
	DeclareArg(env, "greengamma", VTYPE_number);
	DeclareArg(env, "bluegamma", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the \"gamma function\" for the display of each color component.\n"
		"Gamma controls the brightness/contrast of colors displayed on the screen.\n"
		"A gamma value of 1.0 is identity (i.e., no adjustment is made).\n"
		"\n"
		"This function adjusts the gamma based on the \"gamma function\" parameter, you can directly specify lookup tables for gamma adjustment with `sdl.SetGammaRamp`.\n"
		"\n"
		"Not all display hardware is able to change gamma.\n");
}

Gura_ImplementFunction(SetGamma)
{
	return Value(::SDL_SetGamma(static_cast<float>(args.GetNumber(0)),
		static_cast<float>(args.GetNumber(1)), static_cast<float>(args.GetNumber(2))));
}

// sdl.GetGammaRamp()
Gura_DeclareFunction(GetGammaRamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Gets the gamma translation lookup tables currently used by the display. Each table is an array of 256 Uint16 values.\n"
		"\n"
		"Not all display hardware is able to change gamma.\n"
		"\n"
		"**Return Value:** Returns -1 on error.");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "redtable", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "greentable", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "bluetable", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the gamma lookup tables for the display for each color component.\n"
		"Each table is an array of 256 Uint16 values, representing a mapping between the input and output for that channel.\n"
		"The input is the index into the array, and the output is the 16-bit gamma value at that index, scaled to the output color precision.\n"
		"You may pass nullptr to any of the channels to leave them unchanged.\n"
		"\n"
		"This function adjusts the gamma based on lookup tables, you can also have the gamma calculated based on a \"gamma function\" parameter with sdl.Surface#SetGamma.\n"
		"\n"
		"Not all display hardware is able to change gamma.\n"
		"\n"
		"**Return Value:** Returns -1 on error (or if gamma adjustment is not supported).");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "depth", VTYPE_number);
	DeclareArg(env, "Rmask", VTYPE_number);
	DeclareArg(env, "Gmask", VTYPE_number);
	DeclareArg(env, "Bmask", VTYPE_number);
	DeclareArg(env, "Amask", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Allocate an empty surface (must be called after `sdl.SetVideoMode`)\n"
		"\n"
		"If depth is 8 bits an empty palette is allocated for the surface, otherwise a 'packed-pixel' `sdl.PixelFormat` is created using the [RGBA]mask's provided (see sdl.PixelFormat).\n"
		"The flags specifies the type of surface that should be created, it is an OR'd combination of the following possible values.\n"
		"\n"
		"- `sdl.SWSURFACE` .. SDL will create the surface in system memory. This improves\n"
		"                  the performance of pixel level access, however you may not be\n"
		"                  able to take advantage of some types of hardware blitting.\n"
		"- `sdl.HWSURFACE` .. SDL will attempt to create the surface in video memory. This\n"
		"                  will allow SDL to take advantage of Video->Video blits (which\n"
		"                  are often accelerated).\n"
		"- `sdl.SRCCOLORKEY` .. This flag turns on colourkeying for blits from this surface.\n"
		"                  If `sdl.HWSURFACE` is also specified and colourkeyed blits are\n"
		"                  hardware-accelerated, then SDL will attempt to place the\n"
		"                  surface in video memory. Use sdl.SetColorKey to set or clear\n"
		"                  this flag after surface creation.\n"
		"- `sdl.SRCALPHA` .. This flag turns on alpha-blending for blits from this surface.\n"
		"                  If `sdl.HWSURFACE` is also specified and alpha-blending blits\n"
		"                  are hardware-accelerated, then the surface will be placed in\n"
		"                  video memory if possible. Use `sdl.Surface#SetAlpha` to set or\n"
		"                  clear this flag after surface creation.\n"
		"\n"
		"**Note:** If an alpha-channel is specified (that is, if `Amask` is nonzero), then the `sdl.SRCALPHA` flag is automatically set.\n"
		"You may remove this flag by calling `sdl.Surface#SetAlpha` after surface creation.\n"
		"\n"
		"**Return Value:** Returns the created surface, or `nil` upon error.\n");
}

Gura_ImplementFunction(CreateRGBSurface)
{
	SDL_Surface *pSurface = ::SDL_CreateRGBSurface(
		args.GetULong(0), args.GetInt(1), args.GetInt(2), args.GetInt(3),
		args.GetULong(4), args.GetULong(5), args.GetULong(6), args.GetULong(7));
	if (pSurface == nullptr) return Value::Null;
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurface, nullptr));
}

// sdl.CreateRGBSurfaceFrom(image:image) {block?}
Gura_DeclareFunction(CreateRGBSurfaceFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an `sdl.Surface` from the provided image instance."
		"\n"
		"Reference to the image instance is kept in the created `sdl.Surface` instance.\n"
		"\n"
		"See `sdl.CreateRGBSurface` for a more detailed description of the other parameters.\n"
		"\n"
		"**Return Value:** Return the created surface, or `nil` upon error.\n");
}

Gura_ImplementFunction(CreateRGBSurfaceFrom)
{
	Signal &sig = env.GetSignal();
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	Object_Surface *pObj = Object_Surface::CreateSurfaceFromImage(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, args, Value(pObj));
}

// sdl.LoadBMP(file:string) {block?}
Gura_DeclareFunction(LoadBMP)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Loads a surface from a named Windows BMP file.\n"
		"\n"
		"**Return Value:** Returns the new surface, or `nil` if there was an error.\n");
}

Gura_ImplementFunction(LoadBMP)
{
	Signal &sig = env.GetSignal();
	const char *file = args.GetString(0);
	SDL_Surface *pSurface = ::SDL_LoadBMP(file);
	if (pSurface == nullptr) {
		sig.SetError(ERR_RuntimeError, "failed to load an image %s", file);
		return Value::Null;
	}
	return ReturnValue(env, args, Object_Surface::CreateValue(pSurface, nullptr));
}

// sdl.BlitSurface(src:sdl.Surface, srcrect:sdl.Rect:nil, dst:sdl.Surface, dstrect:sdl.Rect:nil)
Gura_DeclareFunction(BlitSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src",		VTYPE_Surface);
	DeclareArg(env, "srcrect",	VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst",		VTYPE_Surface);
	DeclareArg(env, "dstrect",	VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This performs a fast blit from the source surface to the destination surface.\n"
		"\n"
		"The width and height in srcrect determine the size of the copied rectangle.\n"
		"Only the position is used in the dstrect (the width and height are ignored).\n"
		"\n"
		"If srcrect is `nil`, the entire surface is copied.\n"
		"If dstrect is `nil`, then the destination position (upper left corner) is (0, 0).\n"
		"\n"
		"The final blit rectangle is saved in dstrect after all clipping is performed (srcrect is not modified).\n"
		"\n"
		"The blit function should not be called on a locked surface.\n"
		"\n"
		"The results of blitting operations vary greatly depending on whether `sdl.SRCAPLHA` is set or not.\n"
		"See `sdl.Surface#SetAlpha` for an explaination of how this affects your results.\n"
		"Colorkeying and alpha attributes also interact with surface blitting, as the following pseudo-code should hopefully explain.\n"
		"    if (source surface has SDL_SRCALPHA set) {\n"
		"        if (source surface has alpha channel (that is, format->Amask != 0))\n"
		"            blit using per-pixel alpha, ignoring any colour key\n"
		"        else {\n"
		"            if (source surface has SDL_SRCCOLORKEY set)\n"
		"                blit using the colour key AND the per-surface alpha value\n"
		"            else\n"
		"                blit using the per-surface alpha value\n"
		"        }\n"
		"    } else {\n"
		"        if (source surface has SDL_SRCCOLORKEY set)\n"
		"            blit using the colour key\n"
		"        else\n"
		"            ordinary opaque rectangular blit\n"
		"    }\n"
		"\n"
		"**Return Value:** If the blit is successful, it returns 0, otherwise it returns -1.");
}

Gura_ImplementFunction(BlitSurface)
{
	SDL_Surface *src =
		dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	SDL_Surface *dst =
		dynamic_cast<Object_Surface *>(args.GetObject(2))->GetSurface();
	SDL_Rect *srcrect = nullptr, *dstrect = nullptr;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Set the position of the mouse cursor (generates a mouse motion event).\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "data", VTYPE_binary);
	DeclareArg(env, "mask", VTYPE_binary);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	DeclareArg(env, "hot_x", VTYPE_number);
	DeclareArg(env, "hot_y", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Create a cursor using the specified data and mask (in MSB format). The cursor width must be a multiple of 8 bits.\n"
		"\n"
		"The cursor is created in black and white according to the following:\n"
		"\n"
		"- Data / Mask .. Resulting pixel on screen\n"
		"- 0 / 1 .. White\n"
		"- 1 / 1 .. Black\n"
		"- 0 / 0 .. Transparent\n"
		"- 1 / 0 .. Inverted color if possible, black if not.\n");
}

Gura_ImplementFunction(CreateCursor)
{
	Signal &sig = env.GetSignal();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the currently active cursor to the specified one.\n"
		"If the cursor is currently visible, the change will be immediately represented on the display.\n");
}

Gura_ImplementFunction(SetCursor)
{
	Signal &sig = env.GetSignal();
	SDL_Cursor *pCursor =
			dynamic_cast<Object_Cursor *>(args.GetObject(0))->GetCursor();
	if (pCursor == nullptr) {
		sig.SetError(ERR_ValueError, "invalid cursor instance");
		return Value::Null;
	}
	::SDL_SetCursor(pCursor);
	return Value::Null;
}

// sdl.GetCursor()
Gura_DeclareFunction(GetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the currently active mouse cursor.\n");
}

Gura_ImplementFunction(GetCursor)
{
	SDL_Cursor *pCursor = ::SDL_GetCursor();
	return Object_Cursor::CreateValue(pCursor);
}

// sdl.ShowCursor(toggle:number)
Gura_DeclareFunction(ShowCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "toggle", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Toggle whether or not the cursor is shown on the screen.\n"
		"Passing `sdl.ENABLE` displays the cursor and passing `sdl.DISABLE` hides it.\n"
		"The current state of the mouse cursor can be queried by passing `sdl.QUERY`, either `sdl.DISABLE` or `sdl.ENABLE` will be returned.\n"
		"The cursor starts off displayed, but can be turned off.\n"
		"\n"
		"**Return Value:** Returns the current state of the cursor.\n");
}

Gura_ImplementFunction(ShowCursor)
{
	return Value(::SDL_ShowCursor(args.GetInt(0)));
}

// sdl.GL_GetAttribute(attr:number)
Gura_DeclareFunction(GL_GetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the value of the SDL/OpenGL attribute value.\n"
		"This is useful after a call to `sdl.SetVideoMode` to check whether your attributes have been set as you expected.\n"
		"\n"
		"**Return Value:** Returns the attribute value on success, or `nil` on an error.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the OpenGL attribute attr to value.\n"
		"The attributes you set don't take effect until after a call to `sdl.SetVideoMode`.\n"
		"You should use `sdl.GL_GetAttribute` to check the values after a `sdl.SetVideoMode` call.\n"
		"\n"
		"**Return Value:** Returns 0 on success, or -1 on error.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Swap the OpenGL buffers, if double-buffering is supported.\n");
}

Gura_ImplementFunction(GL_SwapBuffers)
{
	::SDL_GL_SwapBuffers();
	return Value::Null;
}

// sdl.CreateYUVOverlay()
Gura_DeclareFunction(CreateYUVOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "display", VTYPE_Surface);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"`sdl.CreateYUVOverlay` creates a YUV overlay of the specified width, height and format\n"
		"(see `sdl.Overlay` for a list of available formats), for the provided display.\n"
		"A sdl.Overlay structure is returned.\n"
		"\n"
		"The term 'overlay' is a misnomer since, unless the overlay is created in hardware,\n"
		"the contents for the display surface underneath the area where the overlay is shown will be overwritten when the overlay is displayed.\n");
}

Gura_ImplementFunction(CreateYUVOverlay)
{
	SDL_Surface *pSurface =
		dynamic_cast<Object_Surface *>(args.GetObject(3))->GetSurface();
	SDL_Overlay *pOverlay = ::SDL_CreateYUVOverlay(
			args.GetInt(0), args.GetInt(1), args.GetULong(2), pSurface);
	if (pOverlay == nullptr) return Value::Null;
	return Object_Overlay::CreateValue(pOverlay);
}

//-----------------------------------------------------------------------------
// SDL functions: Window Management
//-----------------------------------------------------------------------------
// sdl.WM_SetCaption(title:string, icon:string):void
Gura_DeclareFunction(WM_SetCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "title", VTYPE_string);
	DeclareArg(env, "icon", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the title-bar and icon name of the display window.\n");
}

Gura_ImplementFunction(WM_SetCaption)
{
	::SDL_WM_SetCaption(args.GetString(0), args.GetString(1));
	return Value::Null;
}

// sdl.WM_GetCaption()
Gura_DeclareFunction(WM_GetCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a list of strings of title-bar and icon name\n");
}

Gura_ImplementFunction(WM_GetCaption)
{
	char *title = nullptr, *icon = nullptr;
	::SDL_WM_GetCaption(&title, &icon);
	Value valTitle, valIcon;
	if (title != nullptr) valTitle = Value(title);
	if (icon != nullptr) valIcon = Value(icon);
	return Value::CreateList(env, valTitle, valIcon);
}

// sdl.WM_SetIcon(icon:sdl.Surface, mask?:binary)
Gura_DeclareFunction(WM_SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface);
	DeclareArg(env, "mask", VTYPE_binary, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the icon for the display window. Win32 icons must be 32x32.\n"
		"\n"
		"This function must be called before the first call to `sdl.SetVideoMode`.\n"
		"\n"
		"The mask is a bitmask that describes the shape of the icon.\n"
		"If mask is omitted, then the shape is determined by the colorkey of icon, if any, or makes the icon rectangular (no transparency) otherwise.\n"
		"\n"
		"If mask is specified, it points to a bitmap with bits set where the corresponding pixel should be visible.\n"
		"The format of the bitmap is as follows: Scanlines come in the usual top-down order.\n"
		"Each scanline consists of (width / 8) bytes, rounded up.\n"
		"The most significant bit of each byte represents the leftmost pixel.\n");
}

Gura_ImplementFunction(WM_SetIcon)
{
	SDL_Surface *pSurface = dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	const char *mask = args.Is_binary(1)? args.GetBinary(1).data() : nullptr;
	::SDL_WM_SetIcon(pSurface,
				const_cast<Uint8 *>(reinterpret_cast<const Uint8 *>(mask)));
	return Value::Null;
}

// sdl.WM_IconifyWindow()
Gura_DeclareFunction(WM_IconifyWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"If the application is running in a window managed environment SDL attempts to iconify/minimise it.\n"
		"If `sdl.WM_IconifyWindow` is successful, the application will receive a `sdl.APPACTIVE` loss event.\n"
		"\n"
		"**Return Value:** Returns non-zero on success or 0 if iconification is not support or was refused by the window manager.\n");
}

Gura_ImplementFunction(WM_IconifyWindow)
{
	return Value(::SDL_WM_IconifyWindow());
}

// sdl.WM_ToggleFullScreen(surface:sdl.Surface)
Gura_DeclareFunction(WM_ToggleFullScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Toggles the application between windowed and fullscreen mode, if supported.\n"
		"(X11 is the only target currently supported, BeOS support is experimental).\n"
		"\n"
		"**Return Value:** Returns 0 on failure or 1 on success.\n");
}

Gura_ImplementFunction(WM_ToggleFullScreen)
{
	SDL_Surface *pSurface = dynamic_cast<Object_Surface *>(args.GetObject(0))->GetSurface();
	return Value(::SDL_WM_ToggleFullScreen(pSurface));
}

// sdl.WM_GrabInput(mode:number)
Gura_DeclareFunction(WM_GrabInput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Grabbing means that the mouse is confined to the application window,\n"
		"and nearly all keyboard input is passed directly to the application, and not interpreted by a window manager, if any.\n"
		"\n"
		"When mode is `sdl.GRAB_QUERY` the grab mode is not changed, but the current grab mode is returned.\n"
		"\n"
		"Available values for mode are:\n"
		"- `sdl.GRAB_QUERY`\n"
		"- `sdl.GRAB_OFF`\n"
		"- `sdl.GRAB_ON`\n"
		"\n"
		"**Return Value:** The current/new mode value.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Pumps the event loop, gathering events from the input devices.\n"
		"\n"
		"`sdl.PumpEvents` gathers all the pending input information from devices and places it on the event queue.\n"
		"Without calls to `sdl.PumpEvents` no events would ever be placed on the queue.\n"
		"Often calls the need for `sdl.PumpEvents` is hidden from the user since `sdl.PollEvent` and `sdl.WaitEvent` implicitly call `sdl.PumpEvents`.\n"
		"However, if you are not polling or waiting for events (e.g. you are filtering them), then you must call `sdl.PumpEvents` to force an event queue update.\n"
		"\n"
		"**Note:** You can only call this function in the thread that set the video mode.\n");
}

Gura_ImplementFunction(PumpEvents)
{
	::SDL_PumpEvents();
	return Value::Null;
}

// sdl.AddEvents(events[]:Event, mask:number)
Gura_DeclareFunction(AddEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "events", VTYPE_Event, OCCUR_Once, FLAG_List);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This calles a function `SDL_PeepEvents` with `SDL_ADDEVENT`.\n"
		"\n"
		"`sdl.Event` instances, events, will be added to the back of the event queue.\n"
		"\n"
		"This function is thread-safe.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numevents", VTYPE_number);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This calles a function `SDL_PeepEvents` with `SDL_PEEKEVENT`.\n"
		"\n"
		"Up to numevents events at the front of the event queue, matching mask, will be returned and will not be removed from the queue.\n"
		"\n"
		"The mask parameter is an bitwise OR of `sdl.EVENTMASK(event_type)`, for all event types you are interested in.\n"
		"\n"
		"This function is thread-safe.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numevents", VTYPE_number);
	DeclareArg(env, "mask", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This calles a function `SDL_PeepEvents` with `SDL_GETEVENT`.\n"
		"\n"
		"Up to numevents events at the front of the event queue, matching mask, will be returned and will be removed from the queue.\n"
		"\n"
		"The mask parameter is an bitwise OR of `sdl.EVENTMASK(event_type)`, for all event types you are interested in.\n"
		"\n"
		"This function is thread-safe.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Polls for currently pending events, and returns `sdl.Event` instance if there are any pending events, or nil if there are none available.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Waits indefinitely for the next available event, returning `sdl.Event` instance, or nil if there was an error while waiting for events.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "event", VTYPE_Event);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The event queue can actually be used as a two way communication channel.\n"
		"Not only can events be read from the queue, but the user can also push their own events onto it.\n"
		"event is an instance of sdl.Event you wish to push onto the queue.\n"
		"\n"
		"**Note:** Pushing device input events onto the queue doesn't modify the state of the device within SDL.\n"
		"\n"
		"**Return Value:** Returns 0 on success or -1 if the event couldn't be pushed.\n");
}

Gura_ImplementFunction(PushEvent)
{
	SDL_Event *event = &dynamic_cast<Object_Event *>(args.GetObject(0))->GetEvent();
	return Value(::SDL_PushEvent(event));
}

// sdl.SetEventFilter(filter:function)
static Function *_pFuncEventFilter = nullptr;
static int EventFilter(const SDL_Event *event)
{
	if (_pFuncEventFilter == nullptr) return 1;
	Signal sig;
	Environment &env = _pFuncEventFilter->GetEnvScope();
	//ValueList valList;
	//valList.push_back(Object_Event::CreateValue(*event));
	AutoPtr<Args> pArgs(new Args());
	pArgs->AddValue(Object_Event::CreateValue(*event));
	Value result = _pFuncEventFilter->Eval(env, *pArgs);
	if (sig.IsSignalled()) return 0;
	return result.GetBoolean()? 1 : 0;
}

Gura_DeclareFunction(SetEventFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filter", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function sets up a filter to process all events before they are posted to the event queue.\n"
		"This is a very powerful and flexible feature. The filter is prototyped as:\n"
		"\n"
		"    filter(event:sdl.Event)\n"
		"\n"
		"If the filter returns true, then the event will be added to the internal queue.\n"
		"If it returns false, then the event will be dropped from the queue.\n"
		"This allows selective filtering of dynamically.\n"
		"\n"
		"There is one caveat when dealing with the `sdl.QUITEVENT` event type.\n"
		"The event filter is only called when the window manager desires to close the application window.\n"
		"If the event filter returns true, then the window will be closed, otherwise the window will remain open if possible.\n"
		"If the quit event is generated by an interrupt signal, it will bypass the internal queue and be delivered to the application at the next event poll.\n"
		"\n"
		"**Note:** Events pushed onto the queue with sdl.PushEvent or sdl.PeepEvents do not get passed through the event filter.\n"
		"\n"
		"**Note:** Be Careful! The event filter function may run in a different thread so be careful what you do within it.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function retrieves a pointer to the event filter that was previously set using `sdl.SetEventFilter`.\n"
		"A filter function is defined as:\n"
		"\n"
		"    filter(event:sdl.Event)\n"
		"\n"
		"**Return Value:** Returns a pointer to the event filter or nil if no filter has been set.\n");
}

Gura_ImplementFunction(GetEventFilter)
{
	if (_pFuncEventFilter == nullptr) return Value::Null;
	return Value(new Object_function(env, _pFuncEventFilter->Reference()));
}

// sdl.EventState(type:number, state:number)
Gura_DeclareFunction(EventState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_number);
	DeclareArg(env, "state", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function allows you to set the state of processing certain event type's.\n"
		"\n"
		"If state is set to `sdl.IGNORE`, that event type will be automatically dropped from the event queue and will not be filtered.\n"
		"\n"
		"If state is set to `sdl.ENABLE`, that event type will be processed normally.\n"
		"\n"
		"If state is set to `sdl.QUERY`, sdl.EventState will return the current processing state of the specified event type.\n"
		"\n"
		"A list of event type's can be found in the `SDL_Event` section.\n");
}

Gura_ImplementFunction(EventState)
{
	return Value(::SDL_EventState(args.GetUChar(0), args.GetInt(1)));
}

// sdl.CheckKeyState(key:number):map
Gura_DeclareFunction(CheckKeyState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Check if the specified key is being pushed down.\n"
		"key is one of `sdl.K_*` value. It returns true if the key is down, or false otherwise.\n"
		"\n"
		"This functions calls `SDL_GetKeyState` internally.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the current state of the modifier keys (CTRL, ALT, etc.).\n"
		"\n"
		"**Return Value:** The return value can be an OR'd combination of the following value.\n"
		"- `sdl.KMOD_NONE`\n"
		"- `sdl.KMOD_LSHIFT`\n"
		"- `sdl.KMOD_RSHIFT`\n"
		"- `sdl.KMOD_LCTRL`\n"
		"- `sdl.KMOD_RCTRL`\n"
		"- `sdl.KMOD_LALT`\n"
		"- `sdl.KMOD_RALT`\n"
		"- `sdl.KMOD_LMETA`\n"
		"- `sdl.KMOD_RMETA`\n"
		"- `sdl.KMOD_NUM`\n"
		"- `sdl.KMOD_CAPS`\n"
		"- `sdl.KMOD_MODE`\n"
		"\n"
		"SDL also defines the following symbols for convenience:\n"
		"- `sdl.KMOD_CTRL` (= `sdl.KMOD_LCTRL | sdl.KMOD_RCTRL`)\n"
		"- `sdl.KMOD_SHIFT` (= `sdl.KMOD_LSHIFT | sdl.KMOD_RSHIFT`)\n"
		"- `sdl.KMOD_ALT` (= `sdl.KMOD_LALT | sdl.KMOD_RALT`)\n"
		"- `sdl.KMOD_META` (= `sdl.KMOD_LMETA | sdl.KMOD_RMETA`)\n");
}

Gura_ImplementFunction(GetModState)
{
	return Value(static_cast<int>(::SDL_GetModState()));
}

// sdl.SetModState(modstate:number):void
Gura_DeclareFunction(SetModState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modstate", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The inverse of sdl.GetModState, sdl.SetModState allows you to impose modifier key states on your application.\n"
		"\n"
		"Simply pass your desired modifier states into modstate.\n"
		"This value my be a logical OR'd combination of the following:\n"
		"- `sdl.KMOD_NONE`\n"
		"- `sdl.KMOD_LSHIFT`\n"
		"- `sdl.KMOD_RSHIFT`\n"
		"- `sdl.KMOD_LCTRL`\n"
		"- `sdl.KMOD_RCTRL`\n"
		"- `sdl.KMOD_LALT`\n"
		"- `sdl.KMOD_RALT`\n"
		"- `sdl.KMOD_LMETA`\n"
		"- `sdl.KMOD_RMETA`\n"
		"- `sdl.KMOD_NUM`\n"
		"- `sdl.KMOD_CAPS`\n"
		"- `sdl.KMOD_MODE`\n");
}

Gura_ImplementFunction(SetModState)
{
	::SDL_SetModState(static_cast<SDLMod>(args.GetInt(0)));
	return Value::Null;
}

// sdl.GetKeyName(key:number)
Gura_DeclareFunction(GetKeyName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "key", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the SDL-defined name of the key.\n");
}

Gura_ImplementFunction(GetKeyName)
{
	return Value(::SDL_GetKeyName(static_cast<SDLKey>(args.GetInt(0))));
}

// sdl.EnableUNICODE(enable:number)
Gura_DeclareFunction(EnableUNICODE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "enable", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Enables/Disables Unicode keyboard translation.\n"
		"\n"
		"To obtain the character codes corresponding to received keyboard events, Unicode translation must first be turned on using this function.\n"
		"The translation incurs a slight overhead for each keyboard event and is therefore disabled by default.\n"
		"For each subsequently received key down event, the unicode member of the `SDL_keysym` structure will then contain the corresponding character code, or zero for keysyms that do not correspond to any character code.\n"
		"\n"
		"A value of 1 for enable enables Unicode translation; 0 disables it, and -1 leaves it unchanged (useful for querying the current translation mode).\n"
		"\n"
		"Note that only key press events will be translated, not release events.\n"
		"\n"
		"**Return Value:** Returns the previous translation mode (0 or 1).\n");
}

Gura_ImplementFunction(EnableUNICODE)
{
	return Value(::SDL_EnableUNICODE(args.GetInt(0)));
}

// sdl.EnableKeyRepeat(delay:number, interval:number)
Gura_DeclareFunction(EnableKeyRepeat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "delay", VTYPE_number);
	DeclareArg(env, "interval", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Enables or disables the keyboard repeat rate.\n"
		"delay specifies how long the key must be pressed before it begins repeating, it then repeats at the speed specified by interval.\n"
		"Both delay and interval are expressed in milliseconds.\n"
		"\n"
		"Setting delay to 0 disables key repeating completely.\n"
		"Good default values are `sdl.DEFAULT_REPEAT_DELAY` and `sdl.DEFAULT_REPEAT_INTERVAL`.\n"
		"\n"
		"**Return Value:** Returns 0 on success and -1 on failure.\n");
}

Gura_ImplementFunction(EnableKeyRepeat)
{
	return Value(::SDL_EnableKeyRepeat(args.GetInt(0), args.GetInt(1)));
}

// sdl.GetMouseState()
Gura_DeclareFunction(GetMouseState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"It returns a list `[button, x, y]`.\n"
		"`button` is a current button state as a bitmask, which can be tested using the `sdl.BUTTON(button)` function, and `x` and `y` are set to the current mouse cursor position.\n");
}

Gura_ImplementFunction(GetMouseState)
{
	int x, y;
	Uint8 state = ::SDL_GetMouseState(&x, &y);
	return Value::CreateList(env, Value(state), Value(x), Value(y));
}

// sdl.GetRelativeMouseState()
Gura_DeclareFunction(GetRelativeMouseState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"It returns a list `[button, x, y]`.\n"
		"`button` is a current button state as a bitmask, which can be tested using the `sdl.BUTTON(button)` function,\n"
		"and `x` and `y` are set to the change in the mouse position since the last call to `sdl.GetRelativeMouseState` or since event initialization.\n");
}

Gura_ImplementFunction(GetRelativeMouseState)
{
	int x, y;
	Uint8 state = ::SDL_GetRelativeMouseState(&x, &y);
	return Value::CreateList(env, Value(state), Value(x), Value(y));
}

// sdl.GetAppState()
Gura_DeclareFunction(GetAppState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function returns the current state of the application. The value returned is a bitwise combination of:\n"
		"\n"
		"- `sdl.APPMOUSEFOCUS` .. The application has mouse focus.\n"
		"- `sdl.APPINPUTFOCUS` .. The application has keyboard focus\n"
		"- `sdl.APPACTIVE` .. The application is visible\n");
}

Gura_ImplementFunction(GetAppState)
{
	return Value(::SDL_GetAppState());
}

// sdl.JoystickEventState(state:number)
Gura_DeclareFunction(JoystickEventState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "state", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function is used to enable or disable joystick event processing.\n"
		"With joystick event processing disabled you will have to update joystick states with `sdl.JoystickUpdate` and read the joystick information manually.\n"
		"state is either `sdl.QUERY`, `sdl.ENABLE` or `sdl.IGNORE`.\n"
		"\n"
		"**Note:** Joystick event handling is prefered\n"
		"\n"
		"**Return Value:** If state is `sdl.QUERY` then the current state is returned, otherwise the new processing state is returned.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Counts the number of joysticks attached to the system.\n"
		"\n"
		"**Return Value:** Returns the number of attached joysticks.\n");
}

Gura_ImplementFunction(NumJoysticks)
{
	return Value(::SDL_NumJoysticks());
}

// sdl.JoystickName(index:number):map
Gura_DeclareFunction(JoystickName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Get the implementation dependent name of joystick.\n"
		"The index parameter refers to the N'th joystick on the system.\n"
		"\n"
		"**Return Value:** Returns a string of the joystick name.\n");
}

Gura_ImplementFunction(JoystickName)
{
	return Value(::SDL_JoystickName(args.GetInt(0)));
}

// sdl.JoystickOpen(index:number):map
Gura_DeclareFunction(JoystickOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Opens a joystick for use within SDL.\n"
		"The index refers to the N'th joystick in the system.\n"
		"A joystick must be opened before it game be used.\n"
		"\n"
		"**Return Value:** Returns a `sdl.Joystick` instance on success. `nil` on failure.\n");
}

Gura_ImplementFunction(JoystickOpen)
{
	SDL_Joystick *pJoystick = ::SDL_JoystickOpen(args.GetInt(0));
	if (pJoystick == nullptr) return Value::Null;
	return Object_Joystick::CreateValue(pJoystick);
}

// sdl.JoystickOpened(index:number):map
Gura_DeclareFunction(JoystickOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Determines whether a joystick has already been opened within the application.\n"
		"index refers to the N'th joystick on the system.\n"
		"\n"
		"**Return Value:** Returns `true` if the joystick has been opened, or `false` if it has not.\n");
}

Gura_ImplementFunction(JoystickOpened)
{
	return Value(::SDL_JoystickOpened(args.GetInt(0))? true : false);
}

// sdl.JoystickUpdate():void
Gura_DeclareFunction(JoystickUpdate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Updates the state(position, buttons, etc.) of all open joysticks.\n"
		"If joystick events have been enabled with `sdl.JoystickEventState` then this is called automatically in the event loop.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "desired", VTYPE_AudioSpec);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(OpenAudio)
{
	Signal &sig = env.GetSignal();
	SDL_AudioSpec *desired =
		dynamic_cast<Object_AudioSpec *>(args.GetObject(0))->GetAudioSpec();
	SDL_AudioSpec *obtained =
		reinterpret_cast<SDL_AudioSpec *>(::malloc(sizeof(SDL_AudioSpec)));
	if (::SDL_OpenAudio(desired, obtained) < 0) {
		sig.SetError(ERR_RuntimeError, "failed to open audio device");
		::free(obtained);
		return Value::Null;
	}
	return Object_AudioSpec::CreateValue(obtained, nullptr, nullptr, 0);
}

// sdl.PauseAudio(pause_on:number):void
Gura_DeclareFunction(PauseAudio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(PauseAudio)
{
	::SDL_PauseAudio(args.GetInt(0));
	return Value::Null;
}

// sdl.GetAudioStatus()
Gura_DeclareFunction(GetAudioStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(GetAudioStatus)
{
	return Value(static_cast<int>(::SDL_GetAudioStatus()));
}

// sdl.LoadWAV(file:string)
Gura_DeclareFunction(LoadWAV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "file", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(LoadWAV)
{
	Signal &sig = env.GetSignal();
	SDL_AudioSpec *pAudioSpec =
		reinterpret_cast<SDL_AudioSpec *>(::malloc(sizeof(SDL_AudioSpec)));
	Uint8 *audio_buf = nullptr;
	Uint32 audio_len = 0;
	if (::SDL_LoadWAV(args.GetString(0), pAudioSpec, &audio_buf, &audio_len) == nullptr) {
		sig.SetError(ERR_RuntimeError, "failed to load WAV data");
		return Value::Null;
	}
	pAudioSpec->callback = Object_AudioSpec::CallbackStub;
	pAudioSpec->userdata = nullptr;
	return Object_AudioSpec::CreateValue(pAudioSpec, nullptr, audio_buf, audio_len);
}

// sdl.BuildAudioCVT(src_format:number, src_channels:number, src_rate:number,
//                   dst_format:number, dst_channels:number, dst_rate:number)
Gura_DeclareFunction(BuildAudioCVT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number);
	DeclareArg(env, "src_channels", VTYPE_number);
	DeclareArg(env, "src_rate", VTYPE_number);
	DeclareArg(env, "dst_format", VTYPE_number);
	DeclareArg(env, "dst_channels", VTYPE_number);
	DeclareArg(env, "dst_rate", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(LockAudio)
{
	::SDL_LockAudio();
	return Value::Null;
}

// sdl.UnlockAudio():void
Gura_DeclareFunction(UnlockAudio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(UnlockAudio)
{
	::SDL_LockAudio();
	return Value::Null;
}

// sdl.CloseAudio():void
Gura_DeclareFunction(CloseAudio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(CDNumDrives)
{
	return Value(::SDL_CDNumDrives());
}

// sdl.CDName(drive:number):map
Gura_DeclareFunction(CDName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "drive", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(CDName)
{
	return Value(::SDL_CDName(args.GetInt(0)));
}

// sdl.CDOpen(drive:number)
Gura_DeclareFunction(CDOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "drive", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(CDOpen)
{
	Signal &sig = env.GetSignal();
	SDL_CD *pCD = ::SDL_CDOpen(args.GetInt(0));
	if (pCD == nullptr) {
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Get the number of milliseconds since the SDL library initialization.\n"
		"Note that this value wraps if the program runs for more than ~49 days.\n");
}

Gura_ImplementFunction(GetTicks)
{
	return Value(::SDL_GetTicks());
}

// sdl.Delay(ms:number):void
Gura_DeclareFunction(Delay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "ms", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Wait a specified number of milliseconds before returning.\n"
		"`sdl.Delay` will wait at least the specified time, but possible longer due to OS scheduling.\n"
		"\n"
		"**Note:** Count on a delay granularity of at least 10 ms. Some platforms have shorter clock ticks but this is the most common.\n");
}

Gura_ImplementFunction(Delay)
{
	::SDL_Delay(args.GetULong(0));
	return Value::Null;
}

// sdl.AddTimer(interval:number, callback?:function):[thread] {block?}
Gura_DeclareFunction(AddTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number);
	DeclareArg(env, "callback", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(thread_));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Adds a callback function to be run after the specified number of milliseconds has elapsed.\n"
		"The callback function is passed the current timer interval and the user supplied parameter from the `sdl.AddTimer` call and returns the next timer interval.\n"
		"If the returned value from the callback is the same as the one passed in, the periodic alarm continues, otherwise a new alarm is scheduled.\n"
		"\n"
		"To cancel a currently running timer call `sdl.Timer#RemoveTimer` with the `sdl.Timer` instance returned from `sdl.AddTimer`.\n"
		//"\n"
		//"The timer callback function may run in a different thread than your main program, and so shouldn't call any functions from within itself.\n"
		//"You may always call sdl.PushEvent, however.\n"
		"\n"
		"The granularity of the timer is platform-dependent, but you should count on it being at least 10 ms as this is the most common number.\n"
		"This means that if you request a 16 ms timer, your callback will run approximately 20 ms later on an unloaded system.\n"
		"If you wanted to set a flag signaling a frame update at 30 frames per second (every 33 ms), you might set a timer for 30 ms (see example below).\n"
		"If you use this function, you need to pass `sdl.INIT_TIMER` to `sdl.Init`.\n"
		"\n"
		"**Gura:** You can register the timer callback function by specifying callback function in the argument or declaring block\n"
		"It will be called in the same thread of event dispatching loop while you can also run it in a different thread by specying `:thread` attribute.\n"
		"\n"
		"**Return Value:** Returns a `sdl.Timer` instance for the added timer.\n");
}

Gura_ImplementFunction(AddTimer)
{
	Signal &sig = env.GetSignal();
	Object_function *pObjFunc;
	if (args.Is_function(1)) {
		pObjFunc = Object_function::Reference(Object_function::GetObject(args, 1));
	} else if (args.IsBlockSpecified()) {
		const Function *pFunc = args.GetBlockFunc(env, GetSymbolForBlock());
		if (sig.IsSignalled()) return Value::Null;
		pObjFunc = new Object_function(env, Function::Reference(pFunc));
	} else {
		sig.SetError(ERR_ValueError, "function or block must be specified");
		return Value::Null;
	}
	bool threadFlag = args.IsSet(Gura_UserSymbol(thread_));
	Object_Timer *pObj = new Object_Timer(pObjFunc, threadFlag);
	pObj->AddTimer(args.GetULong(0));
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Object constructors
//-----------------------------------------------------------------------------
// sdl.Rect(x:number, y:number, w:number, h:number):map {block?}
Gura_DeclareFunction(Rect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an instance of sdl.Rect structure.");
}

Gura_ImplementFunction(Rect)
{
	SDL_Rect rect;
	rect.x = args.GetInt(0);
	rect.y = args.GetInt(1);
	rect.w = args.GetInt(2);
	rect.h = args.GetInt(3);
	return ReturnValue(env, args, Object_Rect::CreateValue(rect));
}

// sdl.Color(r:number, g:number, b:number):map {block?}
Gura_DeclareFunction(Color)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "g", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Color));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an instance of sdl.Color structure.");
}

Gura_ImplementFunction(Color)
{
	SDL_Color color;
	color.r = args.GetUChar(0);
	color.g = args.GetUChar(1);
	color.b = args.GetUChar(2);
	color.unused = 0;
	return ReturnValue(env, args, Object_Color::CreateValue(color));
}

// sdl.AudioSpec(freq:number => 22050, format:number => AUDIO_S16,
//     channels:number => 1, samples:number => 8192, callback?:function) {block?}
Gura_DeclareFunction(AudioSpec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "freq",		VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(22050));
	DeclareArg(env, "format",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(AUDIO_S16));
	DeclareArg(env, "channels",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(1));
	DeclareArg(env, "samples",	VTYPE_number, OCCUR_Once, FLAG_None,
												new Expr_Value(8192));
	DeclareArg(env, "callback",	VTYPE_function, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"It passes an audio object to the callback that is supposed to fill it\n"
	"with audio data.");
	SetClassToConstruct(Gura_UserClass(AudioSpec));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an instance of `sdl.AudioSpec` structure.");
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
	pAudioSpec->userdata	= nullptr;
	Function *pFuncCallback = nullptr;
	if (args.Is_function(4)) {
		pFuncCallback = Function::Reference(args.GetFunction(4));
	}
	Object_AudioSpec *pObj =
			new Object_AudioSpec(pAudioSpec, pFuncCallback, nullptr, 0);
	pAudioSpec->userdata = pObj;
	return ReturnValue(env, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
// sdl.EVENTMASK(X:number)
Gura_DeclareFunction(EVENTMASK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "X", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a bit mask for an event ID.\n");
}

Gura_ImplementFunction(EVENTMASK)
{
	return Value(SDL_EVENTMASK(args.GetInt(0)));
}

// sdl.BUTTON(X:number)
Gura_DeclareFunction(BUTTON)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "X", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a bit mask to check button status. X is one of the following:\n"
		"- `sdl.BUTTON_LEFT`\n"
		"- `sdl.BUTTON_MIDDLE`\n"
		"- `sdl.BUTTON_RIGHT`\n"
		"- `sdl.BUTTON_WHEELUP`\n"
		"- `sdl.BUTTON_WHEELDOWN`\n"
		"- `sdl.BUTTON_X1`\n"
		"- `sdl.BUTTON_X2`\n");
}

Gura_ImplementFunction(BUTTON)
{
	return Value(SDL_BUTTON(args.GetInt(0)));
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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
	Gura_RealizeAndPrepareUserClass(Cursor,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Timer,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Event,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Rect,			env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Color,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Palette,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(PixelFormat,	env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Surface,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Overlay,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(VideoInfo,	env.LookupClass(VTYPE_object));
	//Gura_RealizeAndPrepareUserClass(Font,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Joystick,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(AudioSpec,	env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(AudioCVT,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(CDtrack,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(CD,			env.LookupClass(VTYPE_object));
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
	Gura_AssignValue(BUTTON_LEFT,		Value(SDL_BUTTON_LEFT));
	Gura_AssignValue(BUTTON_MIDDLE,		Value(SDL_BUTTON_MIDDLE));
	Gura_AssignValue(BUTTON_RIGHT,		Value(SDL_BUTTON_RIGHT));
	Gura_AssignValue(BUTTON_WHEELUP,	Value(SDL_BUTTON_WHEELUP));
	Gura_AssignValue(BUTTON_WHEELDOWN,	Value(SDL_BUTTON_WHEELDOWN));
	Gura_AssignValue(BUTTON_X1,			Value(SDL_BUTTON_X1));
	Gura_AssignValue(BUTTON_X2,			Value(SDL_BUTTON_X2));
	Gura_AssignValue(BUTTON_LMASK,		Value(SDL_BUTTON_LMASK));
	Gura_AssignValue(BUTTON_MMASK,		Value(SDL_BUTTON_MMASK));
	Gura_AssignValue(BUTTON_RMASK,		Value(SDL_BUTTON_RMASK));
	Gura_AssignValue(BUTTON_X1MASK,		Value(SDL_BUTTON_X1MASK));
	Gura_AssignValue(BUTTON_X2MASK,		Value(SDL_BUTTON_X2MASK));
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
	// Class reference assignment or object constructors
	Gura_AssignValue(Cursor,		Value(Gura_UserClass(Cursor)->Reference()));
	Gura_AssignValue(Timer,			Value(Gura_UserClass(Timer)->Reference()));
	Gura_AssignValue(Event,			Value(Gura_UserClass(Event)->Reference()));
	Gura_AssignFunction(Rect);
	Gura_AssignFunction(Color);
	Gura_AssignValue(Palette,		Value(Gura_UserClass(Palette)->Reference()));
	Gura_AssignValue(PixelFormat,	Value(Gura_UserClass(PixelFormat)->Reference()));
	Gura_AssignValue(Surface,		Value(Gura_UserClass(Surface)->Reference()));
	Gura_AssignValue(Overlay,		Value(Gura_UserClass(Overlay)->Reference()));
	Gura_AssignValue(VideoInfo,		Value(Gura_UserClass(VideoInfo)->Reference()));
	//Gura_AssignValue(Font,		Value(Gura_UserClass(Font)->Reference()));
	Gura_AssignValue(Joystick,		Value(Gura_UserClass(Joystick)->Reference()));
	Gura_AssignFunction(AudioSpec);
	Gura_AssignFunctionEx(BuildAudioCVT, "AudioCVT");
	//Gura_AssignValue(CDTrack,		Value(Gura_UserClass(CDTrack)->Reference()));
	Gura_AssignValue(CD,			Value(Gura_UserClass(CD)->Reference()));
	// macros
	Gura_AssignFunction(EVENTMASK);
	Gura_AssignFunction(BUTTON);
	// test function
	Gura_AssignFunction(test);
	return true;
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

Gura_EndModuleBody(sdl, sdl)

Gura_RegisterModule(sdl)
