//----------------------------------------------------------------------------
// wxFontInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTINFO_H__
#define __CLASS_WX_FONTINFO_H__
#include <wx/font.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontInfo);

//----------------------------------------------------------------------------
// Object declaration for wxFontInfo
//----------------------------------------------------------------------------
class Object_wx_FontInfo : public Object {
protected:
	wxFontInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FontInfo)
public:
	inline Object_wx_FontInfo(wxFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FontInfo(Class *pClass, wxFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FontInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxFontInfo *GetEntity() {
		return static_cast<wxFontInfo *>(_pEntity);
	}
	inline wxFontInfo *ReleaseEntity() {
		wxFontInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFontInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
