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
Gura_DeclareFunctionAlias(__ArchiveIterator, "ArchiveIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ArchiveIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArchiveIterator)
{
	//wxArchiveIterator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ArchiveIterator_1, "ArchiveIterator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "arc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ArchiveIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArchiveIterator_1)
{
	//Arc& arc = arg.GetNumber(0)
	//wxArchiveIterator(arc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveIterator)
{
	// Constructor assignment
	Gura_AssignFunction(__ArchiveIterator);
	Gura_AssignFunction(__ArchiveIterator_1);
}

Gura_ImplementDescendantCreator(wx_ArchiveIterator)
{
	return new Object_wx_ArchiveIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
