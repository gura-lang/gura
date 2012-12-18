//----------------------------------------------------------------------------
// wxPickerBase
// extracted from pickerbase.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PICKERBASE_H__
#define __OBJECT_WX_PICKERBASE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPickerBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PickerBase);

//----------------------------------------------------------------------------
// Object declaration for wxPickerBase
//----------------------------------------------------------------------------
class Object_wx_PickerBase : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_PickerBase)
public:
	inline Object_wx_PickerBase(wxPickerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_PickerBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PickerBase(Class *pClass, wxPickerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PickerBase();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPickerBase *GetEntity() {
		return dynamic_cast<wxPickerBase *>(_pEntity);
	}
	inline wxPickerBase *ReleaseEntity() {
		wxPickerBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPickerBase");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
