//----------------------------------------------------------------------------
// wxLogFormatter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGFORMATTER_H__
#define __CLASS_WX_LOGFORMATTER_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogFormatter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogFormatter);

//----------------------------------------------------------------------------
// Object declaration for wxLogFormatter
//----------------------------------------------------------------------------
class Object_wx_LogFormatter : public Object {
protected:
	wxLogFormatter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_LogFormatter)
public:
	inline Object_wx_LogFormatter(wxLogFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_LogFormatter(Class *pClass, wxLogFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_LogFormatter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxLogFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxLogFormatter *GetEntity() {
		return static_cast<wxLogFormatter *>(_pEntity);
	}
	inline wxLogFormatter *ReleaseEntity() {
		wxLogFormatter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogFormatter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
