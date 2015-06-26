//----------------------------------------------------------------------------
// wxArchiveOutputStream
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArchiveOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveOutputStream::~Object_wx_ArchiveOutputStream()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ArchiveOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveOutputStream:");
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
// Class implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveOutputStream)
{
	return new Object_wx_ArchiveOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
