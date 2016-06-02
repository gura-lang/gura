//----------------------------------------------------------------------------
// wxToolbook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TOOLBOOK_H__
#define __CLASS_WX_TOOLBOOK_H__
#include <wx/toolbook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolbook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Toolbook);

//----------------------------------------------------------------------------
// Object declaration for wxToolbook
//----------------------------------------------------------------------------
class Object_wx_Toolbook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Toolbook)
public:
	inline Object_wx_Toolbook(wxToolbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Toolbook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Toolbook(Class *pClass, wxToolbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Toolbook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxToolbook *GetEntity() {
		return static_cast<wxToolbook *>(_pEntity);
	}
	inline wxToolbook *ReleaseEntity() {
		wxToolbook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxToolbook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
