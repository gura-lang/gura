//----------------------------------------------------------------------------
// wxHelpControllerBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HELPCONTROLLERBASE_H__
#define __OBJECT_WX_HELPCONTROLLERBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHelpControllerBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HelpControllerBase);

//----------------------------------------------------------------------------
// Object declaration for wxHelpControllerBase
//----------------------------------------------------------------------------
class Object_wx_HelpControllerBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HelpControllerBase)
public:
	inline Object_wx_HelpControllerBase(wxHelpControllerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HelpControllerBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HelpControllerBase(Class *pClass, wxHelpControllerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HelpControllerBase();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHelpControllerBase *GetEntity() {
		return dynamic_cast<wxHelpControllerBase *>(_pEntity);
	}
	inline wxHelpControllerBase *ReleaseEntity() {
		wxHelpControllerBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHelpControllerBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
