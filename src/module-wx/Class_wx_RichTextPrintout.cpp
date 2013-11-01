//----------------------------------------------------------------------------
// wxRichTextPrintout
// extracted from richtextprintout.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextPrintout: public wxRichTextPrintout, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextPrintout *_pObj;
public:
	inline wx_RichTextPrintout(const wxString& title) : wxRichTextPrintout(title), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextPrintout();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextPrintout *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextPrintout::~wx_RichTextPrintout()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextPrintout::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrintout
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextPrintout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPrintout));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextPrintout)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString title = wxT("Printout");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	wx_RichTextPrintout *pEntity = new wx_RichTextPrintout(title);
	Object_wx_RichTextPrintout *pObj = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextPrintout(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextPrintout, CalculateScaling)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "textRect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "headerRect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "footerRect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, CalculateScaling)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *textRect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxRect *headerRect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	wxRect *footerRect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->CalculateScaling(dc, *textRect, *headerRect, *footerRect);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrintout, GetHeaderFooterData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrintout, GetHeaderFooterData)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxRichTextHeaderFooterData &rtn = pThis->GetEntity()->GetHeaderFooterData();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextHeaderFooterData(new wxRichTextHeaderFooterData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextPrintout, GetPageInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "selPageFrom", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "selPageTo", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RichTextPrintout, GetPageInfo)
{
#if 0
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minPage = args.GetInt(0);
	int maxPage = args.GetInt(1);
	int selPageFrom = args.GetInt(2);
	int selPageTo = args.GetInt(3);
	pThis->GetEntity()->GetPageInfo(minPage, maxPage, selPageFrom, selPageTo);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrintout, GetRichTextBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrintout, GetRichTextBuffer)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *rtn = (wxRichTextBuffer *)pThis->GetEntity()->GetRichTextBuffer();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextBuffer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrintout, HasPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrintout, HasPage)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	bool rtn = pThis->GetEntity()->HasPage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrintout, OnPreparePrinting)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrintout, OnPreparePrinting)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnPreparePrinting();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrintout, OnPrintPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrintout, OnPrintPage)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	bool rtn = pThis->GetEntity()->OnPrintPage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrintout, SetHeaderFooterData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_RichTextHeaderFooterData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetHeaderFooterData)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextHeaderFooterData *data = Object_wx_RichTextHeaderFooterData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetHeaderFooterData(*data);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrintout, SetMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "top", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "left", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "right", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetMargins)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int top = 252;
	if (args.IsValid(0)) top = args.GetInt(0);
	int bottom = 252;
	if (args.IsValid(1)) bottom = args.GetInt(1);
	int left = 252;
	if (args.IsValid(2)) left = args.GetInt(2);
	int right = 252;
	if (args.IsValid(3)) right = args.GetInt(3);
	pThis->GetEntity()->SetMargins(top, bottom, left, right);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrintout, SetRichTextBuffer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetRichTextBuffer)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextBuffer(buffer);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Object_wx_RichTextPrintout::~Object_wx_RichTextPrintout()
{
}

Object *Object_wx_RichTextPrintout::Clone() const
{
	return NULL;
}

String Object_wx_RichTextPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrintout:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrintout)
{
	Gura_AssignFunction(RichTextPrintout);
	Gura_AssignMethod(wx_RichTextPrintout, CalculateScaling);
	Gura_AssignMethod(wx_RichTextPrintout, GetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrintout, GetPageInfo);
	Gura_AssignMethod(wx_RichTextPrintout, GetRichTextBuffer);
	Gura_AssignMethod(wx_RichTextPrintout, HasPage);
	Gura_AssignMethod(wx_RichTextPrintout, OnPreparePrinting);
	Gura_AssignMethod(wx_RichTextPrintout, OnPrintPage);
	Gura_AssignMethod(wx_RichTextPrintout, SetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrintout, SetMargins);
	Gura_AssignMethod(wx_RichTextPrintout, SetRichTextBuffer);
}

Gura_ImplementDescendantCreator(wx_RichTextPrintout)
{
	return new Object_wx_RichTextPrintout((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
