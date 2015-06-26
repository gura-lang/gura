//----------------------------------------------------------------------------
// wxBitmapDataObject
// extracted from bmpdatob.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BITMAPDATAOBJECT_H__
#define __CLASS_WX_BITMAPDATAOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BitmapDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxBitmapDataObject
//----------------------------------------------------------------------------
class Object_wx_BitmapDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_BitmapDataObject)
public:
	inline Object_wx_BitmapDataObject(wxBitmapDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_BitmapDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BitmapDataObject(Class *pClass, wxBitmapDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BitmapDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBitmapDataObject *GetEntity() {
		return dynamic_cast<wxBitmapDataObject *>(_pEntity);
	}
	inline wxBitmapDataObject *ReleaseEntity() {
		wxBitmapDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBitmapDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
