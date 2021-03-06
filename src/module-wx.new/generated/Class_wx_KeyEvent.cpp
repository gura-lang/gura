//----------------------------------------------------------------------------
// wxKeyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxKeyEvent
//----------------------------------------------------------------------------
Object_wx_KeyEvent::~Object_wx_KeyEvent()
{
}

Object *Object_wx_KeyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_KeyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.KeyEvent:");
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
Gura_DeclareFunctionAlias(__KeyEvent, "KeyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "keyEventType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_KeyEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__KeyEvent)
{
	//wxEventType keyEventType = arg.GetNumber(0)
	//wxKeyEvent(keyEventType);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_KeyEvent, __GetKeyCode, "GetKeyCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetKeyCode)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __IsKeyInCategory, "IsKeyInCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "category", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyEvent, __IsKeyInCategory)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int category = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsKeyInCategory(category);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetPosition)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetPosition_1, "GetPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyEvent, __GetPosition_1)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* x = arg.GetNumber(0)
	//wxCoord* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetRawKeyCode, "GetRawKeyCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetRawKeyCode)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 _rtn = pThis->GetEntity()->GetRawKeyCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetRawKeyFlags, "GetRawKeyFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetRawKeyFlags)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 _rtn = pThis->GetEntity()->GetRawKeyFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetUnicodeKey, "GetUnicodeKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetUnicodeKey)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxChar _rtn = pThis->GetEntity()->GetUnicodeKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetX)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord _rtn = pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __GetY)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord _rtn = pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __DoAllowNextEvent, "DoAllowNextEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __DoAllowNextEvent)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoAllowNextEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyEvent, __IsNextEventAllowed, "IsNextEventAllowed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_KeyEvent, __IsNextEventAllowed)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsNextEventAllowed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxKeyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__KeyEvent);
	// Method assignment
	Gura_AssignMethod(wx_KeyEvent, __GetKeyCode);
	Gura_AssignMethod(wx_KeyEvent, __IsKeyInCategory);
	Gura_AssignMethod(wx_KeyEvent, __GetPosition);
	Gura_AssignMethod(wx_KeyEvent, __GetPosition_1);
	Gura_AssignMethod(wx_KeyEvent, __GetRawKeyCode);
	Gura_AssignMethod(wx_KeyEvent, __GetRawKeyFlags);
	Gura_AssignMethod(wx_KeyEvent, __GetUnicodeKey);
	Gura_AssignMethod(wx_KeyEvent, __GetX);
	Gura_AssignMethod(wx_KeyEvent, __GetY);
	Gura_AssignMethod(wx_KeyEvent, __DoAllowNextEvent);
	Gura_AssignMethod(wx_KeyEvent, __IsNextEventAllowed);
}

Gura_ImplementDescendantCreator(wx_KeyEvent)
{
	return new Object_wx_KeyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
