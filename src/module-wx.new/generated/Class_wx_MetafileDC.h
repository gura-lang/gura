//----------------------------------------------------------------------------
// wxMetafileDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_METAFILEDC_H__
#define __CLASS_WX_METAFILEDC_H__
#include <wx/metafile.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMetafileDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MetafileDC);

//----------------------------------------------------------------------------
// Object declaration for wxMetafileDC
//----------------------------------------------------------------------------
class Object_wx_MetafileDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_MetafileDC)
public:
	inline Object_wx_MetafileDC(wxMetafileDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_MetafileDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MetafileDC(Class *pClass, wxMetafileDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MetafileDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMetafileDC *GetEntity() {
		return static_cast<wxMetafileDC *>(_pEntity);
	}
	inline wxMetafileDC *ReleaseEntity() {
		wxMetafileDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMetafileDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
