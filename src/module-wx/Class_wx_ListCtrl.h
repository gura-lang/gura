//----------------------------------------------------------------------------
// wxListCtrl
// extracted from listctrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LISTCTRL_H__
#define __OBJECT_WX_LISTCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxListCtrl
//----------------------------------------------------------------------------
class Object_wx_ListCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ListCtrl)
public:
	inline Object_wx_ListCtrl(wxListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListCtrl(Class *pClass, wxListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListCtrl *GetEntity() {
		return dynamic_cast<wxListCtrl *>(_pEntity);
	}
	inline wxListCtrl *ReleaseEntity() {
		wxListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
