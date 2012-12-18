//----------------------------------------------------------------------------
// wxLanguageInfo
// (handcoded)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LANGUAGEINFO_H__
#define __OBJECT_WX_LANGUAGEINFO_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLanguageInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LanguageInfo);

//----------------------------------------------------------------------------
// Object declaration for wxLanguageInfo
//----------------------------------------------------------------------------
class Object_wx_LanguageInfo : public Object {
protected:
	wxLanguageInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_LanguageInfo)
public:
	inline Object_wx_LanguageInfo(wxLanguageInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_LanguageInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_LanguageInfo(Class *pClass, wxLanguageInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_LanguageInfo();
	virtual Object *Clone() const;
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxLanguageInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxLanguageInfo *GetEntity() { return _pEntity; }
	inline wxLanguageInfo *ReleaseEntity() {
		wxLanguageInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLanguageInfo");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
