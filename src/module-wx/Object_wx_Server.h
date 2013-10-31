//----------------------------------------------------------------------------
// wxServer
// extracted from ipcservr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SERVER_H__
#define __OBJECT_WX_SERVER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Server);

//----------------------------------------------------------------------------
// Object declaration for wxServer
//----------------------------------------------------------------------------
class Object_wx_Server : public Object_wx_ServerBase {
public:
	Gura_DeclareObjectAccessor(wx_Server)
public:
	inline Object_wx_Server(wxServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ServerBase(Gura_UserClass(wx_Server), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Server(Class *pClass, wxServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ServerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Server();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxServer *GetEntity() {
		return dynamic_cast<wxServer *>(_pEntity);
	}
	inline wxServer *ReleaseEntity() {
		wxServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
