//----------------------------------------------------------------------------
// wxRendererVersion
// extracted from rendver.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RendererVersion: public wxRendererVersion, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RendererVersion *_pObj;
public:
	~wx_RendererVersion();
	inline void AssocWithGura(Object_wx_RendererVersion *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RendererVersion::~wx_RendererVersion()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RendererVersion::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRendererVersion
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_RendererVersion, IsCompatible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ver", VTYPE_wx_RendererVersion, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RendererVersion, IsCompatible)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxRendererVersion *ver = Object_wx_RendererVersion::GetObject(arg, 0)->GetEntity();
	bool rtn = wxRendererVersion::IsCompatible(*ver);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRendererVersion
//----------------------------------------------------------------------------
Object_wx_RendererVersion::~Object_wx_RendererVersion()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RendererVersion::Clone() const
{
	return nullptr;
}

String Object_wx_RendererVersion::ToString(bool exprFlag)
{
	String rtn("<wx.RendererVersion:");
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
// Class implementation for wxRendererVersion
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RendererVersion)
{
	Gura_AssignMethod(wx_RendererVersion, IsCompatible);
}

Gura_ImplementDescendantCreator(wx_RendererVersion)
{
	return new Object_wx_RendererVersion((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
