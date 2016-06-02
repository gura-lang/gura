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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewRenderer, wxDataViewRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, wxDataViewRenderer)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, EnableEllipsize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, EnableEllipsize)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->EnableEllipsize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, DisableEllipsize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, DisableEllipsize)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableEllipsize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetAlignment)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetEllipsizeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetEllipsizeMode)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEllipsizeMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetMode)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetOwner)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetValue)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetVariantType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetVariantType)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVariantType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, SetAlignment)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, SetOwner)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int owner = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, SetValue)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, Validate)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Validate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, HasEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, HasEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, CreateEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, CreateEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int labelRect = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->CreateEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetValueFromEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetValueFromEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueFromEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, StartEditing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewRenderer, StartEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int labelRect = arg.GetNumber(1)
	//pThis->GetEntity()->StartEditing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, CancelEditing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, CancelEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CancelEditing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, FinishEditing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, FinishEditing)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FinishEditing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetEditorCtrl)
{
	Object_wx_DataViewRenderer *pThis = Object_wx_DataViewRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetView)
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
	Gura_AssignMethod(wx_DataViewRenderer, wxDataViewRenderer);
	Gura_AssignMethod(wx_DataViewRenderer, EnableEllipsize);
	Gura_AssignMethod(wx_DataViewRenderer, DisableEllipsize);
	Gura_AssignMethod(wx_DataViewRenderer, GetAlignment);
	Gura_AssignMethod(wx_DataViewRenderer, GetEllipsizeMode);
	Gura_AssignMethod(wx_DataViewRenderer, GetMode);
	Gura_AssignMethod(wx_DataViewRenderer, GetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, GetValue);
	Gura_AssignMethod(wx_DataViewRenderer, GetVariantType);
	Gura_AssignMethod(wx_DataViewRenderer, SetAlignment);
	Gura_AssignMethod(wx_DataViewRenderer, SetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, SetValue);
	Gura_AssignMethod(wx_DataViewRenderer, Validate);
	Gura_AssignMethod(wx_DataViewRenderer, HasEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, CreateEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, GetValueFromEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, StartEditing);
	Gura_AssignMethod(wx_DataViewRenderer, CancelEditing);
	Gura_AssignMethod(wx_DataViewRenderer, FinishEditing);
	Gura_AssignMethod(wx_DataViewRenderer, GetEditorCtrl);
	Gura_AssignMethod(wx_DataViewRenderer, GetView);
}

Gura_ImplementDescendantCreator(wx_DataViewRenderer)
{
	return new Object_wx_DataViewRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
