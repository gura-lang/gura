//----------------------------------------------------------------------------
// wxOutputStream
// extracted from outptstr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_OUTPUTSTREAM_H__
#define __OBJECT_WX_OUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_OutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxOutputStream
//----------------------------------------------------------------------------
class Object_wx_OutputStream : public Object_wx_StreamBase {
public:
	Gura_DeclareObjectAccessor(wx_OutputStream)
public:
	inline Object_wx_OutputStream(wxOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_StreamBase(Gura_UserClass(wx_OutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_OutputStream(Class *pClass, wxOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_StreamBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_OutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxOutputStream *GetEntity() {
		return dynamic_cast<wxOutputStream *>(_pEntity);
	}
	inline wxOutputStream *ReleaseEntity() {
		wxOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxOutputStream");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
