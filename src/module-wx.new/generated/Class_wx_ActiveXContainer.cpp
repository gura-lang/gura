//----------------------------------------------------------------------------
// wxActiveXContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Object_wx_ActiveXContainer::~Object_wx_ActiveXContainer()
{
}

Object *Object_wx_ActiveXContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ActiveXContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ActiveXContainer:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ActiveXContainer, wxActiveXContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pUnk", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXContainer, wxActiveXContainer)
{
	Object_wx_ActiveXContainer *pThis = Object_wx_ActiveXContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int iid = arg.GetNumber(1)
	//int pUnk = arg.GetNumber(2)
	//pThis->GetEntity()->wxActiveXContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActiveXContainer, QueryClientSiteInterface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_interface", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXContainer, QueryClientSiteInterface)
{
	Object_wx_ActiveXContainer *pThis = Object_wx_ActiveXContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iid = arg.GetNumber(0)
	//int _interface = arg.GetNumber(1)
	//int desc = arg.GetNumber(2)
	//pThis->GetEntity()->QueryClientSiteInterface();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXContainer)
{
	Gura_AssignMethod(wx_ActiveXContainer, wxActiveXContainer);
	Gura_AssignMethod(wx_ActiveXContainer, QueryClientSiteInterface);
}

Gura_ImplementDescendantCreator(wx_ActiveXContainer)
{
	return new Object_wx_ActiveXContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
