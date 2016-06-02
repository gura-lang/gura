//----------------------------------------------------------------------------
// wxCursor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CURSOR_H__
#define __CLASS_WX_CURSOR_H__
#include <wx/cursor.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCursor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Cursor);

//----------------------------------------------------------------------------
// Object declaration for wxCursor
//----------------------------------------------------------------------------
class Object_wx_Cursor : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Cursor)
public:
	inline Object_wx_Cursor(wxCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Cursor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Cursor(Class *pClass, wxCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Cursor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCursor *GetEntity() {
		return static_cast<wxCursor *>(_pEntity);
	}
	inline wxCursor *ReleaseEntity() {
		wxCursor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCursor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
