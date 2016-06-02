//----------------------------------------------------------------------------
// wxMsgCatalog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MSGCATALOG_H__
#define __CLASS_WX_MSGCATALOG_H__
#include <wx/translation.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMsgCatalog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MsgCatalog);

//----------------------------------------------------------------------------
// Object declaration for wxMsgCatalog
//----------------------------------------------------------------------------
class Object_wx_MsgCatalog : public Object {
protected:
	wxMsgCatalog *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MsgCatalog)
public:
	inline Object_wx_MsgCatalog(wxMsgCatalog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MsgCatalog(Class *pClass, wxMsgCatalog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MsgCatalog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMsgCatalog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMsgCatalog *GetEntity() {
		return static_cast<wxMsgCatalog *>(_pEntity);
	}
	inline wxMsgCatalog *ReleaseEntity() {
		wxMsgCatalog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMsgCatalog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
