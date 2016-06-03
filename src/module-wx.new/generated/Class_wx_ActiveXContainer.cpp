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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ActiveXContainer, "ActiveXContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pUnk", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ActiveXContainer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ActiveXContainer)
{
	//wxWindow* parent = arg.GetNumber(0)
	//REFIID iid = arg.GetNumber(1)
	//IUnknown* pUnk = arg.GetNumber(2)
	//wxActiveXContainer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ActiveXContainer, __QueryClientSiteInterface, "QueryClientSiteInterface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_interface", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXContainer, __QueryClientSiteInterface)
{
	Object_wx_ActiveXContainer *pThis = Object_wx_ActiveXContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//REFIID iid = arg.GetNumber(0)
	//void** _interface = arg.GetNumber(1)
	//const char*& desc = arg.GetNumber(2)
	//pThis->GetEntity()->QueryClientSiteInterface();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXContainer)
{
	// Constructor assignment
	Gura_AssignFunction(__ActiveXContainer);
	// Method assignment
	Gura_AssignMethod(wx_ActiveXContainer, __QueryClientSiteInterface);
}

Gura_ImplementDescendantCreator(wx_ActiveXContainer)
{
	return new Object_wx_ActiveXContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
