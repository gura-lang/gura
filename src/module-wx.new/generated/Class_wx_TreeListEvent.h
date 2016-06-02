//----------------------------------------------------------------------------
// wxTreeListEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREELISTEVENT_H__
#define __CLASS_WX_TREELISTEVENT_H__
#include <wx/treelist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeListEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeListEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTreeListEvent
//----------------------------------------------------------------------------
class Object_wx_TreeListEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_TreeListEvent)
public:
	inline Object_wx_TreeListEvent(wxTreeListEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_TreeListEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeListEvent(Class *pClass, wxTreeListEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeListEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTreeListEvent *GetEntity() {
		return static_cast<wxTreeListEvent *>(_pEntity);
	}
	inline wxTreeListEvent *ReleaseEntity() {
		wxTreeListEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTreeListEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
