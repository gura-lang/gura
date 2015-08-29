//----------------------------------------------------------------------------
// wxMBConvUTF32
// extracted from mbcnvutf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvUTF32: public wxMBConvUTF32, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MBConvUTF32 *_pObj;
public:
	~wx_MBConvUTF32();
	inline void AssocWithGura(Object_wx_MBConvUTF32 *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF32::~wx_MBConvUTF32()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MBConvUTF32::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvUTF32, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF32, MB2WC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF32 *pThis = Object_wx_MBConvUTF32::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t buf = static_cast<wchar_t>(arg.GetUShort(0));
	char psz = arg.GetChar(1);
	size_t n = arg.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConvUTF32, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF32, WC2MB)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF32 *pThis = Object_wx_MBConvUTF32::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char buf = arg.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(arg.GetUShort(1));
	size_t n = arg.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Object_wx_MBConvUTF32::~Object_wx_MBConvUTF32()
{
}

Object *Object_wx_MBConvUTF32::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF32::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF32:");
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
// Class implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF32)
{
	Gura_AssignMethod(wx_MBConvUTF32, MB2WC);
	Gura_AssignMethod(wx_MBConvUTF32, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvUTF32)
{
	return new Object_wx_MBConvUTF32((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
