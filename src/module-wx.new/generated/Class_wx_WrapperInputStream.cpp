//----------------------------------------------------------------------------
// wxWrapperInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWrapperInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Object_wx_WrapperInputStream::~Object_wx_WrapperInputStream()
{
}

Object *Object_wx_WrapperInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_WrapperInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.WrapperInputStream:");
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
Gura_DeclareFunctionAlias(__WrapperInputStream, "WrapperInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WrapperInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WrapperInputStream)
{
	//wxInputStream& stream = arg.GetNumber(0)
	//wxWrapperInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WrapperInputStream_1, "WrapperInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WrapperInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WrapperInputStream_1)
{
	//wxInputStream* stream = arg.GetNumber(0)
	//wxWrapperInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WrapperInputStream_2, "WrapperInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WrapperInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WrapperInputStream_2)
{
	//wxWrapperInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WrapperInputStream, __InitParentStream, "InitParentStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __InitParentStream)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->InitParentStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WrapperInputStream, __InitParentStream_1, "InitParentStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __InitParentStream_1)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream* stream = arg.GetNumber(0)
	//pThis->GetEntity()->InitParentStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WrapperInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__WrapperInputStream);
	Gura_AssignFunction(__WrapperInputStream_1);
	Gura_AssignFunction(__WrapperInputStream_2);
	// Method assignment
	Gura_AssignMethod(wx_WrapperInputStream, __InitParentStream);
	Gura_AssignMethod(wx_WrapperInputStream, __InitParentStream_1);
}

Gura_ImplementDescendantCreator(wx_WrapperInputStream)
{
	return new Object_wx_WrapperInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
