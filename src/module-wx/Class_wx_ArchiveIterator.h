//----------------------------------------------------------------------------
// wxArchiveIterator
// extracted from archive.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVEITERATOR_H__
#define __CLASS_WX_ARCHIVEITERATOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveIterator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveIterator);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveIterator
//----------------------------------------------------------------------------
class Object_wx_ArchiveIterator : public Object {
protected:
	wxArchiveIterator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ArchiveIterator)
public:
	inline Object_wx_ArchiveIterator(wxArchiveIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ArchiveIterator)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ArchiveIterator(Class *pClass, wxArchiveIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ArchiveIterator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxArchiveIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxArchiveIterator *GetEntity() { return _pEntity; }
	inline wxArchiveIterator *ReleaseEntity() {
		wxArchiveIterator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxArchiveIterator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
