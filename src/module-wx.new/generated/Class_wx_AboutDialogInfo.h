//----------------------------------------------------------------------------
// wxAboutDialogInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ABOUTDIALOGINFO_H__
#define __CLASS_WX_ABOUTDIALOGINFO_H__
#include <wx/aboutdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AboutDialogInfo);

//----------------------------------------------------------------------------
// Object declaration for wxAboutDialogInfo
//----------------------------------------------------------------------------
class Object_wx_AboutDialogInfo : public Object {
protected:
	wxAboutDialogInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AboutDialogInfo)
public:
	inline Object_wx_AboutDialogInfo(wxAboutDialogInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AboutDialogInfo(Class *pClass, wxAboutDialogInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AboutDialogInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAboutDialogInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAboutDialogInfo *GetEntity() {
		return static_cast<wxAboutDialogInfo *>(_pEntity);
	}
	inline wxAboutDialogInfo *ReleaseEntity() {
		wxAboutDialogInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAboutDialogInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
