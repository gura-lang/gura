//----------------------------------------------------------------------------
// wxFTP
// extracted from ftp.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FTP_H__
#define __CLASS_WX_FTP_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFTP
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FTP);

//----------------------------------------------------------------------------
// Object declaration for wxFTP
//----------------------------------------------------------------------------
class Object_wx_FTP : public Object_wx_Protocol {
public:
	Gura_DeclareObjectAccessor(wx_FTP)
public:
	inline Object_wx_FTP(wxFTP *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Protocol(Gura_UserClass(wx_FTP), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FTP(Class *pClass, wxFTP *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Protocol(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FTP();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFTP *GetEntity() {
		return dynamic_cast<wxFTP *>(_pEntity);
	}
	inline wxFTP *ReleaseEntity() {
		wxFTP *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFTP");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
