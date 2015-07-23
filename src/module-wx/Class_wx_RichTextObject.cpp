//----------------------------------------------------------------------------
// wxRichTextObject
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextObject: public wxRichTextObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextObject *_pObj;
public:
	~wx_RichTextObject();
	inline void AssocWithGura(Object_wx_RichTextObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextObject::~wx_RichTextObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObject
//----------------------------------------------------------------------------
Object_wx_RichTextObject::~Object_wx_RichTextObject()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RichTextObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextObject:");
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
// Class implementation for wxRichTextObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObject)
{
}

Gura_ImplementDescendantCreator(wx_RichTextObject)
{
	return new Object_wx_RichTextObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
