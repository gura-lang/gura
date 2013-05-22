//----------------------------------------------------------------------------
// wxFFile
// extracted from ffile.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FFILE_H__
#define __OBJECT_WX_FFILE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FFile);

//----------------------------------------------------------------------------
// Object declaration for wxFFile
//----------------------------------------------------------------------------
class Object_wx_FFile : public Object {
protected:
	wxFFile *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FFile)
public:
	inline Object_wx_FFile(wxFFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_FFile)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FFile(Class *pClass, wxFFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FFile();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxFFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxFFile *GetEntity() { return _pEntity; }
	inline wxFFile *ReleaseEntity() {
		wxFFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFFile");
		return true;
	}
};

}}

#endif
