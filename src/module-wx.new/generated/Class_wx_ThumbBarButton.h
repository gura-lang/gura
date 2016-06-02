//----------------------------------------------------------------------------
// wxThumbBarButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_THUMBBARBUTTON_H__
#define __CLASS_WX_THUMBBARBUTTON_H__
#include <wx/taskbarbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxThumbBarButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ThumbBarButton);

//----------------------------------------------------------------------------
// Object declaration for wxThumbBarButton
//----------------------------------------------------------------------------
class Object_wx_ThumbBarButton : public Object {
protected:
	wxThumbBarButton *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ThumbBarButton)
public:
	inline Object_wx_ThumbBarButton(wxThumbBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ThumbBarButton(Class *pClass, wxThumbBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ThumbBarButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxThumbBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxThumbBarButton *GetEntity() {
		return static_cast<wxThumbBarButton *>(_pEntity);
	}
	inline wxThumbBarButton *ReleaseEntity() {
		wxThumbBarButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxThumbBarButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
