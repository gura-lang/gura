//----------------------------------------------------------------------------
// wxFile
// extracted from file.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILE_H__
#define __CLASS_WX_FILE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_File);

//----------------------------------------------------------------------------
// Object declaration for wxFile
//----------------------------------------------------------------------------
class Object_wx_File : public Object {
protected:
	wxFile *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_File)
public:
	inline Object_wx_File(wxFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_File)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_File(Class *pClass, wxFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_File();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxFile *GetEntity() { return _pEntity; }
	inline wxFile *ReleaseEntity() {
		wxFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFile");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
