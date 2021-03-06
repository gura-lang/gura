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
	//Gura::Signal *_pSig;
	Object_wx_GBSizerItem *_pObj;
public:
	inline wx_GBSizerItem(int width, int height, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(width, height, pos, span, flag, border, userData), _pObj(nullptr) {}
	inline wx_GBSizerItem(wxWindow* window, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(window, pos, span, flag, border, userData), _pObj(nullptr) {}
	inline wx_GBSizerItem(wxSizer* sizer, const wxGBPosition& pos, const wxGBSpan& span, int flag, int border, wxObject* userData) : wxGBSizerItem(sizer, pos, span, flag, border, userData), _pObj(nullptr) {}
	~wx_GBSizerItem();
	inline void AssocWithGura(Object_wx_GBSizerItem *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBSizerItem::~wx_GBSizerItem()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GBSizerItem::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBSizerItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 2)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 3)->GetEntity();
	int flag = arg.GetInt(4);
	int border = arg.GetInt(5);
	wxObject *userData = Object_wx_Object::GetObject(arg, 6)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(width, height, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(GBSizerItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 1)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 2)->GetEntity();
	int flag = arg.GetInt(3);
	int border = arg.GetInt(4);
	wxObject *userData = Object_wx_Object::GetObject(arg, 5)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(window, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(GBSizerItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 1)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 2)->GetEntity();
	int flag = arg.GetInt(3);
	int border = arg.GetInt(4);
	wxObject *userData = Object_wx_Object::GetObject(arg, 5)->GetEntity();
	wx_GBSizerItem *pEntity = new wx_GBSizerItem(sizer, *pos, *span, flag, border, userData);
	Object_wx_GBSizerItem *pObj = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBSizerItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GBSizerItem, GetEndPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetEndPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	pThis->GetEntity()->GetEndPos(row, col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition rtn = pThis->GetEntity()->GetPos();
	return ReturnValue(env, arg, Value(new Object_wx_GBPosition(new wxGBPosition(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	pThis->GetEntity()->GetPos(row, col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSpan rtn = pThis->GetEntity()->GetSpan();
	return ReturnValue(env, arg, Value(new Object_wx_GBSpan(new wxGBSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rowspan = arg.GetInt(0);
	int colspan = arg.GetInt(1);
	pThis->GetEntity()->GetSpan(rowspan, colspan);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSizerItem *other = Object_wx_GBSizerItem::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersects(*other);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 0)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersects(*pos, *span);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, SetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, SetPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetPos(*pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GBSizerItem, SetSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSizerItem, SetSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetSpan(*span);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Object_wx_GBSizerItem::~Object_wx_GBSizerItem()
{
}

Object *Object_wx_GBSizerItem::Clone() const
{
	return nullptr;
}

String Object_wx_GBSizerItem::ToString(bool exprFlag)
{
	String rtn("<wx.GBSizerItem:");
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
	return new Object_wx_GBSizerItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
