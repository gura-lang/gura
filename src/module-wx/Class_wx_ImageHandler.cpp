//----------------------------------------------------------------------------
// wxImageHandler
// extracted from image.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ImageHandler: public wxImageHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ImageHandler *_pObj;
public:
	//inline wx_ImageHandler() : wxImageHandler(), _pObj(nullptr) {}
	~wx_ImageHandler();
	inline void AssocWithGura(Object_wx_ImageHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ImageHandler::~wx_ImageHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ImageHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxImageHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(ImageHandlerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ImageHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ImageHandlerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_ImageHandler *pEntity = new wx_ImageHandler();
	Object_wx_ImageHandler *pObj = Object_wx_ImageHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ImageHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ImageHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, GetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ImageHandler, GetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, GetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetExtension();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ImageHandler, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, GetImageCount)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetImageCount(*stream);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageHandler, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, GetType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageHandler, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, GetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetMimeType();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ImageHandler, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "verbose", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, LoadFile)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 1)->GetEntity();
	bool verbose = true;
	if (args.IsValid(2)) verbose = args.GetBoolean(2);
	int index = 0;
	if (args.IsValid(3)) index = args.GetInt(3);
	bool rtn = pThis->GetEntity()->LoadFile(image, *stream, verbose, index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageHandler, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageHandler, SaveFile)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SaveFile(image, *stream);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageHandler, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_ImageHandler, SetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString extension = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetExtension(extension);
	return Value::Null;
}

Gura_DeclareMethod(wx_ImageHandler, SetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString mimetype = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetMimeType(mimetype);
	return Value::Null;
}

Gura_DeclareMethod(wx_ImageHandler, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long type = args.GetLong(0);
	pThis->GetEntity()->SetType(type);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxImageHandler
//----------------------------------------------------------------------------
Object_wx_ImageHandler::~Object_wx_ImageHandler()
{
}

Object *Object_wx_ImageHandler::Clone() const
{
	return nullptr;
}

String Object_wx_ImageHandler::ToString(bool exprFlag)
{
	String rtn("<wx.ImageHandler:");
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
// Class implementation for wxImageHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageHandler)
{
	Gura_AssignFunction(ImageHandlerEmpty);
	Gura_AssignMethod(wx_ImageHandler, GetName);
	Gura_AssignMethod(wx_ImageHandler, GetExtension);
	Gura_AssignMethod(wx_ImageHandler, GetImageCount);
	Gura_AssignMethod(wx_ImageHandler, GetType);
	Gura_AssignMethod(wx_ImageHandler, GetMimeType);
	Gura_AssignMethod(wx_ImageHandler, LoadFile);
	Gura_AssignMethod(wx_ImageHandler, SaveFile);
	Gura_AssignMethod(wx_ImageHandler, SetName);
	Gura_AssignMethod(wx_ImageHandler, SetExtension);
	Gura_AssignMethod(wx_ImageHandler, SetMimeType);
	Gura_AssignMethod(wx_ImageHandler, SetType);
}

Gura_ImplementDescendantCreator(wx_ImageHandler)
{
	return new Object_wx_ImageHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
