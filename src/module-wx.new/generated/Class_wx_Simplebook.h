//----------------------------------------------------------------------------
// wxSimplebook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SIMPLEBOOK_H__
#define __CLASS_WX_SIMPLEBOOK_H__
#include <wx/simplebook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSimplebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Simplebook);

//----------------------------------------------------------------------------
// Object declaration for wxSimplebook
//----------------------------------------------------------------------------
class Object_wx_Simplebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Simplebook)
public:
	inline Object_wx_Simplebook(wxSimplebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Simplebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Simplebook(Class *pClass, wxSimplebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Simplebook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSimplebook *GetEntity() {
		return static_cast<wxSimplebook *>(_pEntity);
	}
	inline wxSimplebook *ReleaseEntity() {
		wxSimplebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSimplebook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
