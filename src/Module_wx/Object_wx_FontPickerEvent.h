//----------------------------------------------------------------------------
// wxFontPickerEvent
// extracted from fontpicker.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FONTPICKEREVENT_H__
#define __OBJECT_WX_FONTPICKEREVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontPickerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontPickerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFontPickerEvent
//----------------------------------------------------------------------------
class Object_wx_FontPickerEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_FontPickerEvent)
public:
	inline Object_wx_FontPickerEvent(wxFontPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_FontPickerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FontPickerEvent(Class *pClass, wxFontPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FontPickerEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFontPickerEvent *GetEntity() {
		return dynamic_cast<wxFontPickerEvent *>(_pEntity);
	}
	inline wxFontPickerEvent *ReleaseEntity() {
		wxFontPickerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFontPickerEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
