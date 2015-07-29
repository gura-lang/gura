//----------------------------------------------------------------------------
// wxMemoryFSHandler
// extracted from fs_mem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryFSHandler: public wxMemoryFSHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MemoryFSHandler *_pObj;
public:
	inline wx_MemoryFSHandler() : wxMemoryFSHandler(), _pObj(nullptr) {}
	~wx_MemoryFSHandler();
	inline void AssocWithGura(Object_wx_MemoryFSHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryFSHandler::~wx_MemoryFSHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MemoryFSHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryFSHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MemoryFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryFSHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MemoryFSHandler *pEntity = new wx_MemoryFSHandler();
	Object_wx_MemoryFSHandler *pObj = Object_wx_MemoryFSHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryFSHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

#if 0
Gura_DeclareClassMethod(wx_MemoryFSHandler, AddFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_MemoryFSHandler, AddFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxImage *image = Object_wx_Image::GetObject(args, 1)->GetEntity();
	long type = args.GetLong(2);
	wxMemoryFSHandler::AddFile(filename, *image, type);
	return Value::Null;
}
#endif

#if 0
Gura_DeclareClassMethod(wx_MemoryFSHandler, AddFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_MemoryFSHandler, AddFile_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	long type = args.GetLong(2);
	wxMemoryFSHandler::AddFile(filename, *bitmap, type);
	return Value::Null;
}
#endif

Gura_DeclareClassMethod(wx_MemoryFSHandler, AddFileWithMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "textdata", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_MemoryFSHandler, AddFileWithMimeType)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString textdata = wxString::FromUTF8(args.GetString(1));
	wxString mimetype = wxString::FromUTF8(args.GetString(2));
	wxMemoryFSHandler::AddFileWithMimeType(filename, textdata, mimetype);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_MemoryFSHandler, AddFileWithMimeType_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "binarydata", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_MemoryFSHandler, AddFileWithMimeType_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int binarydata = args.GetInt(1);
	size_t size = args.GetSizeT(2);
	wxString mimetype = wxString::FromUTF8(args.GetString(3));
	wxMemoryFSHandler::AddFileWithMimeType(filename, binarydata, size, mimetype);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_MemoryFSHandler, RemoveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_MemoryFSHandler, RemoveFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxMemoryFSHandler::RemoveFile(filename);
	return Value::Null;
}

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
// Class implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryFSHandler)
{
	Gura_AssignFunction(MemoryFSHandler);
	//Gura_AssignMethod(wx_MemoryFSHandler, AddFile);
	//Gura_AssignMethod(wx_MemoryFSHandler, AddFile_1);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFileWithMimeType);
	Gura_AssignMethod(wx_MemoryFSHandler, AddFileWithMimeType_1);
	Gura_AssignMethod(wx_MemoryFSHandler, RemoveFile);
}

Gura_ImplementDescendantCreator(wx_MemoryFSHandler)
{
	return new Object_wx_MemoryFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
