//----------------------------------------------------------------------------
// wxConnectionBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONNECTIONBASE_H__
#define __CLASS_WX_CONNECTIONBASE_H__
#include <wx/ipcbase.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConnectionBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ConnectionBase);

//----------------------------------------------------------------------------
// Object declaration for wxConnectionBase
//----------------------------------------------------------------------------
class Object_wx_ConnectionBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ConnectionBase)
public:
	inline Object_wx_ConnectionBase(wxConnectionBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ConnectionBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ConnectionBase(Class *pClass, wxConnectionBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ConnectionBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxConnectionBase *GetEntity() {
		return static_cast<wxConnectionBase *>(_pEntity);
	}
	inline wxConnectionBase *ReleaseEntity() {
		wxConnectionBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxConnectionBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
