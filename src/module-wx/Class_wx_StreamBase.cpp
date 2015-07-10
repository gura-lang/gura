//----------------------------------------------------------------------------
// wxStreamBase
// extracted from strmbase.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(IsOk);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StreamBase: public wxStreamBase, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_StreamBase *_pObj;
public:
	//inline wx_StreamBase() : wxStreamBase(), _pSig(nullptr), _pObj(nullptr) {}
	//virtual bool IsOk();
	~wx_StreamBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StreamBase *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StreamBase::~wx_StreamBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StreamBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(StreamBaseEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_StreamBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(StreamBaseEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_StreamBase *pEntity = new wx_StreamBase();
	Object_wx_StreamBase *pObj = Object_wx_StreamBase::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StreamBase(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_StreamBase, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, GetLength)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->GetLength();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBase, GetLastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, GetLastError)
{
#if 0
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStreamError rtn = pThis->GetEntity()->GetLastError();
	return ReturnValue(env, sig, args, Value(new Object_wx_StreamError(new wxStreamError(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBase, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, GetSize)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBase, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, IsOk)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBase, IsSeekable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, IsSeekable)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSeekable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBase, OnSysRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, OnSysRead)
{
#if 0
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t bufsize = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->OnSysRead(buffer, bufsize);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBase, OnSysSeek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, OnSysSeek)
{
#if 0
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pThis->GetEntity()->OnSysSeek(pos, mode);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBase, OnSysTell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, OnSysTell)
{
#if 0
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->OnSysTell();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBase, OnSysWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBase, OnSysWrite)
{
#if 0
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t bufsize = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->OnSysWrite(buffer, bufsize);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStreamBase
//----------------------------------------------------------------------------
Object_wx_StreamBase::~Object_wx_StreamBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StreamBase::Clone() const
{
	return nullptr;
}

String Object_wx_StreamBase::ToString(bool exprFlag)
{
	String rtn("<wx.StreamBase:");
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
// Class implementation for wxStreamBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBase)
{
	Gura_RealizeUserSymbol(IsOk);
	Gura_AssignFunction(StreamBaseEmpty);
	Gura_AssignMethod(wx_StreamBase, GetLength);
	Gura_AssignMethod(wx_StreamBase, GetLastError);
	Gura_AssignMethod(wx_StreamBase, GetSize);
	Gura_AssignMethod(wx_StreamBase, IsOk);
	Gura_AssignMethod(wx_StreamBase, IsSeekable);
	Gura_AssignMethod(wx_StreamBase, OnSysRead);
	Gura_AssignMethod(wx_StreamBase, OnSysSeek);
	Gura_AssignMethod(wx_StreamBase, OnSysTell);
	Gura_AssignMethod(wx_StreamBase, OnSysWrite);
}

Gura_ImplementDescendantCreator(wx_StreamBase)
{
	return new Object_wx_StreamBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
