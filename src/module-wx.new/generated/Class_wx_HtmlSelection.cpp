//----------------------------------------------------------------------------
// wxHtmlSelection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlSelection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlSelection
//----------------------------------------------------------------------------
Object_wx_HtmlSelection::~Object_wx_HtmlSelection()
{
}

Object *Object_wx_HtmlSelection::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlSelection::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlSelection:");
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
Gura_DeclareFunctionAlias(__HtmlSelection, "HtmlSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlSelection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlSelection)
{
	//wxHtmlSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlSelection, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fromPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromCell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlSelection, __Set)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& fromPos = arg.GetNumber(0)
	//const wxHtmlCell* fromCell = arg.GetNumber(1)
	//const wxPoint& toPos = arg.GetNumber(2)
	//const wxHtmlCell* toCell = arg.GetNumber(3)
	//pThis->GetEntity()->Set(fromPos, fromCell, toPos, toCell);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __Set_1, "Set_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fromCell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlSelection, __Set_1)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlCell* fromCell = arg.GetNumber(0)
	//const wxHtmlCell* toCell = arg.GetNumber(1)
	//pThis->GetEntity()->Set(fromCell, toCell);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetFromCell, "GetFromCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetFromCell)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetToCell, "GetToCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetToCell)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetFromPos, "GetFromPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetFromPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetToPos, "GetToPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetToPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __ClearFromToCharacterPos, "ClearFromToCharacterPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __ClearFromToCharacterPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearFromToCharacterPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __AreFromToCharacterPosSet, "AreFromToCharacterPosSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __AreFromToCharacterPosSet)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AreFromToCharacterPosSet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __SetFromCharacterPos, "SetFromCharacterPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlSelection, __SetFromCharacterPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetFromCharacterPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __SetToCharacterPos, "SetToCharacterPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlSelection, __SetToCharacterPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetToCharacterPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetFromCharacterPos, "GetFromCharacterPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetFromCharacterPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromCharacterPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __GetToCharacterPos, "GetToCharacterPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __GetToCharacterPos)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToCharacterPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlSelection, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlSelection, __IsEmpty)
{
	Object_wx_HtmlSelection *pThis = Object_wx_HtmlSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlSelection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlSelection)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlSelection);
	// Method assignment
	Gura_AssignMethod(wx_HtmlSelection, __Set);
	Gura_AssignMethod(wx_HtmlSelection, __Set_1);
	Gura_AssignMethod(wx_HtmlSelection, __GetFromCell);
	Gura_AssignMethod(wx_HtmlSelection, __GetToCell);
	Gura_AssignMethod(wx_HtmlSelection, __GetFromPos);
	Gura_AssignMethod(wx_HtmlSelection, __GetToPos);
	Gura_AssignMethod(wx_HtmlSelection, __ClearFromToCharacterPos);
	Gura_AssignMethod(wx_HtmlSelection, __AreFromToCharacterPosSet);
	Gura_AssignMethod(wx_HtmlSelection, __SetFromCharacterPos);
	Gura_AssignMethod(wx_HtmlSelection, __SetToCharacterPos);
	Gura_AssignMethod(wx_HtmlSelection, __GetFromCharacterPos);
	Gura_AssignMethod(wx_HtmlSelection, __GetToCharacterPos);
	Gura_AssignMethod(wx_HtmlSelection, __IsEmpty);
}

Gura_ImplementDescendantCreator(wx_HtmlSelection)
{
	return new Object_wx_HtmlSelection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
