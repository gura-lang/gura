//----------------------------------------------------------------------------
// wxStaticBox
// extracted from statbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STATICBOX_H__
#define __OBJECT_WX_STATICBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticBox);

//----------------------------------------------------------------------------
// Object declaration for wxStaticBox
//----------------------------------------------------------------------------
class Object_wx_StaticBox : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StaticBox)
public:
	inline Object_wx_StaticBox(wxStaticBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StaticBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticBox(Class *pClass, wxStaticBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStaticBox *GetEntity() {
		return dynamic_cast<wxStaticBox *>(_pEntity);
	}
	inline wxStaticBox *ReleaseEntity() {
		wxStaticBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStaticBox");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
