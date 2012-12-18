//----------------------------------------------------------------------------
// wxStdDialogButtonSizer
// extracted from stdbtnsz.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STDDIALOGBUTTONSIZER_H__
#define __OBJECT_WX_STDDIALOGBUTTONSIZER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StdDialogButtonSizer);

//----------------------------------------------------------------------------
// Object declaration for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
class Object_wx_StdDialogButtonSizer : public Object_wx_BoxSizer {
public:
	Gura_DeclareObjectAccessor(wx_StdDialogButtonSizer)
public:
	inline Object_wx_StdDialogButtonSizer(wxStdDialogButtonSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(Gura_UserClass(wx_StdDialogButtonSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StdDialogButtonSizer(Class *pClass, wxStdDialogButtonSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StdDialogButtonSizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStdDialogButtonSizer *GetEntity() {
		return dynamic_cast<wxStdDialogButtonSizer *>(_pEntity);
	}
	inline wxStdDialogButtonSizer *ReleaseEntity() {
		wxStdDialogButtonSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStdDialogButtonSizer");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
