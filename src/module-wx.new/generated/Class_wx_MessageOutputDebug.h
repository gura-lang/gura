//----------------------------------------------------------------------------
// wxMessageOutputDebug
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEOUTPUTDEBUG_H__
#define __CLASS_WX_MESSAGEOUTPUTDEBUG_H__
#include <wx/msgout.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageOutputDebug
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageOutputDebug);

//----------------------------------------------------------------------------
// Object declaration for wxMessageOutputDebug
//----------------------------------------------------------------------------
class Object_wx_MessageOutputDebug : public Object_wx_MessageOutputStderr {
public:
	Gura_DeclareObjectAccessor(wx_MessageOutputDebug)
public:
	inline Object_wx_MessageOutputDebug(wxMessageOutputDebug *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutputStderr(Gura_UserClass(wx_MessageOutputDebug), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MessageOutputDebug(Class *pClass, wxMessageOutputDebug *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutputStderr(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MessageOutputDebug();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMessageOutputDebug *GetEntity() {
		return static_cast<wxMessageOutputDebug *>(_pEntity);
	}
	inline wxMessageOutputDebug *ReleaseEntity() {
		wxMessageOutputDebug *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMessageOutputDebug");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
