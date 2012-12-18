//----------------------------------------------------------------------------
// wxPostScriptDC
// extracted from postscpt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_POSTSCRIPTDC_H__
#define __OBJECT_WX_POSTSCRIPTDC_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PostScriptDC);

//----------------------------------------------------------------------------
// Object declaration for wxPostScriptDC
//----------------------------------------------------------------------------
class Object_wx_PostScriptDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_PostScriptDC)
public:
	inline Object_wx_PostScriptDC(wxPostScriptDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_PostScriptDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PostScriptDC(Class *pClass, wxPostScriptDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PostScriptDC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPostScriptDC *GetEntity() {
		return dynamic_cast<wxPostScriptDC *>(_pEntity);
	}
	inline wxPostScriptDC *ReleaseEntity() {
		wxPostScriptDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPostScriptDC");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
