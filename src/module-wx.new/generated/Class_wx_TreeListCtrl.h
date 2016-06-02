//----------------------------------------------------------------------------
// wxTreeListCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREELISTCTRL_H__
#define __CLASS_WX_TREELISTCTRL_H__
#include <wx/treelist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxTreeListCtrl
//----------------------------------------------------------------------------
class Object_wx_TreeListCtrl : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_TreeListCtrl)
public:
	inline Object_wx_TreeListCtrl(wxTreeListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_TreeListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeListCtrl(Class *pClass, wxTreeListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTreeListCtrl *GetEntity() {
		return static_cast<wxTreeListCtrl *>(_pEntity);
	}
	inline wxTreeListCtrl *ReleaseEntity() {
		wxTreeListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTreeListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
