//----------------------------------------------------------------------------
// wxPNMHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PNMHANDLER_H__
#define __OBJECT_WX_PNMHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPNMHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PNMHandler);

//----------------------------------------------------------------------------
// Object declaration for wxPNMHandler
//----------------------------------------------------------------------------
class Object_wx_PNMHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_PNMHandler)
public:
	inline Object_wx_PNMHandler(wxPNMHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_PNMHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PNMHandler(Class *pClass, wxPNMHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PNMHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPNMHandler *GetEntity() {
		return dynamic_cast<wxPNMHandler *>(_pEntity);
	}
	inline wxPNMHandler *ReleaseEntity() {
		wxPNMHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPNMHandler");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
