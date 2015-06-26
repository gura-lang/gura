//----------------------------------------------------------------------------
// wxClipboard
// extracted from clipbrd.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIPBOARD_H__
#define __CLASS_WX_CLIPBOARD_H__

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
		return dynamic_cast<wxClipboard *>(_pEntity);
	}
	inline wxClipboard *ReleaseEntity() {
		wxClipboard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClipboard");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
