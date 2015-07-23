//----------------------------------------------------------------------------
// wxSplitterRenderParams
// extracted from splitpar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SplitterRenderParams: public wxSplitterRenderParams, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SplitterRenderParams *_pObj;
public:
	~wx_SplitterRenderParams();
	inline void AssocWithGura(Object_wx_SplitterRenderParams *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SplitterRenderParams::~wx_SplitterRenderParams()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SplitterRenderParams::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterRenderParams
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplitterRenderParams
//----------------------------------------------------------------------------
Object_wx_SplitterRenderParams::~Object_wx_SplitterRenderParams()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_SplitterRenderParams::Clone() const
{
	return nullptr;
}

String Object_wx_SplitterRenderParams::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterRenderParams:");
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
// Class implementation for wxSplitterRenderParams
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterRenderParams)
{
}

Gura_ImplementDescendantCreator(wx_SplitterRenderParams)
{
	return new Object_wx_SplitterRenderParams((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
