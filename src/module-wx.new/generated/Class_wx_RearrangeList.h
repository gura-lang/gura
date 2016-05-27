//----------------------------------------------------------------------------
// wxRearrangeList
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REARRANGELIST_H__
#define __CLASS_WX_REARRANGELIST_H__
#include <wx/rearrangectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRearrangeList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RearrangeList);

//----------------------------------------------------------------------------
// Object declaration for wxRearrangeList
//----------------------------------------------------------------------------
class Object_wx_RearrangeList : public Object_wx_CheckListBox {
public:
	Gura_DeclareObjectAccessor(wx_RearrangeList)
public:
	inline Object_wx_RearrangeList(wxRearrangeList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CheckListBox(Gura_UserClass(wx_RearrangeList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RearrangeList(Class *pClass, wxRearrangeList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CheckListBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RearrangeList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRearrangeList *GetEntity() {
		return static_cast<wxRearrangeList *>(_pEntity);
	}
	inline wxRearrangeList *ReleaseEntity() {
		wxRearrangeList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRearrangeList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
