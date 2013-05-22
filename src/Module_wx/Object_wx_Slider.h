//----------------------------------------------------------------------------
// wxSlider
// extracted from slider.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SLIDER_H__
#define __OBJECT_WX_SLIDER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSlider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Slider);

//----------------------------------------------------------------------------
// Object declaration for wxSlider
//----------------------------------------------------------------------------
class Object_wx_Slider : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_Slider)
public:
	inline Object_wx_Slider(wxSlider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_Slider), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Slider(Class *pClass, wxSlider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Slider();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSlider *GetEntity() {
		return dynamic_cast<wxSlider *>(_pEntity);
	}
	inline wxSlider *ReleaseEntity() {
		wxSlider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSlider");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
