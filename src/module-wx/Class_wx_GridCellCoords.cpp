//----------------------------------------------------------------------------
// wxGridCellCoords
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellCoords: public wxGridCellCoords, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellCoords *_pObj;
public:
	~wx_GridCellCoords();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellCoords *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellCoords::~wx_GridCellCoords()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellCoords::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellCoords
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Object_wx_GridCellCoords::~Object_wx_GridCellCoords()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GridCellCoords::Clone() const
{
	return NULL;
}

String Object_wx_GridCellCoords::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellCoords:");
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
// Class implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellCoords)
{
}

Gura_ImplementDescendantCreator(wx_GridCellCoords)
{
	return new Object_wx_GridCellCoords((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
