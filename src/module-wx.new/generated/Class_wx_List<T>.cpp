//----------------------------------------------------------------------------
// wxList<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxList<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxList<T>
//----------------------------------------------------------------------------
Object_wx_List<T>::~Object_wx_List<T>()
{
}

Object *Object_wx_List<T>::Clone() const
{
	return nullptr;
}

String Object_wx_List<T>::ToString(bool exprFlag)
{
	String rtn("<wx.List<T>:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_List<T>, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Append)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* object = arg.GetNumber(0)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Append(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __Clear)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __DeleteContents, "DeleteContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "destroy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __DeleteContents)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool destroy = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteContents(destroy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __DeleteNode, "DeleteNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __DeleteNode)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const compatibility_iterator& iter = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteNode(iter);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __DeleteObject, "DeleteObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __DeleteObject)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* object = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteObject(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Erase, "Erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Erase)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const compatibility_iterator& iter = arg.GetNumber(0)
	//pThis->GetEntity()->Erase(iter);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Find)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* object = arg.GetNumber(0)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Find(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __GetCount)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __GetFirst, "GetFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __GetFirst)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __GetLast, "GetLast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __GetLast)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->GetLast();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __IndexOf, "IndexOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __IndexOf)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* obj = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->IndexOf(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Insert)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* object = arg.GetNumber(0)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Insert(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Insert_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t position = arg.GetNumber(0)
	//T* object = arg.GetNumber(1)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Insert(position, object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Insert_2)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//compatibility_iterator iter = arg.GetNumber(0)
	//T* object = arg.GetNumber(1)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Insert(iter, object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __IsEmpty)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Item)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Item(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Member, "Member")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Member)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* object = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Member(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Nth, "Nth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Nth)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxList<T>::compatibility_iterator _rtn = pThis->GetEntity()->Nth(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Number, "Number")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __Number)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->Number();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __Sort, "Sort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compfunc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __Sort)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSortCompareFunction compfunc = arg.GetNumber(0)
	//pThis->GetEntity()->Sort(compfunc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __assign, "assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __assign)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator first = arg.GetNumber(0)
	//const const_iterator& last = arg.GetNumber(1)
	//pThis->GetEntity()->assign(first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __assign_1, "assign_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __assign_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type n = arg.GetNumber(0)
	//const_reference v = arg.GetNumber(1)
	//pThis->GetEntity()->assign(n, v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __back, "back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//reference _rtn = pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __back_1, "back_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __back_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reference _rtn = pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __begin)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator _rtn = pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __begin_1, "begin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __begin_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator _rtn = pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __clear, "clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __clear)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __empty)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __end)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator _rtn = pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __end_1, "end_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __end_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator _rtn = pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __erase, "erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __erase)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const iterator& it = arg.GetNumber(0)
	//iterator _rtn = pThis->GetEntity()->erase(it);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __erase_1, "erase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __erase_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const iterator& first = arg.GetNumber(0)
	//const iterator& last = arg.GetNumber(1)
	//iterator _rtn = pThis->GetEntity()->erase(first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __front, "front")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//reference _rtn = pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __front_1, "front_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __front_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reference _rtn = pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __insert)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const iterator& it = arg.GetNumber(0)
	//iterator _rtn = pThis->GetEntity()->insert(it);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __insert_1, "insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __insert_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const iterator& it = arg.GetNumber(0)
	//size_type n = arg.GetNumber(1)
	//pThis->GetEntity()->insert(it, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __insert_2, "insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __insert_2)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const iterator& it = arg.GetNumber(0)
	//const_iterator first = arg.GetNumber(1)
	//const const_iterator& last = arg.GetNumber(2)
	//pThis->GetEntity()->insert(it, first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __max_size, "max_size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __max_size)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type _rtn = pThis->GetEntity()->max_size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __pop_back, "pop_back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __pop_back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __pop_front, "pop_front")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __pop_front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_front();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __push_back, "push_back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __push_back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reference v = arg.GetNumber(0)
	//pThis->GetEntity()->push_back(v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __push_front, "push_front")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __push_front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reference v = arg.GetNumber(0)
	//pThis->GetEntity()->push_front(v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __rbegin, "rbegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __rbegin)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//reverse_iterator _rtn = pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __rbegin_1, "rbegin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __rbegin_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reverse_iterator _rtn = pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __remove, "remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __remove)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reference v = arg.GetNumber(0)
	//pThis->GetEntity()->remove(v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __rend, "rend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __rend)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//reverse_iterator _rtn = pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __rend_1, "rend_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __rend_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_reverse_iterator _rtn = pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __resize, "resize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, __resize)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type n = arg.GetNumber(0)
	//value_type v = arg.GetNumber(1)
	//pThis->GetEntity()->resize(n, v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __reverse, "reverse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __reverse)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->reverse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __size)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type _rtn = pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_List<T>, __AsVector, "AsVector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, __AsVector)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVector<T> _rtn = pThis->GetEntity()->AsVector();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxList<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_List<T>)
{
	// Class assignment
	Gura_AssignValueEx("List<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_List<T>, __Append);
	Gura_AssignMethod(wx_List<T>, __Clear);
	Gura_AssignMethod(wx_List<T>, __DeleteContents);
	Gura_AssignMethod(wx_List<T>, __DeleteNode);
	Gura_AssignMethod(wx_List<T>, __DeleteObject);
	Gura_AssignMethod(wx_List<T>, __Erase);
	Gura_AssignMethod(wx_List<T>, __Find);
	Gura_AssignMethod(wx_List<T>, __GetCount);
	Gura_AssignMethod(wx_List<T>, __GetFirst);
	Gura_AssignMethod(wx_List<T>, __GetLast);
	Gura_AssignMethod(wx_List<T>, __IndexOf);
	Gura_AssignMethod(wx_List<T>, __Insert);
	Gura_AssignMethod(wx_List<T>, __Insert_1);
	Gura_AssignMethod(wx_List<T>, __Insert_2);
	Gura_AssignMethod(wx_List<T>, __IsEmpty);
	Gura_AssignMethod(wx_List<T>, __Item);
	Gura_AssignMethod(wx_List<T>, __Member);
	Gura_AssignMethod(wx_List<T>, __Nth);
	Gura_AssignMethod(wx_List<T>, __Number);
	Gura_AssignMethod(wx_List<T>, __Sort);
	Gura_AssignMethod(wx_List<T>, __assign);
	Gura_AssignMethod(wx_List<T>, __assign_1);
	Gura_AssignMethod(wx_List<T>, __back);
	Gura_AssignMethod(wx_List<T>, __back_1);
	Gura_AssignMethod(wx_List<T>, __begin);
	Gura_AssignMethod(wx_List<T>, __begin_1);
	Gura_AssignMethod(wx_List<T>, __clear);
	Gura_AssignMethod(wx_List<T>, __empty);
	Gura_AssignMethod(wx_List<T>, __end);
	Gura_AssignMethod(wx_List<T>, __end_1);
	Gura_AssignMethod(wx_List<T>, __erase);
	Gura_AssignMethod(wx_List<T>, __erase_1);
	Gura_AssignMethod(wx_List<T>, __front);
	Gura_AssignMethod(wx_List<T>, __front_1);
	Gura_AssignMethod(wx_List<T>, __insert);
	Gura_AssignMethod(wx_List<T>, __insert_1);
	Gura_AssignMethod(wx_List<T>, __insert_2);
	Gura_AssignMethod(wx_List<T>, __max_size);
	Gura_AssignMethod(wx_List<T>, __pop_back);
	Gura_AssignMethod(wx_List<T>, __pop_front);
	Gura_AssignMethod(wx_List<T>, __push_back);
	Gura_AssignMethod(wx_List<T>, __push_front);
	Gura_AssignMethod(wx_List<T>, __rbegin);
	Gura_AssignMethod(wx_List<T>, __rbegin_1);
	Gura_AssignMethod(wx_List<T>, __remove);
	Gura_AssignMethod(wx_List<T>, __rend);
	Gura_AssignMethod(wx_List<T>, __rend_1);
	Gura_AssignMethod(wx_List<T>, __resize);
	Gura_AssignMethod(wx_List<T>, __reverse);
	Gura_AssignMethod(wx_List<T>, __size);
	Gura_AssignMethod(wx_List<T>, __AsVector);
}

Gura_ImplementDescendantCreator(wx_List<T>)
{
	return new Object_wx_List<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
