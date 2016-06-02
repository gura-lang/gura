//----------------------------------------------------------------------------
// wxGCDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GCDC_H__
#define __CLASS_WX_GCDC_H__
#include <wx/dcgraph.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGCDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GCDC);

//----------------------------------------------------------------------------
// Object declaration for wxGCDC
//----------------------------------------------------------------------------
class Object_wx_GCDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_GCDC)
public:
	inline Object_wx_GCDC(wxGCDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_GCDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GCDC(Class *pClass, wxGCDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GCDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGCDC *GetEntity() {
		return static_cast<wxGCDC *>(_pEntity);
	}
	inline wxGCDC *ReleaseEntity() {
		wxGCDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGCDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
