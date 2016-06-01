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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewChoiceByIndexRenderer, wxDataViewChoiceByIndexRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewChoiceByIndexRenderer, wxDataViewChoiceByIndexRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewChoiceByIndexRenderer *pThis = Object_wx_DataViewChoiceByIndexRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int alignment = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewChoiceByIndexRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewChoiceByIndexRenderer)
{
	Gura_AssignMethod(wx_DataViewChoiceByIndexRenderer, wxDataViewChoiceByIndexRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewChoiceByIndexRenderer)
{
	return new Object_wx_DataViewChoiceByIndexRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
