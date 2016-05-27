//----------------------------------------------------------------------------
// wxLogInterposer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGINTERPOSER_H__
#define __CLASS_WX_LOGINTERPOSER_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogInterposer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogInterposer);

//----------------------------------------------------------------------------
// Object declaration for wxLogInterposer
//----------------------------------------------------------------------------
class Object_wx_LogInterposer : public Object_wx_LogChain {
public:
	Gura_DeclareObjectAccessor(wx_LogInterposer)
public:
	inline Object_wx_LogInterposer(wxLogInterposer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(Gura_UserClass(wx_LogInterposer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogInterposer(Class *pClass, wxLogInterposer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogChain(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogInterposer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogInterposer *GetEntity() {
		return static_cast<wxLogInterposer *>(_pEntity);
	}
	inline wxLogInterposer *ReleaseEntity() {
		wxLogInterposer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogInterposer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
