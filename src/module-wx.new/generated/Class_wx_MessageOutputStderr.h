//----------------------------------------------------------------------------
// wxMessageOutputStderr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEOUTPUTSTDERR_H__
#define __CLASS_WX_MESSAGEOUTPUTSTDERR_H__
#include <wx/msgout.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageOutputStderr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageOutputStderr);

//----------------------------------------------------------------------------
// Object declaration for wxMessageOutputStderr
//----------------------------------------------------------------------------
class Object_wx_MessageOutputStderr : public Object_wx_MessageOutput {
public:
	Gura_DeclareObjectAccessor(wx_MessageOutputStderr)
public:
	inline Object_wx_MessageOutputStderr(wxMessageOutputStderr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutput(Gura_UserClass(wx_MessageOutputStderr), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MessageOutputStderr(Class *pClass, wxMessageOutputStderr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutput(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MessageOutputStderr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMessageOutputStderr *GetEntity() {
		return static_cast<wxMessageOutputStderr *>(_pEntity);
	}
	inline wxMessageOutputStderr *ReleaseEntity() {
		wxMessageOutputStderr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMessageOutputStderr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
