//----------------------------------------------------------------------------
// wxPGEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGEDITOR_H__
#define __CLASS_WX_PGEDITOR_H__
#include <wx/propgrid/editors.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGEditor);

//----------------------------------------------------------------------------
// Object declaration for wxPGEditor
//----------------------------------------------------------------------------
class Object_wx_PGEditor : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PGEditor)
public:
	inline Object_wx_PGEditor(wxPGEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PGEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PGEditor(Class *pClass, wxPGEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PGEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPGEditor *GetEntity() {
		return static_cast<wxPGEditor *>(_pEntity);
	}
	inline wxPGEditor *ReleaseEntity() {
		wxPGEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPGEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
