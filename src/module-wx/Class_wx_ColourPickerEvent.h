//----------------------------------------------------------------------------
// wxColourPickerEvent
// extracted from clrpicker.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLOURPICKEREVENT_H__
#define __CLASS_WX_COLOURPICKEREVENT_H__

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxColourPickerEvent *GetEntity() {
		return dynamic_cast<wxColourPickerEvent *>(_pEntity);
	}
	inline wxColourPickerEvent *ReleaseEntity() {
		wxColourPickerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxColourPickerEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
