//----------------------------------------------------------------------------
// wxMBConvUTF32
// extracted from mbcnvutf.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MBCONVUTF32_H__
#define __OBJECT_WX_MBCONVUTF32_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConvUTF32);

//----------------------------------------------------------------------------
// Object declaration for wxMBConvUTF32
//----------------------------------------------------------------------------
class Object_wx_MBConvUTF32 : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_MBConvUTF32)
public:
	inline Object_wx_MBConvUTF32(wxMBConvUTF32 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_MBConvUTF32), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MBConvUTF32(Class *pClass, wxMBConvUTF32 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MBConvUTF32();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMBConvUTF32 *GetEntity() {
		return dynamic_cast<wxMBConvUTF32 *>(_pEntity);
	}
	inline wxMBConvUTF32 *ReleaseEntity() {
		wxMBConvUTF32 *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMBConvUTF32");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
