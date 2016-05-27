//----------------------------------------------------------------------------
// wxGenericAboutDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GENERICABOUTDIALOG_H__
#define __CLASS_WX_GENERICABOUTDIALOG_H__
#include <wx/generic/aboutdlgg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGenericAboutDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GenericAboutDialog);

//----------------------------------------------------------------------------
// Object declaration for wxGenericAboutDialog
//----------------------------------------------------------------------------
class Object_wx_GenericAboutDialog : public Object {
protected:
	wxGenericAboutDialog *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GenericAboutDialog)
public:
	inline Object_wx_GenericAboutDialog(wxGenericAboutDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GenericAboutDialog(Class *pClass, wxGenericAboutDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GenericAboutDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGenericAboutDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGenericAboutDialog *GetEntity() {
		return static_cast<wxGenericAboutDialog *>(_pEntity);
	}
	inline wxGenericAboutDialog *ReleaseEntity() {
		wxGenericAboutDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGenericAboutDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
