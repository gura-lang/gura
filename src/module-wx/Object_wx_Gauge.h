//----------------------------------------------------------------------------
// wxGauge
// extracted from gauge.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GAUGE_H__
#define __OBJECT_WX_GAUGE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGauge
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Gauge);

//----------------------------------------------------------------------------
// Object declaration for wxGauge
//----------------------------------------------------------------------------
class Object_wx_Gauge : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_Gauge)
public:
	inline Object_wx_Gauge(wxGauge *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_Gauge), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Gauge(Class *pClass, wxGauge *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Gauge();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGauge *GetEntity() {
		return dynamic_cast<wxGauge *>(_pEntity);
	}
	inline wxGauge *ReleaseEntity() {
		wxGauge *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGauge");
		return true;
	}
};

}}

#endif
