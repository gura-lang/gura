//----------------------------------------------------------------------------
// wxStdOutputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STDOUTPUTSTREAM_H__
#define __CLASS_WX_STDOUTPUTSTREAM_H__
#include <wx/stdstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStdOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StdOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxStdOutputStream
//----------------------------------------------------------------------------
class Object_wx_StdOutputStream : public Object {
protected:
	wxStdOutputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StdOutputStream)
public:
	inline Object_wx_StdOutputStream(wxStdOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StdOutputStream(Class *pClass, wxStdOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StdOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStdOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStdOutputStream *GetEntity() {
		return static_cast<wxStdOutputStream *>(_pEntity);
	}
	inline wxStdOutputStream *ReleaseEntity() {
		wxStdOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStdOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
