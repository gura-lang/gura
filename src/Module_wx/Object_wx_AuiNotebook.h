//----------------------------------------------------------------------------
// wxAuiNotebook
// extracted from auinotebook.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_AUINOTEBOOK_H__
#define __OBJECT_WX_AUINOTEBOOK_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiNotebook);

//----------------------------------------------------------------------------
// Object declaration for wxAuiNotebook
//----------------------------------------------------------------------------
class Object_wx_AuiNotebook : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_AuiNotebook)
public:
	inline Object_wx_AuiNotebook(wxAuiNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_AuiNotebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiNotebook(Class *pClass, wxAuiNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiNotebook();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAuiNotebook *GetEntity() {
		return dynamic_cast<wxAuiNotebook *>(_pEntity);
	}
	inline wxAuiNotebook *ReleaseEntity() {
		wxAuiNotebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAuiNotebook");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
