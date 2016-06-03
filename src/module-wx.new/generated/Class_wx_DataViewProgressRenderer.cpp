//----------------------------------------------------------------------------
// wxDataViewProgressRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewProgressRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewProgressRenderer::~Object_wx_DataViewProgressRenderer()
{
}

Object *Object_wx_DataViewProgressRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewProgressRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewProgressRenderer:");
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
Gura_DeclareMethodAlias(wx_DataViewProgressRenderer, __GetDefaultType, "GetDefaultType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewProgressRenderer, __GetDefaultType)
{
	Object_wx_DataViewProgressRenderer *pThis = Object_wx_DataViewProgressRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewProgressRenderer, __wxDataViewProgressRenderer, "wxDataViewProgressRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewProgressRenderer, __wxDataViewProgressRenderer)
{
	Object_wx_DataViewProgressRenderer *pThis = Object_wx_DataViewProgressRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int varianttype = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//pThis->GetEntity()->wxDataViewProgressRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewProgressRenderer)
{
	Gura_AssignMethod(wx_DataViewProgressRenderer, __GetDefaultType);
	Gura_AssignMethod(wx_DataViewProgressRenderer, __wxDataViewProgressRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewProgressRenderer)
{
	return new Object_wx_DataViewProgressRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
