//----------------------------------------------------------------------------
// wxTranslations
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TRANSLATIONS_H__
#define __CLASS_WX_TRANSLATIONS_H__
#include <wx/translation.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTranslations
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Translations);

//----------------------------------------------------------------------------
// Object declaration for wxTranslations
//----------------------------------------------------------------------------
class Object_wx_Translations : public Object {
protected:
	wxTranslations *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Translations)
public:
	inline Object_wx_Translations(wxTranslations *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Translations(Class *pClass, wxTranslations *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Translations();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTranslations *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTranslations *GetEntity() {
		return static_cast<wxTranslations *>(_pEntity);
	}
	inline wxTranslations *ReleaseEntity() {
		wxTranslations *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTranslations");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
