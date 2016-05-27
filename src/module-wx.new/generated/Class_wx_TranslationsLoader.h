//----------------------------------------------------------------------------
// wxTranslationsLoader
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TRANSLATIONSLOADER_H__
#define __CLASS_WX_TRANSLATIONSLOADER_H__
#include <wx/translation.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTranslationsLoader
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TranslationsLoader);

//----------------------------------------------------------------------------
// Object declaration for wxTranslationsLoader
//----------------------------------------------------------------------------
class Object_wx_TranslationsLoader : public Object {
protected:
	wxTranslationsLoader *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TranslationsLoader)
public:
	inline Object_wx_TranslationsLoader(wxTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TranslationsLoader(Class *pClass, wxTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TranslationsLoader();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTranslationsLoader *GetEntity() {
		return static_cast<wxTranslationsLoader *>(_pEntity);
	}
	inline wxTranslationsLoader *ReleaseEntity() {
		wxTranslationsLoader *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTranslationsLoader");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
