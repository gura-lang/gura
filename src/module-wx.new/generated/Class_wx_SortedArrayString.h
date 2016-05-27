//----------------------------------------------------------------------------
// wxSortedArrayString
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SORTEDARRAYSTRING_H__
#define __CLASS_WX_SORTEDARRAYSTRING_H__
#include <wx/arrstr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSortedArrayString
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SortedArrayString);

//----------------------------------------------------------------------------
// Object declaration for wxSortedArrayString
//----------------------------------------------------------------------------
class Object_wx_SortedArrayString : public Object {
protected:
	wxSortedArrayString *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SortedArrayString)
public:
	inline Object_wx_SortedArrayString(wxSortedArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SortedArrayString(Class *pClass, wxSortedArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SortedArrayString();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSortedArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSortedArrayString *GetEntity() {
		return static_cast<wxSortedArrayString *>(_pEntity);
	}
	inline wxSortedArrayString *ReleaseEntity() {
		wxSortedArrayString *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSortedArrayString");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
