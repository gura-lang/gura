//----------------------------------------------------------------------------
// wxBMPHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BMPHANDLER_H__
#define __CLASS_WX_BMPHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBMPHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BMPHandler);

//----------------------------------------------------------------------------
// Object declaration for wxBMPHandler
//----------------------------------------------------------------------------
class Object_wx_BMPHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_BMPHandler)
public:
	inline Object_wx_BMPHandler(wxBMPHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_BMPHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BMPHandler(Class *pClass, wxBMPHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BMPHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBMPHandler *GetEntity() {
		return dynamic_cast<wxBMPHandler *>(_pEntity);
	}
	inline wxBMPHandler *ReleaseEntity() {
		wxBMPHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBMPHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
