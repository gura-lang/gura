//----------------------------------------------------------------------------
// wxLayoutAlgorithm
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LAYOUTALGORITHM_H__
#define __CLASS_WX_LAYOUTALGORITHM_H__
#include <wx/laywin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LayoutAlgorithm);

//----------------------------------------------------------------------------
// Object declaration for wxLayoutAlgorithm
//----------------------------------------------------------------------------
class Object_wx_LayoutAlgorithm : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_LayoutAlgorithm)
public:
	inline Object_wx_LayoutAlgorithm(wxLayoutAlgorithm *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_LayoutAlgorithm), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LayoutAlgorithm(Class *pClass, wxLayoutAlgorithm *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LayoutAlgorithm();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLayoutAlgorithm *GetEntity() {
		return static_cast<wxLayoutAlgorithm *>(_pEntity);
	}
	inline wxLayoutAlgorithm *ReleaseEntity() {
		wxLayoutAlgorithm *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxLayoutAlgorithm");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
