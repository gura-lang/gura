//----------------------------------------------------------------------------
// wxGUIEventLoop
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGUIEventLoop
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGUIEventLoop
//----------------------------------------------------------------------------
Object_wx_GUIEventLoop::~Object_wx_GUIEventLoop()
{
}

Object *Object_wx_GUIEventLoop::Clone() const
{
	return nullptr;
}

String Object_wx_GUIEventLoop::ToString(bool exprFlag)
{
	String rtn("<wx.GUIEventLoop:");
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
Gura_DeclareMethod(wx_GUIEventLoop, wxGUIEventLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GUIEventLoop, wxGUIEventLoop)
{
	Object_wx_GUIEventLoop *pThis = Object_wx_GUIEventLoop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGUIEventLoop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGUIEventLoop
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GUIEventLoop)
{
	Gura_AssignMethod(wx_GUIEventLoop, wxGUIEventLoop);
}

Gura_ImplementDescendantCreator(wx_GUIEventLoop)
{
	return new Object_wx_GUIEventLoop((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
