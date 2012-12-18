//----------------------------------------------------------------------------
// wxMBConvUTF32
// extracted from mbcnvutf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvUTF32: public wxMBConvUTF32, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MBConvUTF32 *_pObj;
public:
	~wx_MBConvUTF32();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MBConvUTF32 *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF32::~wx_MBConvUTF32()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MBConvUTF32::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvUTF32, MB2WC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF32, MB2WC)
{
#if 0
	Object_wx_MBConvUTF32 *pSelf = Object_wx_MBConvUTF32::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wchar_t buf = static_cast<wchar_t>(args.GetUShort(0));
	char psz = args.GetChar(1);
	size_t n = args.GetSizeT(2);
	size_t rtn = pSelf->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MBConvUTF32, WC2MB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF32, WC2MB)
{
#if 0
	Object_wx_MBConvUTF32 *pSelf = Object_wx_MBConvUTF32::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pSelf->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Object_wx_MBConvUTF32::~Object_wx_MBConvUTF32()
{
}

Object *Object_wx_MBConvUTF32::Clone() const
{
	return NULL;
}

String Object_wx_MBConvUTF32::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MBConvUTF32:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MBConvUTF32::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF32)
{
	Gura_AssignMethod(wx_MBConvUTF32, MB2WC);
	Gura_AssignMethod(wx_MBConvUTF32, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvUTF32)
{
	return new Object_wx_MBConvUTF32((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
