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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewCustomRenderer, GetDefaultType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetDefaultType)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, wxDataViewCustomRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, wxDataViewCustomRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//pThis->GetEntity()->wxDataViewCustomRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, ~wxDataViewCustomRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, ~wxDataViewCustomRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDataViewCustomRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, ActivateCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mouseEvent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, ActivateCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int model = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//int mouseEvent = arg.GetNumber(4)
	//pThis->GetEntity()->ActivateCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, CreateEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "labelRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, CreateEditorCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int labelRect = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->CreateEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetValueFromEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetValueFromEditorCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueFromEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, HasEditorCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, HasEditorCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasEditorCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, LeftClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, LeftClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//int cell = arg.GetNumber(1)
	//int model = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->LeftClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int model = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, Render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, Render)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int state = arg.GetNumber(2)
	//pThis->GetEntity()->Render();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, RenderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, RenderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int xoffset = arg.GetNumber(1)
	//int cell = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int state = arg.GetNumber(4)
	//pThis->GetEntity()->RenderText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, StartDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, StartDrag)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//int cell = arg.GetNumber(1)
	//int model = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->StartDrag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetTextExtent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCustomRenderer)
{
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetDefaultType);
	Gura_AssignMethod(wx_DataViewCustomRenderer, wxDataViewCustomRenderer);
	Gura_AssignMethod(wx_DataViewCustomRenderer, ~wxDataViewCustomRenderer);
	Gura_AssignMethod(wx_DataViewCustomRenderer, ActivateCell);
	Gura_AssignMethod(wx_DataViewCustomRenderer, CreateEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetAttr);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetSize);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetValueFromEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, HasEditorCtrl);
	Gura_AssignMethod(wx_DataViewCustomRenderer, LeftClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, Activate);
	Gura_AssignMethod(wx_DataViewCustomRenderer, Render);
	Gura_AssignMethod(wx_DataViewCustomRenderer, RenderText);
	Gura_AssignMethod(wx_DataViewCustomRenderer, StartDrag);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetTextExtent);
}

Gura_ImplementDescendantCreator(wx_DataViewCustomRenderer)
{
	return new Object_wx_DataViewCustomRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
