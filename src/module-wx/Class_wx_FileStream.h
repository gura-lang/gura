//----------------------------------------------------------------------------
// wxFileStream
// extracted from filestrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILESTREAM_H__
#define __CLASS_WX_FILESTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileStream);

//----------------------------------------------------------------------------
// Object declaration for wxFileStream
//----------------------------------------------------------------------------
class Object_wx_FileStream : public Object_wx_FileOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_FileStream)
public:
	inline Object_wx_FileStream(wxFileStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileOutputStream(Gura_UserClass(wx_FileStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileStream(Class *pClass, wxFileStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileStream *GetEntity() {
		return dynamic_cast<wxFileStream *>(_pEntity);
	}
	inline wxFileStream *ReleaseEntity() {
		wxFileStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
