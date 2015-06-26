//----------------------------------------------------------------------------
// wxLogTextCtrl
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGTEXTCTRL_H__
#define __CLASS_WX_LOGTEXTCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogTextCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxLogTextCtrl
//----------------------------------------------------------------------------
class Object_wx_LogTextCtrl : public Object_wx_Log {
public:
	Gura_DeclareObjectAccessor(wx_LogTextCtrl)
public:
	inline Object_wx_LogTextCtrl(wxLogTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(Gura_UserClass(wx_LogTextCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogTextCtrl(Class *pClass, wxLogTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogTextCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogTextCtrl *GetEntity() {
		return dynamic_cast<wxLogTextCtrl *>(_pEntity);
	}
	inline wxLogTextCtrl *ReleaseEntity() {
		wxLogTextCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogTextCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
