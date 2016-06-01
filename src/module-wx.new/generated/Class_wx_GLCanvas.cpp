//----------------------------------------------------------------------------
// wxGLCanvas
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLCanvas
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLCanvas
//----------------------------------------------------------------------------
Object_wx_GLCanvas::~Object_wx_GLCanvas()
{
}

Object *Object_wx_GLCanvas::Clone() const
{
	return nullptr;
}

String Object_wx_GLCanvas::ToString(bool exprFlag)
{
	String rtn("<wx.GLCanvas:");
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
Gura_DeclareMethod(wx_GLCanvas, wxGLCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dispAttrs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, wxGLCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int dispAttrs = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//int palette = arg.GetNumber(7)
	//pThis->GetEntity()->wxGLCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, wxGLCanvas_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attribList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, wxGLCanvas_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int attribList = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//int palette = arg.GetNumber(7)
	//pThis->GetEntity()->wxGLCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, IsDisplaySupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispAttrs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, IsDisplaySupported)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dispAttrs = arg.GetNumber(0)
	//pThis->GetEntity()->IsDisplaySupported();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, IsDisplaySupported_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attribList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, IsDisplaySupported_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attribList = arg.GetNumber(0)
	//pThis->GetEntity()->IsDisplaySupported();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, IsExtensionSupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, IsExtensionSupported)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//pThis->GetEntity()->IsExtensionSupported();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, SetCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, SetCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLCanvas, SwapBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLCanvas, SwapBuffers)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SwapBuffers();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLCanvas)
{
	Gura_AssignMethod(wx_GLCanvas, wxGLCanvas);
	Gura_AssignMethod(wx_GLCanvas, wxGLCanvas_1);
	Gura_AssignMethod(wx_GLCanvas, IsDisplaySupported);
	Gura_AssignMethod(wx_GLCanvas, IsDisplaySupported_1);
	Gura_AssignMethod(wx_GLCanvas, IsExtensionSupported);
	Gura_AssignMethod(wx_GLCanvas, SetColour);
	Gura_AssignMethod(wx_GLCanvas, SetCurrent);
	Gura_AssignMethod(wx_GLCanvas, SwapBuffers);
}

Gura_ImplementDescendantCreator(wx_GLCanvas)
{
	return new Object_wx_GLCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
