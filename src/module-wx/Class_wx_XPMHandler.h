//----------------------------------------------------------------------------
// wxXPMHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XPMHANDLER_H__
#define __CLASS_WX_XPMHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXPMHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XPMHandler);

//----------------------------------------------------------------------------
// Object declaration for wxXPMHandler
//----------------------------------------------------------------------------
class Object_wx_XPMHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_XPMHandler)
public:
	inline Object_wx_XPMHandler(wxXPMHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_XPMHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_XPMHandler(Class *pClass, wxXPMHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_XPMHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxXPMHandler *GetEntity() {
		return dynamic_cast<wxXPMHandler *>(_pEntity);
	}
	inline wxXPMHandler *ReleaseEntity() {
		wxXPMHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxXPMHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
