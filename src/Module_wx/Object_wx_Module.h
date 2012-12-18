//----------------------------------------------------------------------------
// wxModule
// extracted from module.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MODULE_H__
#define __OBJECT_WX_MODULE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxModule
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Module);

//----------------------------------------------------------------------------
// Object declaration for wxModule
//----------------------------------------------------------------------------
class Object_wx_Module : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Module)
public:
	inline Object_wx_Module(wxModule *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Module), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Module(Class *pClass, wxModule *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Module();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxModule *GetEntity() {
		return dynamic_cast<wxModule *>(_pEntity);
	}
	inline wxModule *ReleaseEntity() {
		wxModule *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxModule");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
