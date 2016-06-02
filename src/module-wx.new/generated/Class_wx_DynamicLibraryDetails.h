//----------------------------------------------------------------------------
// wxDynamicLibraryDetails
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DYNAMICLIBRARYDETAILS_H__
#define __CLASS_WX_DYNAMICLIBRARYDETAILS_H__
#include <wx/dynlib.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DynamicLibraryDetails);

//----------------------------------------------------------------------------
// Object declaration for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
class Object_wx_DynamicLibraryDetails : public Object {
protected:
	wxDynamicLibraryDetails *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DynamicLibraryDetails)
public:
	inline Object_wx_DynamicLibraryDetails(wxDynamicLibraryDetails *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DynamicLibraryDetails(Class *pClass, wxDynamicLibraryDetails *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DynamicLibraryDetails();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDynamicLibraryDetails *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDynamicLibraryDetails *GetEntity() {
		return static_cast<wxDynamicLibraryDetails *>(_pEntity);
	}
	inline wxDynamicLibraryDetails *ReleaseEntity() {
		wxDynamicLibraryDetails *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDynamicLibraryDetails");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
