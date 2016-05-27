//----------------------------------------------------------------------------
// wxToolBarToolBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TOOLBARTOOLBASE_H__
#define __CLASS_WX_TOOLBARTOOLBASE_H__
#include <wx/toolbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolBarToolBase);

//----------------------------------------------------------------------------
// Object declaration for wxToolBarToolBase
//----------------------------------------------------------------------------
class Object_wx_ToolBarToolBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ToolBarToolBase)
public:
	inline Object_wx_ToolBarToolBase(wxToolBarToolBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ToolBarToolBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolBarToolBase(Class *pClass, wxToolBarToolBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolBarToolBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxToolBarToolBase *GetEntity() {
		return static_cast<wxToolBarToolBase *>(_pEntity);
	}
	inline wxToolBarToolBase *ReleaseEntity() {
		wxToolBarToolBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxToolBarToolBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
