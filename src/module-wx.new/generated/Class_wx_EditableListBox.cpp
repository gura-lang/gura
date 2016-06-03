//----------------------------------------------------------------------------
// wxEditableListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEditableListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEditableListBox
//----------------------------------------------------------------------------
Object_wx_EditableListBox::~Object_wx_EditableListBox()
{
}

Object *Object_wx_EditableListBox::Clone() const
{
	return nullptr;
}

String Object_wx_EditableListBox::ToString(bool exprFlag)
{
	String rtn("<wx.EditableListBox:");
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
Gura_DeclareMethodAlias(wx_EditableListBox, __wxEditableListBox, "wxEditableListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EditableListBox, __wxEditableListBox)
{
	Object_wx_EditableListBox *pThis = Object_wx_EditableListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxEditableListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EditableListBox, __wxEditableListBox_1, "wxEditableListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EditableListBox, __wxEditableListBox_1)
{
	Object_wx_EditableListBox *pThis = Object_wx_EditableListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxEditableListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EditableListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EditableListBox, __Create)
{
	Object_wx_EditableListBox *pThis = Object_wx_EditableListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EditableListBox, __SetStrings, "SetStrings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strings", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EditableListBox, __SetStrings)
{
	Object_wx_EditableListBox *pThis = Object_wx_EditableListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strings = arg.GetNumber(0)
	//pThis->GetEntity()->SetStrings();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EditableListBox, __GetStrings, "GetStrings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strings", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EditableListBox, __GetStrings)
{
	Object_wx_EditableListBox *pThis = Object_wx_EditableListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strings = arg.GetNumber(0)
	//pThis->GetEntity()->GetStrings();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEditableListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EditableListBox)
{
	Gura_AssignMethod(wx_EditableListBox, __wxEditableListBox);
	Gura_AssignMethod(wx_EditableListBox, __wxEditableListBox_1);
	Gura_AssignMethod(wx_EditableListBox, __Create);
	Gura_AssignMethod(wx_EditableListBox, __SetStrings);
	Gura_AssignMethod(wx_EditableListBox, __GetStrings);
}

Gura_ImplementDescendantCreator(wx_EditableListBox)
{
	return new Object_wx_EditableListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
