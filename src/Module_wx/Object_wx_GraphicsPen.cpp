//----------------------------------------------------------------------------
// wxGraphicsPen
// extracted from graphicspen.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsPen: public wxGraphicsPen, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GraphicsPen *_pObj;
public:
	~wx_GraphicsPen();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsPen *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsPen::~wx_GraphicsPen()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GraphicsPen::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsPen
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsPen
//----------------------------------------------------------------------------
Object_wx_GraphicsPen::~Object_wx_GraphicsPen()
{
}

Object *Object_wx_GraphicsPen::Clone() const
{
	return NULL;
}

String Object_wx_GraphicsPen::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GraphicsPen:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GraphicsPen::DoAssignConstructor(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsPen)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsPen)
{
	return new Object_wx_GraphicsPen((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
