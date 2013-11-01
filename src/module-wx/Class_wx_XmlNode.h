//----------------------------------------------------------------------------
// wxXmlNode
// extracted from xmlnode.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_XMLNODE_H__
#define __OBJECT_WX_XMLNODE_H__

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
				Object(Gura_UserClass(wx_XmlNode)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XmlNode(Class *pClass, wxXmlNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XmlNode();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxXmlNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxXmlNode *GetEntity() { return _pEntity; }
	inline wxXmlNode *ReleaseEntity() {
		wxXmlNode *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxXmlNode");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
