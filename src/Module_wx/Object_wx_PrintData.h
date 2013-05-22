//----------------------------------------------------------------------------
// wxPrintData
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PRINTDATA_H__
#define __OBJECT_WX_PRINTDATA_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PrintData);

//----------------------------------------------------------------------------
// Object declaration for wxPrintData
//----------------------------------------------------------------------------
class Object_wx_PrintData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PrintData)
public:
	inline Object_wx_PrintData(wxPrintData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PrintData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PrintData(Class *pClass, wxPrintData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PrintData();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPrintData *GetEntity() {
		return dynamic_cast<wxPrintData *>(_pEntity);
	}
	inline wxPrintData *ReleaseEntity() {
		wxPrintData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPrintData");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
