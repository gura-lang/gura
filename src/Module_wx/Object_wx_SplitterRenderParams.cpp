//----------------------------------------------------------------------------
// wxSplitterRenderParams
// extracted from splitpar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SplitterRenderParams: public wxSplitterRenderParams, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SplitterRenderParams *_pObj;
public:
	~wx_SplitterRenderParams();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SplitterRenderParams *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SplitterRenderParams::~wx_SplitterRenderParams()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SplitterRenderParams::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterRenderParams
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplitterRenderParams
//----------------------------------------------------------------------------
Object_wx_SplitterRenderParams::~Object_wx_SplitterRenderParams()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_SplitterRenderParams::Clone() const
{
	return NULL;
}

String Object_wx_SplitterRenderParams::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SplitterRenderParams:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SplitterRenderParams::DoAssignConstructor(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxSplitterRenderParams
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterRenderParams)
{
}

Gura_ImplementDescendantCreator(wx_SplitterRenderParams)
{
	return new Object_wx_SplitterRenderParams((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
