//----------------------------------------------------------------------------
// wxNotebook
// extracted from notebook.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_NOTEBOOK_H__
#define __OBJECT_WX_NOTEBOOK_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Notebook);

//----------------------------------------------------------------------------
// Object declaration for wxNotebook
//----------------------------------------------------------------------------
class Object_wx_Notebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Notebook)
public:
	inline Object_wx_Notebook(wxNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Notebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Notebook(Class *pClass, wxNotebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Notebook();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxNotebook *GetEntity() {
		return dynamic_cast<wxNotebook *>(_pEntity);
	}
	inline wxNotebook *ReleaseEntity() {
		wxNotebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNotebook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
