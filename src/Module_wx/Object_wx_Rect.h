//----------------------------------------------------------------------------
// wxRect
// extracted from rect.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RECT_H__
#define __OBJECT_WX_RECT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRect
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Rect);

//----------------------------------------------------------------------------
// Object declaration for wxRect
//----------------------------------------------------------------------------
class Object_wx_Rect : public Object {
protected:
	wxRect *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Rect)
public:
	inline Object_wx_Rect(wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Rect)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Rect(Class *pClass, wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Rect();
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRect *GetEntity() { return _pEntity; }
	inline wxRect *ReleaseEntity() {
		wxRect *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRect");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
