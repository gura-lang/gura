//----------------------------------------------------------------------------
// wxGridTableBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDTABLEBASE_H__
#define __CLASS_WX_GRIDTABLEBASE_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridTableBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridTableBase);

//----------------------------------------------------------------------------
// Object declaration for wxGridTableBase
//----------------------------------------------------------------------------
class Object_wx_GridTableBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_GridTableBase)
public:
	inline Object_wx_GridTableBase(wxGridTableBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_GridTableBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridTableBase(Class *pClass, wxGridTableBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridTableBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridTableBase *GetEntity() {
		return static_cast<wxGridTableBase *>(_pEntity);
	}
	inline wxGridTableBase *ReleaseEntity() {
		wxGridTableBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridTableBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
