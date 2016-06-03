//----------------------------------------------------------------------------
// wxRichTextAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Object_wx_RichTextAttr::~Object_wx_RichTextAttr()
{
}

Object *Object_wx_RichTextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextAttr:");
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
Gura_DeclareFunctionAlias(__RichTextAttr, "RichTextAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextAttr)
{
	//const wxTextAttr& attr = arg.GetNumber(0)
	//wxRichTextAttr();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextAttr_1, "RichTextAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextAttr_1)
{
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//wxRichTextAttr();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextAttr_2, "RichTextAttr_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextAttr_2)
{
	//wxRichTextAttr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextAttr, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __Copy)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __EqPartial)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//bool weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __Apply)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& style = arg.GetNumber(0)
	//const wxRichTextAttr* compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __CollectCommonAttributes)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//wxRichTextAttr& clashingAttr = arg.GetNumber(1)
	//wxRichTextAttr& absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __RemoveStyle)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __GetTextBoxAttr, "GetTextBoxAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, __GetTextBoxAttr)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __GetTextBoxAttr_1, "GetTextBoxAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, __GetTextBoxAttr_1)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __SetTextBoxAttr, "SetTextBoxAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, __SetTextBoxAttr)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextBoxAttr& attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAttr, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, __IsDefault)
{
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAttr)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextAttr);
	Gura_AssignFunction(__RichTextAttr_1);
	Gura_AssignFunction(__RichTextAttr_2);
	// Method assignment
	Gura_AssignMethod(wx_RichTextAttr, __Copy);
	Gura_AssignMethod(wx_RichTextAttr, __EqPartial);
	Gura_AssignMethod(wx_RichTextAttr, __Apply);
	Gura_AssignMethod(wx_RichTextAttr, __CollectCommonAttributes);
	Gura_AssignMethod(wx_RichTextAttr, __RemoveStyle);
	Gura_AssignMethod(wx_RichTextAttr, __GetTextBoxAttr);
	Gura_AssignMethod(wx_RichTextAttr, __GetTextBoxAttr_1);
	Gura_AssignMethod(wx_RichTextAttr, __SetTextBoxAttr);
	Gura_AssignMethod(wx_RichTextAttr, __IsDefault);
}

Gura_ImplementDescendantCreator(wx_RichTextAttr)
{
	return new Object_wx_RichTextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
