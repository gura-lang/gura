//----------------------------------------------------------------------------
// wxMBConvUTF7
// extracted from mbcnvut7.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvUTF7: public wxMBConvUTF7, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MBConvUTF7 *_pObj;
public:
	~wx_MBConvUTF7();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MBConvUTF7 *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF7::~wx_MBConvUTF7()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MBConvUTF7::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF7
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvUTF7, MB2WC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF7, MB2WC)
{
#if 0
	Object_wx_MBConvUTF7 *pThis = Object_wx_MBConvUTF7::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t buf = static_cast<wchar_t>(args.GetUShort(0));
	char psz = args.GetChar(1);
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MBConvUTF7, WC2MB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvUTF7, WC2MB)
{
#if 0
	Object_wx_MBConvUTF7 *pThis = Object_wx_MBConvUTF7::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF7
//----------------------------------------------------------------------------
Object_wx_MBConvUTF7::~Object_wx_MBConvUTF7()
{
}

Object *Object_wx_MBConvUTF7::Clone() const
{
	return NULL;
}

String Object_wx_MBConvUTF7::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MBConvUTF7:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MBConvUTF7::OnModuleEntry(Environment &env, Signal sig)
{
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
	return new Object_wx_MBConvUTF7((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
