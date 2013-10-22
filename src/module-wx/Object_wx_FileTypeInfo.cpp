//----------------------------------------------------------------------------
// wxFileTypeInfo
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileTypeInfo: public wxFileTypeInfo, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileTypeInfo *_pObj;
public:
	~wx_FileTypeInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileTypeInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileTypeInfo::~wx_FileTypeInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileTypeInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileTypeInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Object_wx_FileTypeInfo::~Object_wx_FileTypeInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FileTypeInfo::Clone() const
{
	return NULL;
}

String Object_wx_FileTypeInfo::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileTypeInfo:");
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
// Class implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTypeInfo)
{
}

Gura_ImplementDescendantCreator(wx_FileTypeInfo)
{
	return new Object_wx_FileTypeInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
