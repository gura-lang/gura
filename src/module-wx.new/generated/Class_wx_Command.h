//----------------------------------------------------------------------------
// wxCommand
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMMAND_H__
#define __CLASS_WX_COMMAND_H__
#include <wx/cmdproc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCommand
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Command);

//----------------------------------------------------------------------------
// Object declaration for wxCommand
//----------------------------------------------------------------------------
class Object_wx_Command : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Command)
public:
	inline Object_wx_Command(wxCommand *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Command), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Command(Class *pClass, wxCommand *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Command();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCommand *GetEntity() {
		return static_cast<wxCommand *>(_pEntity);
	}
	inline wxCommand *ReleaseEntity() {
		wxCommand *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCommand");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
