//----------------------------------------------------------------------------
// wxStdInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STDINPUTSTREAM_H__
#define __CLASS_WX_STDINPUTSTREAM_H__
#include <wx/stdstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStdInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StdInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxStdInputStream
//----------------------------------------------------------------------------
class Object_wx_StdInputStream : public Object {
protected:
	wxStdInputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StdInputStream)
public:
	inline Object_wx_StdInputStream(wxStdInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StdInputStream(Class *pClass, wxStdInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StdInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStdInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStdInputStream *GetEntity() {
		return static_cast<wxStdInputStream *>(_pEntity);
	}
	inline wxStdInputStream *ReleaseEntity() {
		wxStdInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStdInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
