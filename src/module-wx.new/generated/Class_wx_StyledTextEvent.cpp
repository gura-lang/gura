//----------------------------------------------------------------------------
// wxStyledTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStyledTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Object_wx_StyledTextEvent::~Object_wx_StyledTextEvent()
{
}

Object *Object_wx_StyledTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_StyledTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextEvent:");
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
Gura_DeclareFunctionAlias(__StyledTextEvent, "StyledTextEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StyledTextEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxStyledTextEvent(commandType, id);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StyledTextEvent_1, "StyledTextEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StyledTextEvent_1)
{
	//const wxStyledTextEvent& event = arg.GetNumber(0)
	//wxStyledTextEvent(event);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetPosition)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetKey, "SetKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "k", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetKey)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int k = arg.GetNumber(0)
	//pThis->GetEntity()->SetKey(k);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetModifiers, "SetModifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetModifiers)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetModifiers(m);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetModificationType, "SetModificationType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetModificationType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->SetModificationType(t);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& t = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(t);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetLength, "SetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetLength)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetLength(len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetLinesAdded, "SetLinesAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "num", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int num = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinesAdded(num);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetLine, "SetLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetLine)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetLine(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetFoldLevelNow, "SetFoldLevelNow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetFoldLevelNow)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetFoldLevelNow(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetFoldLevelPrev, "SetFoldLevelPrev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetFoldLevelPrev)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetFoldLevelPrev(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetMargin, "SetMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetMargin)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargin(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetMessage, "SetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetMessage)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetMessage(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetWParam, "SetWParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetWParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetWParam(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetLParam, "SetLParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetLParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetLParam(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetListType, "SetListType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetListType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetListType(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetX, "SetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetX)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetX(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetY, "SetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetY)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetY(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetToken, "SetToken")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetToken)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetToken(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetAnnotationLinesAdded, "SetAnnotationLinesAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetAnnotationLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnnotationLinesAdded(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetUpdated, "SetUpdated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetUpdated)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetUpdated(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetDragText, "SetDragText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetDragText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& val = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragText(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetDragFlags, "SetDragFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetDragFlags)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __SetDragResult, "SetDragResult")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, __SetDragResult)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDragResult val = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragResult(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetPosition)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetKey, "GetKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetKey)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetModifiers, "GetModifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetModifiers)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModifiers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetModificationType, "GetModificationType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetModificationType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModificationType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetLength)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetLinesAdded, "GetLinesAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinesAdded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetLine, "GetLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetLine)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetFoldLevelNow, "GetFoldLevelNow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetFoldLevelNow)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFoldLevelNow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetFoldLevelPrev, "GetFoldLevelPrev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetFoldLevelPrev)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFoldLevelPrev();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetMargin, "GetMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetMargin)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetMessage, "GetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetMessage)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetWParam, "GetWParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetWParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWParam();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetLParam, "GetLParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetLParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLParam();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetListType, "GetListType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetListType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetListType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetX)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetY)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetToken, "GetToken")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetToken)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToken();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetAnnotationsLinesAdded, "GetAnnotationsLinesAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetAnnotationsLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnnotationsLinesAdded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetUpdated, "GetUpdated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetUpdated)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUpdated();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetDragText, "GetDragText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetDragText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetDragFlags, "GetDragFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetDragFlags)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetDragResult, "GetDragResult")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetDragResult)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragResult();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetShift, "GetShift")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetShift)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShift();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetControl, "GetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetControl)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextEvent, __GetAlt, "GetAlt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, __GetAlt)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__StyledTextEvent);
	Gura_AssignFunction(__StyledTextEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_StyledTextEvent, __SetPosition);
	Gura_AssignMethod(wx_StyledTextEvent, __SetKey);
	Gura_AssignMethod(wx_StyledTextEvent, __SetModifiers);
	Gura_AssignMethod(wx_StyledTextEvent, __SetModificationType);
	Gura_AssignMethod(wx_StyledTextEvent, __SetText);
	Gura_AssignMethod(wx_StyledTextEvent, __SetLength);
	Gura_AssignMethod(wx_StyledTextEvent, __SetLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, __SetLine);
	Gura_AssignMethod(wx_StyledTextEvent, __SetFoldLevelNow);
	Gura_AssignMethod(wx_StyledTextEvent, __SetFoldLevelPrev);
	Gura_AssignMethod(wx_StyledTextEvent, __SetMargin);
	Gura_AssignMethod(wx_StyledTextEvent, __SetMessage);
	Gura_AssignMethod(wx_StyledTextEvent, __SetWParam);
	Gura_AssignMethod(wx_StyledTextEvent, __SetLParam);
	Gura_AssignMethod(wx_StyledTextEvent, __SetListType);
	Gura_AssignMethod(wx_StyledTextEvent, __SetX);
	Gura_AssignMethod(wx_StyledTextEvent, __SetY);
	Gura_AssignMethod(wx_StyledTextEvent, __SetToken);
	Gura_AssignMethod(wx_StyledTextEvent, __SetAnnotationLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, __SetUpdated);
	Gura_AssignMethod(wx_StyledTextEvent, __SetDragText);
	Gura_AssignMethod(wx_StyledTextEvent, __SetDragFlags);
	Gura_AssignMethod(wx_StyledTextEvent, __SetDragResult);
	Gura_AssignMethod(wx_StyledTextEvent, __GetPosition);
	Gura_AssignMethod(wx_StyledTextEvent, __GetKey);
	Gura_AssignMethod(wx_StyledTextEvent, __GetModifiers);
	Gura_AssignMethod(wx_StyledTextEvent, __GetModificationType);
	Gura_AssignMethod(wx_StyledTextEvent, __GetText);
	Gura_AssignMethod(wx_StyledTextEvent, __GetLength);
	Gura_AssignMethod(wx_StyledTextEvent, __GetLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, __GetLine);
	Gura_AssignMethod(wx_StyledTextEvent, __GetFoldLevelNow);
	Gura_AssignMethod(wx_StyledTextEvent, __GetFoldLevelPrev);
	Gura_AssignMethod(wx_StyledTextEvent, __GetMargin);
	Gura_AssignMethod(wx_StyledTextEvent, __GetMessage);
	Gura_AssignMethod(wx_StyledTextEvent, __GetWParam);
	Gura_AssignMethod(wx_StyledTextEvent, __GetLParam);
	Gura_AssignMethod(wx_StyledTextEvent, __GetListType);
	Gura_AssignMethod(wx_StyledTextEvent, __GetX);
	Gura_AssignMethod(wx_StyledTextEvent, __GetY);
	Gura_AssignMethod(wx_StyledTextEvent, __GetToken);
	Gura_AssignMethod(wx_StyledTextEvent, __GetAnnotationsLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, __GetUpdated);
	Gura_AssignMethod(wx_StyledTextEvent, __GetDragText);
	Gura_AssignMethod(wx_StyledTextEvent, __GetDragFlags);
	Gura_AssignMethod(wx_StyledTextEvent, __GetDragResult);
	Gura_AssignMethod(wx_StyledTextEvent, __GetShift);
	Gura_AssignMethod(wx_StyledTextEvent, __GetControl);
	Gura_AssignMethod(wx_StyledTextEvent, __GetAlt);
}

Gura_ImplementDescendantCreator(wx_StyledTextEvent)
{
	return new Object_wx_StyledTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
