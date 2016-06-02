//----------------------------------------------------------------------------
// wxGridStringTable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDSTRINGTABLE_H__
#define __CLASS_WX_GRIDSTRINGTABLE_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridStringTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridStringTable);

//----------------------------------------------------------------------------
// Object declaration for wxGridStringTable
//----------------------------------------------------------------------------
class Object_wx_GridStringTable : public Object_wx_GridTableBase {
public:
	Gura_DeclareObjectAccessor(wx_GridStringTable)
public:
	inline Object_wx_GridStringTable(wxGridStringTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridTableBase(Gura_UserClass(wx_GridStringTable), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridStringTable(Class *pClass, wxGridStringTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridTableBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridStringTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridStringTable *GetEntity() {
		return static_cast<wxGridStringTable *>(_pEntity);
	}
	inline wxGridStringTable *ReleaseEntity() {
		wxGridStringTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridStringTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
