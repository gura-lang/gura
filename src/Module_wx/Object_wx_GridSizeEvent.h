//----------------------------------------------------------------------------
// wxGridSizeEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDSIZEEVENT_H__
#define __OBJECT_WX_GRIDSIZEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridSizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridSizeEvent
//----------------------------------------------------------------------------
class Object_wx_GridSizeEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_GridSizeEvent)
public:
	inline Object_wx_GridSizeEvent(wxGridSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_GridSizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridSizeEvent(Class *pClass, wxGridSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridSizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridSizeEvent *GetEntity() {
		return dynamic_cast<wxGridSizeEvent *>(_pEntity);
	}
	inline wxGridSizeEvent *ReleaseEntity() {
		wxGridSizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridSizeEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
