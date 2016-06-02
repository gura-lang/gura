//----------------------------------------------------------------------------
// wxItemContainerImmutable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ITEMCONTAINERIMMUTABLE_H__
#define __CLASS_WX_ITEMCONTAINERIMMUTABLE_H__
#include <wx/ctrlsub.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxItemContainerImmutable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ItemContainerImmutable);

//----------------------------------------------------------------------------
// Object declaration for wxItemContainerImmutable
//----------------------------------------------------------------------------
class Object_wx_ItemContainerImmutable : public Object {
protected:
	wxItemContainerImmutable *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ItemContainerImmutable)
public:
	inline Object_wx_ItemContainerImmutable(wxItemContainerImmutable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ItemContainerImmutable(Class *pClass, wxItemContainerImmutable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ItemContainerImmutable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxItemContainerImmutable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxItemContainerImmutable *GetEntity() {
		return static_cast<wxItemContainerImmutable *>(_pEntity);
	}
	inline wxItemContainerImmutable *ReleaseEntity() {
		wxItemContainerImmutable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxItemContainerImmutable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
