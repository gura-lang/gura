//----------------------------------------------------------------------------
// wxRichTextCompositeObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCompositeObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Object_wx_RichTextCompositeObject::~Object_wx_RichTextCompositeObject()
{
}

Object *Object_wx_RichTextCompositeObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCompositeObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCompositeObject:");
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
Gura_DeclareFunctionAlias(__wxRichTextCompositeObject, "wxRichTextCompositeObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCompositeObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextCompositeObject)
{
	//int parent = arg.GetNumber(0)
	//wxRichTextCompositeObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __HitTest, "HitTest")
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

Gura_ImplementMethod(wx_RichTextCompositeObject, __HitTest)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __FindPosition)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//int pt = arg.GetNumber(3)
	//int height = arg.GetNumber(4)
	//int forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __CalculateRange)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __DeleteRange)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetTextForRange)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetRangeSize)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int descent = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int position = arg.GetNumber(6)
	//int parentSize = arg.GetNumber(7)
	//int partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Dump, "Dump")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Dump)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Invalidate, "Invalidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Invalidate)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildren)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildren_1, "GetChildren_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildren_1)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildCount)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChild, "GetChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsComposite, "IsComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsComposite)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsAtomic, "IsAtomic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsAtomic)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsEmpty)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildAtPosition, "GetChildAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildAtPosition)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildAtPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Copy)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __AppendChild, "AppendChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __AppendChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->AppendChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __InsertChild, "InsertChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inFrontOf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __InsertChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int inFrontOf = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __RemoveChild, "RemoveChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteChild", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __RemoveChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int deleteChild = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __DeleteChildren)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Defragment, "Defragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Defragment)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//pThis->GetEntity()->Defragment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Move, "Move")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Move)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCompositeObject)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextCompositeObject);
	// Method assignment
	Gura_AssignMethod(wx_RichTextCompositeObject, __HitTest);
	Gura_AssignMethod(wx_RichTextCompositeObject, __FindPosition);
	Gura_AssignMethod(wx_RichTextCompositeObject, __CalculateRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, __DeleteRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetTextForRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextCompositeObject, __Dump);
	Gura_AssignMethod(wx_RichTextCompositeObject, __Invalidate);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetChildren);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetChildren_1);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetChildCount);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, __IsComposite);
	Gura_AssignMethod(wx_RichTextCompositeObject, __IsAtomic);
	Gura_AssignMethod(wx_RichTextCompositeObject, __IsEmpty);
	Gura_AssignMethod(wx_RichTextCompositeObject, __GetChildAtPosition);
	Gura_AssignMethod(wx_RichTextCompositeObject, __Copy);
	Gura_AssignMethod(wx_RichTextCompositeObject, __AppendChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, __InsertChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, __RemoveChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, __DeleteChildren);
	Gura_AssignMethod(wx_RichTextCompositeObject, __Defragment);
	Gura_AssignMethod(wx_RichTextCompositeObject, __Move);
}

Gura_ImplementDescendantCreator(wx_RichTextCompositeObject)
{
	return new Object_wx_RichTextCompositeObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
