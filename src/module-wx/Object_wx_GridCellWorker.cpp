//----------------------------------------------------------------------------
// wxGridCellWorker
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellWorker: public wxGridCellWorker, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellWorker *_pObj;
public:
	~wx_GridCellWorker();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellWorker *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellWorker::~wx_GridCellWorker()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellWorker::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellWorker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellWorker
//----------------------------------------------------------------------------
Object_wx_GridCellWorker::~Object_wx_GridCellWorker()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	//if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GridCellWorker::Clone() const
{
	return NULL;
}

String Object_wx_GridCellWorker::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellWorker:");
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
// Class implementation for wxGridCellWorker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellWorker)
{
}

Gura_ImplementDescendantCreator(wx_GridCellWorker)
{
	return new Object_wx_GridCellWorker((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
