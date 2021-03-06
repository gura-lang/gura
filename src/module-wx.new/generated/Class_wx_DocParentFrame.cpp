//----------------------------------------------------------------------------
// wxDocParentFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocParentFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Object_wx_DocParentFrame::~Object_wx_DocParentFrame()
{
}

Object *Object_wx_DocParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocParentFrame:");
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
Gura_DeclareFunctionAlias(__DocParentFrame, "DocParentFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DocParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DocParentFrame)
{
	//wxDocParentFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DocParentFrame_1, "DocParentFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DocParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DocParentFrame_1)
{
	//wxDocManager* manager = arg.GetNumber(0)
	//wxFrame* parent = arg.GetNumber(1)
	//wxWindowID id = arg.GetNumber(2)
	//const wxString& title = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxDocParentFrame(manager, parent, id, title, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DocParentFrame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocParentFrame, __Create)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocManager* manager = arg.GetNumber(0)
	//wxFrame* parent = arg.GetNumber(1)
	//wxWindowID id = arg.GetNumber(2)
	//const wxString& title = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(manager, parent, id, title, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocParentFrame, __GetDocumentManager, "GetDocumentManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DocParentFrame, __GetDocumentManager)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocManager* _rtn = pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocParentFrame)
{
	// Constructor assignment
	Gura_AssignFunction(__DocParentFrame);
	Gura_AssignFunction(__DocParentFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_DocParentFrame, __Create);
	Gura_AssignMethod(wx_DocParentFrame, __GetDocumentManager);
}

Gura_ImplementDescendantCreator(wx_DocParentFrame)
{
	return new Object_wx_DocParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
