//----------------------------------------------------------------------------
// wxDataInputStream
// extracted from datistrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAINPUTSTREAM_H__
#define __CLASS_WX_DATAINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxDataInputStream
//----------------------------------------------------------------------------
class Object_wx_DataInputStream : public Object {
protected:
	wxDataInputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataInputStream)
public:
	inline Object_wx_DataInputStream(wxDataInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DataInputStream)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataInputStream(Class *pClass, wxDataInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataInputStream *GetEntity() { return _pEntity; }
	inline wxDataInputStream *ReleaseEntity() {
		wxDataInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
