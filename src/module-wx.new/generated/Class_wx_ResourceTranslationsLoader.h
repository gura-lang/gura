//----------------------------------------------------------------------------
// wxResourceTranslationsLoader
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RESOURCETRANSLATIONSLOADER_H__
#define __CLASS_WX_RESOURCETRANSLATIONSLOADER_H__
#include <wx/translation.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ResourceTranslationsLoader);

//----------------------------------------------------------------------------
// Object declaration for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
class Object_wx_ResourceTranslationsLoader : public Object_wx_TranslationsLoader {
public:
	Gura_DeclareObjectAccessor(wx_ResourceTranslationsLoader)
public:
	inline Object_wx_ResourceTranslationsLoader(wxResourceTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TranslationsLoader(Gura_UserClass(wx_ResourceTranslationsLoader), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ResourceTranslationsLoader(Class *pClass, wxResourceTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TranslationsLoader(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ResourceTranslationsLoader();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxResourceTranslationsLoader *GetEntity() {
		return static_cast<wxResourceTranslationsLoader *>(_pEntity);
	}
	inline wxResourceTranslationsLoader *ReleaseEntity() {
		wxResourceTranslationsLoader *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxResourceTranslationsLoader");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
