//----------------------------------------------------------------------------
// wxContextHelp
// extracted from cshelp.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CONTEXTHELP_H__
#define __OBJECT_WX_CONTEXTHELP_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxContextHelp
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ContextHelp);

//----------------------------------------------------------------------------
// Object declaration for wxContextHelp
//----------------------------------------------------------------------------
class Object_wx_ContextHelp : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ContextHelp)
public:
	inline Object_wx_ContextHelp(wxContextHelp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ContextHelp), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ContextHelp(Class *pClass, wxContextHelp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ContextHelp();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxContextHelp *GetEntity() {
		return dynamic_cast<wxContextHelp *>(_pEntity);
	}
	inline wxContextHelp *ReleaseEntity() {
		wxContextHelp *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxContextHelp");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
