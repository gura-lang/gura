//----------------------------------------------------------------------------
// wxMiniFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MINIFRAME_H__
#define __CLASS_WX_MINIFRAME_H__
#include <wx/minifram.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMiniFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MiniFrame);

//----------------------------------------------------------------------------
// Object declaration for wxMiniFrame
//----------------------------------------------------------------------------
class Object_wx_MiniFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_MiniFrame)
public:
	inline Object_wx_MiniFrame(wxMiniFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_MiniFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MiniFrame(Class *pClass, wxMiniFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MiniFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMiniFrame *GetEntity() {
		return static_cast<wxMiniFrame *>(_pEntity);
	}
	inline wxMiniFrame *ReleaseEntity() {
		wxMiniFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMiniFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
