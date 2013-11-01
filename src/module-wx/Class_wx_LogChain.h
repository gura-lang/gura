//----------------------------------------------------------------------------
// wxLogChain
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGCHAIN_H__
#define __CLASS_WX_LOGCHAIN_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogChain
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogChain);

//----------------------------------------------------------------------------
// Object declaration for wxLogChain
//----------------------------------------------------------------------------
class Object_wx_LogChain : public Object_wx_Log {
public:
	Gura_DeclareObjectAccessor(wx_LogChain)
public:
	inline Object_wx_LogChain(wxLogChain *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(Gura_UserClass(wx_LogChain), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogChain(Class *pClass, wxLogChain *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogChain();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogChain *GetEntity() {
		return dynamic_cast<wxLogChain *>(_pEntity);
	}
	inline wxLogChain *ReleaseEntity() {
		wxLogChain *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLogChain");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
