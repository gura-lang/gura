//----------------------------------------------------------------------------
// wxTextCtrlBase
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTCTRLBASE_H__
#define __CLASS_WX_TEXTCTRLBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextCtrlBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextCtrlBase);

//----------------------------------------------------------------------------
// Object declaration for wxTextCtrlBase
//----------------------------------------------------------------------------
class Object_wx_TextCtrlBase : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_TextCtrlBase)
public:
	inline Object_wx_TextCtrlBase(wxTextCtrlBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_TextCtrlBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextCtrlBase(Class *pClass, wxTextCtrlBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextCtrlBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextCtrlBase *GetEntity() {
		return dynamic_cast<wxTextCtrlBase *>(_pEntity);
	}
	inline wxTextCtrlBase *ReleaseEntity() {
		wxTextCtrlBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextCtrlBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
