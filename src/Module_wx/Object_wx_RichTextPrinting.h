//----------------------------------------------------------------------------
// wxRichTextPrinting
// extracted from richtextprinting.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTPRINTING_H__
#define __OBJECT_WX_RICHTEXTPRINTING_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextPrinting);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextPrinting
//----------------------------------------------------------------------------
class Object_wx_RichTextPrinting : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextPrinting)
public:
	inline Object_wx_RichTextPrinting(wxRichTextPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextPrinting), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextPrinting(Class *pClass, wxRichTextPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextPrinting();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextPrinting *GetEntity() {
		return dynamic_cast<wxRichTextPrinting *>(_pEntity);
	}
	inline wxRichTextPrinting *ReleaseEntity() {
		wxRichTextPrinting *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextPrinting");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
