//----------------------------------------------------------------------------
// wxRichTextRenderer
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextRenderer: public wxRichTextRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextRenderer *_pObj;
public:
	~wx_RichTextRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextRenderer::~wx_RichTextRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextRenderer::~Object_wx_RichTextRenderer()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RichTextRenderer::Clone() const
{
	return NULL;
}

String Object_wx_RichTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRenderer:");
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
// Class implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRenderer)
{
}

Gura_ImplementDescendantCreator(wx_RichTextRenderer)
{
	return new Object_wx_RichTextRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
