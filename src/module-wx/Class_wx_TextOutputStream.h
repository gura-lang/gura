//----------------------------------------------------------------------------
// wxTextOutputStream
// extracted from txtstrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTOUTPUTSTREAM_H__
#define __CLASS_WX_TEXTOUTPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxTextOutputStream
//----------------------------------------------------------------------------
class Object_wx_TextOutputStream : public Object {
protected:
	wxTextOutputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextOutputStream)
public:
	inline Object_wx_TextOutputStream(wxTextOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TextOutputStream)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextOutputStream(Class *pClass, wxTextOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTextOutputStream *GetEntity() { return _pEntity; }
	inline wxTextOutputStream *ReleaseEntity() {
		wxTextOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
