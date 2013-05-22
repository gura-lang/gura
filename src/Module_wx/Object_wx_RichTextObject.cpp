//----------------------------------------------------------------------------
// wxRichTextObject
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextObject: public wxRichTextObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextObject *_pObj;
public:
	~wx_RichTextObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextObject::~wx_RichTextObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObject
//----------------------------------------------------------------------------
Object_wx_RichTextObject::~Object_wx_RichTextObject()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RichTextObject::Clone() const
{
	return NULL;
}

String Object_wx_RichTextObject::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextObject:");
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
// Class implementation for wxRichTextObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObject)
{
}

Gura_ImplementDescendantCreator(wx_RichTextObject)
{
	return new Object_wx_RichTextObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
