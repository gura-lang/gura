//----------------------------------------------------------------------------
// wxHtmlPrintout
// extracted from htprint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlPrintout: public wxHtmlPrintout, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlPrintout *_pObj;
public:
	inline wx_HtmlPrintout(const wxString& title) : wxHtmlPrintout(title), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlPrintout();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlPrintout *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlPrintout::~wx_HtmlPrintout()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlPrintout::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlPrintout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlPrintout));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlPrintout)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString title = wxT("Printout");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	wx_HtmlPrintout *pEntity = new wx_HtmlPrintout(title);
	Object_wx_HtmlPrintout *pObj = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlPrintout(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_HtmlPrintout, AddFilter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_wx_HtmlFilter, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_HtmlPrintout, AddFilter)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxHtmlFilter *filter = Object_wx_HtmlFilter::GetObject(args, 0)->GetEntity();
	wxHtmlPrintout::AddFilter(filter);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetFonts)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlPrintout, SetFonts)
{
#if 0
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString normal_face = wxString::FromUTF8(args.GetString(0));
	wxString fixed_face = wxString::FromUTF8(args.GetString(1));
	int *sizes = NULL;
	if (args.IsValid(2)) *sizes = args.GetInt(2);
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetFooter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "footer", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetFooter)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString footer = wxString::FromUTF8(args.GetString(0));
	int pg = wxPAGE_ALL;
	if (args.IsValid(1)) pg = args.GetInt(1);
	pThis->GetEntity()->SetFooter(footer, pg);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHeader)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "header", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHeader)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString header = wxString::FromUTF8(args.GetString(0));
	int pg = wxPAGE_ALL;
	if (args.IsValid(1)) pg = args.GetInt(1);
	pThis->GetEntity()->SetHeader(header, pg);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHtmlFile)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "htmlfile", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHtmlFile)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString htmlfile = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetHtmlFile(htmlfile);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetHtmlText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "html", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "basepath", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "isdir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetHtmlText)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString html = wxString::FromUTF8(args.GetString(0));
	wxString basepath = wxEmptyString;
	if (args.IsValid(1)) basepath = wxString::FromUTF8(args.GetString(1));
	bool isdir = true;
	if (args.IsValid(2)) isdir = args.GetBoolean(2);
	pThis->GetEntity()->SetHtmlText(html, basepath, isdir);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlPrintout, SetMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "top", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "left", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "right", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "spaces", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlPrintout, SetMargins)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Object_wx_HtmlPrintout::~Object_wx_HtmlPrintout()
{
}

Object *Object_wx_HtmlPrintout::Clone() const
{
	return NULL;
}

String Object_wx_HtmlPrintout::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlPrintout:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlPrintout::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(HtmlPrintout);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlPrintout)
{
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
	return new Object_wx_HtmlPrintout((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
