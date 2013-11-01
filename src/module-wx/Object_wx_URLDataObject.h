//----------------------------------------------------------------------------
// wxURLDataObject
// extracted from urldataob.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_URLDATAOBJECT_H__
#define __OBJECT_WX_URLDATAOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxURLDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_URLDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxURLDataObject
//----------------------------------------------------------------------------
class Object_wx_URLDataObject : public Object_wx_DataObjectComposite {
public:
	Gura_DeclareObjectAccessor(wx_URLDataObject)
public:
	inline Object_wx_URLDataObject(wxURLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectComposite(Gura_UserClass(wx_URLDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_URLDataObject(Class *pClass, wxURLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectComposite(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_URLDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxURLDataObject *GetEntity() {
		return dynamic_cast<wxURLDataObject *>(_pEntity);
	}
	inline wxURLDataObject *ReleaseEntity() {
		wxURLDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxURLDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
