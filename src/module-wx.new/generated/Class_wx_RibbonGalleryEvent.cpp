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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RibbonGalleryEvent, wxRibbonGalleryEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gallery", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, wxRibbonGalleryEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//int gallery = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//pThis->GetEntity()->wxRibbonGalleryEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGalleryEvent, GetGallery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, GetGallery)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGallery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGalleryEvent, GetGalleryItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, GetGalleryItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGalleryItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGalleryEvent, SetGallery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gallery", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, SetGallery)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int gallery = arg.GetNumber(0)
	//pThis->GetEntity()->SetGallery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGalleryEvent, SetGalleryItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGalleryEvent, SetGalleryItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonGalleryEvent *pThis = Object_wx_RibbonGalleryEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetGalleryItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGalleryEvent)
{
	Gura_AssignMethod(wx_RibbonGalleryEvent, wxRibbonGalleryEvent);
	Gura_AssignMethod(wx_RibbonGalleryEvent, GetGallery);
	Gura_AssignMethod(wx_RibbonGalleryEvent, GetGalleryItem);
	Gura_AssignMethod(wx_RibbonGalleryEvent, SetGallery);
	Gura_AssignMethod(wx_RibbonGalleryEvent, SetGalleryItem);
}

Gura_ImplementDescendantCreator(wx_RibbonGalleryEvent)
{
	return new Object_wx_RibbonGalleryEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
