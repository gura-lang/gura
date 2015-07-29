//----------------------------------------------------------------------------
// wxQuantize
// extracted from quantize.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Quantize: public wxQuantize, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Quantize *_pObj;
public:
	inline wx_Quantize() : wxQuantize(), _pObj(nullptr) {}
	~wx_Quantize();
	inline void AssocWithGura(Object_wx_Quantize *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Quantize::~wx_Quantize()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Quantize::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxQuantize
//----------------------------------------------------------------------------
Gura_DeclareFunction(QuantizeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Quantize));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(QuantizeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Quantize *pEntity = new wx_Quantize();
	Object_wx_Quantize *pObj = Object_wx_Quantize::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Quantize(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Quantize, Quantize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *src = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(args, 1)->GetEntity();
	wxPalette *pPalette = Object_wx_Palette::GetObject(args, 2)->GetEntity();
	int desiredNoColours = 236;
	if (args.IsValid(3)) desiredNoColours = args.GetInt(3);
	unsigned char eightBitData = 0;
	if (args.IsValid(4)) eightBitData = args.GetUChar(4);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (args.IsValid(5)) flags = args.GetInt(5);
	bool rtn = pThis->GetEntity()->Quantize(*src, *dest, *pPalette, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Quantize, Quantize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *src = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(args, 1)->GetEntity();
	int desiredNoColours = 236;
	if (args.IsValid(2)) desiredNoColours = args.GetInt(2);
	unsigned char eightBitData = 0;
	if (args.IsValid(3)) eightBitData = args.GetUChar(3);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (args.IsValid(4)) flags = args.GetInt(4);
	bool rtn = pThis->GetEntity()->Quantize(*src, *dest, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Quantize, DoQuantize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned w = args.GetInt(0);
	unsigned h = args.GetInt(1);
	unsigned char in_rows = args.GetUChar(2);
	unsigned char out_rows = args.GetUChar(3);
	unsigned char palette = args.GetUChar(4);
	int desiredNoColours = args.GetInt(5);
	pThis->GetEntity()->DoQuantize(w, h, in_rows, out_rows, palette, desiredNoColours);
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
	return nullptr;
}

String Object_wx_Quantize::ToString(bool exprFlag)
{
	String rtn("<wx.Quantize:");
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
// Class implementation for wxQuantize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Quantize)
{
	Gura_AssignFunction(QuantizeEmpty);
	Gura_AssignMethod(wx_Quantize, Quantize);
	Gura_AssignMethod(wx_Quantize, Quantize_1);
	Gura_AssignMethod(wx_Quantize, DoQuantize);
}

Gura_ImplementDescendantCreator(wx_Quantize)
{
	return new Object_wx_Quantize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
