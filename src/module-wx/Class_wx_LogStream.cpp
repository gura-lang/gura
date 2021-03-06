//----------------------------------------------------------------------------
// wxLogStream
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogStream: public wxLogStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LogStream *_pObj;
public:
	inline wx_LogStream(std::ostream *ostr) : wxLogStream(*ostr), _pObj(nullptr) {}
	~wx_LogStream();
	inline void AssocWithGura(Object_wx_LogStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogStream::~wx_LogStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_LogStream *pEntity = new wx_LogStream();
	Object_wx_LogStream *pObj = Object_wx_LogStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_LogStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogStream
//----------------------------------------------------------------------------
Object_wx_LogStream::~Object_wx_LogStream()
{
}

Object *Object_wx_LogStream::Clone() const
{
	return nullptr;
}

String Object_wx_LogStream::ToString(bool exprFlag)
{
	String rtn("<wx.LogStream:");
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
// Class implementation for wxLogStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStream)
{
	Gura_AssignFunction(LogStream);
}

Gura_ImplementDescendantCreator(wx_LogStream)
{
	return new Object_wx_LogStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
