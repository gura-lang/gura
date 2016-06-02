//----------------------------------------------------------------------------
// wxFontMapper
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTMAPPER_H__
#define __CLASS_WX_FONTMAPPER_H__
#include <wx/fontmap.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontMapper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontMapper);

//----------------------------------------------------------------------------
// Object declaration for wxFontMapper
//----------------------------------------------------------------------------
class Object_wx_FontMapper : public Object {
protected:
	wxFontMapper *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FontMapper)
public:
	inline Object_wx_FontMapper(wxFontMapper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FontMapper(Class *pClass, wxFontMapper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FontMapper();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxFontMapper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxFontMapper *GetEntity() {
		return static_cast<wxFontMapper *>(_pEntity);
	}
	inline wxFontMapper *ReleaseEntity() {
		wxFontMapper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFontMapper");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
