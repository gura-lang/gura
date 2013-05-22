//----------------------------------------------------------------------------
// wxSocketInputStream
// extracted from strmsock.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SOCKETINPUTSTREAM_H__
#define __OBJECT_WX_SOCKETINPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxSocketInputStream
//----------------------------------------------------------------------------
class Object_wx_SocketInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_SocketInputStream)
public:
	inline Object_wx_SocketInputStream(wxSocketInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_SocketInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketInputStream(Class *pClass, wxSocketInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketInputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSocketInputStream *GetEntity() {
		return dynamic_cast<wxSocketInputStream *>(_pEntity);
	}
	inline wxSocketInputStream *ReleaseEntity() {
		wxSocketInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSocketInputStream");
		return true;
	}
};

}}

#endif
