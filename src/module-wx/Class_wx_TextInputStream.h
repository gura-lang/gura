//----------------------------------------------------------------------------
// wxTextInputStream
// extracted from txtstrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTINPUTSTREAM_H__
#define __CLASS_WX_TEXTINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxTextInputStream
//----------------------------------------------------------------------------
class Object_wx_TextInputStream : public Object {
protected:
	wxTextInputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextInputStream)
public:
	inline Object_wx_TextInputStream(wxTextInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TextInputStream)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextInputStream(Class *pClass, wxTextInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextInputStream *GetEntity() { return _pEntity; }
	inline wxTextInputStream *ReleaseEntity() {
		wxTextInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
