//----------------------------------------------------------------------------
// wxTreeItemData
// extracted from treedata.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
wx_TreeItemData::~wx_TreeItemData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TreeItemData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemData
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeItemData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreeItemData));
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeItemData)
{
	wx_TreeItemData *pEntity = new wx_TreeItemData(args.GetValue(0));
	Object_wx_TreeItemData *pObj = Object_wx_TreeItemData::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreeItemData(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_TreeItemData, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemData, GetId)
{
	Object_wx_TreeItemData *pSelf = Object_wx_TreeItemData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTreeItemId &rtn = pSelf->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeItemData, SetId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeItemData, SetId)
{
	Object_wx_TreeItemData *pSelf = Object_wx_TreeItemData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *id = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetId(*id);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeItemData, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemData, GetData)
{
	Object_wx_TreeItemData *pSelf = Object_wx_TreeItemData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wx_TreeItemData *pEntity = dynamic_cast<wx_TreeItemData *>(pSelf->GetEntity());
	if (pEntity == NULL) return Value::Null;
	return pEntity->GetValue();
}

Gura_DeclareMethod(wx_TreeItemData, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeItemData, SetData)
{
	Object_wx_TreeItemData *pSelf = Object_wx_TreeItemData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wx_TreeItemData *pEntity = dynamic_cast<wx_TreeItemData *>(pSelf->GetEntity());
	if (pEntity == NULL) return Value::Null;
	pEntity->SetValue(args.GetValue(0));
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemData
//----------------------------------------------------------------------------
Object_wx_TreeItemData::~Object_wx_TreeItemData()
{
}

Object *Object_wx_TreeItemData::Clone() const
{
	return NULL;
}

String Object_wx_TreeItemData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TreeItemData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TreeItemData::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TreeItemData);
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeItemData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemData)
{
	Gura_AssignMethod(wx_TreeItemData, GetId);
	Gura_AssignMethod(wx_TreeItemData, SetId);
	Gura_AssignMethod(wx_TreeItemData, GetData);
	Gura_AssignMethod(wx_TreeItemData, SetData);
}

Gura_ImplementDescendantCreator(wx_TreeItemData)
{
	return new Object_wx_TreeItemData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
