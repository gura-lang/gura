//----------------------------------------------------------------------------
// wxWithImages
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WITHIMAGES_H__
#define __CLASS_WX_WITHIMAGES_H__
#include <wx/withimages.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWithImages
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WithImages);

//----------------------------------------------------------------------------
// Object declaration for wxWithImages
//----------------------------------------------------------------------------
class Object_wx_WithImages : public Object {
protected:
	wxWithImages *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WithImages)
public:
	inline Object_wx_WithImages(wxWithImages *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WithImages(Class *pClass, wxWithImages *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WithImages();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWithImages *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWithImages *GetEntity() {
		return static_cast<wxWithImages *>(_pEntity);
	}
	inline wxWithImages *ReleaseEntity() {
		wxWithImages *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWithImages");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
