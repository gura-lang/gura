//----------------------------------------------------------------------------
// wxSizerXmlHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerXmlHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizerXmlHandler
//----------------------------------------------------------------------------
Object_wx_SizerXmlHandler::~Object_wx_SizerXmlHandler()
{
}

Object *Object_wx_SizerXmlHandler::Clone() const
{
	return nullptr;
}

String Object_wx_SizerXmlHandler::ToString(bool exprFlag)
{
	String rtn("<wx.SizerXmlHandler:");
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
Gura_DeclareMethod(wx_SizerXmlHandler, wxSizerXmlHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerXmlHandler, wxSizerXmlHandler)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSizerXmlHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerXmlHandler, DoCreateResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerXmlHandler, DoCreateResource)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoCreateResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerXmlHandler, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, CanHandle)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerXmlHandler, DoCreateSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, DoCreateSizer)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->DoCreateSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerXmlHandler, IsSizerNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, IsSizerNode)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->IsSizerNode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerXmlHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerXmlHandler)
{
	Gura_AssignMethod(wx_SizerXmlHandler, wxSizerXmlHandler);
	Gura_AssignMethod(wx_SizerXmlHandler, DoCreateResource);
	Gura_AssignMethod(wx_SizerXmlHandler, CanHandle);
	Gura_AssignMethod(wx_SizerXmlHandler, DoCreateSizer);
	Gura_AssignMethod(wx_SizerXmlHandler, IsSizerNode);
}

Gura_ImplementDescendantCreator(wx_SizerXmlHandler)
{
	return new Object_wx_SizerXmlHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
