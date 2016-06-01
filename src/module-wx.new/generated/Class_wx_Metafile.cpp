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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Metafile, wxMetafile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Metafile, wxMetafile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->wxMetafile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Metafile, ~wxMetafile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Metafile, ~wxMetafile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxMetafile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Metafile, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Metafile, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Metafile, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Metafile, Play)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Metafile, SetClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Metafile, SetClipboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetClipboard();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMetafile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Metafile)
{
	Gura_AssignMethod(wx_Metafile, wxMetafile);
	Gura_AssignMethod(wx_Metafile, ~wxMetafile);
	Gura_AssignMethod(wx_Metafile, IsOk);
	Gura_AssignMethod(wx_Metafile, Play);
	Gura_AssignMethod(wx_Metafile, SetClipboard);
}

Gura_ImplementDescendantCreator(wx_Metafile)
{
	return new Object_wx_Metafile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
