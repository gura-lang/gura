//----------------------------------------------------------------------------
// wxHtmlHelpFrame
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddToolbarButtons);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpFrame: public wxHtmlHelpFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlHelpFrame *_pObj;
public:
	inline wx_HtmlHelpFrame(wxHtmlHelpData* data) : wxHtmlHelpFrame(data), _pObj(nullptr) {}
	inline wx_HtmlHelpFrame(wxWindow* parent, int wxWindowID, const wxString& title, int style, wxHtmlHelpData* data) : wxHtmlHelpFrame(parent, wxWindowID, title, style, data), _pObj(nullptr) {}
	//virtual void AddToolbarButtons(wxToolBar * toolBar, int style);
	~wx_HtmlHelpFrame();
	inline void AssocWithGura(Object_wx_HtmlHelpFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpFrame::~wx_HtmlHelpFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlHelpFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxHtmlHelpData *data = (wxHtmlHelpData *)(nullptr);
	if (args.IsValid(0)) data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wx_HtmlHelpFrame *pEntity = new wx_HtmlHelpFrame(data);
	Object_wx_HtmlHelpFrame *pObj = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlHelpFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(HtmlHelpFrame_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpFrame_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int wxWindowID = args.GetInt(1);
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	wxHtmlHelpData *data = (wxHtmlHelpData *)(nullptr);
	if (args.IsValid(4)) data = Object_wx_HtmlHelpData::GetObject(args, 4)->GetEntity();
	wx_HtmlHelpFrame *pEntity = new wx_HtmlHelpFrame(parent, wxWindowID, title, style, data);
	Object_wx_HtmlHelpFrame *pObj = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlHelpFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolBar", VTYPE_wx_ToolBar, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolBar *toolBar = Object_wx_ToolBar::GetObject(args, 0)->GetEntity();
	int style = args.GetInt(1);
	pThis->GetEntity()->AddToolbarButtons(toolBar, style);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pThis->GetEntity()->Create(parent, id, title, style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpFrame, GetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, GetController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *rtn = (wxHtmlHelpController *)pThis->GetEntity()->GetController();
	return ReturnValue(env, args, Value(new Object_wx_HtmlHelpController(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlHelpFrame, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, ReadCustomization)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "contoller", VTYPE_wx_HtmlHelpController, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *contoller = Object_wx_HtmlHelpController::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetController(contoller);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString format = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitleFormat(format);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, WriteCustomization)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Object_wx_HtmlHelpFrame::~Object_wx_HtmlHelpFrame()
{
}

Object *Object_wx_HtmlHelpFrame::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpFrame::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpFrame:");
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
// Class implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpFrame)
{
	Gura_RealizeUserSymbol(AddToolbarButtons);
	Gura_AssignFunction(HtmlHelpFrame);
	Gura_AssignFunction(HtmlHelpFrame_1);
	Gura_AssignMethod(wx_HtmlHelpFrame, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpFrame, Create);
	Gura_AssignMethod(wx_HtmlHelpFrame, GetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpFrame, WriteCustomization);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpFrame)
{
	return new Object_wx_HtmlHelpFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
