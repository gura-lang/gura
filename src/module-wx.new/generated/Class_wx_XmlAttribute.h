//----------------------------------------------------------------------------
// wxXmlAttribute
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLATTRIBUTE_H__
#define __CLASS_WX_XMLATTRIBUTE_H__
#include <wx/xml/xml.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlAttribute);

//----------------------------------------------------------------------------
// Object declaration for wxXmlAttribute
//----------------------------------------------------------------------------
class Object_wx_XmlAttribute : public Object {
protected:
	wxXmlAttribute *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_XmlAttribute)
public:
	inline Object_wx_XmlAttribute(wxXmlAttribute *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XmlAttribute(Class *pClass, wxXmlAttribute *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XmlAttribute();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxXmlAttribute *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxXmlAttribute *GetEntity() {
		return static_cast<wxXmlAttribute *>(_pEntity);
	}
	inline wxXmlAttribute *ReleaseEntity() {
		wxXmlAttribute *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxXmlAttribute");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
