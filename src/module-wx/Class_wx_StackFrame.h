//----------------------------------------------------------------------------
// wxStackFrame
// extracted from stackframe.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STACKFRAME_H__
#define __CLASS_WX_STACKFRAME_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStackFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StackFrame);

//----------------------------------------------------------------------------
// Object declaration for wxStackFrame
//----------------------------------------------------------------------------
class Object_wx_StackFrame : public Object {
protected:
	wxStackFrame *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StackFrame)
public:
	inline Object_wx_StackFrame(wxStackFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StackFrame)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StackFrame(Class *pClass, wxStackFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StackFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStackFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStackFrame *GetEntity() { return _pEntity; }
	inline wxStackFrame *ReleaseEntity() {
		wxStackFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStackFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
