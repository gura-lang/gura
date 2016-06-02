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
Gura_DeclareMethod(wx_List<T>, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Append)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, Clear)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, DeleteContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "destroy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, DeleteContents)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int destroy = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, DeleteNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, DeleteNode)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iter = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, DeleteObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, DeleteObject)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Erase)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iter = arg.GetNumber(0)
	//pThis->GetEntity()->Erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Find)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, GetCount)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, GetFirst)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, GetLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, GetLast)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLast();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, IndexOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, IndexOf)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->IndexOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Insert)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Insert_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Insert_2)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iter = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, IsEmpty)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Item)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Member)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Member)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->Member();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Nth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Nth)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Nth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Number)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, Number)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Number();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compfunc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, Sort)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int compfunc = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, assign)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, assign_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, assign_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, back_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, back_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, begin)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, begin_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, clear)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, empty)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, end)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, end_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, erase)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, erase_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, front)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, front_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, front_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, insert)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, insert_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, insert_2)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int first = arg.GetNumber(1)
	//int last = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, max_size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, max_size)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->max_size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, pop_back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, pop_back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, pop_front)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, pop_front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, push_back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, push_back)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->push_back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, push_front)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, push_front)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->push_front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, rbegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, rbegin)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, rbegin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, rbegin_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, remove)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, rend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, rend)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, rend_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, rend_1)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, resize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_List<T>, resize)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, reverse)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->reverse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, size)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_List<T>, AsVector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_List<T>, AsVector)
{
	Object_wx_List<T> *pThis = Object_wx_List<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AsVector();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxList<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_List<T>)
{
	Gura_AssignMethod(wx_List<T>, Append);
	Gura_AssignMethod(wx_List<T>, Clear);
	Gura_AssignMethod(wx_List<T>, DeleteContents);
	Gura_AssignMethod(wx_List<T>, DeleteNode);
	Gura_AssignMethod(wx_List<T>, DeleteObject);
	Gura_AssignMethod(wx_List<T>, Erase);
	Gura_AssignMethod(wx_List<T>, Find);
	Gura_AssignMethod(wx_List<T>, GetCount);
	Gura_AssignMethod(wx_List<T>, GetFirst);
	Gura_AssignMethod(wx_List<T>, GetLast);
	Gura_AssignMethod(wx_List<T>, IndexOf);
	Gura_AssignMethod(wx_List<T>, Insert);
	Gura_AssignMethod(wx_List<T>, Insert_1);
	Gura_AssignMethod(wx_List<T>, Insert_2);
	Gura_AssignMethod(wx_List<T>, IsEmpty);
	Gura_AssignMethod(wx_List<T>, Item);
	Gura_AssignMethod(wx_List<T>, Member);
	Gura_AssignMethod(wx_List<T>, Nth);
	Gura_AssignMethod(wx_List<T>, Number);
	Gura_AssignMethod(wx_List<T>, Sort);
	Gura_AssignMethod(wx_List<T>, assign);
	Gura_AssignMethod(wx_List<T>, assign_1);
	Gura_AssignMethod(wx_List<T>, back);
	Gura_AssignMethod(wx_List<T>, back_1);
	Gura_AssignMethod(wx_List<T>, begin);
	Gura_AssignMethod(wx_List<T>, begin_1);
	Gura_AssignMethod(wx_List<T>, clear);
	Gura_AssignMethod(wx_List<T>, empty);
	Gura_AssignMethod(wx_List<T>, end);
	Gura_AssignMethod(wx_List<T>, end_1);
	Gura_AssignMethod(wx_List<T>, erase);
	Gura_AssignMethod(wx_List<T>, erase_1);
	Gura_AssignMethod(wx_List<T>, front);
	Gura_AssignMethod(wx_List<T>, front_1);
	Gura_AssignMethod(wx_List<T>, insert);
	Gura_AssignMethod(wx_List<T>, insert_1);
	Gura_AssignMethod(wx_List<T>, insert_2);
	Gura_AssignMethod(wx_List<T>, max_size);
	Gura_AssignMethod(wx_List<T>, pop_back);
	Gura_AssignMethod(wx_List<T>, pop_front);
	Gura_AssignMethod(wx_List<T>, push_back);
	Gura_AssignMethod(wx_List<T>, push_front);
	Gura_AssignMethod(wx_List<T>, rbegin);
	Gura_AssignMethod(wx_List<T>, rbegin_1);
	Gura_AssignMethod(wx_List<T>, remove);
	Gura_AssignMethod(wx_List<T>, rend);
	Gura_AssignMethod(wx_List<T>, rend_1);
	Gura_AssignMethod(wx_List<T>, resize);
	Gura_AssignMethod(wx_List<T>, reverse);
	Gura_AssignMethod(wx_List<T>, size);
	Gura_AssignMethod(wx_List<T>, AsVector);
}

Gura_ImplementDescendantCreator(wx_List<T>)
{
	return new Object_wx_List<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
