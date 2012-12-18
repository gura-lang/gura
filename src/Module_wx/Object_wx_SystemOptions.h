//----------------------------------------------------------------------------
// wxSystemOptions
// extracted from sysopt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SYSTEMOPTIONS_H__
#define __OBJECT_WX_SYSTEMOPTIONS_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSystemOptions
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SystemOptions);

//----------------------------------------------------------------------------
// Object declaration for wxSystemOptions
//----------------------------------------------------------------------------
class Object_wx_SystemOptions : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SystemOptions)
public:
	inline Object_wx_SystemOptions(wxSystemOptions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SystemOptions), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SystemOptions(Class *pClass, wxSystemOptions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SystemOptions();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSystemOptions *GetEntity() {
		return dynamic_cast<wxSystemOptions *>(_pEntity);
	}
	inline wxSystemOptions *ReleaseEntity() {
		wxSystemOptions *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSystemOptions");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
