//----------------------------------------------------------------------------
// wxGraphicsFont
// extracted from graphicsfont.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsFont: public wxGraphicsFont, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GraphicsFont *_pObj;
public:
	~wx_GraphicsFont();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsFont *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsFont::~wx_GraphicsFont()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GraphicsFont::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsFont
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsFont
//----------------------------------------------------------------------------
Object_wx_GraphicsFont::~Object_wx_GraphicsFont()
{
}

Object *Object_wx_GraphicsFont::Clone() const
{
	return NULL;
}

String Object_wx_GraphicsFont::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GraphicsFont:");
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
// Class implementation for wxGraphicsFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsFont)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsFont)
{
	return new Object_wx_GraphicsFont((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
