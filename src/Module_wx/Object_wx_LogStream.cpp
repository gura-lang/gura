//----------------------------------------------------------------------------
// wxLogStream
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogStream: public wxLogStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogStream *_pObj;
public:
	inline wx_LogStream(std::ostream *ostr) : wxLogStream(*ostr), _sig(NULL), _pObj(NULL) {}
	~wx_LogStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogStream::~wx_LogStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LogStream *pEntity = new wx_LogStream();
	Object_wx_LogStream *pObj = Object_wx_LogStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogStream
//----------------------------------------------------------------------------
Object_wx_LogStream::~Object_wx_LogStream()
{
}

Object *Object_wx_LogStream::Clone() const
{
	return NULL;
}

String Object_wx_LogStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LogStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LogStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(LogStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxLogStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStream)
{
}

Gura_ImplementDescendantCreator(wx_LogStream)
{
	return new Object_wx_LogStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
