//----------------------------------------------------------------------------
// wxHeaderColumnSimple
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HEADERCOLUMNSIMPLE_H__
#define __CLASS_WX_HEADERCOLUMNSIMPLE_H__
#include <wx/headercol.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HeaderColumnSimple);

//----------------------------------------------------------------------------
// Object declaration for wxHeaderColumnSimple
//----------------------------------------------------------------------------
class Object_wx_HeaderColumnSimple : public Object_wx_SettableHeaderColumn {
public:
	Gura_DeclareObjectAccessor(wx_HeaderColumnSimple)
public:
	inline Object_wx_HeaderColumnSimple(wxHeaderColumnSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SettableHeaderColumn(Gura_UserClass(wx_HeaderColumnSimple), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HeaderColumnSimple(Class *pClass, wxHeaderColumnSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SettableHeaderColumn(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HeaderColumnSimple();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHeaderColumnSimple *GetEntity() {
		return static_cast<wxHeaderColumnSimple *>(_pEntity);
	}
	inline wxHeaderColumnSimple *ReleaseEntity() {
		wxHeaderColumnSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHeaderColumnSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
