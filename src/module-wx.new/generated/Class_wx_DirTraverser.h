//----------------------------------------------------------------------------
// wxDirTraverser
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIRTRAVERSER_H__
#define __CLASS_WX_DIRTRAVERSER_H__
#include <wx/dir.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDirTraverser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DirTraverser);

//----------------------------------------------------------------------------
// Object declaration for wxDirTraverser
//----------------------------------------------------------------------------
class Object_wx_DirTraverser : public Object {
protected:
	wxDirTraverser *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DirTraverser)
public:
	inline Object_wx_DirTraverser(wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DirTraverser(Class *pClass, wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DirTraverser();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDirTraverser *GetEntity() {
		return static_cast<wxDirTraverser *>(_pEntity);
	}
	inline wxDirTraverser *ReleaseEntity() {
		wxDirTraverser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDirTraverser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
