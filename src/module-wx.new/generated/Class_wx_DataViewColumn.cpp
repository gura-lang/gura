//----------------------------------------------------------------------------
// wxDataViewColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Object_wx_DataViewColumn::~Object_wx_DataViewColumn()
{
}

Object *Object_wx_DataViewColumn::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewColumn::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewColumn:");
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
Gura_DeclareMethodAlias(wx_DataViewColumn, __wxDataViewColumn, "wxDataViewColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, __wxDataViewColumn)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int renderer = arg.GetNumber(1)
	//int model_column = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->wxDataViewColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewColumn, __wxDataViewColumn_1, "wxDataViewColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, __wxDataViewColumn_1)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int renderer = arg.GetNumber(1)
	//int model_column = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->wxDataViewColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewColumn, __GetModelColumn, "GetModelColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewColumn, __GetModelColumn)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModelColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewColumn, __GetOwner, "GetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewColumn, __GetOwner)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewColumn, __GetRenderer, "GetRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewColumn, __GetRenderer)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewColumn)
{
	Gura_AssignMethod(wx_DataViewColumn, __wxDataViewColumn);
	Gura_AssignMethod(wx_DataViewColumn, __wxDataViewColumn_1);
	Gura_AssignMethod(wx_DataViewColumn, __GetModelColumn);
	Gura_AssignMethod(wx_DataViewColumn, __GetOwner);
	Gura_AssignMethod(wx_DataViewColumn, __GetRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewColumn)
{
	return new Object_wx_DataViewColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
