//----------------------------------------------------------------------------
// wxMiniFrame
// extracted from minifram.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MiniFrame: public wxMiniFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MiniFrame *_pObj;
public:
	inline wx_MiniFrame() : wxMiniFrame(), _pObj(nullptr) {}
	inline wx_MiniFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxMiniFrame(parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	~wx_MiniFrame();
	inline void AssocWithGura(Object_wx_MiniFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MiniFrame::~wx_MiniFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MiniFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMiniFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(MiniFrameEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MiniFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MiniFrameEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MiniFrame *pEntity = new wx_MiniFrame();
	Object_wx_MiniFrame *pObj = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MiniFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(MiniFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MiniFrame));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MiniFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCAPTION | wxRESIZE_BORDER;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_MiniFrame *pEntity = new wx_MiniFrame(parent, id, title, *pos, *size, style, name);
	Object_wx_MiniFrame *pObj = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MiniFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MiniFrame, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MiniFrame, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_MiniFrame *pThis = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCAPTION | wxRESIZE_BORDER;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMiniFrame
//----------------------------------------------------------------------------
Object_wx_MiniFrame::~Object_wx_MiniFrame()
{
}

Object *Object_wx_MiniFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MiniFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MiniFrame:");
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
// Class implementation for wxMiniFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MiniFrame)
{
	Gura_AssignFunction(MiniFrameEmpty);
	Gura_AssignFunction(MiniFrame);
	Gura_AssignMethod(wx_MiniFrame, Create);
}

Gura_ImplementDescendantCreator(wx_MiniFrame)
{
	return new Object_wx_MiniFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
