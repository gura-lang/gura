//----------------------------------------------------------------------------
// wxStreamToTextRedirector
// extracted from strtotxt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StreamToTextRedirector: public wxStreamToTextRedirector, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StreamToTextRedirector *_pObj;
public:
	inline wx_StreamToTextRedirector(wxTextCtrl *text, ostream * ostr) : wxStreamToTextRedirector(*text, ostr), _sig(NULL), _pObj(NULL) {}
	~wx_StreamToTextRedirector();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StreamToTextRedirector *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StreamToTextRedirector::~wx_StreamToTextRedirector()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StreamToTextRedirector::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_DeclareFunction(StreamToTextRedirector)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StreamToTextRedirector));
	DeclareArg(env, "*text", VTYPE_wx_TextCtrl, OCCUR_Once);
	DeclareArg(env, "ostr", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StreamToTextRedirector)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxTextCtrl **text = Object_wx_TextCtrl::GetObject(args, 0)->GetEntity();
	Stream & ostr = NULL;
	if (args.IsValid(1)) ostr = args.GetStream(1);
	wx_StreamToTextRedirector *pEntity = new wx_StreamToTextRedirector(**text, ostr);
	Object_wx_StreamToTextRedirector *pObj = Object_wx_StreamToTextRedirector::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StreamToTextRedirector(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Object_wx_StreamToTextRedirector::~Object_wx_StreamToTextRedirector()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StreamToTextRedirector::Clone() const
{
	return NULL;
}

String Object_wx_StreamToTextRedirector::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StreamToTextRedirector:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StreamToTextRedirector::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(StreamToTextRedirector);
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamToTextRedirector)
{
}

Gura_ImplementDescendantCreator(wx_StreamToTextRedirector)
{
	return new Object_wx_StreamToTextRedirector((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
