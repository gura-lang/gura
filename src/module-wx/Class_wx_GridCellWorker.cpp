//----------------------------------------------------------------------------
// wxGridCellWorker
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellWorker: public wxGridCellWorker, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridCellWorker *_pObj;
public:
	~wx_GridCellWorker();
	inline void AssocWithGura(Object_wx_GridCellWorker *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellWorker::~wx_GridCellWorker()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellWorker::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellWorker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellWorker
//----------------------------------------------------------------------------
Object_wx_GridCellWorker::~Object_wx_GridCellWorker()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	//if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GridCellWorker::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellWorker::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellWorker:");
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
// Class implementation for wxGridCellWorker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellWorker)
{
}

Gura_ImplementDescendantCreator(wx_GridCellWorker)
{
	return new Object_wx_GridCellWorker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
