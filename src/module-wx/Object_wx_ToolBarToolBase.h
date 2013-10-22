//----------------------------------------------------------------------------
// wxToolBarToolBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOOLBARTOOLBASE_H__
#define __OBJECT_WX_TOOLBARTOOLBASE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolBarToolBase);

//----------------------------------------------------------------------------
// Object declaration for wxToolBarToolBase
//----------------------------------------------------------------------------
class Object_wx_ToolBarToolBase : public Object {
protected:
	wxToolBarToolBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ToolBarToolBase)
public:
	inline Object_wx_ToolBarToolBase(wxToolBarToolBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ToolBarToolBase)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ToolBarToolBase(Class *pClass, wxToolBarToolBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ToolBarToolBase();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxToolBarToolBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxToolBarToolBase *GetEntity() { return _pEntity; }
	inline wxToolBarToolBase *ReleaseEntity() {
		wxToolBarToolBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToolBarToolBase");
		return true;
	}
};

}}

#endif
