//----------------------------------------------------------------------------
// wxVarHVScrollHelper
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARHVSCROLLHELPER_H__
#define __CLASS_WX_VARHVSCROLLHELPER_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVarHVScrollHelper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VarHVScrollHelper);

//----------------------------------------------------------------------------
// Object declaration for wxVarHVScrollHelper
//----------------------------------------------------------------------------
class Object_wx_VarHVScrollHelper : public Object_wx_VarVScrollHelper {
public:
	Gura_DeclareObjectAccessor(wx_VarHVScrollHelper)
public:
	inline Object_wx_VarHVScrollHelper(wxVarHVScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarVScrollHelper(Gura_UserClass(wx_VarHVScrollHelper), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VarHVScrollHelper(Class *pClass, wxVarHVScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarVScrollHelper(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VarHVScrollHelper();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVarHVScrollHelper *GetEntity() {
		return static_cast<wxVarHVScrollHelper *>(_pEntity);
	}
	inline wxVarHVScrollHelper *ReleaseEntity() {
		wxVarHVScrollHelper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVarHVScrollHelper");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
