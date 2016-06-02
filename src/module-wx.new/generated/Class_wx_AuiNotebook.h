//----------------------------------------------------------------------------
// wxAuiNotebook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUINOTEBOOK_H__
#define __CLASS_WX_AUINOTEBOOK_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiNotebook);

//----------------------------------------------------------------------------
// Object declaration for wxAuiNotebook
//----------------------------------------------------------------------------
class Object_wx_AuiNotebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_AuiNotebook)
public:
	inline Object_wx_AuiNotebook(wxAuiNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_AuiNotebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiNotebook(Class *pClass, wxAuiNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiNotebook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiNotebook *GetEntity() {
		return static_cast<wxAuiNotebook *>(_pEntity);
	}
	inline wxAuiNotebook *ReleaseEntity() {
		wxAuiNotebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAuiNotebook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
