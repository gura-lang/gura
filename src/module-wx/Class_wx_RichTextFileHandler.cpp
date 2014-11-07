//----------------------------------------------------------------------------
// wxRichTextFileHandler
// extracted from richtextfilehandler.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextFileHandler: public wxRichTextFileHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextFileHandler *_pObj;
public:
	//inline wx_RichTextFileHandler(const wxString& name, const wxString& ext, int type) : wxRichTextFileHandler(name, ext, type), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextFileHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextFileHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextFileHandler::~wx_RichTextFileHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextFileHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextFileHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_RichTextFileHandler));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(RichTextFileHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxString ext = wxEmptyString;
	if (args.IsValid(1)) ext = wxString::FromUTF8(args.GetString(1));
	int type = 0;
	if (args.IsValid(2)) type = args.GetInt(2);
	wx_RichTextFileHandler *pEntity = new wx_RichTextFileHandler(name, ext, type);
	Object_wx_RichTextFileHandler *pObj = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextFileHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanHandle)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->CanHandle(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanLoad)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanLoad();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanSave)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanSave();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, DoLoadFile)
{
#if 0
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoLoadFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, DoSaveFile)
{
#if 0
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoSaveFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetEncoding();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetExtension();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, IsVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsVisible();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, LoadFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LoadFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, LoadFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, LoadFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxString filename = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->LoadFile(buffer, filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SaveFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SaveFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, SaveFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SaveFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxString filename = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SaveFile(buffer, filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString encoding = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetEncoding(encoding);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString ext = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetExtension(ext);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int type = args.GetInt(0);
	pThis->GetEntity()->SetType(type);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool visible = args.GetBoolean(0);
	pThis->GetEntity()->SetVisible(visible);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Object_wx_RichTextFileHandler::~Object_wx_RichTextFileHandler()
{
}

Object *Object_wx_RichTextFileHandler::Clone() const
{
	return NULL;
}

String Object_wx_RichTextFileHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFileHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFileHandler)
{
	Gura_AssignFunction(RichTextFileHandler);
	Gura_AssignMethod(wx_RichTextFileHandler, CanHandle);
	Gura_AssignMethod(wx_RichTextFileHandler, CanLoad);
	Gura_AssignMethod(wx_RichTextFileHandler, CanSave);
	Gura_AssignMethod(wx_RichTextFileHandler, DoLoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, DoSaveFile);
	Gura_AssignMethod(wx_RichTextFileHandler, GetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, GetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, GetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, GetName);
	Gura_AssignMethod(wx_RichTextFileHandler, GetType);
	Gura_AssignMethod(wx_RichTextFileHandler, IsVisible);
	Gura_AssignMethod(wx_RichTextFileHandler, LoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, LoadFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, SaveFile);
	Gura_AssignMethod(wx_RichTextFileHandler, SaveFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, SetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, SetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, SetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, SetName);
	Gura_AssignMethod(wx_RichTextFileHandler, SetType);
	Gura_AssignMethod(wx_RichTextFileHandler, SetVisible);
}

Gura_ImplementDescendantCreator(wx_RichTextFileHandler)
{
	return new Object_wx_RichTextFileHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
