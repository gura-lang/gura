//----------------------------------------------------------------------------
// wxClientData
// extracted from clientdat.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CLIENTDATA_H__
#define __OBJECT_WX_CLIENTDATA_H__

Gura_BeginModule(wx)

class Object_wx_ClientData;

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClientData: public wxClientData, public GuraObjectObserver {
private:
	Value _value;
	Gura::Signal _sig;
	Object_wx_ClientData *_pObj;
public:
	inline wx_ClientData(const Value &value) : wxClientData(),
						_value(value), _sig(NULL), _pObj(NULL) {}
	inline wx_ClientData(const wx_ClientData &clientData) : wxClientData(clientData),
						_value(clientData._value), _sig(clientData._sig), _pObj(NULL) {}
	~wx_ClientData();
	inline const Value &GetValue() { return _value; }
	inline void SetValue(const Value &value) { _value = value; }
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ClientData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

//----------------------------------------------------------------------------
// Class declaration for wxClientData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientData);

//----------------------------------------------------------------------------
// Object declaration for wxClientData
//----------------------------------------------------------------------------
class Object_wx_ClientData : public Object {
protected:
	wx_ClientData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ClientData)
public:
	inline Object_wx_ClientData(wx_ClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ClientData)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ClientData(Class *pClass, wx_ClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ClientData();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wx_ClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wx_ClientData *GetEntity() { return _pEntity; }
	inline wx_ClientData *ReleaseEntity() {
		wx_ClientData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxClientData");
		return true;
	}
};

}}

#endif
