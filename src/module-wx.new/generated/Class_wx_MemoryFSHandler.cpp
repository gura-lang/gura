//----------------------------------------------------------------------------
// wxMemoryFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Object_wx_MemoryFSHandler::~Object_wx_MemoryFSHandler()
{
}

Object *Object_wx_MemoryFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryFSHandler:");
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
Gura_DeclareMethod(wx_MemoryFSHandler, wxMemoryFSHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryFSHandler, wxMemoryFSHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxMemoryFSHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryFSHandler, AddFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, AddFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->AddFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryFSHandler, AddFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, AddFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->AddFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryFSHandler, AddFileWithMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textdata", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, AddFileWithMimeType)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int textdata = arg.GetNumber(1)
	//int mimetype = arg.GetNumber(2)
	//pThis->GetEntity()->AddFileWithMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryFSHandler, AddFileWithMimeType_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "binarydata", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, AddFileWithMimeType_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int binarydata = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int mimetype = arg.GetNumber(3)
	//pThis->GetEntity()->AddFileWithMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryFSHandler, RemoveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, RemoveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryFSHandler)
{
	Gura_AssignMethod(wx_MemoryFSHandler, wxMemoryFSHandler);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFile);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFile_1);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFileWithMimeType);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFileWithMimeType_1);
	Gura_AssignMethod(wx_MemoryFSHandler, RemoveFile);
}

Gura_ImplementDescendantCreator(wx_MemoryFSHandler)
{
	return new Object_wx_MemoryFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
