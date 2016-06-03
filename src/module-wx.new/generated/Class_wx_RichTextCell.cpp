//----------------------------------------------------------------------------
// wxRichTextCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCell
//----------------------------------------------------------------------------
Object_wx_RichTextCell::~Object_wx_RichTextCell()
{
}

Object *Object_wx_RichTextCell::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCell::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCell:");
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
Gura_DeclareFunctionAlias(__wxRichTextCell, "wxRichTextCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextCell)
{
	//int parent = arg.GetNumber(0)
	//wxRichTextCell();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextCell_1, "wxRichTextCell_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextCell_1)
{
	//wxRichTextCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextCell, __Draw, "Draw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __Draw)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contextObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __HitTest)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int pt = arg.GetNumber(2)
	//int textPosition = arg.GetNumber(3)
	//int obj = arg.GetNumber(4)
	//int contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __GetXMLNodeName)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __CanEditProperties)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __EditProperties)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __GetColSpan, "GetColSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __GetColSpan)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColSpan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __SetColSpan, "SetColSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __SetColSpan)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int span = arg.GetNumber(0)
	//pThis->GetEntity()->SetColSpan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __GetRowSpan, "GetRowSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __GetRowSpan)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowSpan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __SetRowSpan, "SetRowSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __SetRowSpan)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int span = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowSpan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, __Clone)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCell, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, __Copy)
{
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCell)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextCell);
	Gura_AssignFunction(__wxRichTextCell_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextCell, __Draw);
	Gura_AssignMethod(wx_RichTextCell, __HitTest);
	Gura_AssignMethod(wx_RichTextCell, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextCell, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextCell, __EditProperties);
	Gura_AssignMethod(wx_RichTextCell, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextCell, __GetColSpan);
	Gura_AssignMethod(wx_RichTextCell, __SetColSpan);
	Gura_AssignMethod(wx_RichTextCell, __GetRowSpan);
	Gura_AssignMethod(wx_RichTextCell, __SetRowSpan);
	Gura_AssignMethod(wx_RichTextCell, __Clone);
	Gura_AssignMethod(wx_RichTextCell, __Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextCell)
{
	return new Object_wx_RichTextCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
