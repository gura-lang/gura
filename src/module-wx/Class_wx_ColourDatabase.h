//----------------------------------------------------------------------------
// wxColourDatabase
// extracted from colour.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLOURDATABASE_H__
#define __CLASS_WX_COLOURDATABASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColourDatabase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ColourDatabase);

//----------------------------------------------------------------------------
// Object declaration for wxColourDatabase
//----------------------------------------------------------------------------
class Object_wx_ColourDatabase : public Object {
protected:
	wxColourDatabase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ColourDatabase)
public:
	inline Object_wx_ColourDatabase(wxColourDatabase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ColourDatabase)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ColourDatabase(Class *pClass, wxColourDatabase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ColourDatabase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxColourDatabase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxColourDatabase *GetEntity() { return _pEntity; }
	inline wxColourDatabase *ReleaseEntity() {
		wxColourDatabase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxColourDatabase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
