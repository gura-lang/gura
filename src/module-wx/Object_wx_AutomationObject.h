//----------------------------------------------------------------------------
// wxAutomationObject
// extracted from autoobj.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_AUTOMATIONOBJECT_H__
#define __OBJECT_WX_AUTOMATIONOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAutomationObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AutomationObject);

//----------------------------------------------------------------------------
// Object declaration for wxAutomationObject
//----------------------------------------------------------------------------
class Object_wx_AutomationObject : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_AutomationObject)
public:
	inline Object_wx_AutomationObject(wxAutomationObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_AutomationObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AutomationObject(Class *pClass, wxAutomationObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AutomationObject();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAutomationObject *GetEntity() {
		return dynamic_cast<wxAutomationObject *>(_pEntity);
	}
	inline wxAutomationObject *ReleaseEntity() {
		wxAutomationObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAutomationObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
