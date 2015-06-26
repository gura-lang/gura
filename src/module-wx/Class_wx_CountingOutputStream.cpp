//----------------------------------------------------------------------------
// wxCountingOutputStream
// extracted from countstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CountingOutputStream: public wxCountingOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CountingOutputStream *_pObj;
public:
	inline wx_CountingOutputStream() : wxCountingOutputStream(), _sig(nullptr), _pObj(nullptr) {}
	~wx_CountingOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CountingOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CountingOutputStream::~wx_CountingOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CountingOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(CountingOutputStreamEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CountingOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CountingOutputStreamEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_CountingOutputStream *pEntity = new wx_CountingOutputStream();
	Object_wx_CountingOutputStream *pObj = Object_wx_CountingOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CountingOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CountingOutputStream, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CountingOutputStream, GetSize)
{
	Object_wx_CountingOutputStream *pThis = Object_wx_CountingOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Object_wx_CountingOutputStream::~Object_wx_CountingOutputStream()
{
}

Object *Object_wx_CountingOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_CountingOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.CountingOutputStream:");
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
// Class implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CountingOutputStream)
{
	Gura_AssignFunction(CountingOutputStreamEmpty);
	Gura_AssignMethod(wx_CountingOutputStream, GetSize);
}

Gura_ImplementDescendantCreator(wx_CountingOutputStream)
{
	return new Object_wx_CountingOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
