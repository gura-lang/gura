//----------------------------------------------------------------------------
// wxDataViewColumn
// extracted from dataviewcolumn.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWCOLUMN_H__
#define __OBJECT_WX_DATAVIEWCOLUMN_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewColumn);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewColumn
//----------------------------------------------------------------------------
class Object_wx_DataViewColumn : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DataViewColumn)
public:
	inline Object_wx_DataViewColumn(wxDataViewColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DataViewColumn), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewColumn(Class *pClass, wxDataViewColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewColumn();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewColumn *GetEntity() {
		return dynamic_cast<wxDataViewColumn *>(_pEntity);
	}
	inline wxDataViewColumn *ReleaseEntity() {
		wxDataViewColumn *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewColumn");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
