//----------------------------------------------------------------------------
// wxGLCanvas
// extracted from glcanvas.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

int *MakeAttribList(const ValueList &valList);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GLCanvas: public wxGLCanvas, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GLCanvas *_pObj;
public:
	inline wx_GLCanvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, id, pos, size, style, name, attribList, palette), _sig(NULL), _pObj(NULL) {}
	inline wx_GLCanvas(wxWindow* parent, wxGLContext* sharedContext, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, sharedContext, id, pos, size, style, name, attribList, palette), _sig(NULL), _pObj(NULL) {}
	inline wx_GLCanvas(wxWindow* parent, wxGLCanvas* sharedCanvas, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name, int* attribList, const wxPalette& palette) : wxGLCanvas(parent, sharedCanvas, id, pos, size, style, name, attribList, palette), _sig(NULL), _pObj(NULL) {}
	inline wx_GLCanvas(wxWindow* parent, wxWindowID id, int* attribList, const wxPoint& pos, const wxSize& size, long style, const wxString& name, const wxPalette& palette) : wxGLCanvas(parent, id, attribList, pos, size, style, name, palette), _sig(NULL), _pObj(NULL) {}
	~wx_GLCanvas();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GLCanvas *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GLCanvas::~wx_GLCanvas()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GLCanvas::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGLCanvas
//----------------------------------------------------------------------------
Gura_DeclareFunction(GLCanvas)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "attribList", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLCanvas)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("GLCanvas");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	int *attribList = 0;
	if (args.IsValid(6)) attribList = MakeAttribList(args.GetList(6));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (args.IsValid(7)) palette = Object_wx_Palette::GetObject(args, 7)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

#if 0
Gura_DeclareFunction(GLCanvas_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxGLContext *sharedContext = Object_wx_GLContext::GetObject(args, 1)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(2)) id = static_cast<wxWindowID>(args.GetInt(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("GLCanvas");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	int *attribList = 0;
	if (args.IsValid(7)) attribList = MakeAttribList(args.GetList(7));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (args.IsValid(8)) palette = Object_wx_Palette::GetObject(args, 8)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, sharedContext, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}
#endif

#if 0
Gura_DeclareFunction(GLCanvas_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxGLCanvas *sharedCanvas = Object_wx_GLCanvas::GetObject(args, 1)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(2)) id = static_cast<wxWindowID>(args.GetInt(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("GLCanvas");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	int *attribList = 0;
	if (args.IsValid(7)) attribList = MakeAttribList(args.GetList(7));
	wxPalette *palette = (wxPalette *)(&wxNullPalette);
	if (args.IsValid(8)) palette = Object_wx_Palette::GetObject(args, 8)->GetEntity();
	wx_GLCanvas *pEntity = new wx_GLCanvas(parent, sharedCanvas, id, *pos, *size, style, name, attribList, *palette);
	//delete attribList;
	Object_wx_GLCanvas *pObj = Object_wx_GLCanvas::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GLCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_GLCanvas, GetContext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GLCanvas, GetContext)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGLContext *rtn = (wxGLContext *)pThis->GetEntity()->GetContext();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GLContext(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_GLCanvas, SetCurrent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "RC", VTYPE_any, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GLCanvas, SetCurrent)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	if (args.IsInstanceOf(0, VTYPE_wx_GLContext)) {
		wxGLContext *RC = Object_wx_GLContext::GetObject(args, 0)->GetEntity();
		pThis->GetEntity()->SetCurrent(*RC);
	} else if (args.IsInstanceOf(0, VTYPE_wx_GLCanvas)) {
		wxGLCanvas *RC = Object_wx_GLCanvas::GetObject(args, 0)->GetEntity();
		pThis->GetEntity()->SetCurrent(RC);
	} else if (args.IsInvalid(0)) {
		pThis->GetEntity()->SetCurrent();
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
	}
	return Value::Null;
}

Gura_DeclareMethod(wx_GLCanvas, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, SetColour)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colour = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetColour(colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_GLCanvas, SwapBuffers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLCanvas, SwapBuffers)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SwapBuffers();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGLCanvas
//----------------------------------------------------------------------------
Object_wx_GLCanvas::~Object_wx_GLCanvas()
{
}

Object *Object_wx_GLCanvas::Clone() const
{
	return NULL;
}

String Object_wx_GLCanvas::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GLCanvas:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GLCanvas::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(GLCanvas);
	//Gura_AssignFunction(GLCanvas_1);
	//Gura_AssignFunction(GLCanvas_2);
}

//----------------------------------------------------------------------------
// Class implementation for wxGLCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLCanvas)
{
	Gura_AssignMethod(wx_GLCanvas, GetContext);
	Gura_AssignMethod(wx_GLCanvas, SetCurrent);
	Gura_AssignMethod(wx_GLCanvas, SetColour);
	Gura_AssignMethod(wx_GLCanvas, SwapBuffers);
}

Gura_ImplementDescendantCreator(wx_GLCanvas)
{
	return new Object_wx_GLCanvas((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
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

}}
