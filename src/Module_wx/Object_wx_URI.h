//----------------------------------------------------------------------------
// wxURI
// extracted from uri.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_URI_H__
#define __OBJECT_WX_URI_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxURI
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_URI);

//----------------------------------------------------------------------------
// Object declaration for wxURI
//----------------------------------------------------------------------------
class Object_wx_URI : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_URI)
public:
	inline Object_wx_URI(wxURI *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_URI), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_URI(Class *pClass, wxURI *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_URI();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxURI *GetEntity() {
		return dynamic_cast<wxURI *>(_pEntity);
	}
	inline wxURI *ReleaseEntity() {
		wxURI *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxURI");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
