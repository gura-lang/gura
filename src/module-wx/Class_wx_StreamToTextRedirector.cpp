//----------------------------------------------------------------------------
// wxStreamToTextRedirector
// extracted from strtotxt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StreamToTextRedirector: public wxStreamToTextRedirector, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StreamToTextRedirector *_pObj;
public:
	inline wx_StreamToTextRedirector(wxTextCtrl *text, ostream * ostr) : wxStreamToTextRedirector(*text, ostr), _pObj(nullptr) {}
	~wx_StreamToTextRedirector();
	inline void AssocWithGura(Object_wx_StreamToTextRedirector *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StreamToTextRedirector::~wx_StreamToTextRedirector()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StreamToTextRedirector::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_DeclareFunction(StreamToTextRedirector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StreamToTextRedirector));
	DeclareArg(env, "*text", VTYPE_wx_TextCtrl, OCCUR_Once);
	DeclareArg(env, "ostr", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StreamToTextRedirector)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxTextCtrl **text = Object_wx_TextCtrl::GetObject(arg, 0)->GetEntity();
	Stream & ostr = nullptr;
	if (arg.IsValid(1)) ostr = arg.GetStream(1);
	wx_StreamToTextRedirector *pEntity = new wx_StreamToTextRedirector(**text, ostr);
	Object_wx_StreamToTextRedirector *pObj = Object_wx_StreamToTextRedirector::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StreamToTextRedirector(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Object_wx_StreamToTextRedirector::~Object_wx_StreamToTextRedirector()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StreamToTextRedirector::Clone() const
{
	return nullptr;
}

String Object_wx_StreamToTextRedirector::ToString(bool exprFlag)
{
	String rtn("<wx.StreamToTextRedirector:");
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
// Class implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamToTextRedirector)
{
	Gura_AssignFunction(StreamToTextRedirector);
}

Gura_ImplementDescendantCreator(wx_StreamToTextRedirector)
{
	return new Object_wx_StreamToTextRedirector((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
