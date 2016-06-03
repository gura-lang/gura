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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDataViewCtrl, "wxDataViewCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataViewCtrl)
{
	//wxDataViewCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDataViewCtrl_1, "wxDataViewCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataViewCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxDataViewCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewCtrl, __AllowMultiColumnSort, "AllowMultiColumnSort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AllowMultiColumnSort)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int allow = arg.GetNumber(0)
	//pThis->GetEntity()->AllowMultiColumnSort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_DataViewCtrl, __Create)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependColumn, "PrependColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __InsertColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendBitmapColumn, "AppendBitmapColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendBitmapColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendBitmapColumn_1, "AppendBitmapColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendBitmapColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependBitmapColumn, "PrependBitmapColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependBitmapColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependBitmapColumn_1, "PrependBitmapColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependBitmapColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendDateColumn, "AppendDateColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendDateColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendDateColumn_1, "AppendDateColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendDateColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependDateColumn, "PrependDateColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependDateColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependDateColumn_1, "PrependDateColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependDateColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendIconTextColumn, "AppendIconTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendIconTextColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendIconTextColumn_1, "AppendIconTextColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendIconTextColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependIconTextColumn, "PrependIconTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependIconTextColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependIconTextColumn_1, "PrependIconTextColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependIconTextColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendProgressColumn, "AppendProgressColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendProgressColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendProgressColumn_1, "AppendProgressColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendProgressColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependProgressColumn, "PrependProgressColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependProgressColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependProgressColumn_1, "PrependProgressColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependProgressColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendTextColumn, "AppendTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendTextColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendTextColumn_1, "AppendTextColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendTextColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependTextColumn, "PrependTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependTextColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependTextColumn_1, "PrependTextColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependTextColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendToggleColumn, "AppendToggleColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendToggleColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AppendToggleColumn_1, "AppendToggleColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AppendToggleColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependToggleColumn, "PrependToggleColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependToggleColumn)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __PrependToggleColumn_1, "PrependToggleColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __PrependToggleColumn_1)
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

Gura_DeclareMethodAlias(wx_DataViewCtrl, __AssociateModel, "AssociateModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __AssociateModel)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int model = arg.GetNumber(0)
	//pThis->GetEntity()->AssociateModel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __ClearColumns, "ClearColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __ClearColumns)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __Collapse, "Collapse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __Collapse)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __DeleteColumn, "DeleteColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __DeleteColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __EditItem, "EditItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __EditItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->EditItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __EnableDragSource, "EnableDragSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __EnableDragSource)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDragSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __EnableDropTarget, "EnableDropTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __EnableDropTarget)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDropTarget();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __EnsureVisible)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __Expand)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __ExpandAncestors, "ExpandAncestors")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __ExpandAncestors)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAncestors();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetColumnCount)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetColumnPosition, "GetColumnPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetColumnPosition)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetExpanderColumn, "GetExpanderColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetExpanderColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExpanderColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetCurrentItem, "GetCurrentItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetCurrentItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetCurrentColumn, "GetCurrentColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetCurrentColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetIndent, "GetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetIndent)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetItemRect)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetModel, "GetModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetModel)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetSelectedItemsCount, "GetSelectedItemsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetSelectedItemsCount)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedItemsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetSelection)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetSelections)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetSortingColumn, "GetSortingColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetSortingColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSortingColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __GetSortingColumns, "GetSortingColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __GetSortingColumns)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSortingColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __HasSelection, "HasSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __HasSelection)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __HitTest)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __IsExpanded)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __IsMultiColumnSortAllowed, "IsMultiColumnSortAllowed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __IsMultiColumnSortAllowed)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiColumnSortAllowed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __IsSelected)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __Select)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SelectAll)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SetExpanderColumn, "SetExpanderColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SetExpanderColumn)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetExpanderColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SetCurrentItem, "SetCurrentItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SetCurrentItem)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SetIndent, "SetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SetIndent)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SetSelections, "SetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SetSelections)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __Unselect, "Unselect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __Unselect)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __UnselectAll, "UnselectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, __UnselectAll)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __SetRowHeight, "SetRowHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __SetRowHeight)
{
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowHeight = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewCtrl, __ToggleSortByColumn, "ToggleSortByColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, __ToggleSortByColumn)
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
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewCtrl);
	Gura_AssignFunction(__wxDataViewCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_DataViewCtrl, __AllowMultiColumnSort);
	Gura_AssignMethod(wx_DataViewCtrl, __Create);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __InsertColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendBitmapColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendBitmapColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependBitmapColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependBitmapColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendDateColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendDateColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependDateColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependDateColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendIconTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendIconTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependIconTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependIconTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendProgressColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendProgressColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependProgressColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependProgressColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendToggleColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __AppendToggleColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependToggleColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __PrependToggleColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, __AssociateModel);
	Gura_AssignMethod(wx_DataViewCtrl, __ClearColumns);
	Gura_AssignMethod(wx_DataViewCtrl, __Collapse);
	Gura_AssignMethod(wx_DataViewCtrl, __DeleteColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __EditItem);
	Gura_AssignMethod(wx_DataViewCtrl, __EnableDragSource);
	Gura_AssignMethod(wx_DataViewCtrl, __EnableDropTarget);
	Gura_AssignMethod(wx_DataViewCtrl, __EnsureVisible);
	Gura_AssignMethod(wx_DataViewCtrl, __Expand);
	Gura_AssignMethod(wx_DataViewCtrl, __ExpandAncestors);
	Gura_AssignMethod(wx_DataViewCtrl, __GetColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __GetColumnCount);
	Gura_AssignMethod(wx_DataViewCtrl, __GetColumnPosition);
	Gura_AssignMethod(wx_DataViewCtrl, __GetExpanderColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __GetCurrentItem);
	Gura_AssignMethod(wx_DataViewCtrl, __GetCurrentColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __GetIndent);
	Gura_AssignMethod(wx_DataViewCtrl, __GetItemRect);
	Gura_AssignMethod(wx_DataViewCtrl, __GetModel);
	Gura_AssignMethod(wx_DataViewCtrl, __GetSelectedItemsCount);
	Gura_AssignMethod(wx_DataViewCtrl, __GetSelection);
	Gura_AssignMethod(wx_DataViewCtrl, __GetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, __GetSortingColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __GetSortingColumns);
	Gura_AssignMethod(wx_DataViewCtrl, __HasSelection);
	Gura_AssignMethod(wx_DataViewCtrl, __HitTest);
	Gura_AssignMethod(wx_DataViewCtrl, __IsExpanded);
	Gura_AssignMethod(wx_DataViewCtrl, __IsMultiColumnSortAllowed);
	Gura_AssignMethod(wx_DataViewCtrl, __IsSelected);
	Gura_AssignMethod(wx_DataViewCtrl, __Select);
	Gura_AssignMethod(wx_DataViewCtrl, __SelectAll);
	Gura_AssignMethod(wx_DataViewCtrl, __SetExpanderColumn);
	Gura_AssignMethod(wx_DataViewCtrl, __SetCurrentItem);
	Gura_AssignMethod(wx_DataViewCtrl, __SetIndent);
	Gura_AssignMethod(wx_DataViewCtrl, __SetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, __Unselect);
	Gura_AssignMethod(wx_DataViewCtrl, __UnselectAll);
	Gura_AssignMethod(wx_DataViewCtrl, __SetRowHeight);
	Gura_AssignMethod(wx_DataViewCtrl, __ToggleSortByColumn);
}

Gura_ImplementDescendantCreator(wx_DataViewCtrl)
{
	return new Object_wx_DataViewCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
