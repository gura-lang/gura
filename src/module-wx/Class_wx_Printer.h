//----------------------------------------------------------------------------
// wxPrinter
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PRINTER_H__
#define __CLASS_WX_PRINTER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrinter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Printer);

//----------------------------------------------------------------------------
// Object declaration for wxPrinter
//----------------------------------------------------------------------------
class Object_wx_Printer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Printer)
public:
	inline Object_wx_Printer(wxPrinter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Printer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Printer(Class *pClass, wxPrinter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Printer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPrinter *GetEntity() {
		return dynamic_cast<wxPrinter *>(_pEntity);
	}
	inline wxPrinter *ReleaseEntity() {
		wxPrinter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPrinter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
