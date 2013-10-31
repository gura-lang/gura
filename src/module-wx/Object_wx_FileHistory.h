//----------------------------------------------------------------------------
// wxFileHistory
// extracted from filehist.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILEHISTORY_H__
#define __OBJECT_WX_FILEHISTORY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileHistory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileHistory);

//----------------------------------------------------------------------------
// Object declaration for wxFileHistory
//----------------------------------------------------------------------------
class Object_wx_FileHistory : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FileHistory)
public:
	inline Object_wx_FileHistory(wxFileHistory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FileHistory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileHistory(Class *pClass, wxFileHistory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileHistory();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFileHistory *GetEntity() {
		return dynamic_cast<wxFileHistory *>(_pEntity);
	}
	inline wxFileHistory *ReleaseEntity() {
		wxFileHistory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileHistory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
