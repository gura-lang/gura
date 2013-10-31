//----------------------------------------------------------------------------
// wxXmlProperty
// extracted from xmlproperty.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_XMLPROPERTY_H__
#define __OBJECT_WX_XMLPROPERTY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlProperty
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlProperty);

//----------------------------------------------------------------------------
// Object declaration for wxXmlProperty
//----------------------------------------------------------------------------
class Object_wx_XmlProperty : public Object {
protected:
	wxXmlProperty *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_XmlProperty)
public:
	inline Object_wx_XmlProperty(wxXmlProperty *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_XmlProperty)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XmlProperty(Class *pClass, wxXmlProperty *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XmlProperty();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxXmlProperty *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxXmlProperty *GetEntity() { return _pEntity; }
	inline wxXmlProperty *ReleaseEntity() {
		wxXmlProperty *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxXmlProperty");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
