//----------------------------------------------------------------------------
// wxDialog
// extracted from dialog.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DIALOG_H__
#define __OBJECT_WX_DIALOG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Dialog);

//----------------------------------------------------------------------------
// Object declaration for wxDialog
//----------------------------------------------------------------------------
class Object_wx_Dialog : public Object_wx_TopLevelWindow {
public:
	Gura_DeclareObjectAccessor(wx_Dialog)
public:
	inline Object_wx_Dialog(wxDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TopLevelWindow(Gura_UserClass(wx_Dialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Dialog(Class *pClass, wxDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TopLevelWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Dialog();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDialog *GetEntity() {
		return dynamic_cast<wxDialog *>(_pEntity);
	}
	inline wxDialog *ReleaseEntity() {
		wxDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDialog");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
