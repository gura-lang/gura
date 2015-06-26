//----------------------------------------------------------------------------
// wxCaret
// extracted from caret.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CARET_H__
#define __CLASS_WX_CARET_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCaret
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Caret);

//----------------------------------------------------------------------------
// Object declaration for wxCaret
//----------------------------------------------------------------------------
class Object_wx_Caret : public Object {
protected:
	wxCaret *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Caret)
public:
	inline Object_wx_Caret(wxCaret *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Caret)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Caret(Class *pClass, wxCaret *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Caret();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCaret *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCaret *GetEntity() { return _pEntity; }
	inline wxCaret *ReleaseEntity() {
		wxCaret *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCaret");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
