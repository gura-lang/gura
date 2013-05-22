//----------------------------------------------------------------------------
// wxArchiveIterator
// extracted from archive.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveIterator: public wxArchiveIterator, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArchiveIterator *_pObj;
public:
	~wx_ArchiveIterator();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArchiveIterator *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveIterator::~wx_ArchiveIterator()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArchiveIterator::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Object_wx_ArchiveIterator::~Object_wx_ArchiveIterator()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ArchiveIterator::Clone() const
{
	return NULL;
}

String Object_wx_ArchiveIterator::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ArchiveIterator:");
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
// Class implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveIterator)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveIterator)
{
	return new Object_wx_ArchiveIterator((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
