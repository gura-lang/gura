//----------------------------------------------------------------------------
// wxArrayString
// extracted from arrstrng.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ARRAYSTRING_H__
#define __OBJECT_WX_ARRAYSTRING_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArrayString
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArrayString);

//----------------------------------------------------------------------------
// Object declaration for wxArrayString
//----------------------------------------------------------------------------
class Object_wx_ArrayString : public Object_wx_Array {
public:
	Gura_DeclareObjectAccessor(wx_ArrayString)
public:
	inline Object_wx_ArrayString(wxArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Array(Gura_UserClass(wx_ArrayString), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArrayString(Class *pClass, wxArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Array(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArrayString();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxArrayString *GetEntity() {
		return dynamic_cast<wxArrayString *>(_pEntity);
	}
	inline wxArrayString *ReleaseEntity() {
		wxArrayString *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxArrayString");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
