//----------------------------------------------------------------------------
// wxJPEGHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_JPEGHANDLER_H__
#define __OBJECT_WX_JPEGHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxJPEGHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_JPEGHandler);

//----------------------------------------------------------------------------
// Object declaration for wxJPEGHandler
//----------------------------------------------------------------------------
class Object_wx_JPEGHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_JPEGHandler)
public:
	inline Object_wx_JPEGHandler(wxJPEGHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_JPEGHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_JPEGHandler(Class *pClass, wxJPEGHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_JPEGHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxJPEGHandler *GetEntity() {
		return dynamic_cast<wxJPEGHandler *>(_pEntity);
	}
	inline wxJPEGHandler *ReleaseEntity() {
		wxJPEGHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxJPEGHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
