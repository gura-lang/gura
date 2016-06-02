//----------------------------------------------------------------------------
// wxItemContainer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ITEMCONTAINER_H__
#define __CLASS_WX_ITEMCONTAINER_H__
#include <wx/ctrlsub.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxItemContainer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ItemContainer);

//----------------------------------------------------------------------------
// Object declaration for wxItemContainer
//----------------------------------------------------------------------------
class Object_wx_ItemContainer : public Object_wx_ItemContainerImmutable {
public:
	Gura_DeclareObjectAccessor(wx_ItemContainer)
public:
	inline Object_wx_ItemContainer(wxItemContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ItemContainerImmutable(Gura_UserClass(wx_ItemContainer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ItemContainer(Class *pClass, wxItemContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ItemContainerImmutable(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ItemContainer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxItemContainer *GetEntity() {
		return static_cast<wxItemContainer *>(_pEntity);
	}
	inline wxItemContainer *ReleaseEntity() {
		wxItemContainer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxItemContainer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
