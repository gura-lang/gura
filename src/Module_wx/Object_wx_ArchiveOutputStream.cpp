//----------------------------------------------------------------------------
// wxArchiveOutputStream
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveOutputStream: public wxArchiveOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArchiveOutputStream *_pObj;
public:
	~wx_ArchiveOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArchiveOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveOutputStream::~wx_ArchiveOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArchiveOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveOutputStream::~Object_wx_ArchiveOutputStream()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ArchiveOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_ArchiveOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ArchiveOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ArchiveOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveOutputStream)
{
	return new Object_wx_ArchiveOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
