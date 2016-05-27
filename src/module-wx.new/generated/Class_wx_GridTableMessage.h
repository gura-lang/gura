//----------------------------------------------------------------------------
// wxGridTableMessage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDTABLEMESSAGE_H__
#define __CLASS_WX_GRIDTABLEMESSAGE_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridTableMessage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridTableMessage);

//----------------------------------------------------------------------------
// Object declaration for wxGridTableMessage
//----------------------------------------------------------------------------
class Object_wx_GridTableMessage : public Object {
protected:
	wxGridTableMessage *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridTableMessage)
public:
	inline Object_wx_GridTableMessage(wxGridTableMessage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridTableMessage(Class *pClass, wxGridTableMessage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridTableMessage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGridTableMessage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGridTableMessage *GetEntity() {
		return static_cast<wxGridTableMessage *>(_pEntity);
	}
	inline wxGridTableMessage *ReleaseEntity() {
		wxGridTableMessage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridTableMessage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
