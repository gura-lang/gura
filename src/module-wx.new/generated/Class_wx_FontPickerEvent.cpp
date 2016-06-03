//----------------------------------------------------------------------------
// wxFontPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Object_wx_FontPickerEvent::~Object_wx_FontPickerEvent()
{
}

Object *Object_wx_FontPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerEvent:");
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
Gura_DeclareMethodAlias(wx_FontPickerEvent, __wxFontPickerEvent, "wxFontPickerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerEvent, __wxFontPickerEvent)
{
	Object_wx_FontPickerEvent *pThis = Object_wx_FontPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int generator = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int font = arg.GetNumber(2)
	//pThis->GetEntity()->wxFontPickerEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerEvent, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerEvent, __GetFont)
{
	Object_wx_FontPickerEvent *pThis = Object_wx_FontPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerEvent, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerEvent, __SetFont)
{
	Object_wx_FontPickerEvent *pThis = Object_wx_FontPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerEvent)
{
	Gura_AssignMethod(wx_FontPickerEvent, __wxFontPickerEvent);
	Gura_AssignMethod(wx_FontPickerEvent, __GetFont);
	Gura_AssignMethod(wx_FontPickerEvent, __SetFont);
}

Gura_ImplementDescendantCreator(wx_FontPickerEvent)
{
	return new Object_wx_FontPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
