//----------------------------------------------------------------------------
// wxSymbolPickerDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSymbolPickerDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Object_wx_SymbolPickerDialog::~Object_wx_SymbolPickerDialog()
{
}

Object *Object_wx_SymbolPickerDialog::Clone() const
{
	return nullptr;
}

String Object_wx_SymbolPickerDialog::ToString(bool exprFlag)
{
	String rtn("<wx.SymbolPickerDialog:");
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
Gura_DeclareFunctionAlias(__SymbolPickerDialog, "SymbolPickerDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SymbolPickerDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SymbolPickerDialog)
{
	//wxSymbolPickerDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SymbolPickerDialog_1, "SymbolPickerDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialFont", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normalTextFont", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SymbolPickerDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SymbolPickerDialog_1)
{
	//const wxString& symbol = arg.GetNumber(0)
	//const wxString& initialFont = arg.GetNumber(1)
	//const wxString& normalTextFont = arg.GetNumber(2)
	//wxWindow* parent = arg.GetNumber(3)
	//wxWindowID id = arg.GetNumber(4)
	//const wxString& title = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//const wxSize& size = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//wxSymbolPickerDialog(symbol, initialFont, normalTextFont, parent, id, title, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialFont", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normalTextFont", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __Create)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& symbol = arg.GetNumber(0)
	//const wxString& initialFont = arg.GetNumber(1)
	//const wxString& normalTextFont = arg.GetNumber(2)
	//wxWindow* parent = arg.GetNumber(3)
	//wxWindowID id = arg.GetNumber(4)
	//const wxString& caption = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//const wxSize& size = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//pThis->GetEntity()->Create(symbol, initialFont, normalTextFont, parent, id, caption, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __GetFontName, "GetFontName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __GetFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __GetFromUnicode, "GetFromUnicode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __GetFromUnicode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromUnicode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __GetNormalTextFontName, "GetNormalTextFontName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __GetNormalTextFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNormalTextFontName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __GetSymbol, "GetSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __GetSymbol)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSymbol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __GetSymbolChar, "GetSymbolChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __GetSymbolChar)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSymbolChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __HasSelection, "HasSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __HasSelection)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __SetFontName, "SetFontName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __SetFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString value = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontName(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __SetFromUnicode, "SetFromUnicode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __SetFromUnicode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool value = arg.GetNumber(0)
	//pThis->GetEntity()->SetFromUnicode(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __SetNormalTextFontName, "SetNormalTextFontName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __SetNormalTextFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString value = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalTextFontName(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __SetSymbol, "SetSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __SetSymbol)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString value = arg.GetNumber(0)
	//pThis->GetEntity()->SetSymbol(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __SetUnicodeMode, "SetUnicodeMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unicodeMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __SetUnicodeMode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool unicodeMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnicodeMode(unicodeMode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SymbolPickerDialog, __UseNormalFont, "UseNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, __UseNormalFont)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UseNormalFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SymbolPickerDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__SymbolPickerDialog);
	Gura_AssignFunction(__SymbolPickerDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_SymbolPickerDialog, __Create);
	Gura_AssignMethod(wx_SymbolPickerDialog, __GetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, __GetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, __GetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, __GetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, __GetSymbolChar);
	Gura_AssignMethod(wx_SymbolPickerDialog, __HasSelection);
	Gura_AssignMethod(wx_SymbolPickerDialog, __SetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, __SetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, __SetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, __SetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, __SetUnicodeMode);
	Gura_AssignMethod(wx_SymbolPickerDialog, __UseNormalFont);
}

Gura_ImplementDescendantCreator(wx_SymbolPickerDialog)
{
	return new Object_wx_SymbolPickerDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
