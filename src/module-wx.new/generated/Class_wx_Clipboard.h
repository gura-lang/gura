//----------------------------------------------------------------------------
// wxClipboard
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIPBOARD_H__
#define __CLASS_WX_CLIPBOARD_H__
#include <wx/clipbrd.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClipboard
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Clipboard);

//----------------------------------------------------------------------------
// Object declaration for wxClipboard
//----------------------------------------------------------------------------
class Object_wx_Clipboard : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Clipboard)
public:
	inline Object_wx_Clipboard(wxClipboard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Clipboard), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Clipboard(Class *pClass, wxClipboard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Clipboard();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxClipboard *GetEntity() {
		return static_cast<wxClipboard *>(_pEntity);
	}
	inline wxClipboard *ReleaseEntity() {
		wxClipboard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxClipboard");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
