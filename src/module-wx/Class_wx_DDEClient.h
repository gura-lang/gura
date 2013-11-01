//----------------------------------------------------------------------------
// wxDDEClient
// extracted from ddeclint.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DDECLIENT_H__
#define __CLASS_WX_DDECLIENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDDEClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DDEClient);

//----------------------------------------------------------------------------
// Object declaration for wxDDEClient
//----------------------------------------------------------------------------
class Object_wx_DDEClient : public Object_wx_ClientBase {
public:
	Gura_DeclareObjectAccessor(wx_DDEClient)
public:
	inline Object_wx_DDEClient(wxDDEClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(Gura_UserClass(wx_DDEClient), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DDEClient(Class *pClass, wxDDEClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DDEClient();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDDEClient *GetEntity() {
		return dynamic_cast<wxDDEClient *>(_pEntity);
	}
	inline wxDDEClient *ReleaseEntity() {
		wxDDEClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDDEClient");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
