//----------------------------------------------------------------------------
// wxXmlNode
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLNODE_H__
#define __CLASS_WX_XMLNODE_H__
#include <wx/xml/xml.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlNode
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlNode);

//----------------------------------------------------------------------------
// Object declaration for wxXmlNode
//----------------------------------------------------------------------------
class Object_wx_XmlNode : public Object {
protected:
	wxXmlNode *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_XmlNode)
public:
	inline Object_wx_XmlNode(wxXmlNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XmlNode(Class *pClass, wxXmlNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XmlNode();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxXmlNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxXmlNode *GetEntity() {
		return static_cast<wxXmlNode *>(_pEntity);
	}
	inline wxXmlNode *ReleaseEntity() {
		wxXmlNode *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXmlNode");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
