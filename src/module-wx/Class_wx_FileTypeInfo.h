//----------------------------------------------------------------------------
// wxFileTypeInfo
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILETYPEINFO_H__
#define __CLASS_WX_FILETYPEINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileTypeInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileTypeInfo);

//----------------------------------------------------------------------------
// Object declaration for wxFileTypeInfo
//----------------------------------------------------------------------------
class Object_wx_FileTypeInfo : public Object {
protected:
	wxFileTypeInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FileTypeInfo)
public:
	inline Object_wx_FileTypeInfo(wxFileTypeInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_FileTypeInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FileTypeInfo(Class *pClass, wxFileTypeInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FileTypeInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxFileTypeInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxFileTypeInfo *GetEntity() { return _pEntity; }
	inline wxFileTypeInfo *ReleaseEntity() {
		wxFileTypeInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileTypeInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
