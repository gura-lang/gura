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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GUIEventLoop, "GUIEventLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GUIEventLoop));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GUIEventLoop)
{
	//wxGUIEventLoop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGUIEventLoop
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GUIEventLoop)
{
	// Constructor assignment
	Gura_AssignFunction(__GUIEventLoop);
}

Gura_ImplementDescendantCreator(wx_GUIEventLoop)
{
	return new Object_wx_GUIEventLoop((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
