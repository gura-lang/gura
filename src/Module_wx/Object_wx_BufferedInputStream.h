//----------------------------------------------------------------------------
// wxBufferedInputStream
// extracted from strmbfrd.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BUFFEREDINPUTSTREAM_H__
#define __OBJECT_WX_BUFFEREDINPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBufferedInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BufferedInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxBufferedInputStream
//----------------------------------------------------------------------------
class Object_wx_BufferedInputStream : public Object_wx_FilterInputStream {
public:
	Gura_DeclareObjectAccessor(wx_BufferedInputStream)
public:
	inline Object_wx_BufferedInputStream(wxBufferedInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(Gura_UserClass(wx_BufferedInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BufferedInputStream(Class *pClass, wxBufferedInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BufferedInputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBufferedInputStream *GetEntity() {
		return dynamic_cast<wxBufferedInputStream *>(_pEntity);
	}
	inline wxBufferedInputStream *ReleaseEntity() {
		wxBufferedInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBufferedInputStream");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
