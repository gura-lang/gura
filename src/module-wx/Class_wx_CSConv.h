//----------------------------------------------------------------------------
// wxCSConv
// extracted from csconv.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CSCONV_H__
#define __CLASS_WX_CSCONV_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCSConv
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CSConv);

//----------------------------------------------------------------------------
// Object declaration for wxCSConv
//----------------------------------------------------------------------------
class Object_wx_CSConv : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_CSConv)
public:
	inline Object_wx_CSConv(wxCSConv *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_CSConv), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CSConv(Class *pClass, wxCSConv *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CSConv();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCSConv *GetEntity() {
		return dynamic_cast<wxCSConv *>(_pEntity);
	}
	inline wxCSConv *ReleaseEntity() {
		wxCSConv *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCSConv");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
