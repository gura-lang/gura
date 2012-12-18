//----------------------------------------------------------------------------
// wxBoxSizer
// extracted from boxsizer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BOXSIZER_H__
#define __OBJECT_WX_BOXSIZER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBoxSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BoxSizer);

//----------------------------------------------------------------------------
// Object declaration for wxBoxSizer
//----------------------------------------------------------------------------
class Object_wx_BoxSizer : public Object_wx_Sizer {
public:
	Gura_DeclareObjectAccessor(wx_BoxSizer)
public:
	inline Object_wx_BoxSizer(wxBoxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(Gura_UserClass(wx_BoxSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BoxSizer(Class *pClass, wxBoxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BoxSizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBoxSizer *GetEntity() {
		return dynamic_cast<wxBoxSizer *>(_pEntity);
	}
	inline wxBoxSizer *ReleaseEntity() {
		wxBoxSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBoxSizer");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
