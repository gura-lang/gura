//----------------------------------------------------------------------------
// wxDataViewRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewRenderer::~Object_wx_DataViewRenderer()
{
}

Object *Object_wx_DataViewRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewRenderer:");
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
Gura_DeclareFunctionAlias(__DataViewRenderer, "DataViewRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewRenderer)
{
	//const wxString& varianttype = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//wxDataViewRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewRenderer, __EnableEllipsize, "EnableEllipsize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __EnableEllipsize)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEllipsizeMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->EnableEllipsize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __DisableEllipsize, "DisableEllipsize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __DisableEllipsize)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableEllipsize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetAlignment, "GetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetAlignment)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetEllipsizeMode, "GetEllipsizeMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetEllipsizeMode)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEllipsizeMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetMode)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetOwner, "GetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetOwner)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetValue)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetVariantType, "GetVariantType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetVariantType)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVariantType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __SetAlignment)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __SetOwner, "SetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __SetOwner)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* owner = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __SetValue)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __Validate, "Validate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __Validate)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//pThis->GetEntity()->Validate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __HasEditorCtrl, "HasEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __HasEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __CreateEditorCtrl, "CreateEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __CreateEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxRect labelRect = arg.GetNumber(1)
	//const wxVariant& value = arg.GetNumber(2)
	//pThis->GetEntity()->CreateEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetValueFromEditorCtrl, "GetValueFromEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetValueFromEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* editor = arg.GetNumber(0)
	//wxVariant& value = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueFromEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __StartEditing, "StartEditing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, __StartEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxRect labelRect = arg.GetNumber(1)
	//pThis->GetEntity()->StartEditing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __CancelEditing, "CancelEditing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __CancelEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CancelEditing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __FinishEditing, "FinishEditing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __FinishEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FinishEditing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetEditorCtrl, "GetEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewRenderer, __GetView, "GetView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, __GetView)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewRenderer);
	// Method assignment
	Gura_AssignMethod(wx_DataViewRenderer, __EnableEllipsize);
	Gura_AssignMethod(wx_DataViewRenderer, __DisableEllipsize);
	Gura_AssignMethod(wx_DataViewRenderer, __GetAlignment);
	Gura_AssignMethod(wx_DataViewRenderer, __GetEllipsizeMode);
	Gura_AssignMethod(wx_DataViewRenderer, __GetMode);
	Gura_AssignMethod(wx_DataViewRenderer, __GetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, __GetValue);
	Gura_AssignMethod(wx_DataViewRenderer, __GetVariantType);
	Gura_AssignMethod(wx_DataViewRenderer, __SetAlignment);
	Gura_AssignMethod(wx_DataViewRenderer, __SetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, __SetValue);
	Gura_AssignMethod(wx_DataViewRenderer, __Validate);
	Gura_AssignMethod(wx_DataViewRenderer, __HasEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, __CreateEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, __GetValueFromEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, __StartEditing);
	Gura_AssignMethod(wx_DataViewRenderer, __CancelEditing);
	Gura_AssignMethod(wx_DataViewRenderer, __FinishEditing);
	Gura_AssignMethod(wx_DataViewRenderer, __GetEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, __GetView);
}

Gura_ImplementDescendantCreator(wx_DataViewRenderer)
{
	return new Object_wx_DataViewRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
