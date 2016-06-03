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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Cursor, "Cursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor)
{
	//wxCursor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Cursor_1, "Cursor_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor_1)
{
	//const char bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int hotSpotX = arg.GetNumber(3)
	//int hotSpotY = arg.GetNumber(4)
	//const char maskBits[] _arg5 = arg.GetNumber(5)
	//wxCursor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Cursor_2, "Cursor_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor_2)
{
	//const wxString& cursorName = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//int hotSpotX = arg.GetNumber(2)
	//int hotSpotY = arg.GetNumber(3)
	//wxCursor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Cursor_3, "Cursor_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorId", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor_3)
{
	//wxStockCursor cursorId = arg.GetNumber(0)
	//wxCursor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Cursor_4, "Cursor_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor_4)
{
	//const wxImage& image = arg.GetNumber(0)
	//wxCursor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Cursor_5, "Cursor_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Cursor_5)
{
	//const wxCursor& cursor = arg.GetNumber(0)
	//wxCursor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	// Constructor assignment
	Gura_AssignFunction(__Cursor);
	Gura_AssignFunction(__Cursor_1);
	Gura_AssignFunction(__Cursor_2);
	Gura_AssignFunction(__Cursor_3);
	Gura_AssignFunction(__Cursor_4);
	Gura_AssignFunction(__Cursor_5);
	// Method assignment
	Gura_AssignMethod(wx_Cursor, __IsOk);
	Gura_AssignMethod(wx_Cursor, __GetHotSpot);
}

Gura_ImplementDescendantCreator(wx_Cursor)
{
	return new Object_wx_Cursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
