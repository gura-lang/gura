//----------------------------------------------------------------------------
// wxMetafileDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafileDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMetafileDC
//----------------------------------------------------------------------------
Object_wx_MetafileDC::~Object_wx_MetafileDC()
{
}

Object *Object_wx_MetafileDC::Clone() const
{
	return nullptr;
}

String Object_wx_MetafileDC::ToString(bool exprFlag)
{
	String rtn("<wx.MetafileDC:");
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
Gura_DeclareFunctionAlias(__MetafileDC, "MetafileDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MetafileDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MetafileDC)
{
	//const wxString& filename = arg.GetNumber(0)
	//wxMetafileDC(filename);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MetafileDC, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MetafileDC, __Close)
{
	Object_wx_MetafileDC *pThis = Object_wx_MetafileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMetafile* _rtn = pThis->GetEntity()->Close();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMetafileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MetafileDC)
{
	// Constructor assignment
	Gura_AssignFunction(__MetafileDC);
	// Method assignment
	Gura_AssignMethod(wx_MetafileDC, __Close);
}

Gura_ImplementDescendantCreator(wx_MetafileDC)
{
	return new Object_wx_MetafileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
