//----------------------------------------------------------------------------
// wxSize
// extracted from size.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SIZE_H__
#define __OBJECT_WX_SIZE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSize
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Size);

//----------------------------------------------------------------------------
// Object declaration for wxSize
//----------------------------------------------------------------------------
class Object_wx_Size : public Object {
protected:
	wxSize *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Size)
public:
	inline Object_wx_Size(wxSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Size)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Size(Class *pClass, wxSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Size();
	virtual Object *Clone() const;
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxSize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxSize *GetEntity() { return _pEntity; }
	inline wxSize *ReleaseEntity() {
		wxSize *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSize");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
