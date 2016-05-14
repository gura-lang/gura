//----------------------------------------------------------------------------
// wxThreadHelper
// extracted from threadh.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Entry);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ThreadHelper: public wxThreadHelper, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ThreadHelper *_pObj;
public:
	//inline wx_ThreadHelper() : wxThreadHelper(), _pObj(nullptr) {}
	//virtual ExitCode Entry();
	~wx_ThreadHelper();
	inline void AssocWithGura(Object_wx_ThreadHelper *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ThreadHelper::~wx_ThreadHelper()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ThreadHelper::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadHelper
//----------------------------------------------------------------------------
Gura_DeclareFunction(ThreadHelperEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ThreadHelper));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ThreadHelperEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_ThreadHelper *pEntity = new wx_ThreadHelper();
	Object_wx_ThreadHelper *pObj = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ThreadHelper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, CreateThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "stackSize", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, CreateThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxThreadKind kind = wxTHREAD_JOINABLE;
	if (arg.IsValid(0)) kind = static_cast<wxThreadKind>(arg.GetInt(0));
	unsigned int stackSize = 0;
	if (arg.IsValid(1)) stackSize = arg.GetInt(1);
	wxThreadError rtn = pThis->GetEntity()->CreateThread(kind, stackSize);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ThreadHelper, Entry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, Entry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxThread::ExitCode rtn = pThis->GetEntity()->Entry();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ThreadHelper, GetThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ThreadHelper, GetThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxThread *rtn = (wxThread *)pThis->GetEntity()->GetThread();
	return ReturnValue(env, arg, Value(new Object_wx_Thread(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxThreadHelper
//----------------------------------------------------------------------------
Object_wx_ThreadHelper::~Object_wx_ThreadHelper()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ThreadHelper::Clone() const
{
	return nullptr;
}

String Object_wx_ThreadHelper::ToString(bool exprFlag)
{
	String rtn("<wx.ThreadHelper:");
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
// Class implementation for wxThreadHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadHelper)
{
	Gura_RealizeUserSymbol(Entry);
	Gura_AssignFunction(ThreadHelperEmpty);
	Gura_AssignMethod(wx_ThreadHelper, CreateThread);
	Gura_AssignMethod(wx_ThreadHelper, Entry);
	Gura_AssignMethod(wx_ThreadHelper, GetThread);
}

Gura_ImplementDescendantCreator(wx_ThreadHelper)
{
	return new Object_wx_ThreadHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
