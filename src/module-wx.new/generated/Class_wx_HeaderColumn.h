//----------------------------------------------------------------------------
// wxHeaderColumn
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HEADERCOLUMN_H__
#define __CLASS_WX_HEADERCOLUMN_H__
#include <wx/headercol.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHeaderColumn
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HeaderColumn);

//----------------------------------------------------------------------------
// Object declaration for wxHeaderColumn
//----------------------------------------------------------------------------
class Object_wx_HeaderColumn : public Object {
protected:
	wxHeaderColumn *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HeaderColumn)
public:
	inline Object_wx_HeaderColumn(wxHeaderColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HeaderColumn(Class *pClass, wxHeaderColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HeaderColumn();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHeaderColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHeaderColumn *GetEntity() {
		return static_cast<wxHeaderColumn *>(_pEntity);
	}
	inline wxHeaderColumn *ReleaseEntity() {
		wxHeaderColumn *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHeaderColumn");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
