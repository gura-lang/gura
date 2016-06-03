//----------------------------------------------------------------------------
// wxDocMDIParentFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocMDIParentFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Object_wx_DocMDIParentFrame::~Object_wx_DocMDIParentFrame()
{
}

Object *Object_wx_DocMDIParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocMDIParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocMDIParentFrame:");
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
Gura_DeclareFunctionAlias(__DocMDIParentFrame, "DocMDIParentFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DocMDIParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DocMDIParentFrame)
{
	//wxDocMDIParentFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DocMDIParentFrame_1, "DocMDIParentFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DocMDIParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DocMDIParentFrame_1)
{
	//wxDocManager* manager = arg.GetNumber(0)
	//wxFrame* parent = arg.GetNumber(1)
	//wxWindowID id = arg.GetNumber(2)
	//const wxString& title = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxDocMDIParentFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DocMDIParentFrame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIParentFrame, __Create)
{
	Object_wx_DocMDIParentFrame *pThis = Object_wx_DocMDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocManager* manager = arg.GetNumber(0)
	//wxFrame* parent = arg.GetNumber(1)
	//wxWindowID id = arg.GetNumber(2)
	//const wxString& title = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocMDIParentFrame)
{
	// Constructor assignment
	Gura_AssignFunction(__DocMDIParentFrame);
	Gura_AssignFunction(__DocMDIParentFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_DocMDIParentFrame, __Create);
}

Gura_ImplementDescendantCreator(wx_DocMDIParentFrame)
{
	return new Object_wx_DocMDIParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
