//----------------------------------------------------------------------------
// wxStringTokenizer
// extracted from tokenizr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STRINGTOKENIZER_H__
#define __OBJECT_WX_STRINGTOKENIZER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringTokenizer);

//----------------------------------------------------------------------------
// Object declaration for wxStringTokenizer
//----------------------------------------------------------------------------
class Object_wx_StringTokenizer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_StringTokenizer)
public:
	inline Object_wx_StringTokenizer(wxStringTokenizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_StringTokenizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StringTokenizer(Class *pClass, wxStringTokenizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StringTokenizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStringTokenizer *GetEntity() {
		return dynamic_cast<wxStringTokenizer *>(_pEntity);
	}
	inline wxStringTokenizer *ReleaseEntity() {
		wxStringTokenizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStringTokenizer");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
