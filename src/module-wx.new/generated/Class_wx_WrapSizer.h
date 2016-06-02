//----------------------------------------------------------------------------
// wxWrapSizer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WRAPSIZER_H__
#define __CLASS_WX_WRAPSIZER_H__
#include <wx/wrapsizer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWrapSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WrapSizer);

//----------------------------------------------------------------------------
// Object declaration for wxWrapSizer
//----------------------------------------------------------------------------
class Object_wx_WrapSizer : public Object_wx_BoxSizer {
public:
	Gura_DeclareObjectAccessor(wx_WrapSizer)
public:
	inline Object_wx_WrapSizer(wxWrapSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(Gura_UserClass(wx_WrapSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WrapSizer(Class *pClass, wxWrapSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WrapSizer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWrapSizer *GetEntity() {
		return static_cast<wxWrapSizer *>(_pEntity);
	}
	inline wxWrapSizer *ReleaseEntity() {
		wxWrapSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWrapSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
