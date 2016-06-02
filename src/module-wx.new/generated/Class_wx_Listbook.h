//----------------------------------------------------------------------------
// wxListbook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LISTBOOK_H__
#define __CLASS_WX_LISTBOOK_H__
#include <wx/listbook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListbook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Listbook);

//----------------------------------------------------------------------------
// Object declaration for wxListbook
//----------------------------------------------------------------------------
class Object_wx_Listbook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Listbook)
public:
	inline Object_wx_Listbook(wxListbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Listbook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Listbook(Class *pClass, wxListbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Listbook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListbook *GetEntity() {
		return static_cast<wxListbook *>(_pEntity);
	}
	inline wxListbook *ReleaseEntity() {
		wxListbook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxListbook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
