//----------------------------------------------------------------------------
// wxTreeItemData
// extracted from treedata.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
wx_TreeItemData::~wx_TreeItemData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TreeItemData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemData
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreeItemData));
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeItemData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TreeItemData *pEntity = new wx_TreeItemData(args.GetValue(0));
	Object_wx_TreeItemData *pObj = Object_wx_TreeItemData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TreeItemData(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TreeItemData, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemData, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxTreeItemId &rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeItemData, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeItemData, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTreeItemId *id = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetId(*id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemData, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemData, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wx_TreeItemData *pEntity = dynamic_cast<wx_TreeItemData *>(pThis->GetEntity());
	if (pEntity == nullptr) return Value::Nil;
	return pEntity->GetValue();
}

Gura_DeclareMethod(wx_TreeItemData, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeItemData, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wx_TreeItemData *pEntity = dynamic_cast<wx_TreeItemData *>(pThis->GetEntity());
	if (pEntity == nullptr) return Value::Nil;
	pEntity->SetValue(args.GetValue(0));
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemData
//----------------------------------------------------------------------------
Object_wx_TreeItemData::~Object_wx_TreeItemData()
{
}

Object *Object_wx_TreeItemData::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemData::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemData:");
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
// Class implementation for wxTreeItemData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemData)
{
	Gura_AssignFunction(TreeItemData);
	Gura_AssignMethod(wx_TreeItemData, GetId);
	Gura_AssignMethod(wx_TreeItemData, SetId);
	Gura_AssignMethod(wx_TreeItemData, GetData);
	Gura_AssignMethod(wx_TreeItemData, SetData);
}

Gura_ImplementDescendantCreator(wx_TreeItemData)
{
	return new Object_wx_TreeItemData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
