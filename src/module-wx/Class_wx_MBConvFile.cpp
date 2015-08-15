//----------------------------------------------------------------------------
// wxMBConvFile
// extracted from mbcnvfil.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConvFile: public wxMBConvFile, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MBConvFile *_pObj;
public:
	~wx_MBConvFile();
	inline void AssocWithGura(Object_wx_MBConvFile *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConvFile::~wx_MBConvFile()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MBConvFile::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvFile
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MBConvFile, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvFile, MB2WC)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConvFile *pThis = Object_wx_MBConvFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t buf = static_cast<wchar_t>(args.GetUShort(0));
	char psz = args.GetChar(1);
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConvFile, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConvFile, WC2MB)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConvFile *pThis = Object_wx_MBConvFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMBConvFile
//----------------------------------------------------------------------------
Object_wx_MBConvFile::~Object_wx_MBConvFile()
{
}

Object *Object_wx_MBConvFile::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvFile::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvFile:");
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
// Class implementation for wxMBConvFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvFile)
{
	Gura_AssignMethod(wx_MBConvFile, MB2WC);
	Gura_AssignMethod(wx_MBConvFile, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConvFile)
{
	return new Object_wx_MBConvFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
