//----------------------------------------------------------------------------
// wxVListBox
// extracted from vlbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_VLISTBOX_H__
#define __OBJECT_WX_VLISTBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VListBox);

//----------------------------------------------------------------------------
// Object declaration for wxVListBox
//----------------------------------------------------------------------------
class Object_wx_VListBox : public Object_wx_VScrolledWindow {
public:
	Gura_DeclareObjectAccessor(wx_VListBox)
public:
	inline Object_wx_VListBox(wxVListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VScrolledWindow(Gura_UserClass(wx_VListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VListBox(Class *pClass, wxVListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VScrolledWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VListBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxVListBox *GetEntity() {
		return dynamic_cast<wxVListBox *>(_pEntity);
	}
	inline wxVListBox *ReleaseEntity() {
		wxVListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxVListBox");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
