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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GLCanvas, "GLCanvas")
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
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GLCanvas)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxGLAttributes& dispAttrs = arg.GetNumber(1)
	//wxWindowID id = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//const wxPalette& palette = arg.GetNumber(7)
	//wxGLCanvas(parent, dispAttrs, id, pos, size, style, name, palette);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GLCanvas_1, "GLCanvas_1")
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
	SetClassToConstruct(Gura_UserClass(wx_GLCanvas));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GLCanvas_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const int* attribList = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//const wxPalette& palette = arg.GetNumber(7)
	//wxGLCanvas(parent, id, attribList, pos, size, style, name, palette);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GLCanvas, __IsDisplaySupported, "IsDisplaySupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispAttrs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, __IsDisplaySupported)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGLAttributes& dispAttrs = arg.GetNumber(0)
	//pThis->GetEntity()->IsDisplaySupported(dispAttrs);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLCanvas, __IsDisplaySupported_1, "IsDisplaySupported_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attribList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, __IsDisplaySupported_1)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const int* attribList = arg.GetNumber(0)
	//pThis->GetEntity()->IsDisplaySupported(attribList);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLCanvas, __IsExtensionSupported, "IsExtensionSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, __IsExtensionSupported)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* extension = arg.GetNumber(0)
	//pThis->GetEntity()->IsExtensionSupported(extension);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLCanvas, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, __SetColour)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLCanvas, __SetCurrent, "SetCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLCanvas, __SetCurrent)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGLContext& context = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrent(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLCanvas, __SwapBuffers, "SwapBuffers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLCanvas, __SwapBuffers)
{
	Object_wx_GLCanvas *pThis = Object_wx_GLCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SwapBuffers();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLCanvas)
{
	// Constructor assignment
	Gura_AssignFunction(__GLCanvas);
	Gura_AssignFunction(__GLCanvas_1);
	// Method assignment
	Gura_AssignMethod(wx_GLCanvas, __IsDisplaySupported);
	Gura_AssignMethod(wx_GLCanvas, __IsDisplaySupported_1);
	Gura_AssignMethod(wx_GLCanvas, __IsExtensionSupported);
	Gura_AssignMethod(wx_GLCanvas, __SetColour);
	Gura_AssignMethod(wx_GLCanvas, __SetCurrent);
	Gura_AssignMethod(wx_GLCanvas, __SwapBuffers);
}

Gura_ImplementDescendantCreator(wx_GLCanvas)
{
	return new Object_wx_GLCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
