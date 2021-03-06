//----------------------------------------------------------------------------
// wxRichToolTip
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTOOLTIP_H__
#define __CLASS_WX_RICHTOOLTIP_H__
#include <wx/richtooltip.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichToolTip
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichToolTip);

//----------------------------------------------------------------------------
// Object declaration for wxRichToolTip
//----------------------------------------------------------------------------
class Object_wx_RichToolTip : public Object {
protected:
	wxRichToolTip *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichToolTip)
public:
	inline Object_wx_RichToolTip(wxRichToolTip *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichToolTip(Class *pClass, wxRichToolTip *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichToolTip();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichToolTip *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichToolTip *GetEntity() {
		return static_cast<wxRichToolTip *>(_pEntity);
	}
	inline wxRichToolTip *ReleaseEntity() {
		wxRichToolTip *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichToolTip");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
