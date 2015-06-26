//----------------------------------------------------------------------------
// wxTopLevelWindow
// extracted from tlw.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TOPLEVELWINDOW_H__
#define __CLASS_WX_TOPLEVELWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TopLevelWindow);

//----------------------------------------------------------------------------
// Object declaration for wxTopLevelWindow
//----------------------------------------------------------------------------
class Object_wx_TopLevelWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_TopLevelWindow)
public:
	inline Object_wx_TopLevelWindow(wxTopLevelWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_TopLevelWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TopLevelWindow(Class *pClass, wxTopLevelWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TopLevelWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTopLevelWindow *GetEntity() {
		return dynamic_cast<wxTopLevelWindow *>(_pEntity);
	}
	inline wxTopLevelWindow *ReleaseEntity() {
		wxTopLevelWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTopLevelWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
