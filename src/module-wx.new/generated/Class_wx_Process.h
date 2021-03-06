//----------------------------------------------------------------------------
// wxProcess
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROCESS_H__
#define __CLASS_WX_PROCESS_H__
#include <wx/process.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProcess
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Process);

//----------------------------------------------------------------------------
// Object declaration for wxProcess
//----------------------------------------------------------------------------
class Object_wx_Process : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Process)
public:
	inline Object_wx_Process(wxProcess *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Process), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Process(Class *pClass, wxProcess *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Process();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxProcess *GetEntity() {
		return static_cast<wxProcess *>(_pEntity);
	}
	inline wxProcess *ReleaseEntity() {
		wxProcess *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxProcess");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
