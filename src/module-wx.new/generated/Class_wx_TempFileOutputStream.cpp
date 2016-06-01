//----------------------------------------------------------------------------
// wxTempFileOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFileOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Object_wx_TempFileOutputStream::~Object_wx_TempFileOutputStream()
{
}

Object *Object_wx_TempFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TempFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TempFileOutputStream:");
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
Gura_DeclareMethod(wx_TempFileOutputStream, wxTempFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TempFileOutputStream, wxTempFileOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFileOutputStream *pThis = Object_wx_TempFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->wxTempFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TempFileOutputStream, Commit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Commit)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFileOutputStream *pThis = Object_wx_TempFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Commit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TempFileOutputStream, Discard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Discard)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFileOutputStream *pThis = Object_wx_TempFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Discard();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFileOutputStream)
{
	Gura_AssignMethod(wx_TempFileOutputStream, wxTempFileOutputStream);
	Gura_AssignMethod(wx_TempFileOutputStream, Commit);
	Gura_AssignMethod(wx_TempFileOutputStream, Discard);
}

Gura_ImplementDescendantCreator(wx_TempFileOutputStream)
{
	return new Object_wx_TempFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
