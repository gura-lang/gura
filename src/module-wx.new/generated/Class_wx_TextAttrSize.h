//----------------------------------------------------------------------------
// wxTextAttrSize
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRSIZE_H__
#define __CLASS_WX_TEXTATTRSIZE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrSize
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrSize);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrSize
//----------------------------------------------------------------------------
class Object_wx_TextAttrSize : public Object {
protected:
	wxTextAttrSize *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrSize)
public:
	inline Object_wx_TextAttrSize(wxTextAttrSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrSize(Class *pClass, wxTextAttrSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrSize();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrSize *GetEntity() {
		return static_cast<wxTextAttrSize *>(_pEntity);
	}
	inline wxTextAttrSize *ReleaseEntity() {
		wxTextAttrSize *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrSize");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
