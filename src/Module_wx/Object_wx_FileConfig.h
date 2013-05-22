//----------------------------------------------------------------------------
// wxFileConfig
// extracted from fileconf.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILECONFIG_H__
#define __OBJECT_WX_FILECONFIG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileConfig
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileConfig);

//----------------------------------------------------------------------------
// Object declaration for wxFileConfig
//----------------------------------------------------------------------------
class Object_wx_FileConfig : public Object_wx_ConfigBase {
public:
	Gura_DeclareObjectAccessor(wx_FileConfig)
public:
	inline Object_wx_FileConfig(wxFileConfig *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConfigBase(Gura_UserClass(wx_FileConfig), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileConfig(Class *pClass, wxFileConfig *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConfigBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileConfig();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFileConfig *GetEntity() {
		return dynamic_cast<wxFileConfig *>(_pEntity);
	}
	inline wxFileConfig *ReleaseEntity() {
		wxFileConfig *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileConfig");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
