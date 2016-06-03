//----------------------------------------------------------------------------
// wxDataViewCustomRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCustomRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewCustomRenderer::~Object_wx_DataViewCustomRenderer()
{
}

Object *Object_wx_DataViewCustomRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCustomRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCustomRenderer:");
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
Gura_DeclareFunctionAlias(__wxDataViewCustomRenderer, "wxDataViewCustomRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDataViewCustomRenderer)
{
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//wxDataViewCustomRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __GetDefaultType, "GetDefaultType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __GetDefaultType)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __ActivateCell, "ActivateCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mouseEvent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __ActivateCell)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int model = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//int mouseEvent = arg.GetNumber(4)
	//pThis->GetEntity()->ActivateCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __CreateEditorCtrl, "CreateEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __CreateEditorCtrl)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int labelRect = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->CreateEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __GetAttr, "GetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __GetAttr)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __GetSize)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __GetValueFromEditorCtrl, "GetValueFromEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __GetValueFromEditorCtrl)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueFromEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __HasEditorCtrl, "HasEditorCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __HasEditorCtrl)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __LeftClick, "LeftClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __LeftClick)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//int cell = arg.GetNumber(1)
	//int model = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->LeftClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __Activate, "Activate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __Activate)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int model = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __Render, "Render")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __Render)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int state = arg.GetNumber(2)
	//pThis->GetEntity()->Render();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __RenderText, "RenderText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __RenderText)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int xoffset = arg.GetNumber(1)
	//int cell = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int state = arg.GetNumber(4)
	//pThis->GetEntity()->RenderText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __StartDrag, "StartDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __StartDrag)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//int cell = arg.GetNumber(1)
	//int model = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->StartDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCustomRenderer, __GetTextExtent, "GetTextExtent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, __GetTextExtent)
{
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCustomRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewCustomRenderer);
	// Method assignment
	Gura_AssignMethod(wx_DataViewCustomRenderer, __GetDefaultType);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __ActivateCell);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __CreateEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __GetAttr);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __GetSize);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __GetValueFromEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __HasEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __LeftClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __Activate);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __Render);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __RenderText);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __StartDrag);
	Gura_AssignMethod(wx_DataViewCustomRenderer, __GetTextExtent);
}

Gura_ImplementDescendantCreator(wx_DataViewCustomRenderer)
{
	return new Object_wx_DataViewCustomRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
