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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextCompositeObject, wxRichTextCompositeObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, wxRichTextCompositeObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextCompositeObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, ~wxRichTextCompositeObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, ~wxRichTextCompositeObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextCompositeObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, HitTest)
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

Gura_ImplementMethod(wx_RichTextCompositeObject, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextCompositeObject, FindPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, FindPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//int pt = arg.GetNumber(3)
	//int height = arg.GetNumber(4)
	//int forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, CalculateRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, DeleteRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetTextForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetTextForRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextCompositeObject, GetRangeSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextCompositeObject, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, Dump)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, Invalidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, Invalidate)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetChildren_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetChildren_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetChildCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, IsComposite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, IsComposite)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, IsAtomic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, IsAtomic)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, GetChildAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, GetChildAtPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, AppendChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, AppendChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->AppendChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, InsertChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inFrontOf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, InsertChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int inFrontOf = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, RemoveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteChild", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, RemoveChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int deleteChild = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, DeleteChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, DeleteChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, Defragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, Defragment)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//pThis->GetEntity()->Defragment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCompositeObject, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCompositeObject, Move)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCompositeObject *pThis = Object_wx_RichTextCompositeObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCompositeObject)
{
	Gura_AssignMethod(wx_RichTextCompositeObject, wxRichTextCompositeObject);
	Gura_AssignMethod(wx_RichTextCompositeObject, ~wxRichTextCompositeObject);
	Gura_AssignMethod(wx_RichTextCompositeObject, HitTest);
	Gura_AssignMethod(wx_RichTextCompositeObject, FindPosition);
	Gura_AssignMethod(wx_RichTextCompositeObject, CalculateRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, DeleteRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetTextForRange);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetRangeSize);
	Gura_AssignMethod(wx_RichTextCompositeObject, Dump);
	Gura_AssignMethod(wx_RichTextCompositeObject, Invalidate);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetChildren);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetChildren_1);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetChildCount);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, IsComposite);
	Gura_AssignMethod(wx_RichTextCompositeObject, IsAtomic);
	Gura_AssignMethod(wx_RichTextCompositeObject, IsEmpty);
	Gura_AssignMethod(wx_RichTextCompositeObject, GetChildAtPosition);
	Gura_AssignMethod(wx_RichTextCompositeObject, Copy);
	Gura_AssignMethod(wx_RichTextCompositeObject, AppendChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, InsertChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, RemoveChild);
	Gura_AssignMethod(wx_RichTextCompositeObject, DeleteChildren);
	Gura_AssignMethod(wx_RichTextCompositeObject, Defragment);
	Gura_AssignMethod(wx_RichTextCompositeObject, Move);
}

Gura_ImplementDescendantCreator(wx_RichTextCompositeObject)
{
	return new Object_wx_RichTextCompositeObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
