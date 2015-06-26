//----------------------------------------------------------------------------
// wxGraphicsBrush
// extracted from graphicsbrush.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsBrush: public wxGraphicsBrush, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GraphicsBrush *_pObj;
public:
	~wx_GraphicsBrush();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsBrush *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsBrush::~wx_GraphicsBrush()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsBrush::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsBrush
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsBrush
//----------------------------------------------------------------------------
Object_wx_GraphicsBrush::~Object_wx_GraphicsBrush()
{
}

Object *Object_wx_GraphicsBrush::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsBrush::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsBrush:");
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
// Class implementation for wxGraphicsBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsBrush)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsBrush)
{
	return new Object_wx_GraphicsBrush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
