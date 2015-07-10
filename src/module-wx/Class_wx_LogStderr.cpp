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
	Gura::Signal *_pSig;
	Object_wx_LogStderr *_pObj;
public:
	inline wx_LogStderr() : _pSig(nullptr), _pObj(nullptr) {}
	inline wx_LogStderr(FILE *fp) : wxLogStderr(fp), _pSig(nullptr), _pObj(nullptr) {}
	~wx_LogStderr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogStderr *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogStderr::~wx_LogStderr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogStderr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStderr
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogStderr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogStderr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogStderr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LogStderr *pEntity = new wx_LogStderr();
	Object_wx_LogStderr *pObj = Object_wx_LogStderr::GetThisObj(args);
	if (pObj == nullptr) {
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
	return nullptr;
}

String Object_wx_LogStderr::ToString(bool exprFlag)
{
	String rtn("<wx.LogStderr:");
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
// Class implementation for wxLogStderr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStderr)
{
	Gura_AssignFunction(LogStderr);
}

Gura_ImplementDescendantCreator(wx_LogStderr)
{
	return new Object_wx_LogStderr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
