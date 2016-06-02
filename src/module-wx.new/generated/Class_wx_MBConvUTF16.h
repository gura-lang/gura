//----------------------------------------------------------------------------
// wxMBConvUTF16
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MBCONVUTF16_H__
#define __CLASS_WX_MBCONVUTF16_H__
#include <wx/strconv.h>

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxMBConvUTF16 *GetEntity() {
		return static_cast<wxMBConvUTF16 *>(_pEntity);
	}
	inline wxMBConvUTF16 *ReleaseEntity() {
		wxMBConvUTF16 *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMBConvUTF16");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
