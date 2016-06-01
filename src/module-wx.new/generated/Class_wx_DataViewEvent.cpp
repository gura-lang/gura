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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewEvent, wxDataViewEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, wxDataViewEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxDataViewEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataViewColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataViewColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataViewColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, IsEditCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEditCancelled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataViewColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataViewColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataViewColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "model", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int model = arg.GetNumber(0)
	//pThis->GetEntity()->SetModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDragFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDragFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDropEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDropEffect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDropEffect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetCacheFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetCacheFrom)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCacheFrom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetCacheTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetCacheTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCacheTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetEditCanceled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editCancelled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetEditCanceled)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editCancelled = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditCanceled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetCache)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, GetDragFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDragFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDragFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDropEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDropEffect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int effect = arg.GetNumber(0)
	//pThis->GetEntity()->SetDropEffect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewEvent)
{
	Gura_AssignMethod(wx_DataViewEvent, wxDataViewEvent);
	Gura_AssignMethod(wx_DataViewEvent, GetColumn);
	Gura_AssignMethod(wx_DataViewEvent, GetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, GetModel);
	Gura_AssignMethod(wx_DataViewEvent, GetPosition);
	Gura_AssignMethod(wx_DataViewEvent, GetValue);
	Gura_AssignMethod(wx_DataViewEvent, IsEditCancelled);
	Gura_AssignMethod(wx_DataViewEvent, SetColumn);
	Gura_AssignMethod(wx_DataViewEvent, SetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, SetModel);
	Gura_AssignMethod(wx_DataViewEvent, SetValue);
	Gura_AssignMethod(wx_DataViewEvent, SetDataObject);
	Gura_AssignMethod(wx_DataViewEvent, GetDataFormat);
	Gura_AssignMethod(wx_DataViewEvent, GetDataSize);
	Gura_AssignMethod(wx_DataViewEvent, GetDataBuffer);
	Gura_AssignMethod(wx_DataViewEvent, SetDragFlags);
	Gura_AssignMethod(wx_DataViewEvent, GetDropEffect);
	Gura_AssignMethod(wx_DataViewEvent, GetCacheFrom);
	Gura_AssignMethod(wx_DataViewEvent, GetCacheTo);
	Gura_AssignMethod(wx_DataViewEvent, GetItem);
	Gura_AssignMethod(wx_DataViewEvent, SetItem);
	Gura_AssignMethod(wx_DataViewEvent, SetEditCanceled);
	Gura_AssignMethod(wx_DataViewEvent, SetPosition);
	Gura_AssignMethod(wx_DataViewEvent, SetCache);
	Gura_AssignMethod(wx_DataViewEvent, GetDataObject);
	Gura_AssignMethod(wx_DataViewEvent, SetDataFormat);
	Gura_AssignMethod(wx_DataViewEvent, SetDataSize);
	Gura_AssignMethod(wx_DataViewEvent, SetDataBuffer);
	Gura_AssignMethod(wx_DataViewEvent, GetDragFlags);
	Gura_AssignMethod(wx_DataViewEvent, SetDropEffect);
}

Gura_ImplementDescendantCreator(wx_DataViewEvent)
{
	return new Object_wx_DataViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
