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
Gura_DeclareFunctionAlias(__RichTextCompositeObject, "RichTextCompositeObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCompositeObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCompositeObject)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextCompositeObject(parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxPoint& pt = arg.GetNumber(2)
	//long& textPosition = arg.GetNumber(3)
	//wxRichTextObject** obj = arg.GetNumber(4)
	//wxRichTextObject** contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//int _rtn = pThis->GetEntity()->HitTest(dc, context, pt, textPosition, obj, contextObj, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//long index = arg.GetNumber(2)
	//wxPoint& pt = arg.GetNumber(3)
	//int* height = arg.GetNumber(4)
	//bool forceLineStart = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->FindPosition(dc, context, index, pt, height, forceLineStart);
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
	//long start = arg.GetNumber(0)
	//long& end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange(start, end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __DeleteRange)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetTextForRange)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetTextForRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxSize& size = arg.GetNumber(1)
	//int& descent = arg.GetNumber(2)
	//wxDC& dc = arg.GetNumber(3)
	//wxRichTextDrawingContext& context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//const wxPoint& position = arg.GetNumber(6)
	//const wxSize& parentSize = arg.GetNumber(7)
	//wxArrayInt* partialExtents = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->GetRangeSize(range, size, descent, dc, context, flags, position, parentSize, partialExtents);
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
	//wxTextOutputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump(stream);
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
	//const wxRichTextRange& invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate(invalidRange);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildren)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObjectList& _rtn = pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildren_1, "GetChildren_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildren_1)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextObjectList& _rtn = pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildCount)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChild, "GetChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->GetChild(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsComposite, "IsComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsComposite)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsAtomic, "IsAtomic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsAtomic)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __IsEmpty)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __GetChildAtPosition, "GetChildAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __GetChildAtPosition)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->GetChildAtPosition(pos);
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
	//const wxRichTextCompositeObject& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __AppendChild, "AppendChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __AppendChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* child = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->AppendChild(child);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __InsertChild, "InsertChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inFrontOf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __InsertChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* child = arg.GetNumber(0)
	//wxRichTextObject* inFrontOf = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->InsertChild(child, inFrontOf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __RemoveChild, "RemoveChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteChild", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __RemoveChild)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* child = arg.GetNumber(0)
	//bool deleteChild = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->RemoveChild(child, deleteChild);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __DeleteChildren)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCompositeObject, __Defragment, "Defragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, __Defragment)
{
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextDrawingContext& context = arg.GetNumber(0)
	//const wxRichTextRange& range = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Defragment(context, range);
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
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move(pt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCompositeObject)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextCompositeObject);
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
