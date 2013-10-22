//----------------------------------------------------------------------------
// wxRichTextHTMLHandler
// extracted from richtexthtmlhandler.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextHTMLHandler: public wxRichTextHTMLHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextHTMLHandler *_pObj;
public:
	inline wx_RichTextHTMLHandler(const wxString& name, const wxString& ext, int type) : wxRichTextHTMLHandler(name, ext, type), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextHTMLHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextHTMLHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextHTMLHandler::~wx_RichTextHTMLHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextHTMLHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextHTMLHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHTMLHandler));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextHTMLHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxT("HTML");
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxString ext = wxT("html");
	if (args.IsValid(1)) ext = wxString::FromUTF8(args.GetString(1));
	int type = wxRICHTEXT_TYPE_HTML;
	if (args.IsValid(2)) type = args.GetInt(2);
	wx_RichTextHTMLHandler *pEntity = new wx_RichTextHTMLHandler(name, ext, type);
	Object_wx_RichTextHTMLHandler *pObj = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextHTMLHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearTemporaryImageLocations();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteTemporaryImages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageLocations", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	std::auto_ptr<wxArrayString> imageLocations(CreateArrayString(args.GetList(1)));
	bool rtn = pThis->GetEntity()->DeleteTemporaryImages(flags, *imageLocations);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
#if 0
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoSaveFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pThis->GetEntity()->GetFontSizeMapping();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetTempDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayString rtn = pThis->GetEntity()->GetTemporaryImageLocations();
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "counter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int counter = args.GetInt(0);
	pThis->GetEntity()->SetFileCounter(counter);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fontSizeMapping", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayInt> fontSizeMapping(CreateArrayInt(args.GetList(0)));
	pThis->GetEntity()->SetFontSizeMapping(*fontSizeMapping);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tempDir", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString tempDir = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTempDir(tempDir);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "locations", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> locations(CreateArrayString(args.GetList(0)));
	pThis->GetEntity()->SetTemporaryImageLocations(*locations);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextHTMLHandler::~Object_wx_RichTextHTMLHandler()
{
}

Object *Object_wx_RichTextHTMLHandler::Clone() const
{
	return NULL;
}

String Object_wx_RichTextHTMLHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextHTMLHandler:");
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
// Class implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHTMLHandler)
{
	Gura_AssignFunction(RichTextHTMLHandler);
	Gura_AssignMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DoSaveFile);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetFileCounter);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations);
}

Gura_ImplementDescendantCreator(wx_RichTextHTMLHandler)
{
	return new Object_wx_RichTextHTMLHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
