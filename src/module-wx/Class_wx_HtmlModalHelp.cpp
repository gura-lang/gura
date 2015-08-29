//----------------------------------------------------------------------------
// wxHtmlModalHelp
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlModalHelp: public wxHtmlModalHelp, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlModalHelp *_pObj;
public:
	inline wx_HtmlModalHelp(wxWindow* parent, const wxString& helpFile, const wxString& topic, int style) : wxHtmlModalHelp(parent, helpFile, topic, style), _pObj(nullptr) {}
	~wx_HtmlModalHelp();
	inline void AssocWithGura(Object_wx_HtmlModalHelp *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlModalHelp::~wx_HtmlModalHelp()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlModalHelp::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlModalHelp
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlModalHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlModalHelp));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "helpFile", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlModalHelp)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString helpFile = wxString::FromUTF8(arg.GetString(1));
	wxString topic = wxEmptyString;
	if (arg.IsValid(2)) topic = wxString::FromUTF8(arg.GetString(2));
	int style = wxHF_DEFAULT_STYLE | wxHF_DIALOG | wxHF_MODAL;
	if (arg.IsValid(3)) style = arg.GetInt(3);
	wx_HtmlModalHelp *pEntity = new wx_HtmlModalHelp(parent, helpFile, topic, style);
	Object_wx_HtmlModalHelp *pObj = Object_wx_HtmlModalHelp::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlModalHelp(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlModalHelp
//----------------------------------------------------------------------------
Object_wx_HtmlModalHelp::~Object_wx_HtmlModalHelp()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HtmlModalHelp::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlModalHelp::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlModalHelp:");
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
// Class implementation for wxHtmlModalHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlModalHelp)
{
	Gura_AssignFunction(HtmlModalHelp);
}

Gura_ImplementDescendantCreator(wx_HtmlModalHelp)
{
	return new Object_wx_HtmlModalHelp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
