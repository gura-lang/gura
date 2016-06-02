//----------------------------------------------------------------------------
// wxCmdLineArg
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CMDLINEARG_H__
#define __CLASS_WX_CMDLINEARG_H__
#include <wx/cmdline.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCmdLineArg
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CmdLineArg);

//----------------------------------------------------------------------------
// Object declaration for wxCmdLineArg
//----------------------------------------------------------------------------
class Object_wx_CmdLineArg : public Object {
protected:
	wxCmdLineArg *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CmdLineArg)
public:
	inline Object_wx_CmdLineArg(wxCmdLineArg *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CmdLineArg(Class *pClass, wxCmdLineArg *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CmdLineArg();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCmdLineArg *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCmdLineArg *GetEntity() {
		return static_cast<wxCmdLineArg *>(_pEntity);
	}
	inline wxCmdLineArg *ReleaseEntity() {
		wxCmdLineArg *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCmdLineArg");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
