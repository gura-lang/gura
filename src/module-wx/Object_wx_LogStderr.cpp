//----------------------------------------------------------------------------
// wxLogStderr
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogStderr: public wxLogStderr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogStderr *_pObj;
public:
	inline wx_LogStderr() : _sig(NULL), _pObj(NULL) {}
	inline wx_LogStderr(FILE *fp) : wxLogStderr(fp), _sig(NULL), _pObj(NULL) {}
	~wx_LogStderr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogStderr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogStderr::~wx_LogStderr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogStderr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStderr
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogStderr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogStderr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogStderr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LogStderr *pEntity = new wx_LogStderr();
	Object_wx_LogStderr *pObj = Object_wx_LogStderr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogStderr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogStderr
//----------------------------------------------------------------------------
Object_wx_LogStderr::~Object_wx_LogStderr()
{
}

Object *Object_wx_LogStderr::Clone() const
{
	return NULL;
}

String Object_wx_LogStderr::ToString(bool exprFlag)
{
	String rtn("<wx.LogStderr:");
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
// Class implementation for wxLogStderr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStderr)
{
	Gura_AssignFunction(LogStderr);
}

Gura_ImplementDescendantCreator(wx_LogStderr)
{
	return new Object_wx_LogStderr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
