//----------------------------------------------------------------------------
// wxQuantize
// extracted from quantize.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Quantize: public wxQuantize, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Quantize *_pObj;
public:
	inline wx_Quantize() : wxQuantize(), _sig(NULL), _pObj(NULL) {}
	~wx_Quantize();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Quantize *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Quantize::~wx_Quantize()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Quantize::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxQuantize
//----------------------------------------------------------------------------
Gura_DeclareFunction(QuantizeEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Quantize));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(QuantizeEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Quantize *pEntity = new wx_Quantize();
	Object_wx_Quantize *pObj = Object_wx_Quantize::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Quantize(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Quantize, Quantize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "src", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "dest", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "pPalette", VTYPE_wx_Palette, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Quantize, Quantize)
{
#if 0
	Object_wx_Quantize *pSelf = Object_wx_Quantize::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImage *src = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(args, 1)->GetEntity();
	wxPalette *pPalette = Object_wx_Palette::GetObject(args, 2)->GetEntity();
	int desiredNoColours = 236;
	if (args.IsValid(3)) desiredNoColours = args.GetInt(3);
	unsigned char eightBitData = 0;
	if (args.IsValid(4)) eightBitData = args.GetUChar(4);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (args.IsValid(5)) flags = args.GetInt(5);
	bool rtn = pSelf->GetEntity()->Quantize(*src, *dest, *pPalette, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Quantize, Quantize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "src", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "dest", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Quantize, Quantize_1)
{
#if 0
	Object_wx_Quantize *pSelf = Object_wx_Quantize::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImage *src = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(args, 1)->GetEntity();
	int desiredNoColours = 236;
	if (args.IsValid(2)) desiredNoColours = args.GetInt(2);
	unsigned char eightBitData = 0;
	if (args.IsValid(3)) eightBitData = args.GetUChar(3);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (args.IsValid(4)) flags = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->Quantize(*src, *dest, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Quantize, DoQuantize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "in_rows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "out_rows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Quantize, DoQuantize)
{
#if 0
	Object_wx_Quantize *pSelf = Object_wx_Quantize::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned w = args.GetInt(0);
	unsigned h = args.GetInt(1);
	unsigned char in_rows = args.GetUChar(2);
	unsigned char out_rows = args.GetUChar(3);
	unsigned char palette = args.GetUChar(4);
	int desiredNoColours = args.GetInt(5);
	pSelf->GetEntity()->DoQuantize(w, h, in_rows, out_rows, palette, desiredNoColours);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxQuantize
//----------------------------------------------------------------------------
Object_wx_Quantize::~Object_wx_Quantize()
{
}

Object *Object_wx_Quantize::Clone() const
{
	return NULL;
}

String Object_wx_Quantize::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Quantize:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Quantize::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(QuantizeEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxQuantize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Quantize)
{
	Gura_AssignMethod(wx_Quantize, Quantize);
	Gura_AssignMethod(wx_Quantize, Quantize_1);
	Gura_AssignMethod(wx_Quantize, DoQuantize);
}

Gura_ImplementDescendantCreator(wx_Quantize)
{
	return new Object_wx_Quantize((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
