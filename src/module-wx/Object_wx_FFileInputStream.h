//----------------------------------------------------------------------------
// wxFFileInputStream
// extracted from ffilestr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FFILEINPUTSTREAM_H__
#define __OBJECT_WX_FFILEINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FFileInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFFileInputStream
//----------------------------------------------------------------------------
class Object_wx_FFileInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_FFileInputStream)
public:
	inline Object_wx_FFileInputStream(wxFFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_FFileInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FFileInputStream(Class *pClass, wxFFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FFileInputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFFileInputStream *GetEntity() {
		return dynamic_cast<wxFFileInputStream *>(_pEntity);
	}
	inline wxFFileInputStream *ReleaseEntity() {
		wxFFileInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFFileInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
