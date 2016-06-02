//----------------------------------------------------------------------------
// wxAcceleratorTable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACCELERATORTABLE_H__
#define __CLASS_WX_ACCELERATORTABLE_H__
#include <wx/accel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AcceleratorTable);

//----------------------------------------------------------------------------
// Object declaration for wxAcceleratorTable
//----------------------------------------------------------------------------
class Object_wx_AcceleratorTable : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_AcceleratorTable)
public:
	inline Object_wx_AcceleratorTable(wxAcceleratorTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_AcceleratorTable), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AcceleratorTable(Class *pClass, wxAcceleratorTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AcceleratorTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAcceleratorTable *GetEntity() {
		return static_cast<wxAcceleratorTable *>(_pEntity);
	}
	inline wxAcceleratorTable *ReleaseEntity() {
		wxAcceleratorTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAcceleratorTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
