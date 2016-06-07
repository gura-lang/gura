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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SizerXmlHandler, "SizerXmlHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SizerXmlHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerXmlHandler)
{
	//wxSizerXmlHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SizerXmlHandler, __DoCreateResource, "DoCreateResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SizerXmlHandler, __DoCreateResource)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* _rtn = pThis->GetEntity()->DoCreateResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerXmlHandler, __CanHandle, "CanHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, __CanHandle)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* node = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanHandle(node);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerXmlHandler, __DoCreateSizer, "DoCreateSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, __DoCreateSizer)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxSizer* _rtn = pThis->GetEntity()->DoCreateSizer(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerXmlHandler, __IsSizerNode, "IsSizerNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerXmlHandler, __IsSizerNode)
{
	Object_wx_SizerXmlHandler *pThis = Object_wx_SizerXmlHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* node = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsSizerNode(node);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerXmlHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerXmlHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__SizerXmlHandler);
	// Method assignment
	Gura_AssignMethod(wx_SizerXmlHandler, __DoCreateResource);
	Gura_AssignMethod(wx_SizerXmlHandler, __CanHandle);
	Gura_AssignMethod(wx_SizerXmlHandler, __DoCreateSizer);
	Gura_AssignMethod(wx_SizerXmlHandler, __IsSizerNode);
}

Gura_ImplementDescendantCreator(wx_SizerXmlHandler)
{
	return new Object_wx_SizerXmlHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
