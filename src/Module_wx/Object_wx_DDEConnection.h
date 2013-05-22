//----------------------------------------------------------------------------
// wxDDEConnection
// extracted from ddeconn.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DDECONNECTION_H__
#define __OBJECT_WX_DDECONNECTION_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDDEConnection *GetEntity() {
		return dynamic_cast<wxDDEConnection *>(_pEntity);
	}
	inline wxDDEConnection *ReleaseEntity() {
		wxDDEConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDDEConnection");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
