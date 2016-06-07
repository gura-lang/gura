//----------------------------------------------------------------------------
// wxChoicebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChoicebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoicebook
//----------------------------------------------------------------------------
Object_wx_Choicebook::~Object_wx_Choicebook()
{
}

Object *Object_wx_Choicebook::Clone() const
{
	return nullptr;
}

String Object_wx_Choicebook::ToString(bool exprFlag)
{
	String rtn("<wx.Choicebook:");
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
Gura_DeclareFunctionAlias(__Choicebook, "Choicebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Choicebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Choicebook)
{
	//wxChoicebook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Choicebook_1, "Choicebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Choicebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Choicebook_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxChoicebook(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Choicebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choicebook, __Create)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choicebook, __GetChoiceCtrl, "GetChoiceCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choicebook, __GetChoiceCtrl)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxChoice* _rtn = pThis->GetEntity()->GetChoiceCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxChoicebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choicebook)
{
	// Constructor assignment
	Gura_AssignFunction(__Choicebook);
	Gura_AssignFunction(__Choicebook_1);
	// Method assignment
	Gura_AssignMethod(wx_Choicebook, __Create);
	Gura_AssignMethod(wx_Choicebook, __GetChoiceCtrl);
}

Gura_ImplementDescendantCreator(wx_Choicebook)
{
	return new Object_wx_Choicebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
