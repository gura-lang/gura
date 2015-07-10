//----------------------------------------------------------------------------
// wxHashTable
// extracted from hash.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HASHTABLE_H__
#define __CLASS_WX_HASHTABLE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHashTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HashTable);

//----------------------------------------------------------------------------
// Object declaration for wxHashTable
//----------------------------------------------------------------------------
class Object_wx_HashTable : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HashTable)
public:
	inline Object_wx_HashTable(wxHashTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HashTable), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HashTable(Class *pClass, wxHashTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HashTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHashTable *GetEntity() {
		return dynamic_cast<wxHashTable *>(_pEntity);
	}
	inline wxHashTable *ReleaseEntity() {
		wxHashTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHashTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
