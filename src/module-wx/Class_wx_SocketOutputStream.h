//----------------------------------------------------------------------------
// wxSocketOutputStream
// extracted from strmsock.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SOCKETOUTPUTSTREAM_H__
#define __CLASS_WX_SOCKETOUTPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxSocketOutputStream
//----------------------------------------------------------------------------
class Object_wx_SocketOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_SocketOutputStream)
public:
	inline Object_wx_SocketOutputStream(wxSocketOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_SocketOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketOutputStream(Class *pClass, wxSocketOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSocketOutputStream *GetEntity() {
		return dynamic_cast<wxSocketOutputStream *>(_pEntity);
	}
	inline wxSocketOutputStream *ReleaseEntity() {
		wxSocketOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSocketOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
