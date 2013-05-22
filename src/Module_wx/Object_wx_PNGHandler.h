//----------------------------------------------------------------------------
// wxPNGHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PNGHANDLER_H__
#define __OBJECT_WX_PNGHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPNGHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PNGHandler);

//----------------------------------------------------------------------------
// Object declaration for wxPNGHandler
//----------------------------------------------------------------------------
class Object_wx_PNGHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_PNGHandler)
public:
	inline Object_wx_PNGHandler(wxPNGHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_PNGHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PNGHandler(Class *pClass, wxPNGHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PNGHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPNGHandler *GetEntity() {
		return dynamic_cast<wxPNGHandler *>(_pEntity);
	}
	inline wxPNGHandler *ReleaseEntity() {
		wxPNGHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPNGHandler");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
