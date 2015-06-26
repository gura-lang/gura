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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellCoords::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellCoords
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Object_wx_GridCellCoords::~Object_wx_GridCellCoords()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GridCellCoords::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellCoords::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellCoords:");
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
// Class implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellCoords)
{
}

Gura_ImplementDescendantCreator(wx_GridCellCoords)
{
	return new Object_wx_GridCellCoords((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
