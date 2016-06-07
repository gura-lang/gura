//----------------------------------------------------------------------------
// wxCountingOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCountingOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Object_wx_CountingOutputStream::~Object_wx_CountingOutputStream()
{
}

Object *Object_wx_CountingOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_CountingOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.CountingOutputStream:");
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
Gura_DeclareFunctionAlias(__CountingOutputStream, "CountingOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CountingOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CountingOutputStream)
{
	//wxCountingOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CountingOutputStream, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CountingOutputStream, __GetLength)
{
	Object_wx_CountingOutputStream *pThis = Object_wx_CountingOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileOffset _rtn = pThis->GetEntity()->GetLength();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CountingOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__CountingOutputStream);
	// Method assignment
	Gura_AssignMethod(wx_CountingOutputStream, __GetLength);
}

Gura_ImplementDescendantCreator(wx_CountingOutputStream)
{
	return new Object_wx_CountingOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
