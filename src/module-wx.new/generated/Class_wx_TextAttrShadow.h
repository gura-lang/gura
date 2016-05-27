//----------------------------------------------------------------------------
// wxTextAttrShadow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRSHADOW_H__
#define __CLASS_WX_TEXTATTRSHADOW_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrShadow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrShadow);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrShadow
//----------------------------------------------------------------------------
class Object_wx_TextAttrShadow : public Object {
protected:
	wxTextAttrShadow *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrShadow)
public:
	inline Object_wx_TextAttrShadow(wxTextAttrShadow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrShadow(Class *pClass, wxTextAttrShadow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrShadow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrShadow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrShadow *GetEntity() {
		return static_cast<wxTextAttrShadow *>(_pEntity);
	}
	inline wxTextAttrShadow *ReleaseEntity() {
		wxTextAttrShadow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrShadow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
