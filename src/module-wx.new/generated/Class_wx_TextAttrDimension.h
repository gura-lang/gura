//----------------------------------------------------------------------------
// wxTextAttrDimension
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRDIMENSION_H__
#define __CLASS_WX_TEXTATTRDIMENSION_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrDimension
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrDimension);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrDimension
//----------------------------------------------------------------------------
class Object_wx_TextAttrDimension : public Object {
protected:
	wxTextAttrDimension *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrDimension)
public:
	inline Object_wx_TextAttrDimension(wxTextAttrDimension *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrDimension(Class *pClass, wxTextAttrDimension *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrDimension();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrDimension *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrDimension *GetEntity() {
		return static_cast<wxTextAttrDimension *>(_pEntity);
	}
	inline wxTextAttrDimension *ReleaseEntity() {
		wxTextAttrDimension *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrDimension");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
