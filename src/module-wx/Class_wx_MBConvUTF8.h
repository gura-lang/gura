//----------------------------------------------------------------------------
// wxMBConvUTF8
// extracted from mbcnvut8.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MBCONVUTF8_H__
#define __CLASS_WX_MBCONVUTF8_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConvUTF8
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConvUTF8);

//----------------------------------------------------------------------------
// Object declaration for wxMBConvUTF8
//----------------------------------------------------------------------------
class Object_wx_MBConvUTF8 : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_MBConvUTF8)
public:
	inline Object_wx_MBConvUTF8(wxMBConvUTF8 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_MBConvUTF8), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MBConvUTF8(Class *pClass, wxMBConvUTF8 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MBConvUTF8();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMBConvUTF8 *GetEntity() {
		return dynamic_cast<wxMBConvUTF8 *>(_pEntity);
	}
	inline wxMBConvUTF8 *ReleaseEntity() {
		wxMBConvUTF8 *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMBConvUTF8");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
