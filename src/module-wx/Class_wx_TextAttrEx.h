//----------------------------------------------------------------------------
// wxTextAttrEx
// extracted from textattrex.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TEXTATTREX_H__
#define __OBJECT_WX_TEXTATTREX_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrEx
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrEx);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrEx
//----------------------------------------------------------------------------
class Object_wx_TextAttrEx : public Object_wx_TextAttr {
public:
	Gura_DeclareObjectAccessor(wx_TextAttrEx)
public:
	inline Object_wx_TextAttrEx(wxTextAttrEx *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextAttr(Gura_UserClass(wx_TextAttrEx), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextAttrEx(Class *pClass, wxTextAttrEx *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextAttr(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextAttrEx();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextAttrEx *GetEntity() {
		return static_cast<wxTextAttrEx *>(_pEntity);
	}
	inline wxTextAttrEx *ReleaseEntity() {
		wxTextAttrEx *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrEx");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
