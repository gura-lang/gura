//----------------------------------------------------------------------------
// wxRichTextPrintout
// extracted from richtextprintout.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTPRINTOUT_H__
#define __OBJECT_WX_RICHTEXTPRINTOUT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextPrintout
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextPrintout);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextPrintout
//----------------------------------------------------------------------------
class Object_wx_RichTextPrintout : public Object_wx_Printout {
public:
	Gura_DeclareObjectAccessor(wx_RichTextPrintout)
public:
	inline Object_wx_RichTextPrintout(wxRichTextPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(Gura_UserClass(wx_RichTextPrintout), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextPrintout(Class *pClass, wxRichTextPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextPrintout();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextPrintout *GetEntity() {
		return dynamic_cast<wxRichTextPrintout *>(_pEntity);
	}
	inline wxRichTextPrintout *ReleaseEntity() {
		wxRichTextPrintout *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextPrintout");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
