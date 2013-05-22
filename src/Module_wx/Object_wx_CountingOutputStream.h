//----------------------------------------------------------------------------
// wxCountingOutputStream
// extracted from countstr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COUNTINGOUTPUTSTREAM_H__
#define __OBJECT_WX_COUNTINGOUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CountingOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxCountingOutputStream
//----------------------------------------------------------------------------
class Object_wx_CountingOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_CountingOutputStream)
public:
	inline Object_wx_CountingOutputStream(wxCountingOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_CountingOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CountingOutputStream(Class *pClass, wxCountingOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CountingOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCountingOutputStream *GetEntity() {
		return dynamic_cast<wxCountingOutputStream *>(_pEntity);
	}
	inline wxCountingOutputStream *ReleaseEntity() {
		wxCountingOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCountingOutputStream");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
