//----------------------------------------------------------------------------
// wxServerBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SERVERBASE_H__
#define __CLASS_WX_SERVERBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxServerBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ServerBase);

//----------------------------------------------------------------------------
// Object declaration for wxServerBase
//----------------------------------------------------------------------------
class Object_wx_ServerBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ServerBase)
public:
	inline Object_wx_ServerBase(wxServerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ServerBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ServerBase(Class *pClass, wxServerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ServerBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxServerBase *GetEntity() {
		return dynamic_cast<wxServerBase *>(_pEntity);
	}
	inline wxServerBase *ReleaseEntity() {
		wxServerBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxServerBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
