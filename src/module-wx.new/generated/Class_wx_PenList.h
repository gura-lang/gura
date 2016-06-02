//----------------------------------------------------------------------------
// wxPenList
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PENLIST_H__
#define __CLASS_WX_PENLIST_H__
#include <wx/pen.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPenList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PenList);

//----------------------------------------------------------------------------
// Object declaration for wxPenList
//----------------------------------------------------------------------------
class Object_wx_PenList : public Object {
protected:
	wxPenList *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PenList)
public:
	inline Object_wx_PenList(wxPenList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PenList(Class *pClass, wxPenList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PenList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPenList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPenList *GetEntity() {
		return static_cast<wxPenList *>(_pEntity);
	}
	inline wxPenList *ReleaseEntity() {
		wxPenList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPenList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
