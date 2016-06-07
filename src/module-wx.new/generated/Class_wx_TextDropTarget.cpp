//----------------------------------------------------------------------------
// wxTextDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Object_wx_TextDropTarget::~Object_wx_TextDropTarget()
{
}

Object *Object_wx_TextDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_TextDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.TextDropTarget:");
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
Gura_DeclareFunctionAlias(__TextDropTarget, "TextDropTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextDropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextDropTarget)
{
	//wxTextDropTarget();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextDropTarget, __OnDrop, "OnDrop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDropTarget, __OnDrop)
{
	Object_wx_TextDropTarget *pThis = Object_wx_TextDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnDrop(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDropTarget, __OnDropText, "OnDropText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDropTarget, __OnDropText)
{
	Object_wx_TextDropTarget *pThis = Object_wx_TextDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//const wxString& data = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->OnDropText(x, y, data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDropTarget)
{
	// Constructor assignment
	Gura_AssignFunction(__TextDropTarget);
	// Method assignment
	Gura_AssignMethod(wx_TextDropTarget, __OnDrop);
	Gura_AssignMethod(wx_TextDropTarget, __OnDropText);
}

Gura_ImplementDescendantCreator(wx_TextDropTarget)
{
	return new Object_wx_TextDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
