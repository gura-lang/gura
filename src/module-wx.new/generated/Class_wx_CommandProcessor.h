//----------------------------------------------------------------------------
// wxCommandProcessor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMMANDPROCESSOR_H__
#define __CLASS_WX_COMMANDPROCESSOR_H__
#include <wx/cmdproc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCommandProcessor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CommandProcessor);

//----------------------------------------------------------------------------
// Object declaration for wxCommandProcessor
//----------------------------------------------------------------------------
class Object_wx_CommandProcessor : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_CommandProcessor)
public:
	inline Object_wx_CommandProcessor(wxCommandProcessor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_CommandProcessor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CommandProcessor(Class *pClass, wxCommandProcessor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CommandProcessor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCommandProcessor *GetEntity() {
		return static_cast<wxCommandProcessor *>(_pEntity);
	}
	inline wxCommandProcessor *ReleaseEntity() {
		wxCommandProcessor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCommandProcessor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
