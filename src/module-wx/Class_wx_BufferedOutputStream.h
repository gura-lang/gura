//----------------------------------------------------------------------------
// wxBufferedOutputStream
// extracted from strmbfrd.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BUFFEREDOUTPUTSTREAM_H__
#define __CLASS_WX_BUFFEREDOUTPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BufferedOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxBufferedOutputStream
//----------------------------------------------------------------------------
class Object_wx_BufferedOutputStream : public Object_wx_FilterOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_BufferedOutputStream)
public:
	inline Object_wx_BufferedOutputStream(wxBufferedOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(Gura_UserClass(wx_BufferedOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BufferedOutputStream(Class *pClass, wxBufferedOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BufferedOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBufferedOutputStream *GetEntity() {
		return dynamic_cast<wxBufferedOutputStream *>(_pEntity);
	}
	inline wxBufferedOutputStream *ReleaseEntity() {
		wxBufferedOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBufferedOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
