//----------------------------------------------------------------------------
// wxLogStderr
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGSTDERR_H__
#define __CLASS_WX_LOGSTDERR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogStderr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogStderr);

//----------------------------------------------------------------------------
// Object declaration for wxLogStderr
//----------------------------------------------------------------------------
class Object_wx_LogStderr : public Object_wx_Log {
public:
	Gura_DeclareObjectAccessor(wx_LogStderr)
public:
	inline Object_wx_LogStderr(wxLogStderr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(Gura_UserClass(wx_LogStderr), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogStderr(Class *pClass, wxLogStderr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogStderr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogStderr *GetEntity() {
		return dynamic_cast<wxLogStderr *>(_pEntity);
	}
	inline wxLogStderr *ReleaseEntity() {
		wxLogStderr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogStderr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
