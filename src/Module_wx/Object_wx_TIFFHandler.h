//----------------------------------------------------------------------------
// wxTIFFHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TIFFHANDLER_H__
#define __OBJECT_WX_TIFFHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTIFFHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TIFFHandler);

//----------------------------------------------------------------------------
// Object declaration for wxTIFFHandler
//----------------------------------------------------------------------------
class Object_wx_TIFFHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_TIFFHandler)
public:
	inline Object_wx_TIFFHandler(wxTIFFHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_TIFFHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TIFFHandler(Class *pClass, wxTIFFHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TIFFHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTIFFHandler *GetEntity() {
		return dynamic_cast<wxTIFFHandler *>(_pEntity);
	}
	inline wxTIFFHandler *ReleaseEntity() {
		wxTIFFHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTIFFHandler");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
