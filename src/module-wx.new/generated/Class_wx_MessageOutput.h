//----------------------------------------------------------------------------
// wxMessageOutput
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEOUTPUT_H__
#define __CLASS_WX_MESSAGEOUTPUT_H__
#include <wx/msgout.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageOutput
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageOutput);

//----------------------------------------------------------------------------
// Object declaration for wxMessageOutput
//----------------------------------------------------------------------------
class Object_wx_MessageOutput : public Object {
protected:
	wxMessageOutput *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MessageOutput)
public:
	inline Object_wx_MessageOutput(wxMessageOutput *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MessageOutput(Class *pClass, wxMessageOutput *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MessageOutput();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMessageOutput *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMessageOutput *GetEntity() {
		return static_cast<wxMessageOutput *>(_pEntity);
	}
	inline wxMessageOutput *ReleaseEntity() {
		wxMessageOutput *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMessageOutput");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
