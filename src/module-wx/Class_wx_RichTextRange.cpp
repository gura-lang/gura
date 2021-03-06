//----------------------------------------------------------------------------
// wxRichTextRange
// extracted from richtextrange.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextRange: public wxRichTextRange, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextRange *_pObj;
public:
	inline wx_RichTextRange(long start, long end) : wxRichTextRange(start, end), _pObj(nullptr) {}
	inline wx_RichTextRange(const wxRichTextRange& range) : wxRichTextRange(range), _pObj(nullptr) {}
	inline wx_RichTextRange() : wxRichTextRange(), _pObj(nullptr) {}
	~wx_RichTextRange();
	inline void AssocWithGura(Object_wx_RichTextRange *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextRange::~wx_RichTextRange()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextRange::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRange
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextRange)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	long end = arg.GetLong(1);
	wx_RichTextRange *pEntity = new wx_RichTextRange(start, end);
	Object_wx_RichTextRange *pObj = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextRange(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(RichTextRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextRange_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 0)->GetEntity();
	wx_RichTextRange *pEntity = new wx_RichTextRange(*range);
	Object_wx_RichTextRange *pObj = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextRange(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(RichTextRangeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextRangeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RichTextRange *pEntity = new wx_RichTextRange();
	Object_wx_RichTextRange *pObj = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextRange(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextRange, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long pos = arg.GetLong(0);
	bool rtn = pThis->GetEntity()->Contains(pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, GetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, GetEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetEnd();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, GetLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetLength();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, GetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, GetStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetStart();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, FromInternal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, FromInternal)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextRange rtn = pThis->GetEntity()->FromInternal();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextRange, IsOutside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, IsOutside)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsOutside(*range);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, IsWithin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, IsWithin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsWithin(*range);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, LimitTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, LimitTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->LimitTo(*range);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextRange, SetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long end = arg.GetLong(0);
	pThis->GetEntity()->SetEnd(end);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	long end = arg.GetLong(1);
	pThis->GetEntity()->SetRange(start, end);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, SetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	pThis->GetEntity()->SetStart(start);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, Swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, Swap)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Swap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, ToInternal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextRange, ToInternal)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextRange rtn = pThis->GetEntity()->ToInternal();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRange
//----------------------------------------------------------------------------
Object_wx_RichTextRange::~Object_wx_RichTextRange()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RichTextRange::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRange::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRange:");
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
// Class implementation for wxRichTextRange
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRange)
{
	Gura_AssignFunction(RichTextRange);
	Gura_AssignFunction(RichTextRange_1);
	Gura_AssignFunction(RichTextRangeEmpty);
	Gura_AssignMethod(wx_RichTextRange, Contains);
	Gura_AssignMethod(wx_RichTextRange, GetEnd);
	Gura_AssignMethod(wx_RichTextRange, GetLength);
	Gura_AssignMethod(wx_RichTextRange, GetStart);
	Gura_AssignMethod(wx_RichTextRange, FromInternal);
	Gura_AssignMethod(wx_RichTextRange, IsOutside);
	Gura_AssignMethod(wx_RichTextRange, IsWithin);
	Gura_AssignMethod(wx_RichTextRange, LimitTo);
	Gura_AssignMethod(wx_RichTextRange, SetEnd);
	Gura_AssignMethod(wx_RichTextRange, SetRange);
	Gura_AssignMethod(wx_RichTextRange, SetStart);
	Gura_AssignMethod(wx_RichTextRange, Swap);
	Gura_AssignMethod(wx_RichTextRange, ToInternal);
}

Gura_ImplementDescendantCreator(wx_RichTextRange)
{
	return new Object_wx_RichTextRange((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
