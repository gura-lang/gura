//----------------------------------------------------------------------------
// wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCORNERHEADERRENDERER_H__
#define __CLASS_WX_GRIDCORNERHEADERRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCornerHeaderRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCornerHeaderRenderer : public Object {
protected:
	wxGridCornerHeaderRenderer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridCornerHeaderRenderer)
public:
	inline Object_wx_GridCornerHeaderRenderer(wxGridCornerHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridCornerHeaderRenderer(Class *pClass, wxGridCornerHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridCornerHeaderRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGridCornerHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGridCornerHeaderRenderer *GetEntity() {
		return static_cast<wxGridCornerHeaderRenderer *>(_pEntity);
	}
	inline wxGridCornerHeaderRenderer *ReleaseEntity() {
		wxGridCornerHeaderRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCornerHeaderRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
