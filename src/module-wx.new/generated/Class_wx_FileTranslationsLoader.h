//----------------------------------------------------------------------------
// wxFileTranslationsLoader
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILETRANSLATIONSLOADER_H__
#define __CLASS_WX_FILETRANSLATIONSLOADER_H__
#include <wx/translation.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileTranslationsLoader
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileTranslationsLoader);

//----------------------------------------------------------------------------
// Object declaration for wxFileTranslationsLoader
//----------------------------------------------------------------------------
class Object_wx_FileTranslationsLoader : public Object_wx_TranslationsLoader {
public:
	Gura_DeclareObjectAccessor(wx_FileTranslationsLoader)
public:
	inline Object_wx_FileTranslationsLoader(wxFileTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TranslationsLoader(Gura_UserClass(wx_FileTranslationsLoader), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileTranslationsLoader(Class *pClass, wxFileTranslationsLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TranslationsLoader(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileTranslationsLoader();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileTranslationsLoader *GetEntity() {
		return static_cast<wxFileTranslationsLoader *>(_pEntity);
	}
	inline wxFileTranslationsLoader *ReleaseEntity() {
		wxFileTranslationsLoader *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileTranslationsLoader");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
