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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SimpleHtmlListBox)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//wxSimpleHtmlListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SimpleHtmlListBox_1, "SimpleHtmlListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxSimpleHtmlListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SimpleHtmlListBox_2, "SimpleHtmlListBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, __Create)
{
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SimpleHtmlListBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
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
