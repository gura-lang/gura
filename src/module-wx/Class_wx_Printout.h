//----------------------------------------------------------------------------
// wxPrintout
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PRINTOUT_H__
#define __CLASS_WX_PRINTOUT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintout
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Printout);

//----------------------------------------------------------------------------
// Object declaration for wxPrintout
//----------------------------------------------------------------------------
class Object_wx_Printout : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Printout)
public:
	inline Object_wx_Printout(wxPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Printout), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Printout(Class *pClass, wxPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Printout();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPrintout *GetEntity() {
		return dynamic_cast<wxPrintout *>(_pEntity);
	}
	inline wxPrintout *ReleaseEntity() {
		wxPrintout *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPrintout");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
