//----------------------------------------------------------------------------
// wxHtmlPrintout
// extracted from htprint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlPrintout: public wxHtmlPrintout, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlPrintout *_pObj;
public:
	inline wx_HtmlPrintout(const wxString& title) : wxHtmlPrintout(title), _pObj(nullptr) {}
	~wx_HtmlPrintout();
	inline void AssocWithGura(Object_wx_HtmlPrintout *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlPrintout::~wx_HtmlPrintout()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlPrintout::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlPrintout));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlPrintout)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString title = wxT("Printout");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	wx_HtmlPrintout *pEntity = new wx_HtmlPrintout(title);
	Object_wx_HtmlPrintout *pObj = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlPrintout(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareClassMethod(wx_HtmlPrintout, AddFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_wx_HtmlFilter, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_HtmlPrintout, AddFilter)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxHtmlFilter *filter = Object_wx_HtmlFilter::GetObject(args, 0)->GetEntity();
	wxHtmlPrintout::AddFilter(filter);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlPrintout, SetFonts)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString normal_face = wxString::FromUTF8(args.GetString(0));
	wxString fixed_face = wxString::FromUTF8(args.GetString(1));
	int *sizes = nullptr;
	if (args.IsValid(2)) *sizes = args.GetInt(2);
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetFooter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "footer", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetFooter)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString footer = wxString::FromUTF8(args.GetString(0));
	int pg = wxPAGE_ALL;
	if (args.IsValid(1)) pg = args.GetInt(1);
	pThis->GetEntity()->SetFooter(footer, pg);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "header", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHeader)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString header = wxString::FromUTF8(args.GetString(0));
	int pg = wxPAGE_ALL;
	if (args.IsValid(1)) pg = args.GetInt(1);
	pThis->GetEntity()->SetHeader(header, pg);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHtmlFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "htmlfile", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHtmlFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString htmlfile = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetHtmlFile(htmlfile);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHtmlText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "html", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "basepath", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "isdir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHtmlText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString html = wxString::FromUTF8(args.GetString(0));
	wxString basepath = wxEmptyString;
	if (args.IsValid(1)) basepath = wxString::FromUTF8(args.GetString(1));
	bool isdir = true;
	if (args.IsValid(2)) isdir = args.GetBoolean(2);
	pThis->GetEntity()->SetHtmlText(html, basepath, isdir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "top", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "left", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "right", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "spaces", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	float top = 25.2;
	if (args.IsValid(0)) top = args.GetFloat(0);
	float bottom = 25.2;
	if (args.IsValid(1)) bottom = args.GetFloat(1);
	float left = 25.2;
	if (args.IsValid(2)) left = args.GetFloat(2);
	float right = 25.2;
	if (args.IsValid(3)) right = args.GetFloat(3);
	float spaces = 5;
	if (args.IsValid(4)) spaces = args.GetFloat(4);
	pThis->GetEntity()->SetMargins(top, bottom, left, right, spaces);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Object_wx_HtmlPrintout::~Object_wx_HtmlPrintout()
{
}

Object *Object_wx_HtmlPrintout::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlPrintout:");
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
// Class implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlPrintout)
{
	Gura_AssignFunction(HtmlPrintout);
	Gura_AssignMethod(wx_HtmlPrintout, AddFilter);
	Gura_AssignMethod(wx_HtmlPrintout, SetFonts);
	Gura_AssignMethod(wx_HtmlPrintout, SetFooter);
	Gura_AssignMethod(wx_HtmlPrintout, SetHeader);
	Gura_AssignMethod(wx_HtmlPrintout, SetHtmlFile);
	Gura_AssignMethod(wx_HtmlPrintout, SetHtmlText);
	Gura_AssignMethod(wx_HtmlPrintout, SetMargins);
}

Gura_ImplementDescendantCreator(wx_HtmlPrintout)
{
	return new Object_wx_HtmlPrintout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
