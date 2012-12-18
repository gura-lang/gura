//----------------------------------------------------------------------------
// wxArchiveNotifier
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveNotifier: public wxArchiveNotifier, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArchiveNotifier *_pObj;
public:
	~wx_ArchiveNotifier();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArchiveNotifier *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveNotifier::~wx_ArchiveNotifier()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArchiveNotifier::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveNotifier
//----------------------------------------------------------------------------
Object_wx_ArchiveNotifier::~Object_wx_ArchiveNotifier()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ArchiveNotifier::Clone() const
{
	return NULL;
}

String Object_wx_ArchiveNotifier::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ArchiveNotifier:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ArchiveNotifier::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveNotifier)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveNotifier)
{
	return new Object_wx_ArchiveNotifier((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
