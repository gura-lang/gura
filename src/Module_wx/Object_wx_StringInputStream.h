//----------------------------------------------------------------------------
// wxStringInputStream
// extracted from sistream.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STRINGINPUTSTREAM_H__
#define __OBJECT_WX_STRINGINPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxStringInputStream
//----------------------------------------------------------------------------
class Object_wx_StringInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_StringInputStream)
public:
	inline Object_wx_StringInputStream(wxStringInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_StringInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StringInputStream(Class *pClass, wxStringInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StringInputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStringInputStream *GetEntity() {
		return dynamic_cast<wxStringInputStream *>(_pEntity);
	}
	inline wxStringInputStream *ReleaseEntity() {
		wxStringInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStringInputStream");
		return true;
	}
};

}}

#endif
