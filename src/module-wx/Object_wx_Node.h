//----------------------------------------------------------------------------
// wxNode
// extracted from node.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_NODE_H__
#define __OBJECT_WX_NODE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNode
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Node);

//----------------------------------------------------------------------------
// Object declaration for wxNode
//----------------------------------------------------------------------------
class Object_wx_Node : public Object {
protected:
	wxNode *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Node)
public:
	inline Object_wx_Node(wxNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Node)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Node(Class *pClass, wxNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Node();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxNode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxNode *GetEntity() { return _pEntity; }
	inline wxNode *ReleaseEntity() {
		wxNode *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNode");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
