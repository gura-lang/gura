//----------------------------------------------------------------------------
// wxDataViewCtrl
// extracted from dataviewctrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWCTRL_H__
#define __OBJECT_WX_DATAVIEWCTRL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewCtrl
//----------------------------------------------------------------------------
class Object_wx_DataViewCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_DataViewCtrl)
public:
	inline Object_wx_DataViewCtrl(wxDataViewCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_DataViewCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewCtrl(Class *pClass, wxDataViewCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewCtrl();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewCtrl *GetEntity() {
		return dynamic_cast<wxDataViewCtrl *>(_pEntity);
	}
	inline wxDataViewCtrl *ReleaseEntity() {
		wxDataViewCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewCtrl");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
