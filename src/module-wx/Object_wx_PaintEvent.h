//----------------------------------------------------------------------------
// wxPaintEvent
// extracted from paintevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PAINTEVENT_H__
#define __OBJECT_WX_PAINTEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPaintEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PaintEvent);

//----------------------------------------------------------------------------
// Object declaration for wxPaintEvent
//----------------------------------------------------------------------------
class Object_wx_PaintEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_PaintEvent)
public:
	inline Object_wx_PaintEvent(wxPaintEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_PaintEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PaintEvent(Class *pClass, wxPaintEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PaintEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPaintEvent *GetEntity() {
		return dynamic_cast<wxPaintEvent *>(_pEntity);
	}
	inline wxPaintEvent *ReleaseEntity() {
		wxPaintEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPaintEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
