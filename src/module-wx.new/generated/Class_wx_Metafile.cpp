//----------------------------------------------------------------------------
// wxMetafile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMetafile
//----------------------------------------------------------------------------
Object_wx_Metafile::~Object_wx_Metafile()
{
}

Object *Object_wx_Metafile::Clone() const
{
	return nullptr;
}

String Object_wx_Metafile::ToString(bool exprFlag)
{
	String rtn("<wx.Metafile:");
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
Gura_DeclareFunctionAlias(__Metafile, "Metafile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Metafile));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Metafile)
{
	//const wxString& filename = arg.GetNumber(0)
	//wxMetafile(filename);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Metafile, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Metafile, __IsOk)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Metafile, __Play, "Play")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Metafile, __Play)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* dc = arg.GetNumber(0)
	//pThis->GetEntity()->Play(dc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Metafile, __SetClipboard, "SetClipboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Metafile, __SetClipboard)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetClipboard(width, height);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMetafile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Metafile)
{
	// Constructor assignment
	Gura_AssignFunction(__Metafile);
	// Method assignment
	Gura_AssignMethod(wx_Metafile, __IsOk);
	Gura_AssignMethod(wx_Metafile, __Play);
	Gura_AssignMethod(wx_Metafile, __SetClipboard);
}

Gura_ImplementDescendantCreator(wx_Metafile)
{
	return new Object_wx_Metafile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
