//----------------------------------------------------------------------------
// wxFileDropTarget
// extracted from fildrptg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnDrop);
Gura_DeclarePrivUserSymbol(OnDropFiles);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileDropTarget: public wxFileDropTarget, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileDropTarget *_pObj;
public:
	inline wx_FileDropTarget() : wxFileDropTarget(), _pObj(nullptr) {}
	virtual bool OnDrop(wxCoord x, wxCoord y);
	virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
	~wx_FileDropTarget();
	inline void AssocWithGura(Object_wx_FileDropTarget *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileDropTarget::~wx_FileDropTarget()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileDropTarget::GuraObjectDeleted()
{
	_pObj = nullptr;
}

bool wx_FileDropTarget::OnDrop(wxCoord x, wxCoord y)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDrop);
	if (pFunc == nullptr) return wxFileDropTarget::OnDrop(x, y);
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_FileDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDropFiles);
	if (pFunc == nullptr) return false;
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(ArrayStringToValue(env, filenames));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileDropTarget)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FileDropTarget *pEntity = new wx_FileDropTarget();
	Object_wx_FileDropTarget *pObj = Object_wx_FileDropTarget::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileDropTarget(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FileDropTarget, OnDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDropTarget, OnDrop)
{
#if 0
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	int *data = args.GetInt(2);
	size_t size = args.GetSizeT(3);
	bool rtn = pThis->GetEntity()->OnDrop(x, y, *data, size);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileDropTarget, OnDropFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "filenames", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDropTarget, OnDropFiles)
{
	Object_wx_FileDropTarget *pThis = Object_wx_FileDropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	std::unique_ptr<wxArrayString> filenames(CreateArrayString(args.GetList(2)));
	bool rtn = pThis->GetEntity()->OnDropFiles(x, y, *filenames);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Object_wx_FileDropTarget::~Object_wx_FileDropTarget()
{
}

Object *Object_wx_FileDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_FileDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.FileDropTarget:");
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
// Class implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDropTarget)
{
	Gura_RealizeUserSymbol(OnDrop);
	Gura_RealizeUserSymbol(OnDropFiles);
	Gura_AssignFunction(FileDropTarget);
	Gura_AssignMethod(wx_FileDropTarget, OnDrop);
	Gura_AssignMethod(wx_FileDropTarget, OnDropFiles);
}

Gura_ImplementDescendantCreator(wx_FileDropTarget)
{
	return new Object_wx_FileDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
