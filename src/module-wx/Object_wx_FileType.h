//----------------------------------------------------------------------------
// wxFileType
// extracted from filetype.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILETYPE_H__
#define __OBJECT_WX_FILETYPE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileType
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileType);

//----------------------------------------------------------------------------
// Object declaration for wxFileType
//----------------------------------------------------------------------------
class Object_wx_FileType : public Object {
protected:
	wxFileType *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FileType)
public:
	inline Object_wx_FileType(wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_FileType)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FileType(Class *pClass, wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FileType();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxFileType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxFileType *GetEntity() { return _pEntity; }
	inline wxFileType *ReleaseEntity() {
		wxFileType *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileType");
		return true;
	}
};

}}

#endif
