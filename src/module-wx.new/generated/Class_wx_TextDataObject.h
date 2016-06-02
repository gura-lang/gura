//----------------------------------------------------------------------------
// wxTextDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTDATAOBJECT_H__
#define __CLASS_WX_TEXTDATAOBJECT_H__
#include <wx/dataobj.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxTextDataObject
//----------------------------------------------------------------------------
class Object_wx_TextDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_TextDataObject)
public:
	inline Object_wx_TextDataObject(wxTextDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_TextDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextDataObject(Class *pClass, wxTextDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextDataObject *GetEntity() {
		return static_cast<wxTextDataObject *>(_pEntity);
	}
	inline wxTextDataObject *ReleaseEntity() {
		wxTextDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
