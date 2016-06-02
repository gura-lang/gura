//----------------------------------------------------------------------------
// wxChoicebook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CHOICEBOOK_H__
#define __CLASS_WX_CHOICEBOOK_H__
#include <wx/choicebk.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxChoicebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Choicebook);

//----------------------------------------------------------------------------
// Object declaration for wxChoicebook
//----------------------------------------------------------------------------
class Object_wx_Choicebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Choicebook)
public:
	inline Object_wx_Choicebook(wxChoicebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Choicebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Choicebook(Class *pClass, wxChoicebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Choicebook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxChoicebook *GetEntity() {
		return static_cast<wxChoicebook *>(_pEntity);
	}
	inline wxChoicebook *ReleaseEntity() {
		wxChoicebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxChoicebook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
