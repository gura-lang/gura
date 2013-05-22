//----------------------------------------------------------------------------
// wxStringOutputStream
// extracted from sostream.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STRINGOUTPUTSTREAM_H__
#define __OBJECT_WX_STRINGOUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxStringOutputStream
//----------------------------------------------------------------------------
class Object_wx_StringOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_StringOutputStream)
public:
	inline Object_wx_StringOutputStream(wxStringOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_StringOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StringOutputStream(Class *pClass, wxStringOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StringOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStringOutputStream *GetEntity() {
		return dynamic_cast<wxStringOutputStream *>(_pEntity);
	}
	inline wxStringOutputStream *ReleaseEntity() {
		wxStringOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStringOutputStream");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
