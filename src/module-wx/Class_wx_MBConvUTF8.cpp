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
	Gura::Signal _sig;
	Object_wx_MBConvUTF8 *_pObj;
public:
	~wx_MBConvUTF8();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MBConvUTF8 *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvUTF8::~wx_MBConvUTF8()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MBConvUTF8::GuraObjectDeleted()
{
	_pObj = NULL;
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
#if 0
	Object_wx_MBConvUTF8 *pThis = Object_wx_MBConvUTF8::GetThisObj(args);
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
#if 0
	Object_wx_MBConvUTF8 *pThis = Object_wx_MBConvUTF8::GetThisObj(args);
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
// Object implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Object_wx_MBConvUTF8::~Object_wx_MBConvUTF8()
{
}

Object *Object_wx_MBConvUTF8::Clone() const
{
	return NULL;
}

String Object_wx_MBConvUTF8::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF8:");
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
// Class implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF8)
{
	Gura_AssignMethod(wx_MBConvUTF8, MB2WC);
	Gura_AssignMethod(wx_MBConvUTF8, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvUTF8)
{
	return new Object_wx_MBConvUTF8((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
