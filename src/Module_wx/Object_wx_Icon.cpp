//----------------------------------------------------------------------------
// wxIcon
// extracted from icon.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Icon: public wxIcon, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Icon *_pObj;
public:
	inline wx_Icon() : wxIcon(), _sig(NULL), _pObj(NULL) {}
	inline wx_Icon(const wxIcon& icon) : wxIcon(icon), _sig(NULL), _pObj(NULL) {}
	//inline wx_Icon(void* data, int type, int width, int height, int depth) : wxIcon(data, type, width, height, depth), _sig(NULL), _pObj(NULL) {}
	//inline wx_Icon(const char bits[], int width, int height, int depth) : wxIcon(bits[], width, height, depth), _sig(NULL), _pObj(NULL) {}
	//inline wx_Icon(int width, int height, int depth) : wxIcon(width, height, depth), _sig(NULL), _pObj(NULL) {}
	inline wx_Icon(char** bits) : wxIcon(bits), _sig(NULL), _pObj(NULL) {}
	inline wx_Icon(const char** bits) : wxIcon(bits), _sig(NULL), _pObj(NULL) {}
	inline wx_Icon(const wxString& name, wxBitmapType type, int desiredWidth, int desiredHeight) : wxIcon(name, type, desiredWidth, desiredHeight), _sig(NULL), _pObj(NULL) {}
	inline wx_Icon(const wxIconLocation& loc) : wxIcon(loc), _sig(NULL), _pObj(NULL) {}
	~wx_Icon();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Icon *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Icon::~wx_Icon()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Icon::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIcon
//----------------------------------------------------------------------------
Gura_DeclareFunction(EmptyIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EmptyIcon)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Icon *pEntity = new wx_Icon();
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Icon)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "desiredWidth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "desiredHeight", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Icon)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	int desiredWidth = -1;
	if (args.IsValid(2)) desiredWidth = args.GetInt(2);
	int desiredHeight = -1;
	if (args.IsValid(3)) desiredHeight = args.GetInt(3);
	wx_Icon *pEntity = new wx_Icon(name, type, desiredWidth, desiredHeight);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(IconFromXPMData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bits", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconFromXPMData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	const char **bits = new const char *[args.GetList(0).size()];
	size_t i = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Value &value = *pValue;
		bits[i++] = value.GetString();
	}
	wx_Icon *pEntity = new wx_Icon(bits);
	delete[] bits;
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Icon_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Icon_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int data = args.GetInt(0);
	int type = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	int depth = -1;
	if (args.IsValid(4)) depth = args.GetInt(4);
	wx_Icon *pEntity = new wx_Icon(data, type, width, height, depth);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Icon_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "bits[]", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Icon_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char bits[] = args.GetChar(0);
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	int depth = 1;
	if (args.IsValid(3)) depth = args.GetInt(3);
	wx_Icon *pEntity = new wx_Icon(bits[], width, height, depth);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Icon_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Icon_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	int depth = -1;
	if (args.IsValid(2)) depth = args.GetInt(2);
	wx_Icon *pEntity = new wx_Icon(width, height, depth);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Icon_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Icon_5)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char bits = args.GetChar(0);
	wx_Icon *pEntity = new wx_Icon(bits);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Icon_7)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareArg(env, "loc", VTYPE_wx_IconLocation, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Icon_7)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxIconLocation *loc = Object_wx_IconLocation::GetObject(args, 0)->GetEntity();
	wx_Icon *pEntity = new wx_Icon(*loc);
	Object_wx_Icon *pObj = Object_wx_Icon::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Icon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Icon, CopyFromBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, CopyFromBitmap)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->CopyFromBitmap(*bmp);
	return Value::Null;
}

Gura_DeclareMethod(wx_Icon, GetDepth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, GetDepth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDepth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Icon, GetHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, GetHeight)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Icon, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, GetWidth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Icon, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, LoadFile)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->LoadFile(name, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Icon, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, IsOk)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Icon, SaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Icon, SaveFile)
{
#if 0
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	wxPalette *palette = (wxPalette *)(NULL);
	if (args.IsValid(2)) palette = Object_wx_Palette::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SaveFile(name, type, palette);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Icon, SetDepth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetDepth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int depth = args.GetInt(0);
	pThis->GetEntity()->SetDepth(depth);
	return Value::Null;
}

Gura_DeclareMethod(wx_Icon, SetHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetHeight)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Icon, SetWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetWidth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxIcon
//----------------------------------------------------------------------------
Object_wx_Icon::~Object_wx_Icon()
{
}

Object *Object_wx_Icon::Clone() const
{
	return NULL;
}

String Object_wx_Icon::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Icon:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Icon)
{
	Gura_AssignFunction(EmptyIcon);
	Gura_AssignFunction(Icon);
	Gura_AssignFunction(IconFromXPMData);
	Gura_AssignFunction(Icon_1);
	Gura_AssignFunction(Icon_2);
	Gura_AssignFunction(Icon_3);
	Gura_AssignFunction(Icon_5);
	Gura_AssignFunction(Icon_7);
	Gura_AssignMethod(wx_Icon, CopyFromBitmap);
	Gura_AssignMethod(wx_Icon, GetDepth);
	Gura_AssignMethod(wx_Icon, GetHeight);
	Gura_AssignMethod(wx_Icon, GetWidth);
	Gura_AssignMethod(wx_Icon, LoadFile);
	Gura_AssignMethod(wx_Icon, IsOk);
	Gura_AssignMethodEx(wx_Icon, IsOk, "Ok");
	Gura_AssignMethod(wx_Icon, SaveFile);
	Gura_AssignMethod(wx_Icon, SetDepth);
	Gura_AssignMethod(wx_Icon, SetHeight);
	Gura_AssignMethod(wx_Icon, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Icon)
{
	return new Object_wx_Icon((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
