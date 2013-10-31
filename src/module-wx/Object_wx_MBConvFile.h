//----------------------------------------------------------------------------
// wxMBConvFile
// extracted from mbcnvfil.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MBCONVFILE_H__
#define __OBJECT_WX_MBCONVFILE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConvFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConvFile);

//----------------------------------------------------------------------------
// Object declaration for wxMBConvFile
//----------------------------------------------------------------------------
class Object_wx_MBConvFile : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_MBConvFile)
public:
	inline Object_wx_MBConvFile(wxMBConvFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_MBConvFile), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MBConvFile(Class *pClass, wxMBConvFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MBConvFile();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMBConvFile *GetEntity() {
		return dynamic_cast<wxMBConvFile *>(_pEntity);
	}
	inline wxMBConvFile *ReleaseEntity() {
		wxMBConvFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMBConvFile");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
