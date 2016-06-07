//----------------------------------------------------------------------------
// wxDataViewEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewEvent
//----------------------------------------------------------------------------
Object_wx_DataViewEvent::~Object_wx_DataViewEvent()
{
}

Object *Object_wx_DataViewEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewEvent:");
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
Gura_DeclareFunctionAlias(__DataViewEvent, "DataViewEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//wxDataViewEvent(commandType, winid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewEvent, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDataViewColumn, "GetDataViewColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDataViewColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* _rtn = pThis->GetEntity()->GetDataViewColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetModel, "GetModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetModel)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewModel* _rtn = pThis->GetEntity()->GetModel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetPosition)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetValue)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __IsEditCancelled, "IsEditCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __IsEditCancelled)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEditCancelled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDataViewColumn, "SetDataViewColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDataViewColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* col = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataViewColumn(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetModel, "SetModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetModel)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewModel* model = arg.GetNumber(0)
	//pThis->GetEntity()->SetModel(model);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetValue)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDataObject, "SetDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDataObject)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataObject* obj = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataObject(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDataFormat, "GetDataFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDataFormat)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataFormat _rtn = pThis->GetEntity()->GetDataFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDataSize, "GetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDataSize)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDataBuffer, "GetDataBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDataBuffer)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* _rtn = pThis->GetEntity()->GetDataBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDragFlags, "SetDragFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDragFlags)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDropEffect, "GetDropEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDropEffect)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDragResult _rtn = pThis->GetEntity()->GetDropEffect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetCacheFrom, "GetCacheFrom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetCacheFrom)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCacheFrom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetCacheTo, "GetCacheTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetCacheTo)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCacheTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetItem)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewItem _rtn = pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetItem, "SetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetItem)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->SetItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetEditCanceled, "SetEditCanceled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editCancelled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetEditCanceled)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool editCancelled = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditCanceled(editCancelled);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetPosition)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetCache, "SetCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetCache)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetCache(from, to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDataObject, "GetDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDataObject)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataObject* _rtn = pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDataFormat, "SetDataFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDataFormat)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataFormat& format = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataFormat(format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDataSize, "SetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDataSize)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDataBuffer, "SetDataBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDataBuffer)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* buf = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataBuffer(buf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __GetDragFlags, "GetDragFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, __GetDragFlags)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetDragFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewEvent, __SetDropEffect, "SetDropEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, __SetDropEffect)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDragResult effect = arg.GetNumber(0)
	//pThis->GetEntity()->SetDropEffect(effect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewEvent);
	// Method assignment
	Gura_AssignMethod(wx_DataViewEvent, __GetColumn);
	Gura_AssignMethod(wx_DataViewEvent, __GetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, __GetModel);
	Gura_AssignMethod(wx_DataViewEvent, __GetPosition);
	Gura_AssignMethod(wx_DataViewEvent, __GetValue);
	Gura_AssignMethod(wx_DataViewEvent, __IsEditCancelled);
	Gura_AssignMethod(wx_DataViewEvent, __SetColumn);
	Gura_AssignMethod(wx_DataViewEvent, __SetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, __SetModel);
	Gura_AssignMethod(wx_DataViewEvent, __SetValue);
	Gura_AssignMethod(wx_DataViewEvent, __SetDataObject);
	Gura_AssignMethod(wx_DataViewEvent, __GetDataFormat);
	Gura_AssignMethod(wx_DataViewEvent, __GetDataSize);
	Gura_AssignMethod(wx_DataViewEvent, __GetDataBuffer);
	Gura_AssignMethod(wx_DataViewEvent, __SetDragFlags);
	Gura_AssignMethod(wx_DataViewEvent, __GetDropEffect);
	Gura_AssignMethod(wx_DataViewEvent, __GetCacheFrom);
	Gura_AssignMethod(wx_DataViewEvent, __GetCacheTo);
	Gura_AssignMethod(wx_DataViewEvent, __GetItem);
	Gura_AssignMethod(wx_DataViewEvent, __SetItem);
	Gura_AssignMethod(wx_DataViewEvent, __SetEditCanceled);
	Gura_AssignMethod(wx_DataViewEvent, __SetPosition);
	Gura_AssignMethod(wx_DataViewEvent, __SetCache);
	Gura_AssignMethod(wx_DataViewEvent, __GetDataObject);
	Gura_AssignMethod(wx_DataViewEvent, __SetDataFormat);
	Gura_AssignMethod(wx_DataViewEvent, __SetDataSize);
	Gura_AssignMethod(wx_DataViewEvent, __SetDataBuffer);
	Gura_AssignMethod(wx_DataViewEvent, __GetDragFlags);
	Gura_AssignMethod(wx_DataViewEvent, __SetDropEffect);
}

Gura_ImplementDescendantCreator(wx_DataViewEvent)
{
	return new Object_wx_DataViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
