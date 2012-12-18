//----------------------------------------------------------------------------
// wxFilterOutputStream
// extracted from fltoutst.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILTEROUTPUTSTREAM_H__
#define __OBJECT_WX_FILTEROUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFilterOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FilterOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFilterOutputStream
//----------------------------------------------------------------------------
class Object_wx_FilterOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_FilterOutputStream)
public:
	inline Object_wx_FilterOutputStream(wxFilterOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_FilterOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FilterOutputStream(Class *pClass, wxFilterOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FilterOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFilterOutputStream *GetEntity() {
		return dynamic_cast<wxFilterOutputStream *>(_pEntity);
	}
	inline wxFilterOutputStream *ReleaseEntity() {
		wxFilterOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFilterOutputStream");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
