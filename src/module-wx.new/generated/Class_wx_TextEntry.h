//----------------------------------------------------------------------------
// wxTextEntry
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTENTRY_H__
#define __CLASS_WX_TEXTENTRY_H__
#include <wx/textentry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextEntry
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextEntry);

//----------------------------------------------------------------------------
// Object declaration for wxTextEntry
//----------------------------------------------------------------------------
class Object_wx_TextEntry : public Object {
protected:
	wxTextEntry *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextEntry)
public:
	inline Object_wx_TextEntry(wxTextEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextEntry(Class *pClass, wxTextEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextEntry();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextEntry *GetEntity() {
		return static_cast<wxTextEntry *>(_pEntity);
	}
	inline wxTextEntry *ReleaseEntity() {
		wxTextEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextEntry");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
