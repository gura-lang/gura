//----------------------------------------------------------------------------
// wxSingleInstanceChecker
// extracted from snglinst.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SingleInstanceChecker: public wxSingleInstanceChecker, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SingleInstanceChecker *_pObj;
public:
	inline wx_SingleInstanceChecker() : wxSingleInstanceChecker(), _pObj(nullptr) {}
	inline wx_SingleInstanceChecker(const wxString& name, const wxString& path) : wxSingleInstanceChecker(name, path), _pObj(nullptr) {}
	~wx_SingleInstanceChecker();
	inline void AssocWithGura(Object_wx_SingleInstanceChecker *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SingleInstanceChecker::~wx_SingleInstanceChecker()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SingleInstanceChecker::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_DeclareFunction(SingleInstanceCheckerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SingleInstanceChecker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SingleInstanceCheckerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SingleInstanceChecker *pEntity = new wx_SingleInstanceChecker();
	Object_wx_SingleInstanceChecker *pObj = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SingleInstanceChecker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(SingleInstanceChecker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SingleInstanceChecker));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SingleInstanceChecker)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxEmptyString;
	if (arg.IsValid(1)) path = wxString::FromUTF8(arg.GetString(1));
	wx_SingleInstanceChecker *pEntity = new wx_SingleInstanceChecker(name, path);
	Object_wx_SingleInstanceChecker *pObj = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SingleInstanceChecker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SingleInstanceChecker, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxEmptyString;
	if (arg.IsValid(1)) path = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->Create(name, path);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SingleInstanceChecker, IsAnotherRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, IsAnotherRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsAnotherRunning();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Object_wx_SingleInstanceChecker::~Object_wx_SingleInstanceChecker()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_SingleInstanceChecker::Clone() const
{
	return nullptr;
}

String Object_wx_SingleInstanceChecker::ToString(bool exprFlag)
{
	String rtn("<wx.SingleInstanceChecker:");
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
// Class implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleInstanceChecker)
{
	Gura_AssignFunction(SingleInstanceCheckerEmpty);
	Gura_AssignFunction(SingleInstanceChecker);
	Gura_AssignMethod(wx_SingleInstanceChecker, Create);
	Gura_AssignMethod(wx_SingleInstanceChecker, IsAnotherRunning);
}

Gura_ImplementDescendantCreator(wx_SingleInstanceChecker)
{
	return new Object_wx_SingleInstanceChecker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
