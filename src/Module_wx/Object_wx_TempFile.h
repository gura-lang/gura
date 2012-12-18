//----------------------------------------------------------------------------
// wxTempFile
// extracted from tempfile.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TEMPFILE_H__
#define __OBJECT_WX_TEMPFILE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTempFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TempFile);

//----------------------------------------------------------------------------
// Object declaration for wxTempFile
//----------------------------------------------------------------------------
class Object_wx_TempFile : public Object {
protected:
	wxTempFile *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TempFile)
public:
	inline Object_wx_TempFile(wxTempFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TempFile)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TempFile(Class *pClass, wxTempFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TempFile();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxTempFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTempFile *GetEntity() { return _pEntity; }
	inline wxTempFile *ReleaseEntity() {
		wxTempFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTempFile");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
