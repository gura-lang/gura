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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DocParentFrame, wxDocParentFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocParentFrame, wxDocParentFrame)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDocParentFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocParentFrame, wxDocParentFrame_1)
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

Gura_ImplementMethod(wx_DocParentFrame, wxDocParentFrame_1)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int title = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxDocParentFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocParentFrame, Create)
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

Gura_ImplementMethod(wx_DocParentFrame, Create)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int title = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocParentFrame, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocParentFrame, GetDocumentManager)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocParentFrame)
{
	Gura_AssignMethod(wx_DocParentFrame, wxDocParentFrame);
	Gura_AssignMethod(wx_DocParentFrame, wxDocParentFrame_1);
	Gura_AssignMethod(wx_DocParentFrame, Create);
	Gura_AssignMethod(wx_DocParentFrame, GetDocumentManager);
}

Gura_ImplementDescendantCreator(wx_DocParentFrame)
{
	return new Object_wx_DocParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
