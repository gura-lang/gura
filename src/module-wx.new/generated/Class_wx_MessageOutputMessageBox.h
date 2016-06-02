//----------------------------------------------------------------------------
// wxMessageOutputMessageBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEOUTPUTMESSAGEBOX_H__
#define __CLASS_WX_MESSAGEOUTPUTMESSAGEBOX_H__
#include <wx/msgout.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageOutputMessageBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageOutputMessageBox);

//----------------------------------------------------------------------------
// Object declaration for wxMessageOutputMessageBox
//----------------------------------------------------------------------------
class Object_wx_MessageOutputMessageBox : public Object_wx_MessageOutput {
public:
	Gura_DeclareObjectAccessor(wx_MessageOutputMessageBox)
public:
	inline Object_wx_MessageOutputMessageBox(wxMessageOutputMessageBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutput(Gura_UserClass(wx_MessageOutputMessageBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MessageOutputMessageBox(Class *pClass, wxMessageOutputMessageBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutput(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MessageOutputMessageBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMessageOutputMessageBox *GetEntity() {
		return static_cast<wxMessageOutputMessageBox *>(_pEntity);
	}
	inline wxMessageOutputMessageBox *ReleaseEntity() {
		wxMessageOutputMessageBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMessageOutputMessageBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
