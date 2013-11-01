//----------------------------------------------------------------------------
// wxTGAHandler
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TGAHANDLER_H__
#define __OBJECT_WX_TGAHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTGAHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TGAHandler);

//----------------------------------------------------------------------------
// Object declaration for wxTGAHandler
//----------------------------------------------------------------------------
class Object_wx_TGAHandler : public Object_wx_ImageHandler {
public:
	Gura_DeclareObjectAccessor(wx_TGAHandler)
public:
	inline Object_wx_TGAHandler(wxTGAHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(Gura_UserClass(wx_TGAHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TGAHandler(Class *pClass, wxTGAHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ImageHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TGAHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTGAHandler *GetEntity() {
		return dynamic_cast<wxTGAHandler *>(_pEntity);
	}
	inline wxTGAHandler *ReleaseEntity() {
		wxTGAHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTGAHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
