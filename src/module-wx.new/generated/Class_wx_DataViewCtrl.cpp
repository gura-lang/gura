//----------------------------------------------------------------------------
// wxDataViewCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewCtrl::~Object_wx_DataViewCtrl()
{
}

Object *Object_wx_DataViewCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCtrl:");
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
Gura_DeclareMethod(wx_DataViewCtrl, wxDataViewCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, wxDataViewCtrl)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, wxDataViewCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, wxDataViewCtrl_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxDataViewCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AllowMultiColumnSort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AllowMultiColumnSort)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int allow = arg.GetNumber(0)
	//pThis->GetEntity()->AllowMultiColumnSort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Create)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, InsertColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendBitmapColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendBitmapColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependBitmapColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependBitmapColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependBitmapColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependBitmapColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependBitmapColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependBitmapColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendDateColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendDateColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependDateColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependDateColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependDateColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependDateColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependDateColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependDateColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendIconTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendIconTextColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendIconTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendIconTextColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendIconTextColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendIconTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependIconTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependIconTextColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependIconTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependIconTextColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependIconTextColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependIconTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendProgressColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendProgressColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependProgressColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependProgressColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependProgressColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependProgressColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependProgressColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependProgressColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependTextColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependTextColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependTextColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendToggleColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->AppendToggleColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependToggleColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependToggleColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependToggleColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, PrependToggleColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, PrependToggleColumn_1)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int model_column = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->PrependToggleColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, AssociateModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, AssociateModel)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int model = arg.GetNumber(0)
	//pThis->GetEntity()->AssociateModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, ClearColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, ClearColumns)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Collapse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Collapse)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, DeleteColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, EditItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, EditItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->EditItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, EnableDragSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, EnableDragSource)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDragSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, EnableDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, EnableDropTarget)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDropTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, EnsureVisible)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Expand)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, ExpandAncestors)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, ExpandAncestors)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAncestors();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetColumnCount)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetColumnPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetColumnPosition)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetExpanderColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetExpanderColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExpanderColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetCurrentItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetCurrentItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetCurrentColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetCurrentColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetIndent)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetItemRect)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetModel)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelectedItemsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelectedItemsCount)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedItemsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelection)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelections)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSortingColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSortingColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSortingColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSortingColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSortingColumns)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSortingColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, HasSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, HasSelection)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, HitTest)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, IsExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, IsExpanded)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, IsMultiColumnSortAllowed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, IsMultiColumnSortAllowed)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiColumnSortAllowed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, IsSelected)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Select)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, SelectAll)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetExpanderColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetExpanderColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetExpanderColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetCurrentItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetCurrentItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetIndent)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelections)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Unselect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Unselect)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, UnselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, UnselectAll)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetRowHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetRowHeight)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowHeight = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, ToggleSortByColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, ToggleSortByColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleSortByColumn();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCtrl)
{
	Gura_AssignMethod(wx_DataViewCtrl, wxDataViewCtrl);
	Gura_AssignMethod(wx_DataViewCtrl, wxDataViewCtrl_1);
	Gura_AssignMethod(wx_DataViewCtrl, AllowMultiColumnSort);
	Gura_AssignMethod(wx_DataViewCtrl, Create);
	Gura_AssignMethod(wx_DataViewCtrl, AppendColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependColumn);
	Gura_AssignMethod(wx_DataViewCtrl, InsertColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendBitmapColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendBitmapColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependBitmapColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependBitmapColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendDateColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendDateColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependDateColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependDateColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendIconTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendIconTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependIconTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependIconTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendProgressColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendProgressColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependProgressColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependProgressColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendToggleColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendToggleColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, PrependToggleColumn);
	Gura_AssignMethod(wx_DataViewCtrl, PrependToggleColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AssociateModel);
	Gura_AssignMethod(wx_DataViewCtrl, ClearColumns);
	Gura_AssignMethod(wx_DataViewCtrl, Collapse);
	Gura_AssignMethod(wx_DataViewCtrl, DeleteColumn);
	Gura_AssignMethod(wx_DataViewCtrl, EditItem);
	Gura_AssignMethod(wx_DataViewCtrl, EnableDragSource);
	Gura_AssignMethod(wx_DataViewCtrl, EnableDropTarget);
	Gura_AssignMethod(wx_DataViewCtrl, EnsureVisible);
	Gura_AssignMethod(wx_DataViewCtrl, Expand);
	Gura_AssignMethod(wx_DataViewCtrl, ExpandAncestors);
	Gura_AssignMethod(wx_DataViewCtrl, GetColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetColumnCount);
	Gura_AssignMethod(wx_DataViewCtrl, GetColumnPosition);
	Gura_AssignMethod(wx_DataViewCtrl, GetExpanderColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetCurrentItem);
	Gura_AssignMethod(wx_DataViewCtrl, GetCurrentColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetIndent);
	Gura_AssignMethod(wx_DataViewCtrl, GetItemRect);
	Gura_AssignMethod(wx_DataViewCtrl, GetModel);
	Gura_AssignMethod(wx_DataViewCtrl, GetSelectedItemsCount);
	Gura_AssignMethod(wx_DataViewCtrl, GetSelection);
	Gura_AssignMethod(wx_DataViewCtrl, GetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, GetSortingColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetSortingColumns);
	Gura_AssignMethod(wx_DataViewCtrl, HasSelection);
	Gura_AssignMethod(wx_DataViewCtrl, HitTest);
	Gura_AssignMethod(wx_DataViewCtrl, IsExpanded);
	Gura_AssignMethod(wx_DataViewCtrl, IsMultiColumnSortAllowed);
	Gura_AssignMethod(wx_DataViewCtrl, IsSelected);
	Gura_AssignMethod(wx_DataViewCtrl, Select);
	Gura_AssignMethod(wx_DataViewCtrl, SelectAll);
	Gura_AssignMethod(wx_DataViewCtrl, SetExpanderColumn);
	Gura_AssignMethod(wx_DataViewCtrl, SetCurrentItem);
	Gura_AssignMethod(wx_DataViewCtrl, SetIndent);
	Gura_AssignMethod(wx_DataViewCtrl, SetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, Unselect);
	Gura_AssignMethod(wx_DataViewCtrl, UnselectAll);
	Gura_AssignMethod(wx_DataViewCtrl, SetRowHeight);
	Gura_AssignMethod(wx_DataViewCtrl, ToggleSortByColumn);
}

Gura_ImplementDescendantCreator(wx_DataViewCtrl)
{
	return new Object_wx_DataViewCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
