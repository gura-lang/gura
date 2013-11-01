//----------------------------------------------------------------------------
// wxMBConvUTF7
// extracted from mbcnvut7.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MBCONVUTF7_H__
#define __CLASS_WX_MBCONVUTF7_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConvUTF7
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConvUTF7);

//----------------------------------------------------------------------------
// Object declaration for wxMBConvUTF7
//----------------------------------------------------------------------------
class Object_wx_MBConvUTF7 : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_MBConvUTF7)
public:
	inline Object_wx_MBConvUTF7(wxMBConvUTF7 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_MBConvUTF7), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MBConvUTF7(Class *pClass, wxMBConvUTF7 *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MBConvUTF7();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMBConvUTF7 *GetEntity() {
		return dynamic_cast<wxMBConvUTF7 *>(_pEntity);
	}
	inline wxMBConvUTF7 *ReleaseEntity() {
		wxMBConvUTF7 *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMBConvUTF7");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
