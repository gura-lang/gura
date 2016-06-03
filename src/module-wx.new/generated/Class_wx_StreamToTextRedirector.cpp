//----------------------------------------------------------------------------
// wxStreamToTextRedirector
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamToTextRedirector
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Object_wx_StreamToTextRedirector::~Object_wx_StreamToTextRedirector()
{
}

Object *Object_wx_StreamToTextRedirector::Clone() const
{
	return nullptr;
}

String Object_wx_StreamToTextRedirector::ToString(bool exprFlag)
{
	String rtn("<wx.StreamToTextRedirector:");
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
Gura_DeclareMethodAlias(wx_StreamToTextRedirector, __wxStreamToTextRedirector, "wxStreamToTextRedirector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ostr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamToTextRedirector, __wxStreamToTextRedirector)
{
	Object_wx_StreamToTextRedirector *pThis = Object_wx_StreamToTextRedirector::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int ostr = arg.GetNumber(1)
	//pThis->GetEntity()->wxStreamToTextRedirector();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamToTextRedirector)
{
	Gura_AssignMethod(wx_StreamToTextRedirector, __wxStreamToTextRedirector);
}

Gura_ImplementDescendantCreator(wx_StreamToTextRedirector)
{
	return new Object_wx_StreamToTextRedirector((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
