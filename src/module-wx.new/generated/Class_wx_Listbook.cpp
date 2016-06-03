//----------------------------------------------------------------------------
// wxListbook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListbook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListbook
//----------------------------------------------------------------------------
Object_wx_Listbook::~Object_wx_Listbook()
{
}

Object *Object_wx_Listbook::Clone() const
{
	return nullptr;
}

String Object_wx_Listbook::ToString(bool exprFlag)
{
	String rtn("<wx.Listbook:");
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
Gura_DeclareFunctionAlias(__Listbook, "Listbook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Listbook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Listbook)
{
	//wxListbook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Listbook_1, "Listbook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Listbook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Listbook_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxListbook();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Listbook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Listbook, __Create)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Listbook, __GetListView, "GetListView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Listbook, __GetListView)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetListView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Listbook)
{
	// Constructor assignment
	Gura_AssignFunction(__Listbook);
	Gura_AssignFunction(__Listbook_1);
	// Method assignment
	Gura_AssignMethod(wx_Listbook, __Create);
	Gura_AssignMethod(wx_Listbook, __GetListView);
}

Gura_ImplementDescendantCreator(wx_Listbook)
{
	return new Object_wx_Listbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
