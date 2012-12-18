//----------------------------------------------------------------------------
// wxTextDataObject
// extracted from txtdatob.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TEXTDATAOBJECT_H__
#define __OBJECT_WX_TEXTDATAOBJECT_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTextDataObject *GetEntity() {
		return dynamic_cast<wxTextDataObject *>(_pEntity);
	}
	inline wxTextDataObject *ReleaseEntity() {
		wxTextDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextDataObject");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
