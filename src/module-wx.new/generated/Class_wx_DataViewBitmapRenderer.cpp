//----------------------------------------------------------------------------
// wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewBitmapRenderer::~Object_wx_DataViewBitmapRenderer()
{
}

Object *Object_wx_DataViewBitmapRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewBitmapRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewBitmapRenderer:");
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
Gura_DeclareMethod(wx_DataViewBitmapRenderer, GetDefaultType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewBitmapRenderer, GetDefaultType)
{
	Object_wx_DataViewBitmapRenderer *pThis = Object_wx_DataViewBitmapRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewBitmapRenderer, wxDataViewBitmapRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewBitmapRenderer, wxDataViewBitmapRenderer)
{
	Object_wx_DataViewBitmapRenderer *pThis = Object_wx_DataViewBitmapRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewBitmapRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewBitmapRenderer)
{
	Gura_AssignMethod(wx_DataViewBitmapRenderer, GetDefaultType);
	Gura_AssignMethod(wx_DataViewBitmapRenderer, wxDataViewBitmapRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewBitmapRenderer)
{
	return new Object_wx_DataViewBitmapRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
