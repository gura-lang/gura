//----------------------------------------------------------------------------
// wxFileDropTarget
// extracted from fildrptg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnDrop);
Gura_DeclarePrivUserSymbol(OnDropFiles);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileDropTarget: public wxFileDropTarget, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileDropTarget *_pObj;
public:
	//inline wx_FileDropTarget() : wxFileDropTarget(), _sig(NULL), _pObj(NULL) {}
	//virtual bool OnDrop(long x, long y, const void *data, size_t size);
	//virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
	~wx_FileDropTarget();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileDropTarget *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileDropTarget::~wx_FileDropTarget()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileDropTarget::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileDropTargetEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileDropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileDropTargetEmpty)
{
#if 0
	wx_FileDropTarget *pEntity = new wx_FileDropTarget();
	Object_wx_FileDropTarget *pObj = Object_wx_FileDropTarget::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileDropTarget(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileDropTarget, OnDrop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_FileDropTarget *pSelf = Object_wx_FileDropTarget::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	int *data = args.GetInt(2);
	size_t size = args.GetSizeT(3);
	bool rtn = pSelf->GetEntity()->OnDrop(x, y, *data, size);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileDropTarget, OnDropFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "filenames", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDropTarget, OnDropFiles)
{
	Object_wx_FileDropTarget *pSelf = Object_wx_FileDropTarget::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	std::auto_ptr<wxArrayString> filenames(CreateArrayString(args.GetList(2)));
	bool rtn = pSelf->GetEntity()->OnDropFiles(x, y, *filenames);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Object_wx_FileDropTarget::~Object_wx_FileDropTarget()
{
}

Object *Object_wx_FileDropTarget::Clone() const
{
	return NULL;
}

String Object_wx_FileDropTarget::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileDropTarget:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileDropTarget::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnDrop);
	Gura_RealizeUserSymbol(OnDropFiles);
	Gura_AssignFunction(FileDropTargetEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDropTarget)
{
	Gura_AssignMethod(wx_FileDropTarget, OnDrop);
	Gura_AssignMethod(wx_FileDropTarget, OnDropFiles);
}

Gura_ImplementDescendantCreator(wx_FileDropTarget)
{
	return new Object_wx_FileDropTarget((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
