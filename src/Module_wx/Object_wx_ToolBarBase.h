//----------------------------------------------------------------------------
// wxToolBarBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOOLBARBASE_H__
#define __OBJECT_WX_TOOLBARBASE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolBarBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolBarBase);

//----------------------------------------------------------------------------
// Object declaration for wxToolBarBase
//----------------------------------------------------------------------------
class Object_wx_ToolBarBase : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ToolBarBase)
public:
	inline Object_wx_ToolBarBase(wxToolBarBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ToolBarBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolBarBase(Class *pClass, wxToolBarBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolBarBase();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxToolBarBase *GetEntity() {
		return dynamic_cast<wxToolBarBase *>(_pEntity);
	}
	inline wxToolBarBase *ReleaseEntity() {
		wxToolBarBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToolBarBase");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
