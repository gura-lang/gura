//----------------------------------------------------------------------------
// wxTextFile
// extracted from textfile.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TEXTFILE_H__
#define __OBJECT_WX_TEXTFILE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextFile);

//----------------------------------------------------------------------------
// Object declaration for wxTextFile
//----------------------------------------------------------------------------
class Object_wx_TextFile : public Object {
protected:
	wxTextFile *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextFile)
public:
	inline Object_wx_TextFile(wxTextFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TextFile)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextFile(Class *pClass, wxTextFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextFile();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxTextFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTextFile *GetEntity() { return _pEntity; }
	inline wxTextFile *ReleaseEntity() {
		wxTextFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextFile");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
