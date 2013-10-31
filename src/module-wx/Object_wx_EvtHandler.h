//----------------------------------------------------------------------------
// wxEvtHandler
// extracted from evthand.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_EVTHANDLER_H__
#define __OBJECT_WX_EVTHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEvtHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EvtHandler);

//----------------------------------------------------------------------------
// Object declaration for wxEvtHandler
//----------------------------------------------------------------------------
class Object_wx_EvtHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_EvtHandler)
public:
	inline Object_wx_EvtHandler(wxEvtHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_EvtHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_EvtHandler(Class *pClass, wxEvtHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_EvtHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxEvtHandler *GetEntity() {
		return dynamic_cast<wxEvtHandler *>(_pEntity);
	}
	inline wxEvtHandler *ReleaseEntity() {
		wxEvtHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxEvtHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
