//----------------------------------------------------------------------------
// wxLogWindow
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGWINDOW_H__
#define __CLASS_WX_LOGWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogWindow);

//----------------------------------------------------------------------------
// Object declaration for wxLogWindow
//----------------------------------------------------------------------------
class Object_wx_LogWindow : public Object_wx_LogPassThrough {
public:
	Gura_DeclareObjectAccessor(wx_LogWindow)
public:
	inline Object_wx_LogWindow(wxLogWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogPassThrough(Gura_UserClass(wx_LogWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogWindow(Class *pClass, wxLogWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogPassThrough(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogWindow *GetEntity() {
		return dynamic_cast<wxLogWindow *>(_pEntity);
	}
	inline wxLogWindow *ReleaseEntity() {
		wxLogWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLogWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
