//----------------------------------------------------------------------------
// wxMessageOutputBest
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEOUTPUTBEST_H__
#define __CLASS_WX_MESSAGEOUTPUTBEST_H__
#include <wx/msgout.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageOutputBest
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageOutputBest);

//----------------------------------------------------------------------------
// Object declaration for wxMessageOutputBest
//----------------------------------------------------------------------------
class Object_wx_MessageOutputBest : public Object_wx_MessageOutputStderr {
public:
	Gura_DeclareObjectAccessor(wx_MessageOutputBest)
public:
	inline Object_wx_MessageOutputBest(wxMessageOutputBest *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutputStderr(Gura_UserClass(wx_MessageOutputBest), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MessageOutputBest(Class *pClass, wxMessageOutputBest *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MessageOutputStderr(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MessageOutputBest();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMessageOutputBest *GetEntity() {
		return static_cast<wxMessageOutputBest *>(_pEntity);
	}
	inline wxMessageOutputBest *ReleaseEntity() {
		wxMessageOutputBest *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMessageOutputBest");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
