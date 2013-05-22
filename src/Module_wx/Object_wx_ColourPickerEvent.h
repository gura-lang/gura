//----------------------------------------------------------------------------
// wxColourPickerEvent
// extracted from clrpicker.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COLOURPICKEREVENT_H__
#define __OBJECT_WX_COLOURPICKEREVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColourPickerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ColourPickerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxColourPickerEvent
//----------------------------------------------------------------------------
class Object_wx_ColourPickerEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ColourPickerEvent)
public:
	inline Object_wx_ColourPickerEvent(wxColourPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ColourPickerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ColourPickerEvent(Class *pClass, wxColourPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ColourPickerEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxColourPickerEvent *GetEntity() {
		return dynamic_cast<wxColourPickerEvent *>(_pEntity);
	}
	inline wxColourPickerEvent *ReleaseEntity() {
		wxColourPickerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxColourPickerEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
