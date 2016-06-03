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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__StreamToTextRedirector, "StreamToTextRedirector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ostr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StreamToTextRedirector));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StreamToTextRedirector)
{
	//wxTextCtrl* text = arg.GetNumber(0)
	//ostream* ostr = arg.GetNumber(1)
	//wxStreamToTextRedirector();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamToTextRedirector)
{
	// Constructor assignment
	Gura_AssignFunction(__StreamToTextRedirector);
}

Gura_ImplementDescendantCreator(wx_StreamToTextRedirector)
{
	return new Object_wx_StreamToTextRedirector((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
