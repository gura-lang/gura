//----------------------------------------------------------------------------
// wxThreadHelper
// extracted from threadh.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(Entry);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ThreadHelper: public wxThreadHelper, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ThreadHelper *_pObj;
public:
	//inline wx_ThreadHelper() : wxThreadHelper(), _sig(NULL), _pObj(NULL) {}
	//virtual ExitCode Entry();
	~wx_ThreadHelper();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ThreadHelper *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ThreadHelper::~wx_ThreadHelper()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ThreadHelper::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadHelper
//----------------------------------------------------------------------------
Gura_DeclareFunction(ThreadHelperEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ThreadHelper));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ThreadHelperEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_ThreadHelper *pEntity = new wx_ThreadHelper();
	Object_wx_ThreadHelper *pObj = Object_wx_ThreadHelper::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ThreadHelper(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_ThreadHelper, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stackSize", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, Create)
{
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned stackSize = 0;
	if (args.IsValid(0)) stackSize = args.GetInt(0);
	wxThreadError rtn = pThis->GetEntity()->Create(stackSize);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ThreadHelper, Entry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, Entry)
{
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThread::ExitCode rtn = pThis->GetEntity()->Entry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ThreadHelper, GetThread)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, GetThread)
{
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThread *rtn = (wxThread *)pThis->GetEntity()->GetThread();
	return ReturnValue(env, sig, args, Value(new Object_wx_Thread(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxThreadHelper
//----------------------------------------------------------------------------
Object_wx_ThreadHelper::~Object_wx_ThreadHelper()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ThreadHelper::Clone() const
{
	return NULL;
}

String Object_wx_ThreadHelper::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ThreadHelper:");
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
// Class implementation for wxThreadHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadHelper)
{
	Gura_RealizeUserSymbol(Entry);
	Gura_AssignFunction(ThreadHelperEmpty);
	Gura_AssignMethod(wx_ThreadHelper, Create);
	Gura_AssignMethod(wx_ThreadHelper, Entry);
	Gura_AssignMethod(wx_ThreadHelper, GetThread);
}

Gura_ImplementDescendantCreator(wx_ThreadHelper)
{
	return new Object_wx_ThreadHelper((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
