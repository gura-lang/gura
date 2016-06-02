//----------------------------------------------------------------------------
// wxDataViewColumn
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWCOLUMN_H__
#define __CLASS_WX_DATAVIEWCOLUMN_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewColumn);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewColumn
//----------------------------------------------------------------------------
class Object_wx_DataViewColumn : public Object_wx_SettableHeaderColumn {
public:
	Gura_DeclareObjectAccessor(wx_DataViewColumn)
public:
	inline Object_wx_DataViewColumn(wxDataViewColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SettableHeaderColumn(Gura_UserClass(wx_DataViewColumn), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewColumn(Class *pClass, wxDataViewColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SettableHeaderColumn(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewColumn();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewColumn *GetEntity() {
		return static_cast<wxDataViewColumn *>(_pEntity);
	}
	inline wxDataViewColumn *ReleaseEntity() {
		wxDataViewColumn *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewColumn");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
