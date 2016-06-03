//----------------------------------------------------------------------------
// wxRichTextFontTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFontTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFontTable
//----------------------------------------------------------------------------
Object_wx_RichTextFontTable::~Object_wx_RichTextFontTable()
{
}

Object *Object_wx_RichTextFontTable::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFontTable::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFontTable:");
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
Gura_DeclareMethodAlias(wx_RichTextFontTable, __wxRichTextFontTable, "wxRichTextFontTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFontTable, __wxRichTextFontTable)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextFontTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __wxRichTextFontTable_1, "wxRichTextFontTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFontTable, __wxRichTextFontTable_1)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextFontTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFontTable, __IsOk)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __FindFont, "FindFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontSpec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFontTable, __FindFont)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontSpec = arg.GetNumber(0)
	//pThis->GetEntity()->FindFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFontTable, __Clear)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __SetFontScale, "SetFontScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFontTable, __SetFontScale)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontScale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFontTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFontTable)
{
	Gura_AssignMethod(wx_RichTextFontTable, __wxRichTextFontTable);
	Gura_AssignMethod(wx_RichTextFontTable, __wxRichTextFontTable_1);
	Gura_AssignMethod(wx_RichTextFontTable, __IsOk);
	Gura_AssignMethod(wx_RichTextFontTable, __FindFont);
	Gura_AssignMethod(wx_RichTextFontTable, __Clear);
	Gura_AssignMethod(wx_RichTextFontTable, __SetFontScale);
}

Gura_ImplementDescendantCreator(wx_RichTextFontTable)
{
	return new Object_wx_RichTextFontTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
