//----------------------------------------------------------------------------
// wxLogInterposerTemp
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGINTERPOSERTEMP_H__
#define __CLASS_WX_LOGINTERPOSERTEMP_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogInterposerTemp
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogInterposerTemp);

//----------------------------------------------------------------------------
// Object declaration for wxLogInterposerTemp
//----------------------------------------------------------------------------
class Object_wx_LogInterposerTemp : public Object_wx_LogChain {
public:
	Gura_DeclareObjectAccessor(wx_LogInterposerTemp)
public:
	inline Object_wx_LogInterposerTemp(wxLogInterposerTemp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(Gura_UserClass(wx_LogInterposerTemp), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogInterposerTemp(Class *pClass, wxLogInterposerTemp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogInterposerTemp();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogInterposerTemp *GetEntity() {
		return static_cast<wxLogInterposerTemp *>(_pEntity);
	}
	inline wxLogInterposerTemp *ReleaseEntity() {
		wxLogInterposerTemp *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxLogInterposerTemp");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
