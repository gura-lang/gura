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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileDropTarget, "FileDropTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileDropTarget)
{
	//wxFileDropTarget();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileDropTarget, __OnDrop, "OnDrop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDropTarget, __OnDrop)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnDrop(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDropTarget, __OnDropFiles, "OnDropFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDropTarget, __OnDropFiles)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//const wxArrayString& filenames = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->OnDropFiles(x, y, filenames);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDropTarget)
{
	// Constructor assignment
	Gura_AssignFunction(__FileDropTarget);
	// Method assignment
	Gura_AssignMethod(wx_FileDropTarget, __OnDrop);
	Gura_AssignMethod(wx_FileDropTarget, __OnDropFiles);
}

Gura_ImplementDescendantCreator(wx_FileDropTarget)
{
	return new Object_wx_FileDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
