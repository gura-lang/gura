//----------------------------------------------------------------------------
// wxDDEConnection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DDECONNECTION_H__
#define __CLASS_WX_DDECONNECTION_H__
#include <wx/dde.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDDEConnection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DDEConnection);

//----------------------------------------------------------------------------
// Object declaration for wxDDEConnection
//----------------------------------------------------------------------------
class Object_wx_DDEConnection : public Object_wx_ConnectionBase {
public:
	Gura_DeclareObjectAccessor(wx_DDEConnection)
public:
	inline Object_wx_DDEConnection(wxDDEConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(Gura_UserClass(wx_DDEConnection), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DDEConnection(Class *pClass, wxDDEConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DDEConnection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDDEConnection *GetEntity() {
		return static_cast<wxDDEConnection *>(_pEntity);
	}
	inline wxDDEConnection *ReleaseEntity() {
		wxDDEConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDDEConnection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
