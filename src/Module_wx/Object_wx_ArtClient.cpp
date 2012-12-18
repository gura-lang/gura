//----------------------------------------------------------------------------
// wxArtClient
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArtClient: public wxArtClient, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArtClient *_pObj;
public:
	~wx_ArtClient();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArtClient *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArtClient::~wx_ArtClient()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArtClient::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArtClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArtClient
//----------------------------------------------------------------------------
Object_wx_ArtClient::~Object_wx_ArtClient()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ArtClient::Clone() const
{
	return NULL;
}

String Object_wx_ArtClient::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ArtClient:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ArtClient::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxArtClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArtClient)
{
}

Gura_ImplementDescendantCreator(wx_ArtClient)
{
	return new Object_wx_ArtClient((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
