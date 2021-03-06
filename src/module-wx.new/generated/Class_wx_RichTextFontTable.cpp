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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextFontTable, "RichTextFontTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFontTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFontTable)
{
	//wxRichTextFontTable();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextFontTable_1, "RichTextFontTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFontTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFontTable_1)
{
	//const wxRichTextFontTable& table = arg.GetNumber(0)
	//wxRichTextFontTable(table);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextFontTable, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFontTable, __IsOk)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFontTable, __FindFont, "FindFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "fontSpec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFontTable, __FindFont)
{
	Object_wx_RichTextFontTable *pThis = Object_wx_RichTextFontTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& fontSpec = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->FindFont(fontSpec);
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
	//double fontScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontScale(fontScale);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFontTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFontTable)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextFontTable);
	Gura_AssignFunction(__RichTextFontTable_1);
	// Method assignment
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
