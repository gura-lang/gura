//----------------------------------------------------------------------------
// wxClientBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENTBASE_H__
#define __CLASS_WX_CLIENTBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClientBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientBase);

//----------------------------------------------------------------------------
// Object declaration for wxClientBase
//----------------------------------------------------------------------------
class Object_wx_ClientBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ClientBase)
public:
	inline Object_wx_ClientBase(wxClientBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ClientBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ClientBase(Class *pClass, wxClientBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ClientBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxClientBase *GetEntity() {
		return dynamic_cast<wxClientBase *>(_pEntity);
	}
	inline wxClientBase *ReleaseEntity() {
		wxClientBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClientBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
