//----------------------------------------------------------------------------
// wxSimpleHtmlListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSimpleHtmlListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Object_wx_SimpleHtmlListBox::~Object_wx_SimpleHtmlListBox()
{
}

Object *Object_wx_SimpleHtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_SimpleHtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.SimpleHtmlListBox:");
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
Gura_DeclareFunctionAlias(__SimpleHtmlListBox, "SimpleHtmlListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SimpleHtmlListBox)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxSimpleHtmlListBox(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SimpleHtmlListBox_1, "SimpleHtmlListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SimpleHtmlListBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxSimpleHtmlListBox(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SimpleHtmlListBox_2, "SimpleHtmlListBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SimpleHtmlListBox_2)
{
	//wxSimpleHtmlListBox();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SimpleHtmlListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, __Create)
{
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SimpleHtmlListBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, __Create_1)
{
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SimpleHtmlListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__SimpleHtmlListBox);
	Gura_AssignFunction(__SimpleHtmlListBox_1);
	Gura_AssignFunction(__SimpleHtmlListBox_2);
	// Method assignment
	Gura_AssignMethod(wx_SimpleHtmlListBox, __Create);
	Gura_AssignMethod(wx_SimpleHtmlListBox, __Create_1);
}

Gura_ImplementDescendantCreator(wx_SimpleHtmlListBox)
{
	return new Object_wx_SimpleHtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
