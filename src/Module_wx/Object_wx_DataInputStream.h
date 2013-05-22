//----------------------------------------------------------------------------
// wxDataInputStream
// extracted from datistrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAINPUTSTREAM_H__
#define __OBJECT_WX_DATAINPUTSTREAM_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDataInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDataInputStream *GetEntity() { return _pEntity; }
	inline wxDataInputStream *ReleaseEntity() {
		wxDataInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataInputStream");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
