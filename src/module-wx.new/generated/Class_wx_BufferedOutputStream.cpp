//----------------------------------------------------------------------------
// wxBufferedOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Object_wx_BufferedOutputStream::~Object_wx_BufferedOutputStream()
{
}

Object *Object_wx_BufferedOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedOutputStream:");
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
Gura_DeclareFunctionAlias(__BufferedOutputStream, "BufferedOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedOutputStream)
{
	//wxOutputStream& stream = arg.GetNumber(0)
	//wxStreamBuffer* buffer = arg.GetNumber(1)
	//wxBufferedOutputStream(stream, buffer);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BufferedOutputStream_1, "BufferedOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedOutputStream_1)
{
	//wxOutputStream& stream = arg.GetNumber(0)
	//size_t bufsize = arg.GetNumber(1)
	//wxBufferedOutputStream(stream, bufsize);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BufferedOutputStream, __SeekO, "SeekO")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedOutputStream, __SeekO)
{
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileOffset pos = arg.GetNumber(0)
	//wxSeekMode mode = arg.GetNumber(1)
	//wxFileOffset _rtn = pThis->GetEntity()->SeekO(pos, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedOutputStream, __Sync, "Sync")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedOutputStream, __Sync)
{
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Sync();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__BufferedOutputStream);
	Gura_AssignFunction(__BufferedOutputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_BufferedOutputStream, __SeekO);
	Gura_AssignMethod(wx_BufferedOutputStream, __Sync);
}

Gura_ImplementDescendantCreator(wx_BufferedOutputStream)
{
	return new Object_wx_BufferedOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
