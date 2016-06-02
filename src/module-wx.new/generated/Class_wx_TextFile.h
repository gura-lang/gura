//----------------------------------------------------------------------------
// wxTextFile
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTFILE_H__
#define __CLASS_WX_TEXTFILE_H__
#include <wx/textfile.h>

Gura_BeginModuleScope(wx)

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
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextFile(Class *pClass, wxTextFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextFile();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextFile *GetEntity() {
		return static_cast<wxTextFile *>(_pEntity);
	}
	inline wxTextFile *ReleaseEntity() {
		wxTextFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextFile");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
