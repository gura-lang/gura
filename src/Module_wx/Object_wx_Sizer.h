//----------------------------------------------------------------------------
// wxSizer
// extracted from sizer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SIZER_H__
#define __OBJECT_WX_SIZER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Sizer);

//----------------------------------------------------------------------------
// Object declaration for wxSizer
//----------------------------------------------------------------------------
class Object_wx_Sizer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Sizer)
public:
	inline Object_wx_Sizer(wxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Sizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Sizer(Class *pClass, wxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Sizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSizer *GetEntity() {
		return dynamic_cast<wxSizer *>(_pEntity);
	}
	inline wxSizer *ReleaseEntity() {
		wxSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSizer");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
