//----------------------------------------------------------------------------
// wxTextCompleter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTCOMPLETER_H__
#define __CLASS_WX_TEXTCOMPLETER_H__
#include <wx/textcompleter.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextCompleter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextCompleter);

//----------------------------------------------------------------------------
// Object declaration for wxTextCompleter
//----------------------------------------------------------------------------
class Object_wx_TextCompleter : public Object {
protected:
	wxTextCompleter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextCompleter)
public:
	inline Object_wx_TextCompleter(wxTextCompleter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextCompleter(Class *pClass, wxTextCompleter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextCompleter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextCompleter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextCompleter *GetEntity() {
		return static_cast<wxTextCompleter *>(_pEntity);
	}
	inline wxTextCompleter *ReleaseEntity() {
		wxTextCompleter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextCompleter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
