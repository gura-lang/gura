//----------------------------------------------------------------------------
// wxStringBufferLength
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STRINGBUFFERLENGTH_H__
#define __CLASS_WX_STRINGBUFFERLENGTH_H__
#include <wx/string.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringBufferLength
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringBufferLength);

//----------------------------------------------------------------------------
// Object declaration for wxStringBufferLength
//----------------------------------------------------------------------------
class Object_wx_StringBufferLength : public Object {
protected:
	wxStringBufferLength *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StringBufferLength)
public:
	inline Object_wx_StringBufferLength(wxStringBufferLength *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StringBufferLength(Class *pClass, wxStringBufferLength *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StringBufferLength();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStringBufferLength *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStringBufferLength *GetEntity() {
		return static_cast<wxStringBufferLength *>(_pEntity);
	}
	inline wxStringBufferLength *ReleaseEntity() {
		wxStringBufferLength *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStringBufferLength");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
