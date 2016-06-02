//----------------------------------------------------------------------------
// wxTreeCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREECTRL_H__
#define __CLASS_WX_TREECTRL_H__
#include <wx/treectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxTreeCtrl
//----------------------------------------------------------------------------
class Object_wx_TreeCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_TreeCtrl)
public:
	inline Object_wx_TreeCtrl(wxTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_TreeCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeCtrl(Class *pClass, wxTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTreeCtrl *GetEntity() {
		return static_cast<wxTreeCtrl *>(_pEntity);
	}
	inline wxTreeCtrl *ReleaseEntity() {
		wxTreeCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTreeCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
