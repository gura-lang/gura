//----------------------------------------------------------------------------
// wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewChoiceByIndexRenderer::~Object_wx_DataViewChoiceByIndexRenderer()
{
}

Object *Object_wx_DataViewChoiceByIndexRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewChoiceByIndexRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewChoiceByIndexRenderer:");
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
Gura_DeclareFunctionAlias(__DataViewChoiceByIndexRenderer, "DataViewChoiceByIndexRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewChoiceByIndexRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewChoiceByIndexRenderer)
{
	//const wxArrayString& choices = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int alignment = arg.GetNumber(2)
	//wxDataViewChoiceByIndexRenderer(choices, mode, alignment);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewChoiceByIndexRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewChoiceByIndexRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewChoiceByIndexRenderer)
{
	return new Object_wx_DataViewChoiceByIndexRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
