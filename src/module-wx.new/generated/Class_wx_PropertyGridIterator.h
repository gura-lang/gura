//----------------------------------------------------------------------------
// wxPropertyGridIterator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRIDITERATOR_H__
#define __CLASS_WX_PROPERTYGRIDITERATOR_H__
#include <wx/propgrid/propgridpagestate.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGridIterator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGridIterator);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGridIterator
//----------------------------------------------------------------------------
class Object_wx_PropertyGridIterator : public Object {
protected:
	wxPropertyGridIterator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PropertyGridIterator)
public:
	inline Object_wx_PropertyGridIterator(wxPropertyGridIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PropertyGridIterator(Class *pClass, wxPropertyGridIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PropertyGridIterator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPropertyGridIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPropertyGridIterator *GetEntity() {
		return static_cast<wxPropertyGridIterator *>(_pEntity);
	}
	inline wxPropertyGridIterator *ReleaseEntity() {
		wxPropertyGridIterator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPropertyGridIterator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
