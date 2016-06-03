//----------------------------------------------------------------------------
// wxArchiveIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Object_wx_ArchiveIterator::~Object_wx_ArchiveIterator()
{
}

Object *Object_wx_ArchiveIterator::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveIterator::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveIterator:");
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
Gura_DeclareFunctionAlias(__wxArchiveIterator, "wxArchiveIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxArchiveIterator)
{
	//wxArchiveIterator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxArchiveIterator_1, "wxArchiveIterator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxArchiveIterator_1)
{
	//int arc = arg.GetNumber(0)
	//wxArchiveIterator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveIterator)
{
	// Constructor assignment
	Gura_AssignFunction(__wxArchiveIterator);
	Gura_AssignFunction(__wxArchiveIterator_1);
}

Gura_ImplementDescendantCreator(wx_ArchiveIterator)
{
	return new Object_wx_ArchiveIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
