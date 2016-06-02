//----------------------------------------------------------------------------
// wxGLAttribsBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GLATTRIBSBASE_H__
#define __CLASS_WX_GLATTRIBSBASE_H__
#include <wx/glcanvas.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGLAttribsBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GLAttribsBase);

//----------------------------------------------------------------------------
// Object declaration for wxGLAttribsBase
//----------------------------------------------------------------------------
class Object_wx_GLAttribsBase : public Object {
protected:
	wxGLAttribsBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GLAttribsBase)
public:
	inline Object_wx_GLAttribsBase(wxGLAttribsBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GLAttribsBase(Class *pClass, wxGLAttribsBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GLAttribsBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGLAttribsBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGLAttribsBase *GetEntity() {
		return static_cast<wxGLAttribsBase *>(_pEntity);
	}
	inline wxGLAttribsBase *ReleaseEntity() {
		wxGLAttribsBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGLAttribsBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
