//----------------------------------------------------------------------------
// wxMBConvUTF7
// extracted from mbcnvut7.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvUTF7: public wxMBConvUTF7, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MBConvUTF7 *_pObj;
public:
	~wx_MBConvUTF7();
	inline void AssocWithGura(Object_wx_MBConvUTF7 *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF7::~wx_MBConvUTF7()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MBConvUTF7::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF7
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvUTF7, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF7, MB2WC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF7 *pThis = Object_wx_MBConvUTF7::GetObjectThis(args);
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

Gura_DeclareMethod(wx_MBConvUTF7, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF7, WC2MB)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MBConvUTF7 *pThis = Object_wx_MBConvUTF7::GetObjectThis(args);
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
// Object implementation for wxMBConvUTF7
//----------------------------------------------------------------------------
Object_wx_MBConvUTF7::~Object_wx_MBConvUTF7()
{
}

Object *Object_wx_MBConvUTF7::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF7::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF7:");
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
// Class implementation for wxMBConvUTF7
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF7)
{
	Gura_AssignMethod(wx_MBConvUTF7, MB2WC);
	Gura_AssignMethod(wx_MBConvUTF7, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvUTF7)
{
	return new Object_wx_MBConvUTF7((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
