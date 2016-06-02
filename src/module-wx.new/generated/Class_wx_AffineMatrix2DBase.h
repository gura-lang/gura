//----------------------------------------------------------------------------
// wxAffineMatrix2DBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AFFINEMATRIX2DBASE_H__
#define __CLASS_WX_AFFINEMATRIX2DBASE_H__
#include <wx/affinematrix2dbase.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AffineMatrix2DBase);

//----------------------------------------------------------------------------
// Object declaration for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
class Object_wx_AffineMatrix2DBase : public Object {
protected:
	wxAffineMatrix2DBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AffineMatrix2DBase)
public:
	inline Object_wx_AffineMatrix2DBase(wxAffineMatrix2DBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AffineMatrix2DBase(Class *pClass, wxAffineMatrix2DBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AffineMatrix2DBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAffineMatrix2DBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAffineMatrix2DBase *GetEntity() {
		return static_cast<wxAffineMatrix2DBase *>(_pEntity);
	}
	inline wxAffineMatrix2DBase *ReleaseEntity() {
		wxAffineMatrix2DBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAffineMatrix2DBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
