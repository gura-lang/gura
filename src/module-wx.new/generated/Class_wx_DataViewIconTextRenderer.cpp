//----------------------------------------------------------------------------
// wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewIconTextRenderer::~Object_wx_DataViewIconTextRenderer()
{
}

Object *Object_wx_DataViewIconTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIconTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIconTextRenderer:");
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
Gura_DeclareMethod(wx_DataViewIconTextRenderer, GetDefaultType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIconTextRenderer, GetDefaultType)
{
	Object_wx_DataViewIconTextRenderer *pThis = Object_wx_DataViewIconTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconTextRenderer, wxDataViewIconTextRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconTextRenderer, wxDataViewIconTextRenderer)
{
	Object_wx_DataViewIconTextRenderer *pThis = Object_wx_DataViewIconTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewIconTextRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIconTextRenderer)
{
	Gura_AssignMethod(wx_DataViewIconTextRenderer, GetDefaultType);
	Gura_AssignMethod(wx_DataViewIconTextRenderer, wxDataViewIconTextRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewIconTextRenderer)
{
	return new Object_wx_DataViewIconTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
