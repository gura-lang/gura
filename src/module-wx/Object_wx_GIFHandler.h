//----------------------------------------------------------------------------
// wxGIFHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GIFHANDLER_H__
#define __OBJECT_WX_GIFHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGIFHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GIFHandler);

//----------------------------------------------------------------------------
// Object declaration for wxGIFHandler
//----------------------------------------------------------------------------
class Object_wx_GIFHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_GIFHandler)
public:
	inline Object_wx_GIFHandler(wxGIFHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_GIFHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GIFHandler(Class *pClass, wxGIFHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GIFHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGIFHandler *GetEntity() {
		return dynamic_cast<wxGIFHandler *>(_pEntity);
	}
	inline wxGIFHandler *ReleaseEntity() {
		wxGIFHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGIFHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
