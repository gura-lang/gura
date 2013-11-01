//----------------------------------------------------------------------------
// wxLogPassThrough
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LOGPASSTHROUGH_H__
#define __OBJECT_WX_LOGPASSTHROUGH_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogPassThrough
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogPassThrough);

//----------------------------------------------------------------------------
// Object declaration for wxLogPassThrough
//----------------------------------------------------------------------------
class Object_wx_LogPassThrough : public Object_wx_LogChain {
public:
	Gura_DeclareObjectAccessor(wx_LogPassThrough)
public:
	inline Object_wx_LogPassThrough(wxLogPassThrough *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(Gura_UserClass(wx_LogPassThrough), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogPassThrough(Class *pClass, wxLogPassThrough *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogPassThrough();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogPassThrough *GetEntity() {
		return dynamic_cast<wxLogPassThrough *>(_pEntity);
	}
	inline wxLogPassThrough *ReleaseEntity() {
		wxLogPassThrough *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLogPassThrough");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
