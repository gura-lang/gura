//----------------------------------------------------------------------------
// wxCmdLineParser
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CMDLINEPARSER_H__
#define __CLASS_WX_CMDLINEPARSER_H__
#include <wx/cmdline.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CmdLineParser);

//----------------------------------------------------------------------------
// Object declaration for wxCmdLineParser
//----------------------------------------------------------------------------
class Object_wx_CmdLineParser : public Object {
protected:
	wxCmdLineParser *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CmdLineParser)
public:
	inline Object_wx_CmdLineParser(wxCmdLineParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CmdLineParser(Class *pClass, wxCmdLineParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CmdLineParser();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCmdLineParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCmdLineParser *GetEntity() {
		return static_cast<wxCmdLineParser *>(_pEntity);
	}
	inline wxCmdLineParser *ReleaseEntity() {
		wxCmdLineParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCmdLineParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
