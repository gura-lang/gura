//----------------------------------------------------------------------------
// wxDataViewSpinRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewSpinRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewSpinRenderer::~Object_wx_DataViewSpinRenderer()
{
}

Object *Object_wx_DataViewSpinRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewSpinRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewSpinRenderer:");
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
Gura_DeclareFunctionAlias(__wxDataViewSpinRenderer, "wxDataViewSpinRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewSpinRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataViewSpinRenderer)
{
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//wxDataViewSpinRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewSpinRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewSpinRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewSpinRenderer)
{
	return new Object_wx_DataViewSpinRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
