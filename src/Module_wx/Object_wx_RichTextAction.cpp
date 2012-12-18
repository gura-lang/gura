//----------------------------------------------------------------------------
// wxRichTextAction
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextAction: public wxRichTextAction, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextAction *_pObj;
public:
	~wx_RichTextAction();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextAction *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextAction::~wx_RichTextAction()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextAction::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAction
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAction
//----------------------------------------------------------------------------
Object_wx_RichTextAction::~Object_wx_RichTextAction()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RichTextAction::Clone() const
{
	return NULL;
}

String Object_wx_RichTextAction::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextAction:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextAction::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextAction
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAction)
{
}

Gura_ImplementDescendantCreator(wx_RichTextAction)
{
	return new Object_wx_RichTextAction((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
