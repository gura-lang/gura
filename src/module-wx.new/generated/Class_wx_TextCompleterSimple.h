//----------------------------------------------------------------------------
// wxTextCompleterSimple
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTCOMPLETERSIMPLE_H__
#define __CLASS_WX_TEXTCOMPLETERSIMPLE_H__
#include <wx/textcompleter.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextCompleterSimple
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextCompleterSimple);

//----------------------------------------------------------------------------
// Object declaration for wxTextCompleterSimple
//----------------------------------------------------------------------------
class Object_wx_TextCompleterSimple : public Object_wx_TextCompleter {
public:
	Gura_DeclareObjectAccessor(wx_TextCompleterSimple)
public:
	inline Object_wx_TextCompleterSimple(wxTextCompleterSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextCompleter(Gura_UserClass(wx_TextCompleterSimple), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextCompleterSimple(Class *pClass, wxTextCompleterSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextCompleter(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextCompleterSimple();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextCompleterSimple *GetEntity() {
		return static_cast<wxTextCompleterSimple *>(_pEntity);
	}
	inline wxTextCompleterSimple *ReleaseEntity() {
		wxTextCompleterSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextCompleterSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
