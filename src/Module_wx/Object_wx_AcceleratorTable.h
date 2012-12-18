//----------------------------------------------------------------------------
// wxAcceleratorTable
// extracted from accel.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ACCELERATORTABLE_H__
#define __OBJECT_WX_ACCELERATORTABLE_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAcceleratorTable *GetEntity() {
		return dynamic_cast<wxAcceleratorTable *>(_pEntity);
	}
	inline wxAcceleratorTable *ReleaseEntity() {
		wxAcceleratorTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAcceleratorTable");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
