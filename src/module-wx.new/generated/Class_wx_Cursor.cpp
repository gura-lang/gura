//----------------------------------------------------------------------------
// wxCursor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCursor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCursor
//----------------------------------------------------------------------------
Object_wx_Cursor::~Object_wx_Cursor()
{
}

Object *Object_wx_Cursor::Clone() const
{
	return nullptr;
}

String Object_wx_Cursor::ToString(bool exprFlag)
{
	String rtn("<wx.Cursor:");
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
Gura_DeclareMethodAlias(wx_Cursor, __wxCursor, "wxCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __wxCursor_1, "wxCursor_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maskBits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor_1)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int hotSpotX = arg.GetNumber(3)
	//int hotSpotY = arg.GetNumber(4)
	//int maskBits = arg.GetNumber(5)
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __wxCursor_2, "wxCursor_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor_2)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursorName = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int hotSpotX = arg.GetNumber(2)
	//int hotSpotY = arg.GetNumber(3)
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __wxCursor_3, "wxCursor_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor_3)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursorId = arg.GetNumber(0)
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __wxCursor_4, "wxCursor_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor_4)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __wxCursor_5, "wxCursor_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Cursor, __wxCursor_5)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->wxCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Cursor, __IsOk)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Cursor, __GetHotSpot, "GetHotSpot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Cursor, __GetHotSpot)
{
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotSpot();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Cursor)
{
	Gura_AssignMethod(wx_Cursor, __wxCursor);
	Gura_AssignMethod(wx_Cursor, __wxCursor_1);
	Gura_AssignMethod(wx_Cursor, __wxCursor_2);
	Gura_AssignMethod(wx_Cursor, __wxCursor_3);
	Gura_AssignMethod(wx_Cursor, __wxCursor_4);
	Gura_AssignMethod(wx_Cursor, __wxCursor_5);
	Gura_AssignMethod(wx_Cursor, __IsOk);
	Gura_AssignMethod(wx_Cursor, __GetHotSpot);
}

Gura_ImplementDescendantCreator(wx_Cursor)
{
	return new Object_wx_Cursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
