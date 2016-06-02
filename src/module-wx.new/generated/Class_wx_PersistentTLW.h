//----------------------------------------------------------------------------
// wxPersistentTLW
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENTTLW_H__
#define __CLASS_WX_PERSISTENTTLW_H__
#include <wx/persist/toplevel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistentTLW
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistentTLW);

//----------------------------------------------------------------------------
// Object declaration for wxPersistentTLW
//----------------------------------------------------------------------------
class Object_wx_PersistentTLW : public Object_wx_PersistentWindow {
public:
	Gura_DeclareObjectAccessor(wx_PersistentTLW)
public:
	inline Object_wx_PersistentTLW(wxPersistentTLW *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentWindow(Gura_UserClass(wx_PersistentTLW), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PersistentTLW(Class *pClass, wxPersistentTLW *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PersistentTLW();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPersistentTLW *GetEntity() {
		return static_cast<wxPersistentTLW *>(_pEntity);
	}
	inline wxPersistentTLW *ReleaseEntity() {
		wxPersistentTLW *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPersistentTLW");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
