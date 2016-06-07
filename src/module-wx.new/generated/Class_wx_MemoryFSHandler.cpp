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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MemoryFSHandler, "MemoryFSHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MemoryFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MemoryFSHandler)
{
	//wxMemoryFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MemoryFSHandler, __AddFile, "AddFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, __AddFile)
{
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//wxImage& image = arg.GetNumber(1)
	//wxBitmapType type = arg.GetNumber(2)
	//pThis->GetEntity()->AddFile(filename, image, type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryFSHandler, __AddFile_1, "AddFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, __AddFile_1)
{
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//wxBitmapType type = arg.GetNumber(2)
	//pThis->GetEntity()->AddFile(filename, bitmap, type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryFSHandler, __AddFileWithMimeType, "AddFileWithMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textdata", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, __AddFileWithMimeType)
{
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& textdata = arg.GetNumber(1)
	//const wxString& mimetype = arg.GetNumber(2)
	//pThis->GetEntity()->AddFileWithMimeType(filename, textdata, mimetype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryFSHandler, __AddFileWithMimeType_1, "AddFileWithMimeType_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "binarydata", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, __AddFileWithMimeType_1)
{
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const void* binarydata = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//const wxString& mimetype = arg.GetNumber(3)
	//pThis->GetEntity()->AddFileWithMimeType(filename, binarydata, size, mimetype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryFSHandler, __RemoveFile, "RemoveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryFSHandler, __RemoveFile)
{
	Object_wx_MemoryFSHandler *pThis = Object_wx_MemoryFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFile(filename);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryFSHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__MemoryFSHandler);
	// Method assignment
	Gura_AssignMethod(wx_MemoryFSHandler, __AddFile);
	Gura_AssignMethod(wx_MemoryFSHandler, __AddFile_1);
	Gura_AssignMethod(wx_MemoryFSHandler, __AddFileWithMimeType);
	Gura_AssignMethod(wx_MemoryFSHandler, __AddFileWithMimeType_1);
	Gura_AssignMethod(wx_MemoryFSHandler, __RemoveFile);
}

Gura_ImplementDescendantCreator(wx_MemoryFSHandler)
{
	return new Object_wx_MemoryFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
