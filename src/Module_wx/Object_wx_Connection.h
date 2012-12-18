//----------------------------------------------------------------------------
// wxConnection
// extracted from ipcconn.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CONNECTION_H__
#define __OBJECT_WX_CONNECTION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConnection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Connection);

//----------------------------------------------------------------------------
// Object declaration for wxConnection
//----------------------------------------------------------------------------
class Object_wx_Connection : public Object_wx_ConnectionBase {
public:
	Gura_DeclareObjectAccessor(wx_Connection)
public:
	inline Object_wx_Connection(wxConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(Gura_UserClass(wx_Connection), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Connection(Class *pClass, wxConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Connection();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxConnection *GetEntity() {
		return dynamic_cast<wxConnection *>(_pEntity);
	}
	inline wxConnection *ReleaseEntity() {
		wxConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxConnection");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
