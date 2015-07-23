//----------------------------------------------------------------------------
// wxListItem
// extracted from listitem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListItem: public wxListItem, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ListItem *_pObj;
public:
	inline wx_ListItem() : wxListItem(), _pObj(nullptr) {}
	~wx_ListItem();
	inline void AssocWithGura(Object_wx_ListItem *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListItem::~wx_ListItem()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ListItem::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListItem
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListItem)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ListItem *pEntity = new wx_ListItem();
	Object_wx_ListItem *pObj = Object_wx_ListItem::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ListItem, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, Clear)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, GetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListColumnFormat rtn = pThis->GetEntity()->GetAlign();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItem, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColumn();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetData();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItem, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetImage();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetMask();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetState();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetText();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListItem, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItem, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItem, GetWidth)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItem, SetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListColumnFormat align = static_cast<wxListColumnFormat>(args.GetInt(0));
	pThis->GetEntity()->SetAlign(align);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colBack = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetColumn(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long data = args.GetLong(0);
	pThis->GetEntity()->SetData(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetData_1)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	pThis->GetEntity()->SetData(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long id = args.GetLong(0);
	pThis->GetEntity()->SetId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int image = args.GetInt(0);
	pThis->GetEntity()->SetImage(image);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long mask = args.GetLong(0);
	pThis->GetEntity()->SetMask(mask);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long state = args.GetLong(0);
	pThis->GetEntity()->SetState(state);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetStateMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetStateMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long stateMask = args.GetLong(0);
	pThis->GetEntity()->SetStateMask(stateMask);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colText);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItem, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetWidth)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxListItem
//----------------------------------------------------------------------------
Object_wx_ListItem::~Object_wx_ListItem()
{
}

Object *Object_wx_ListItem::Clone() const
{
	return nullptr;
}

String Object_wx_ListItem::ToString(bool exprFlag)
{
	String rtn("<wx.ListItem:");
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
// Class implementation for wxListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItem)
{
	Gura_AssignFunction(ListItem);
	Gura_AssignMethod(wx_ListItem, Clear);
	Gura_AssignMethod(wx_ListItem, GetAlign);
	Gura_AssignMethod(wx_ListItem, GetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, GetColumn);
	Gura_AssignMethod(wx_ListItem, GetData);
	Gura_AssignMethod(wx_ListItem, GetFont);
	Gura_AssignMethod(wx_ListItem, GetId);
	Gura_AssignMethod(wx_ListItem, GetImage);
	Gura_AssignMethod(wx_ListItem, GetMask);
	Gura_AssignMethod(wx_ListItem, GetState);
	Gura_AssignMethod(wx_ListItem, GetText);
	Gura_AssignMethod(wx_ListItem, GetTextColour);
	Gura_AssignMethod(wx_ListItem, GetWidth);
	Gura_AssignMethod(wx_ListItem, SetAlign);
	Gura_AssignMethod(wx_ListItem, SetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, SetColumn);
	Gura_AssignMethod(wx_ListItem, SetData);
	Gura_AssignMethod(wx_ListItem, SetData_1);
	Gura_AssignMethod(wx_ListItem, SetFont);
	Gura_AssignMethod(wx_ListItem, SetId);
	Gura_AssignMethod(wx_ListItem, SetImage);
	Gura_AssignMethod(wx_ListItem, SetMask);
	Gura_AssignMethod(wx_ListItem, SetState);
	Gura_AssignMethod(wx_ListItem, SetStateMask);
	Gura_AssignMethod(wx_ListItem, SetText);
	Gura_AssignMethod(wx_ListItem, SetTextColour);
	Gura_AssignMethod(wx_ListItem, SetWidth);
}

Gura_ImplementDescendantCreator(wx_ListItem)
{
	return new Object_wx_ListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
