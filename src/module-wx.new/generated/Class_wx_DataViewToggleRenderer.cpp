//----------------------------------------------------------------------------
// wxDataViewToggleRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewToggleRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewToggleRenderer::~Object_wx_DataViewToggleRenderer()
{
}

Object *Object_wx_DataViewToggleRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewToggleRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewToggleRenderer:");
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
Gura_DeclareMethodAlias(wx_DataViewToggleRenderer, __GetDefaultType, "GetDefaultType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewToggleRenderer, __GetDefaultType)
{
	Object_wx_DataViewToggleRenderer *pThis = Object_wx_DataViewToggleRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewToggleRenderer, __wxDataViewToggleRenderer, "wxDataViewToggleRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewToggleRenderer, __wxDataViewToggleRenderer)
{
	Object_wx_DataViewToggleRenderer *pThis = Object_wx_DataViewToggleRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewToggleRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewToggleRenderer)
{
	Gura_AssignMethod(wx_DataViewToggleRenderer, __GetDefaultType);
	Gura_AssignMethod(wx_DataViewToggleRenderer, __wxDataViewToggleRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewToggleRenderer)
{
	return new Object_wx_DataViewToggleRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
