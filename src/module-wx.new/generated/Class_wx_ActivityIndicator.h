//----------------------------------------------------------------------------
// wxActivityIndicator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACTIVITYINDICATOR_H__
#define __CLASS_WX_ACTIVITYINDICATOR_H__
#include <wx/activityindicator.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxActivityIndicator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ActivityIndicator);

//----------------------------------------------------------------------------
// Object declaration for wxActivityIndicator
//----------------------------------------------------------------------------
class Object_wx_ActivityIndicator : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ActivityIndicator)
public:
	inline Object_wx_ActivityIndicator(wxActivityIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ActivityIndicator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ActivityIndicator(Class *pClass, wxActivityIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ActivityIndicator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxActivityIndicator *GetEntity() {
		return static_cast<wxActivityIndicator *>(_pEntity);
	}
	inline wxActivityIndicator *ReleaseEntity() {
		wxActivityIndicator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxActivityIndicator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
