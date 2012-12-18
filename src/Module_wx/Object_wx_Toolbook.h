//----------------------------------------------------------------------------
// wxToolbook
// extracted from toolbook.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOOLBOOK_H__
#define __OBJECT_WX_TOOLBOOK_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolbook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Toolbook);

//----------------------------------------------------------------------------
// Object declaration for wxToolbook
//----------------------------------------------------------------------------
class Object_wx_Toolbook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Toolbook)
public:
	inline Object_wx_Toolbook(wxToolbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Toolbook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Toolbook(Class *pClass, wxToolbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Toolbook();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxToolbook *GetEntity() {
		return dynamic_cast<wxToolbook *>(_pEntity);
	}
	inline wxToolbook *ReleaseEntity() {
		wxToolbook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToolbook");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
