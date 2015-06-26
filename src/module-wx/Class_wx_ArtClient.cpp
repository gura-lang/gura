//----------------------------------------------------------------------------
// wxArtClient
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArtClient::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArtClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArtClient
//----------------------------------------------------------------------------
Object_wx_ArtClient::~Object_wx_ArtClient()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ArtClient::Clone() const
{
	return nullptr;
}

String Object_wx_ArtClient::ToString(bool exprFlag)
{
	String rtn("<wx.ArtClient:");
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
// Class implementation for wxArtClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArtClient)
{
}

Gura_ImplementDescendantCreator(wx_ArtClient)
{
	return new Object_wx_ArtClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
