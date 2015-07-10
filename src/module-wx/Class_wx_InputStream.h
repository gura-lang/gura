//----------------------------------------------------------------------------
// wxInputStream
// extracted from inputstr.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_INPUTSTREAM_H__
#define __CLASS_WX_INPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_InputStream);

//----------------------------------------------------------------------------
// Object declaration for wxInputStream
//----------------------------------------------------------------------------
class Object_wx_InputStream : public Object_wx_StreamBase {
public:
	Gura_DeclareObjectAccessor(wx_InputStream)
public:
	inline Object_wx_InputStream(wxInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_StreamBase(Gura_UserClass(wx_InputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_InputStream(Class *pClass, wxInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_StreamBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_InputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxInputStream *GetEntity() {
		return dynamic_cast<wxInputStream *>(_pEntity);
	}
	inline wxInputStream *ReleaseEntity() {
		wxInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
