//----------------------------------------------------------------------------
// wxTreebook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREEBOOK_H__
#define __CLASS_WX_TREEBOOK_H__
#include <wx/treebook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Treebook);

//----------------------------------------------------------------------------
// Object declaration for wxTreebook
//----------------------------------------------------------------------------
class Object_wx_Treebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Treebook)
public:
	inline Object_wx_Treebook(wxTreebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Treebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Treebook(Class *pClass, wxTreebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Treebook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTreebook *GetEntity() {
		return static_cast<wxTreebook *>(_pEntity);
	}
	inline wxTreebook *ReleaseEntity() {
		wxTreebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTreebook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
