//----------------------------------------------------------------------------
// wxFileDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Object_wx_FileDropTarget::~Object_wx_FileDropTarget()
{
}

Object *Object_wx_FileDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_FileDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.FileDropTarget:");
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
Gura_DeclareMethod(wx_FileDropTarget, wxFileDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDropTarget, wxFileDropTarget)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFileDropTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDropTarget, OnDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDropTarget, OnDrop)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OnDrop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDropTarget, OnDropFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDropTarget, OnDropFiles)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int filenames = arg.GetNumber(2)
	//pThis->GetEntity()->OnDropFiles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDropTarget)
{
	Gura_AssignMethod(wx_FileDropTarget, wxFileDropTarget);
	Gura_AssignMethod(wx_FileDropTarget, OnDrop);
	Gura_AssignMethod(wx_FileDropTarget, OnDropFiles);
}

Gura_ImplementDescendantCreator(wx_FileDropTarget)
{
	return new Object_wx_FileDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
