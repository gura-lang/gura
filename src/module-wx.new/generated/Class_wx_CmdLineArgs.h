//----------------------------------------------------------------------------
// wxCmdLineArgs
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CMDLINEARGS_H__
#define __CLASS_WX_CMDLINEARGS_H__
#include <wx/cmdline.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCmdLineArgs
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CmdLineArgs);

//----------------------------------------------------------------------------
// Object declaration for wxCmdLineArgs
//----------------------------------------------------------------------------
class Object_wx_CmdLineArgs : public Object {
protected:
	wxCmdLineArgs *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CmdLineArgs)
public:
	inline Object_wx_CmdLineArgs(wxCmdLineArgs *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CmdLineArgs(Class *pClass, wxCmdLineArgs *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CmdLineArgs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCmdLineArgs *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCmdLineArgs *GetEntity() {
		return static_cast<wxCmdLineArgs *>(_pEntity);
	}
	inline wxCmdLineArgs *ReleaseEntity() {
		wxCmdLineArgs *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCmdLineArgs");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
