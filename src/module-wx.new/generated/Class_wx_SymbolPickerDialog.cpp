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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSymbolPickerDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog_1)
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
}

Gura_ImplementMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//int initialFont = arg.GetNumber(1)
	//int normalTextFont = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int id = arg.GetNumber(4)
	//int title = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//pThis->GetEntity()->wxSymbolPickerDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, Create)
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

Gura_ImplementMethod(wx_SymbolPickerDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//int initialFont = arg.GetNumber(1)
	//int normalTextFont = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int id = arg.GetNumber(4)
	//int caption = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFromUnicode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNormalTextFontName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSymbolChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, HasSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, HasSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetFromUnicode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalTextFontName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unicodeMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int unicodeMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnicodeMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UseNormalFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SymbolPickerDialog)
{
	Gura_AssignMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog);
	Gura_AssignMethod(wx_SymbolPickerDialog, wxSymbolPickerDialog_1);
	Gura_AssignMethod(wx_SymbolPickerDialog, Create);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetSymbolChar);
	Gura_AssignMethod(wx_SymbolPickerDialog, HasSelection);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetUnicodeMode);
	Gura_AssignMethod(wx_SymbolPickerDialog, UseNormalFont);
}

Gura_ImplementDescendantCreator(wx_SymbolPickerDialog)
{
	return new Object_wx_SymbolPickerDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
