//----------------------------------------------------------------------------
// wxStringOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Object_wx_StringOutputStream::~Object_wx_StringOutputStream()
{
}

Object *Object_wx_StringOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StringOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StringOutputStream:");
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
Gura_DeclareFunctionAlias(__StringOutputStream, "StringOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StringOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StringOutputStream)
{
	//wxString* pString = arg.GetNumber(0)
	//wxMBConv& conv = arg.GetNumber(1)
	//wxStringOutputStream(pString, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StringOutputStream, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StringOutputStream, __GetString)
{
	Object_wx_StringOutputStream *pThis = Object_wx_StringOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__StringOutputStream);
	// Method assignment
	Gura_AssignMethod(wx_StringOutputStream, __GetString);
}

Gura_ImplementDescendantCreator(wx_StringOutputStream)
{
	return new Object_wx_StringOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
