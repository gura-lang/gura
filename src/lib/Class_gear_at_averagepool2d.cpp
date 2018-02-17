//=============================================================================
// Gura class: gear@averagepool2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_AveragePool2d
//-----------------------------------------------------------------------------
bool Gear_AveragePool2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePadRow = 0, sizePadCol = 0;
	CalcPadding2d(this, pArray->GetDims(), &sizePadRow, &sizePadCol);
	return pArray->CalcAveragePool2d(sig, pArrayRtn, GetSizeRow(), GetSizeCol(), GetStridesRow(), GetStridesCol(),
								 sizePadRow, sizePadCol, GetChannelPos());
}

bool Gear_AveragePool2d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_AveragePool2d::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Gear_AveragePool2d::ToString() const
{
	String str;
	char buff[80];
	str += "averagepool2d";
	::sprintf(buff, ":size=(%zu,%zu)", GetSizeRow(), GetSizeCol());
	str += buff;
	::sprintf(buff, ":strides=(%zu,%zu)", GetStridesRow(), GetStridesCol());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

Object *Gear_AveragePool2d::ToObject(Environment &env) const
{
	return new Object_gear_at_averagepool2d(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_AveragePool2d
//-----------------------------------------------------------------------------
bool NodeGear_AveragePool2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_AveragePool2d::EvalForward(Environment &env)
{
	Gear_AveragePool2d *pGear = GetGear();
	const Array *pArrayFwdSrc = GetConnectorSrc()->GetArrayFwd();
	if (_pArrayFwd.IsNull()) {
		Gear::CalcPadding2d(pGear, pArrayFwdSrc->GetDims(), &_sizePadRow, &_sizePadCol);
	}
	return pArrayFwdSrc->CalcAveragePool2d(
		env, _pArrayFwd,
		pGear->GetSizeRow(), pGear->GetSizeCol(), pGear->GetStridesRow(), pGear->GetStridesCol(),
		_sizePadRow, _sizePadCol, pGear->GetChannelPos());
}

bool NodeGear_AveragePool2d::EvalBackward(Environment &env)
{
#if 0
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	AutoPtr<Array> &pArrayGradDst = GetConnectorSrc()->GetArrayGradAutoPtr();		
	if (pArrayGradDst.IsNull()) {
		pArrayGradDst.reset(GetConnectorSrc()->GetArrayFwd()->CreateLike());
	}
	pArrayGradDst->FillZero();
	if (GetConnectorSrc()->GetNodeSrc()->IsVulnerable()) {
		const Array *pArrayGradSrc = (*ppConnectorDst)->GetArrayGrad();
		const Double *pElemGradSrc = dynamic_cast<const ArrayT<Double> *>(pArrayGradSrc)->GetPointer();
		Double *pElemGradDst = dynamic_cast<ArrayT<Double> *>(pArrayGradDst.get())->GetPointer();
		const UInt32 *pElemIndex = dynamic_cast<ArrayT<UInt32> *>(_pArrayOfIndex.get())->GetPointer();
		size_t nElems = pArrayGradSrc->GetElemNum();
		for (size_t iElem = 0; iElem < nElems; iElem++, pElemGradSrc++, pElemIndex++) {
			*(pElemGradDst + *pElemIndex) += *pElemGradSrc;
		}
	}
#endif
	return false;
}

Trainer::NodeGear *NodeGear_AveragePool2d::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_AveragePool2d(Object_gear_at_averagepool2d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_averagepool2d
//-----------------------------------------------------------------------------
Object_gear_at_averagepool2d::Object_gear_at_averagepool2d(Environment &env, Gear_AveragePool2d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_averagepool2d), pGear)
{
}

Object *Object_gear_at_averagepool2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@averagepool2d(size[]:number, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_averagepool2d, "gear@averagepool2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_averagepool2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@averagepool2d` instance.\n");
}

Gura_ImplementFunction(gear_at_averagepool2d)
{
	size_t sizeRow = 0;
	size_t sizeCol = 0;
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Last;
	Value value1, value2;
	if (arg.GetListValues(0, &value1, &value2)) {
		sizeRow = value1.GetSizeT();
		sizeCol = value2.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "size must have two elements");
		return Value::Nil;
	}
	if (arg.IsInvalid(1)) {
		// nothing to do
	} else if (arg.GetListValues(1, &value1, &value2)) {
		stridesRow = value1.GetSizeT();
		stridesCol = value2.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "strides must have two elements");
		return Value::Nil;
	}
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	}
	Object_gear_at_averagepool2d *pObj = new Object_gear_at_averagepool2d(
		env, new Gear_AveragePool2d(sizeRow, sizeCol, stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@averagepool2d#channel_pos
Gura_DeclareProperty_R(gear_at_averagepool2d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool2d, channel_pos)
{
	const Gear_AveragePool2d *pGear = Object_gear_at_averagepool2d::GetObject(valueThis)->GetGear();
	return Value(Array::ChannelPosToSymbol(pGear->GetChannelPos()));
}

// gear@averagepool2d#padding
Gura_DeclareProperty_R(gear_at_averagepool2d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool2d, padding)
{
	const Gear_AveragePool2d *pGear = Object_gear_at_averagepool2d::GetObject(valueThis)->GetGear();
	return Value(Gear::PaddingTypeToSymbol(pGear->GetPaddingType()));
}

// gear@averagepool2d#size
Gura_DeclareProperty_R(gear_at_averagepool2d, size)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool2d, size)
{
	const Gear_AveragePool2d *pGear = Object_gear_at_averagepool2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetSizeRow()), Value(pGear->GetSizeCol()));
}

// gear@averagepool2d#strides
Gura_DeclareProperty_R(gear_at_averagepool2d, strides)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool2d, strides)
{
	const Gear_AveragePool2d *pGear = Object_gear_at_averagepool2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetStridesRow()), Value(pGear->GetStridesCol()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_averagepool2d::Class_gear_at_averagepool2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_averagepool2d)
{
}

void Class_gear_at_averagepool2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_averagepool2d);
	// Assignment of properties
	Gura_AssignProperty(gear_at_averagepool2d, channel_pos);
	Gura_AssignProperty(gear_at_averagepool2d, padding);
	Gura_AssignProperty(gear_at_averagepool2d, size);
	Gura_AssignProperty(gear_at_averagepool2d, strides);
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_averagepool2d, new NodeGear_AveragePool2d::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_averagepool2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
