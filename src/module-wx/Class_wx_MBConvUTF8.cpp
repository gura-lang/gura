//----------------------------------------------------------------------------
// wxMBConvUTF8
// extracted from mbcnvut8.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvUTF8: public wxMBConvUTF8, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MBConvUTF8 *_pObj;
public:
	~wx_MBConvUTF8();
	inline void AssocWithGura(Object_wx_MBConvUTF8 *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF8::~wx_MBConvUTF8()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MBConvUTF8::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF8
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvUTF8, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF8, MB2WC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF8 *pThis = Object_wx_MBConvUTF8::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t buf = static_cast<wchar_t>(args.GetUShort(0));
	char psz = args.GetChar(1);
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConvUTF8, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF8, WC2MB)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF8 *pThis = Object_wx_MBConvUTF8::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Object_wx_MBConvUTF8::~Object_wx_MBConvUTF8()
{
}

Object *Object_wx_MBConvUTF8::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF8::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF8:");
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
// Class implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF8)
{
	Gura_AssignMethod(wx_MBConvUTF8, MB2WC);
	Gura_AssignMethod(wx_MBConvUTF8, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvUTF8)
{
	return new Object_wx_MBConvUTF8((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
