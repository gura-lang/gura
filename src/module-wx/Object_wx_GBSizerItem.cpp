//----------------------------------------------------------------------------
// wxGBSizerItem
// extracted from gbsizeritem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GBSizerItem: public wxGBSizerItem, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GBSizerItem *_pObj;
public:
	inline wx_GBSizerItem(int width, int height, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(width, height, pos, span, flag, border, userData), _sig(NULL), _pObj(NULL) {}
	inline wx_GBSizerItem(wxWindow* window, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(window, pos, span, flag, border, userData), _sig(NULL), _pObj(NULL) {}
	inline wx_GBSizerItem(wxSizer* sizer, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(sizer, pos, span, flag, border, userData), _sig(NULL), _pObj(NULL) {}
	~wx_GBSizerItem();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GBSizerItem *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBSizerItem::~wx_GBSizerItem()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GBSizerItem::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBSizerItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSizerItem)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 2)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 3)->GetEntity();
	int flag = args.GetInt(4);
	int border = args.GetInt(5);
	wxObject *userData = Object_wx_Object::GetObject(args, 6)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(width, height, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GBSizerItem_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSizerItem_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 2)->GetEntity();
	int flag = args.GetInt(3);
	int border = args.GetInt(4);
	wxObject *userData = Object_wx_Object::GetObject(args, 5)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(window, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GBSizerItem_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSizerItem_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 2)->GetEntity();
	int flag = args.GetInt(3);
	int border = args.GetInt(4);
	wxObject *userData = Object_wx_Object::GetObject(args, 5)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(sizer, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GBSizerItem, GetEndPos)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetEndPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	pThis->GetEntity()->GetEndPos(row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition rtn = pThis->GetEntity()->GetPos();
	return ReturnValue(env, sig, args, Value(new Object_wx_GBPosition(new wxGBPosition(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	pThis->GetEntity()->GetPos(row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSpan rtn = pThis->GetEntity()->GetSpan();
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSpan(new wxGBSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rowspan = args.GetInt(0);
	int colspan = args.GetInt(1);
	pThis->GetEntity()->GetSpan(rowspan, colspan);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *other = Object_wx_GBSizerItem::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersects(*other);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersects(*pos, *span);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, SetPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, SetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetPos(*pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, SetSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, SetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetSpan(*span);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Object_wx_GBSizerItem::~Object_wx_GBSizerItem()
{
}

Object *Object_wx_GBSizerItem::Clone() const
{
	return NULL;
}

String Object_wx_GBSizerItem::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GBSizerItem:");
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
// Class implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSizerItem)
{
	Gura_AssignFunction(GBSizerItem);
	Gura_AssignFunction(GBSizerItem_1);
	Gura_AssignFunction(GBSizerItem_2);
	Gura_AssignMethod(wx_GBSizerItem, GetEndPos);
	Gura_AssignMethod(wx_GBSizerItem, GetPos);
	Gura_AssignMethod(wx_GBSizerItem, GetPos_1);
	Gura_AssignMethod(wx_GBSizerItem, GetSpan);
	Gura_AssignMethod(wx_GBSizerItem, GetSpan_1);
	Gura_AssignMethod(wx_GBSizerItem, Intersects);
	Gura_AssignMethod(wx_GBSizerItem, Intersects_1);
	Gura_AssignMethod(wx_GBSizerItem, SetPos);
	Gura_AssignMethod(wx_GBSizerItem, SetSpan);
}

Gura_ImplementDescendantCreator(wx_GBSizerItem)
{
	return new Object_wx_GBSizerItem((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
