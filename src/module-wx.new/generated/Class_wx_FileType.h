//----------------------------------------------------------------------------
// wxFileType
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILETYPE_H__
#define __CLASS_WX_FILETYPE_H__
#include <wx/mimetype.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileType
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileType);

//----------------------------------------------------------------------------
// Object declaration for wxFileType
//----------------------------------------------------------------------------
class Object_wx_FileType : public Object {
protected:
	wxFileType *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FileType)
public:
	inline Object_wx_FileType(wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FileType(Class *pClass, wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FileType();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxFileType *GetEntity() {
		return static_cast<wxFileType *>(_pEntity);
	}
	inline wxFileType *ReleaseEntity() {
		wxFileType *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileType");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
