//----------------------------------------------------------------------------
// wxTextAttrDimensions
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRDIMENSIONS_H__
#define __CLASS_WX_TEXTATTRDIMENSIONS_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrDimensions
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrDimensions);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrDimensions
//----------------------------------------------------------------------------
class Object_wx_TextAttrDimensions : public Object {
protected:
	wxTextAttrDimensions *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrDimensions)
public:
	inline Object_wx_TextAttrDimensions(wxTextAttrDimensions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrDimensions(Class *pClass, wxTextAttrDimensions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrDimensions();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrDimensions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrDimensions *GetEntity() {
		return static_cast<wxTextAttrDimensions *>(_pEntity);
	}
	inline wxTextAttrDimensions *ReleaseEntity() {
		wxTextAttrDimensions *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextAttrDimensions");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
