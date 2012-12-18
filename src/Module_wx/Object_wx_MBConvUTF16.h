//----------------------------------------------------------------------------
// wxMBConvUTF16
// extracted from mbcnvutf.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MBCONVUTF16_H__
#define __OBJECT_WX_MBCONVUTF16_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConvUTF16
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConvUTF16);

//----------------------------------------------------------------------------
// Object declaration for wxMBConvUTF16
//----------------------------------------------------------------------------
class Object_wx_MBConvUTF16 : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_MBConvUTF16)
public:
	inline Object_wx_MBConvUTF16(wxMBConvUTF16 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_MBConvUTF16), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MBConvUTF16(Class *pClass, wxMBConvUTF16 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MBConvUTF16();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMBConvUTF16 *GetEntity() {
		return dynamic_cast<wxMBConvUTF16 *>(_pEntity);
	}
	inline wxMBConvUTF16 *ReleaseEntity() {
		wxMBConvUTF16 *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMBConvUTF16");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
