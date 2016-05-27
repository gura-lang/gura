//----------------------------------------------------------------------------
// wxPGVIterator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGVITERATOR_H__
#define __CLASS_WX_PGVITERATOR_H__
#include <wx/propgrid/propgridpagestate.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGVIterator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGVIterator);

//----------------------------------------------------------------------------
// Object declaration for wxPGVIterator
//----------------------------------------------------------------------------
class Object_wx_PGVIterator : public Object {
protected:
	wxPGVIterator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PGVIterator)
public:
	inline Object_wx_PGVIterator(wxPGVIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PGVIterator(Class *pClass, wxPGVIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PGVIterator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPGVIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPGVIterator *GetEntity() {
		return static_cast<wxPGVIterator *>(_pEntity);
	}
	inline wxPGVIterator *ReleaseEntity() {
		wxPGVIterator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPGVIterator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
