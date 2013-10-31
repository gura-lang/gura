//----------------------------------------------------------------------------
// wxCursor
// extracted from cursor.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CURSOR_H__
#define __OBJECT_WX_CURSOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCursor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Cursor);

//----------------------------------------------------------------------------
// Object declaration for wxCursor
//----------------------------------------------------------------------------
class Object_wx_Cursor : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Cursor)
public:
	inline Object_wx_Cursor(wxCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Cursor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Cursor(Class *pClass, wxCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Cursor();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCursor *GetEntity() {
		return dynamic_cast<wxCursor *>(_pEntity);
	}
	inline wxCursor *ReleaseEntity() {
		wxCursor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCursor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
