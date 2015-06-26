//----------------------------------------------------------------------------
// wxBookCtrlBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BOOKCTRLBASE_H__
#define __CLASS_WX_BOOKCTRLBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBookCtrlBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BookCtrlBase);

//----------------------------------------------------------------------------
// Object declaration for wxBookCtrlBase
//----------------------------------------------------------------------------
class Object_wx_BookCtrlBase : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_BookCtrlBase)
public:
	inline Object_wx_BookCtrlBase(wxBookCtrlBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_BookCtrlBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BookCtrlBase(Class *pClass, wxBookCtrlBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BookCtrlBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBookCtrlBase *GetEntity() {
		return dynamic_cast<wxBookCtrlBase *>(_pEntity);
	}
	inline wxBookCtrlBase *ReleaseEntity() {
		wxBookCtrlBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBookCtrlBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
