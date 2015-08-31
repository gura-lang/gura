//----------------------------------------------------------------------------
// wxRichTextHTMLHandler
// extracted from richtexthtmlhandler.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextHTMLHandler: public wxRichTextHTMLHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextHTMLHandler *_pObj;
public:
	inline wx_RichTextHTMLHandler(const wxString& name, const wxString& ext, int type) : wxRichTextHTMLHandler(name, ext, type), _pObj(nullptr) {}
	~wx_RichTextHTMLHandler();
	inline void AssocWithGura(Object_wx_RichTextHTMLHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextHTMLHandler::~wx_RichTextHTMLHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextHTMLHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextHTMLHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHTMLHandler));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextHTMLHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxT("HTML");
	if (arg.IsValid(0)) name = wxString::FromUTF8(arg.GetString(0));
	wxString ext = wxT("html");
	if (arg.IsValid(1)) ext = wxString::FromUTF8(arg.GetString(1));
	int type = wxRICHTEXT_TYPE_HTML;
	if (arg.IsValid(2)) type = arg.GetInt(2);
	wx_RichTextHTMLHandler *pEntity = new wx_RichTextHTMLHandler(name, ext, type);
	Object_wx_RichTextHTMLHandler *pObj = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextHTMLHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ClearTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DeleteTemporaryImages();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageLocations", VTYPE_string, OCCUR_Once, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	std::unique_ptr<wxArrayString> imageLocations(CreateArrayString(arg.GetList(1)));
	bool rtn = pThis->GetEntity()->DeleteTemporaryImages(flags, *imageLocations);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoSaveFile(buffer, *stream);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayInt rtn = pThis->GetEntity()->GetFontSizeMapping();
	return ReturnValue(env, arg, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTempDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetTemporaryImageLocations();
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "counter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int counter = arg.GetInt(0);
	pThis->GetEntity()->SetFileCounter(counter);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fontSizeMapping", VTYPE_number, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayInt> fontSizeMapping(CreateArrayInt(arg.GetList(0)));
	pThis->GetEntity()->SetFontSizeMapping(*fontSizeMapping);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tempDir", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString tempDir = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetTempDir(tempDir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "locations", VTYPE_string, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> locations(CreateArrayString(arg.GetList(0)));
	pThis->GetEntity()->SetTemporaryImageLocations(*locations);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextHTMLHandler::~Object_wx_RichTextHTMLHandler()
{
}

Object *Object_wx_RichTextHTMLHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHTMLHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHTMLHandler:");
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
	return new Object_wx_RichTextHTMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
