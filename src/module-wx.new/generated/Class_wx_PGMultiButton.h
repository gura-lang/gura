//----------------------------------------------------------------------------
// wxPGMultiButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGMULTIBUTTON_H__
#define __CLASS_WX_PGMULTIBUTTON_H__
#include <wx/propgrid/editors.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGMultiButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGMultiButton);

//----------------------------------------------------------------------------
// Object declaration for wxPGMultiButton
//----------------------------------------------------------------------------
class Object_wx_PGMultiButton : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_PGMultiButton)
public:
	inline Object_wx_PGMultiButton(wxPGMultiButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_PGMultiButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PGMultiButton(Class *pClass, wxPGMultiButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PGMultiButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPGMultiButton *GetEntity() {
		return static_cast<wxPGMultiButton *>(_pEntity);
	}
	inline wxPGMultiButton *ReleaseEntity() {
		wxPGMultiButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPGMultiButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
