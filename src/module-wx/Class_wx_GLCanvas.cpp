//----------------------------------------------------------------------------
// wxGLCanvas
// extracted from glcanvas.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

int *MakeAttribList(const ValueList &valList);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GLCanvas: public wxGLCanvas, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GLCanvas *_pObj;
public:
	inline wx_GLCanvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, id, pos, size, style, name, attribList, palette), _pObj(nullptr) {}
	inline wx_GLCanvas(wxWindow* parent, wxGLContext* sharedContext, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, sharedContext, id, pos, size, style, name, attribList, palette), _pObj(nullptr) {}
	inline wx_GLCanvas(wxWindow* parent, wxGLCanvas* sharedCanvas, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, sharedCanvas, id, pos, size, style, name, attribList, palette), _pObj(nullptr) {}
	inline wx_GLCanvas(wxWindow* parent, wxWindowID id, int* attribList, const wxPoint& pos, const wxSize& size, long style, const wxString& name, const wxPalette& palette) : wxGLCanvas(parent, id, attribList, pos, size, style, name, palette), _pObj(nullptr) {}
	~wx_GLCanvas();
	inline void AssocWithGura(Object_wx_GLCanvas *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GLCanvas::~wx_GLCanvas()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GLCanvas::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGLCanvas
//----------------------------------------------------------------------------
Gura_DeclareFunction(GLCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "attribList", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLCanvas)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("GLCanvas");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	int *attribList = 0;
	if (arg.IsValid(6)) attribList = MakeAttribList(arg.GetList(6));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (arg.IsValid(7)) palette = Object_wx_Palette::GetObject(arg, 7)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

#if 0
Gura_DeclareFunction(GLCanvas_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "sharedContext", VTYPE_wx_GLContext, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "attribList", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLCanvas_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxGLContext *sharedContext = Object_wx_GLContext::GetObject(arg, 1)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(2)) id = static_cast<wxWindowID>(arg.GetInt(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = 0;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("GLCanvas");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	int *attribList = 0;
	if (arg.IsValid(7)) attribList = MakeAttribList(arg.GetList(7));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (arg.IsValid(8)) palette = Object_wx_Palette::GetObject(arg, 8)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, sharedContext, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}
#endif

#if 0
Gura_DeclareFunction(GLCanvas_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "sharedCanvas", VTYPE_wx_GLCanvas, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "attribList", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLCanvas_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxGLCanvas *sharedCanvas = Object_wx_GLCanvas::GetObject(arg, 1)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(2)) id = static_cast<wxWindowID>(arg.GetInt(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = 0;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("GLCanvas");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	int *attribList = 0;
	if (arg.IsValid(7)) attribList = MakeAttribList(arg.GetList(7));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (arg.IsValid(8)) palette = Object_wx_Palette::GetObject(arg, 8)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, sharedCanvas, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}
#endif

Gura_DeclareMethod(wx_GLCanvas, GetContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GLCanvas, GetContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGLContext *rtn = (wxGLContext *)pThis->GetEntity()->GetContext();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_GLContext(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_GLCanvas, SetCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "RC", VTYPE_any, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GLCanvas, SetCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	if (arg.IsInstanceOf(0, VTYPE_wx_GLContext)) {
		wxGLContext *RC = Object_wx_GLContext::GetObject(arg, 0)->GetEntity();
		pThis->GetEntity()->SetCurrent(*RC);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_GLCanvas)) {
		wxGLCanvas *RC = Object_wx_GLCanvas::GetObject(arg, 0)->GetEntity();
		pThis->GetEntity()->SetCurrent(RC);
	} else if (arg.IsInvalid(0)) {
		pThis->GetEntity()->SetCurrent();
	} else {
		SetError_ArgumentTypeByIndex(sig, arg, 0);
	}
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString colour = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, SwapBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLCanvas, SwapBuffers)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SwapBuffers();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGLCanvas
//----------------------------------------------------------------------------
Object_wx_GLCanvas::~Object_wx_GLCanvas()
{
}

Object *Object_wx_GLCanvas::Clone() const
{
	return nullptr;
}

String Object_wx_GLCanvas::ToString(bool exprFlag)
{
	String rtn("<wx.GLCanvas:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLCanvas)
{
	Gura_AssignFunction(GLCanvas);
	//Gura_AssignFunction(GLCanvas_1);
	//Gura_AssignFunction(GLCanvas_2);
	Gura_AssignMethod(wx_GLCanvas, GetContext);
	Gura_AssignMethod(wx_GLCanvas, SetCurrent);
	Gura_AssignMethod(wx_GLCanvas, SetColour);
	Gura_AssignMethod(wx_GLCanvas, SwapBuffers);
}

Gura_ImplementDescendantCreator(wx_GLCanvas)
{
	return new Object_wx_GLCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

int *MakeAttribList(const ValueList &valList)
{
	int *attribList = new int [valList.size() + 1];
	size_t i = 0;
	foreach_const (ValueList, pValue, valList) {
		const Value &value = *pValue;
		attribList[i++] = value.GetInt();
	}
	attribList[i] = 0;
	return attribList;
}

Gura_EndModuleScope(wx)
