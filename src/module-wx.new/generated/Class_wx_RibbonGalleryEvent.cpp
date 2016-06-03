//----------------------------------------------------------------------------
// wxRibbonGalleryEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonGalleryEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Object_wx_RibbonGalleryEvent::~Object_wx_RibbonGalleryEvent()
{
}

Object *Object_wx_RibbonGalleryEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonGalleryEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonGalleryEvent:");
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
Gura_DeclareFunctionAlias(__RibbonGalleryEvent, "RibbonGalleryEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gallery", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonGalleryEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonGalleryEvent)
{
	//wxEventType command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//wxRibbonGallery* gallery = arg.GetNumber(2)
	//wxRibbonGalleryItem* item = arg.GetNumber(3)
	//wxRibbonGalleryEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonGalleryEvent, __GetGallery, "GetGallery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, __GetGallery)
{
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGallery();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGalleryEvent, __GetGalleryItem, "GetGalleryItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, __GetGalleryItem)
{
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGalleryItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGalleryEvent, __SetGallery, "SetGallery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gallery", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, __SetGallery)
{
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonGallery* gallery = arg.GetNumber(0)
	//pThis->GetEntity()->SetGallery();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGalleryEvent, __SetGalleryItem, "SetGalleryItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, __SetGalleryItem)
{
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonGalleryItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->SetGalleryItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGalleryEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonGalleryEvent);
	// Method assignment
	Gura_AssignMethod(wx_RibbonGalleryEvent, __GetGallery);
	Gura_AssignMethod(wx_RibbonGalleryEvent, __GetGalleryItem);
	Gura_AssignMethod(wx_RibbonGalleryEvent, __SetGallery);
	Gura_AssignMethod(wx_RibbonGalleryEvent, __SetGalleryItem);
}

Gura_ImplementDescendantCreator(wx_RibbonGalleryEvent)
{
	return new Object_wx_RibbonGalleryEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
