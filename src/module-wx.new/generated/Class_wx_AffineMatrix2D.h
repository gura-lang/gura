//----------------------------------------------------------------------------
// wxAffineMatrix2D
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AFFINEMATRIX2D_H__
#define __CLASS_WX_AFFINEMATRIX2D_H__
#include <wx/affinematrix2d.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAffineMatrix2D
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AffineMatrix2D);

//----------------------------------------------------------------------------
// Object declaration for wxAffineMatrix2D
//----------------------------------------------------------------------------
class Object_wx_AffineMatrix2D : public Object_wx_AffineMatrix2DBase {
public:
	Gura_DeclareObjectAccessor(wx_AffineMatrix2D)
public:
	inline Object_wx_AffineMatrix2D(wxAffineMatrix2D *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AffineMatrix2DBase(Gura_UserClass(wx_AffineMatrix2D), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AffineMatrix2D(Class *pClass, wxAffineMatrix2D *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AffineMatrix2DBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AffineMatrix2D();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAffineMatrix2D *GetEntity() {
		return static_cast<wxAffineMatrix2D *>(_pEntity);
	}
	inline wxAffineMatrix2D *ReleaseEntity() {
		wxAffineMatrix2D *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAffineMatrix2D");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
