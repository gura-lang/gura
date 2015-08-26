//----------------------------------------------------------------------------
// wxArray
// extracted from array.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Array: public wxArray, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Array *_pObj;
public:
	inline wx_Array() : wxArray(), _pObj(nullptr) {}
	inline wx_Array(const wxArray& array) : wxArray(array), _pObj(nullptr) {}
	~wx_Array();
	inline void AssocWithGura(Object_wx_Array *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Array::~wx_Array()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Array::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArray
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Array, WX_DEFINE_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_ARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_EXPORTED_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_EXPORTED_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_EXPORTED_ARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_USER_EXPORTED_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_USER_EXPORTED_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_USER_EXPORTED_ARRAY(, , );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_SORTED_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_SORTED_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_SORTED_ARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_SORTED_EXPORTED_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_SORTED_EXPORTED_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_SORTED_EXPORTED_ARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_SORTED_USER_EXPORTED_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_SORTED_USER_EXPORTED_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_SORTED_USER_EXPORTED_ARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DECLARE_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DECLARE_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DECLARE_OBJARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DECLARE_EXPORTED_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DECLARE_EXPORTED_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DECLARE_EXPORTED_OBJARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DECLARE_USER_EXPORTED_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DECLARE_USER_EXPORTED_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DECLARE_USER_EXPORTED_OBJARRAY(, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_OBJARRAY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_EXPORTED_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_EXPORTED_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_EXPORTED_OBJARRAY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_DEFINE_USER_EXPORTED_OBJARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, WX_DEFINE_USER_EXPORTED_OBJARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WX_DEFINE_USER_EXPORTED_OBJARRAY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_APPEND_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_wx_Array, OCCUR_Once);
	DeclareArg(env, "other", VTYPE_wx_Array, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, WX_APPEND_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArray *array = Object_wx_Array::GetObject(args, 0)->GetEntity();
	wxArray *other = Object_wx_Array::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->WX_APPEND_ARRAY(*array, *other);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_PREPEND_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_wx_Array, OCCUR_Once);
	DeclareArg(env, "other", VTYPE_wx_Array, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, WX_PREPEND_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArray *array = Object_wx_Array::GetObject(args, 0)->GetEntity();
	wxArray *other = Object_wx_Array::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->WX_PREPEND_ARRAY(*array, *other);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, WX_CLEAR_ARRAY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_wx_Array, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, WX_CLEAR_ARRAY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArray *array = Object_wx_Array::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->WX_CLEAR_ARRAY(*array);
	return Value::Nil;
}

Gura_DeclareFunction(ArrayEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Array));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ArrayEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Array *pEntity = new wx_Array();
	Object_wx_Array *pObj = Object_wx_Array::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Array(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Array, wxObjArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array, wxObjArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, wxSortedArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, wxSortedArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int compareFunction = args.GetInt(0);
	pThis->GetEntity()->wxSortedArray(compareFunction);
	return Value::Nil;
}

Gura_DeclareFunction(Array)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Array));
	DeclareArg(env, "array", VTYPE_wx_Array, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Array)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxArray *array = Object_wx_Array::GetObject(args, 0)->GetEntity();
	wx_Array *pEntity = new wx_Array(*array);
	Object_wx_Array *pObj = Object_wx_Array::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Array(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Array, wxSortedArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_wx_SortedArray, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, wxSortedArray_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSortedArray *array = Object_wx_SortedArray::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxSortedArray(*array);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, wxObjArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_wx_ObjArray, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, wxObjArray_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObjArray *array = Object_wx_ObjArray::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxObjArray(*array);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t copies = 1;
	if (args.IsValid(1)) copies = args.GetSizeT(1);
	pThis->GetEntity()->Add(, copies);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Add_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t copies = 1;
	if (args.IsValid(1)) copies = args.GetSizeT(1);
	pThis->GetEntity()->Add(, copies);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, Alloc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	pThis->GetEntity()->Alloc(count);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Count)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->Count();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Array, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = args.GetSizeT(0);
}

Gura_DeclareMethod(wx_Array, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array, Empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Array, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "searchFromEnd", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Index)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool searchFromEnd = false;
	if (args.IsValid(1)) searchFromEnd = args.GetBoolean(1);
	int rtn = pThis->GetEntity()->Index(, searchFromEnd);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Array, Index_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Index_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->Index();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Array, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(1);
	size_t copies = 1;
	if (args.IsValid(2)) copies = args.GetSizeT(2);
	pThis->GetEntity()->Insert(, n, copies);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, Insert_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(1);
	pThis->GetEntity()->Insert(, n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Insert_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(1);
	size_t copies = 1;
	if (args.IsValid(2)) copies = args.GetSizeT(2);
	pThis->GetEntity()->Insert(, n, copies);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Array, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Item)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = args.GetSizeT(0);
}

Gura_DeclareMethod(wx_Array, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, Last)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, RemoveAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Array, RemoveAt)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = args.GetSizeT(0);
	size_t count = 1;
	if (args.IsValid(1)) count = args.GetSizeT(1);
	pThis->GetEntity()->RemoveAt(index, count);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, SetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array, SetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	pThis->GetEntity()->SetCount(count, );
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array, Shrink)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_Array, Sort)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array *pThis = Object_wx_Array::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Sort();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxArray
//----------------------------------------------------------------------------
Object_wx_Array::~Object_wx_Array()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Array::Clone() const
{
	return nullptr;
}

String Object_wx_Array::ToString(bool exprFlag)
{
	String rtn("<wx.Array:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Array)
{
	Gura_AssignFunction(ArrayEmpty);
	Gura_AssignFunction(Array);
	Gura_AssignMethod(wx_Array, WX_DEFINE_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_EXPORTED_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_USER_EXPORTED_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_SORTED_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_SORTED_EXPORTED_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_SORTED_USER_EXPORTED_ARRAY);
	Gura_AssignMethod(wx_Array, WX_DECLARE_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_DECLARE_EXPORTED_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_DECLARE_USER_EXPORTED_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_EXPORTED_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_DEFINE_USER_EXPORTED_OBJARRAY);
	Gura_AssignMethod(wx_Array, WX_APPEND_ARRAY);
	Gura_AssignMethod(wx_Array, WX_PREPEND_ARRAY);
	Gura_AssignMethod(wx_Array, WX_CLEAR_ARRAY);
	Gura_AssignMethod(wx_Array, wxObjArray);
	Gura_AssignMethod(wx_Array, wxSortedArray);
	Gura_AssignMethod(wx_Array, wxSortedArray_1);
	Gura_AssignMethod(wx_Array, wxObjArray_1);
	Gura_AssignMethod(wx_Array, Add);
	Gura_AssignMethod(wx_Array, Add_1);
	Gura_AssignMethod(wx_Array, Add_2);
	Gura_AssignMethod(wx_Array, Alloc);
	Gura_AssignMethod(wx_Array, Clear);
	Gura_AssignMethod(wx_Array, Count);
	Gura_AssignMethod(wx_Array, Detach);
	Gura_AssignMethod(wx_Array, Empty);
	Gura_AssignMethod(wx_Array, GetCount);
	Gura_AssignMethod(wx_Array, Index);
	Gura_AssignMethod(wx_Array, Index_1);
	Gura_AssignMethod(wx_Array, Insert);
	Gura_AssignMethod(wx_Array, Insert_1);
	Gura_AssignMethod(wx_Array, Insert_2);
	Gura_AssignMethod(wx_Array, IsEmpty);
	Gura_AssignMethod(wx_Array, Item);
	Gura_AssignMethod(wx_Array, Last);
	Gura_AssignMethod(wx_Array, Remove);
	Gura_AssignMethod(wx_Array, RemoveAt);
	Gura_AssignMethod(wx_Array, SetCount);
	Gura_AssignMethod(wx_Array, Shrink);
	Gura_AssignMethod(wx_Array, Sort);
}

Gura_ImplementDescendantCreator(wx_Array)
{
	return new Object_wx_Array((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
