//----------------------------------------------------------------------------
// wxToolbook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolbook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolbook
//----------------------------------------------------------------------------
Object_wx_Toolbook::~Object_wx_Toolbook()
{
}

Object *Object_wx_Toolbook::Clone() const
{
	return nullptr;
}

String Object_wx_Toolbook::ToString(bool exprFlag)
{
	String rtn("<wx.Toolbook:");
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
Gura_DeclareFunctionAlias(__Toolbook, "Toolbook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Toolbook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Toolbook)
{
	//wxToolbook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Toolbook_1, "Toolbook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Toolbook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Toolbook_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxToolbook(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Toolbook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Toolbook, __Create)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Toolbook, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Toolbook, __GetToolBar)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBarBase* _rtn = pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Toolbook)
{
	// Constructor assignment
	Gura_AssignFunction(__Toolbook);
	Gura_AssignFunction(__Toolbook_1);
	// Method assignment
	Gura_AssignMethod(wx_Toolbook, __Create);
	Gura_AssignMethod(wx_Toolbook, __GetToolBar);
}

Gura_ImplementDescendantCreator(wx_Toolbook)
{
	return new Object_wx_Toolbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
