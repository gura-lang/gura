//----------------------------------------------------------------------------
// wxBrushList
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BRUSHLIST_H__
#define __CLASS_WX_BRUSHLIST_H__
#include <wx/brush.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBrushList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BrushList);

//----------------------------------------------------------------------------
// Object declaration for wxBrushList
//----------------------------------------------------------------------------
class Object_wx_BrushList : public Object {
protected:
	wxBrushList *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_BrushList)
public:
	inline Object_wx_BrushList(wxBrushList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_BrushList(Class *pClass, wxBrushList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_BrushList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxBrushList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxBrushList *GetEntity() {
		return static_cast<wxBrushList *>(_pEntity);
	}
	inline wxBrushList *ReleaseEntity() {
		wxBrushList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBrushList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
