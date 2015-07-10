//----------------------------------------------------------------------------
// wxRichTextHeaderFooterData
// extracted from richtextheaderfooterdata.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextHeaderFooterData: public wxRichTextHeaderFooterData, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_RichTextHeaderFooterData *_pObj;
public:
	inline wx_RichTextHeaderFooterData() : wxRichTextHeaderFooterData(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_RichTextHeaderFooterData(const wxRichTextHeaderFooterData& data) : wxRichTextHeaderFooterData(data), _pSig(nullptr), _pObj(nullptr) {}
	~wx_RichTextHeaderFooterData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextHeaderFooterData *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextHeaderFooterData::~wx_RichTextHeaderFooterData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextHeaderFooterData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextHeaderFooterDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHeaderFooterData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextHeaderFooterDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RichTextHeaderFooterData *pEntity = new wx_RichTextHeaderFooterData();
	Object_wx_RichTextHeaderFooterData *pObj = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextHeaderFooterData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(RichTextHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHeaderFooterData));
	DeclareArg(env, "data", VTYPE_wx_RichTextHeaderFooterData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextHeaderFooterData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextHeaderFooterData *data = Object_wx_RichTextHeaderFooterData::GetObject(args, 0)->GetEntity();
	wx_RichTextHeaderFooterData *pEntity = new wx_RichTextHeaderFooterData(*data);
	Object_wx_RichTextHeaderFooterData *pObj = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextHeaderFooterData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Clear)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_RichTextHeaderFooterData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Copy)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextHeaderFooterData *data = Object_wx_RichTextHeaderFooterData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Copy(*data);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFont)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFooterMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFooterMargin)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFooterMargin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFooterText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (args.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(1)) location = static_cast<wxRichTextPageLocation>(args.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetFooterText(page, location);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetHeaderMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetHeaderMargin)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeaderMargin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetHeaderText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (args.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(1)) location = static_cast<wxRichTextPageLocation>(args.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetHeaderText(page, location);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetShowOnFirstPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int headerFooter = args.GetInt(0);
	wxRichTextOddEvenPage page = static_cast<wxRichTextOddEvenPage>(args.GetInt(1));
	wxRichTextPageLocation location = static_cast<wxRichTextPageLocation>(args.GetInt(2));
	wxString rtn = pThis->GetEntity()->GetText(headerFooter, page, location);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetTextColour)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Init)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetFont)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetFooterText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (args.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(2)) location = static_cast<wxRichTextPageLocation>(args.GetInt(2));
	pThis->GetEntity()->SetFooterText(text, page, location);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetHeaderText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (args.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(2)) location = static_cast<wxRichTextPageLocation>(args.GetInt(2));
	pThis->GetEntity()->SetHeaderText(text, page, location);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "headerMargin", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "footerMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetMargins)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int headerMargin = args.GetInt(0);
	int footerMargin = args.GetInt(1);
	pThis->GetEntity()->SetMargins(headerMargin, footerMargin);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "showOnFirstPage", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool showOnFirstPage = args.GetBoolean(0);
	pThis->GetEntity()->SetShowOnFirstPage(showOnFirstPage);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	int headerFooter = args.GetInt(1);
	wxRichTextOddEvenPage page = static_cast<wxRichTextOddEvenPage>(args.GetInt(2));
	wxRichTextPageLocation location = static_cast<wxRichTextPageLocation>(args.GetInt(3));
	pThis->GetEntity()->SetText(text, headerFooter, page, location);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetTextColour)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*col);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Object_wx_RichTextHeaderFooterData::~Object_wx_RichTextHeaderFooterData()
{
}

Object *Object_wx_RichTextHeaderFooterData::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHeaderFooterData::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHeaderFooterData:");
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
// Class implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHeaderFooterData)
{
	Gura_AssignFunction(RichTextHeaderFooterDataEmpty);
	Gura_AssignFunction(RichTextHeaderFooterData);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Clear);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Copy);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFooterMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetHeaderMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetTextColour);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Init);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetMargins);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetTextColour);
}

Gura_ImplementDescendantCreator(wx_RichTextHeaderFooterData)
{
	return new Object_wx_RichTextHeaderFooterData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
