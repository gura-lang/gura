//----------------------------------------------------------------------------
// wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewChoiceRenderer::~Object_wx_DataViewChoiceRenderer()
{
}

Object *Object_wx_DataViewChoiceRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewChoiceRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewChoiceRenderer:");
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
Gura_DeclareFunctionAlias(__wxDataViewChoiceRenderer, "wxDataViewChoiceRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewChoiceRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataViewChoiceRenderer)
{
	//int choices = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int alignment = arg.GetNumber(2)
	//wxDataViewChoiceRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewChoiceRenderer, __GetChoice, "GetChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewChoiceRenderer, __GetChoice)
{
	Object_wx_DataViewChoiceRenderer *pThis = Object_wx_DataViewChoiceRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetChoice();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewChoiceRenderer, __GetChoices, "GetChoices")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewChoiceRenderer, __GetChoices)
{
	Object_wx_DataViewChoiceRenderer *pThis = Object_wx_DataViewChoiceRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChoices();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewChoiceRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewChoiceRenderer);
	// Method assignment
	Gura_AssignMethod(wx_DataViewChoiceRenderer, __GetChoice);
	Gura_AssignMethod(wx_DataViewChoiceRenderer, __GetChoices);
}

Gura_ImplementDescendantCreator(wx_DataViewChoiceRenderer)
{
	return new Object_wx_DataViewChoiceRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
