//----------------------------------------------------------------------------
// wxAuiNotebookEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUINOTEBOOKEVENT_H__
#define __CLASS_WX_AUINOTEBOOKEVENT_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiNotebookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiNotebookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxAuiNotebookEvent
//----------------------------------------------------------------------------
class Object_wx_AuiNotebookEvent : public Object_wx_BookCtrlEvent {
public:
	Gura_DeclareObjectAccessor(wx_AuiNotebookEvent)
public:
	inline Object_wx_AuiNotebookEvent(wxAuiNotebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlEvent(Gura_UserClass(wx_AuiNotebookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiNotebookEvent(Class *pClass, wxAuiNotebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiNotebookEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiNotebookEvent *GetEntity() {
		return static_cast<wxAuiNotebookEvent *>(_pEntity);
	}
	inline wxAuiNotebookEvent *ReleaseEntity() {
		wxAuiNotebookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiNotebookEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
