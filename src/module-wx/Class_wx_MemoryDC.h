//----------------------------------------------------------------------------
// wxMemoryDC
// extracted from memorydc.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MEMORYDC_H__
#define __CLASS_WX_MEMORYDC_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMemoryDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MemoryDC);

//----------------------------------------------------------------------------
// Object declaration for wxMemoryDC
//----------------------------------------------------------------------------
class Object_wx_MemoryDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_MemoryDC)
public:
	inline Object_wx_MemoryDC(wxMemoryDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_MemoryDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MemoryDC(Class *pClass, wxMemoryDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MemoryDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMemoryDC *GetEntity() {
		return dynamic_cast<wxMemoryDC *>(_pEntity);
	}
	inline wxMemoryDC *ReleaseEntity() {
		wxMemoryDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMemoryDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
