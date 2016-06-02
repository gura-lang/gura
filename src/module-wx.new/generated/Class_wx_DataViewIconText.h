//----------------------------------------------------------------------------
// wxDataViewIconText
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWICONTEXT_H__
#define __CLASS_WX_DATAVIEWICONTEXT_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewIconText
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewIconText);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewIconText
//----------------------------------------------------------------------------
class Object_wx_DataViewIconText : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DataViewIconText)
public:
	inline Object_wx_DataViewIconText(wxDataViewIconText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DataViewIconText), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewIconText(Class *pClass, wxDataViewIconText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewIconText();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewIconText *GetEntity() {
		return static_cast<wxDataViewIconText *>(_pEntity);
	}
	inline wxDataViewIconText *ReleaseEntity() {
		wxDataViewIconText *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewIconText");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
