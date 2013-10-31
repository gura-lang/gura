//----------------------------------------------------------------------------
// wxDynamicLibraryDetails
// extracted from dynlib.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DYNAMICLIBRARYDETAILS_H__
#define __OBJECT_WX_DYNAMICLIBRARYDETAILS_H__

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
				Object(Gura_UserClass(wx_DynamicLibraryDetails)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DynamicLibraryDetails(Class *pClass, wxDynamicLibraryDetails *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DynamicLibraryDetails();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDynamicLibraryDetails *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDynamicLibraryDetails *GetEntity() { return _pEntity; }
	inline wxDynamicLibraryDetails *ReleaseEntity() {
		wxDynamicLibraryDetails *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDynamicLibraryDetails");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
