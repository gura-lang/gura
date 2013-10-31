//----------------------------------------------------------------------------
// wxFileDirPickerEvent
// extracted from filepicker.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILEDIRPICKEREVENT_H__
#define __OBJECT_WX_FILEDIRPICKEREVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileDirPickerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFileDirPickerEvent
//----------------------------------------------------------------------------
class Object_wx_FileDirPickerEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_FileDirPickerEvent)
public:
	inline Object_wx_FileDirPickerEvent(wxFileDirPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_FileDirPickerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileDirPickerEvent(Class *pClass, wxFileDirPickerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileDirPickerEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFileDirPickerEvent *GetEntity() {
		return dynamic_cast<wxFileDirPickerEvent *>(_pEntity);
	}
	inline wxFileDirPickerEvent *ReleaseEntity() {
		wxFileDirPickerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileDirPickerEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
