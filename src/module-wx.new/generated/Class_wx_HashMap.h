//----------------------------------------------------------------------------
// wxHashMap
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HASHMAP_H__
#define __CLASS_WX_HASHMAP_H__
#include <wx/hashmap.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHashMap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HashMap);

//----------------------------------------------------------------------------
// Object declaration for wxHashMap
//----------------------------------------------------------------------------
class Object_wx_HashMap : public Object {
protected:
	wxHashMap *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HashMap)
public:
	inline Object_wx_HashMap(wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HashMap(Class *pClass, wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HashMap();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHashMap *GetEntity() {
		return static_cast<wxHashMap *>(_pEntity);
	}
	inline wxHashMap *ReleaseEntity() {
		wxHashMap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHashMap");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
