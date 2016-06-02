//----------------------------------------------------------------------------
// wxRichMessageDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHMESSAGEDIALOG_H__
#define __CLASS_WX_RICHMESSAGEDIALOG_H__
#include <wx/richmsgdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichMessageDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichMessageDialog);

//----------------------------------------------------------------------------
// Object declaration for wxRichMessageDialog
//----------------------------------------------------------------------------
class Object_wx_RichMessageDialog : public Object {
protected:
	wxRichMessageDialog *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichMessageDialog)
public:
	inline Object_wx_RichMessageDialog(wxRichMessageDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichMessageDialog(Class *pClass, wxRichMessageDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichMessageDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichMessageDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichMessageDialog *GetEntity() {
		return static_cast<wxRichMessageDialog *>(_pEntity);
	}
	inline wxRichMessageDialog *ReleaseEntity() {
		wxRichMessageDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichMessageDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
