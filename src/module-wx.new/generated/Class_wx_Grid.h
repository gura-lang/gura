//----------------------------------------------------------------------------
// wxGrid
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRID_H__
#define __CLASS_WX_GRID_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGrid
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Grid);

//----------------------------------------------------------------------------
// Object declaration for wxGrid
//----------------------------------------------------------------------------
class Object_wx_Grid : public Object {
protected:
	wxGrid *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Grid)
public:
	inline Object_wx_Grid(wxGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Grid(Class *pClass, wxGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Grid();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGrid *GetEntity() {
		return static_cast<wxGrid *>(_pEntity);
	}
	inline wxGrid *ReleaseEntity() {
		wxGrid *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGrid");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
