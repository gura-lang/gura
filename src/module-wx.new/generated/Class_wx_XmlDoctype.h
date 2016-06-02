//----------------------------------------------------------------------------
// wxXmlDoctype
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLDOCTYPE_H__
#define __CLASS_WX_XMLDOCTYPE_H__
#include <wx/xml/xml.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlDoctype
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlDoctype);

//----------------------------------------------------------------------------
// Object declaration for wxXmlDoctype
//----------------------------------------------------------------------------
class Object_wx_XmlDoctype : public Object {
protected:
	wxXmlDoctype *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_XmlDoctype)
public:
	inline Object_wx_XmlDoctype(wxXmlDoctype *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XmlDoctype(Class *pClass, wxXmlDoctype *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XmlDoctype();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxXmlDoctype *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxXmlDoctype *GetEntity() {
		return static_cast<wxXmlDoctype *>(_pEntity);
	}
	inline wxXmlDoctype *ReleaseEntity() {
		wxXmlDoctype *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXmlDoctype");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
