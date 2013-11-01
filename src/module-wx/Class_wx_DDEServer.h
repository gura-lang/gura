//----------------------------------------------------------------------------
// wxDDEServer
// extracted from ddeservr.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DDESERVER_H__
#define __CLASS_WX_DDESERVER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDDEServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DDEServer);

//----------------------------------------------------------------------------
// Object declaration for wxDDEServer
//----------------------------------------------------------------------------
class Object_wx_DDEServer : public Object_wx_ServerBase {
public:
	Gura_DeclareObjectAccessor(wx_DDEServer)
public:
	inline Object_wx_DDEServer(wxDDEServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ServerBase(Gura_UserClass(wx_DDEServer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DDEServer(Class *pClass, wxDDEServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ServerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DDEServer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDDEServer *GetEntity() {
		return dynamic_cast<wxDDEServer *>(_pEntity);
	}
	inline wxDDEServer *ReleaseEntity() {
		wxDDEServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDDEServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
