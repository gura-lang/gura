//----------------------------------------------------------------------------
// wxPCXHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PCXHANDLER_H__
#define __OBJECT_WX_PCXHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPCXHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PCXHandler);

//----------------------------------------------------------------------------
// Object declaration for wxPCXHandler
//----------------------------------------------------------------------------
class Object_wx_PCXHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_PCXHandler)
public:
	inline Object_wx_PCXHandler(wxPCXHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_PCXHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PCXHandler(Class *pClass, wxPCXHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PCXHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPCXHandler *GetEntity() {
		return dynamic_cast<wxPCXHandler *>(_pEntity);
	}
	inline wxPCXHandler *ReleaseEntity() {
		wxPCXHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPCXHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
