//----------------------------------------------------------------------------
// wxStaticLine
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATICLINE_H__
#define __CLASS_WX_STATICLINE_H__
#include <wx/statline.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticLine
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticLine);

//----------------------------------------------------------------------------
// Object declaration for wxStaticLine
//----------------------------------------------------------------------------
class Object_wx_StaticLine : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StaticLine)
public:
	inline Object_wx_StaticLine(wxStaticLine *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StaticLine), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticLine(Class *pClass, wxStaticLine *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticLine();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStaticLine *GetEntity() {
		return static_cast<wxStaticLine *>(_pEntity);
	}
	inline wxStaticLine *ReleaseEntity() {
		wxStaticLine *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStaticLine");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
