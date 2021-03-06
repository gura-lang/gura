#include "stdafx.h"
#include "Class_ifd.h"

Gura_BeginModuleScope(jpeg)

static const char *helpDoc_en = R"**(
# Overview


# Property

A `jpeg.ifd` instance has the following properties:

${markdown.makedoc@property(`en, jpeg.ifd)}


# Method

${markdown.makedoc@function(`en
jpeg.ifd.each
)}
)**";

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
template<typename RATIONAL_T>
Value RationalToValue(Signal &sig, const RATIONAL_T &rational)
{
	unsigned long numerator = Gura_UnpackUInt32(rational.numerator);
	unsigned long denominator = Gura_UnpackUInt32(rational.denominator);
	if (denominator == 0) {
		if (numerator != 0) {
			sig.SetError(ERR_ValueError, "rational denominator can't be zero");
			return Value::Nil;
		}
		denominator = 1;
	}
	return Value(Rational(numerator, denominator));
}

template<typename RATIONAL_T>
Value SRationalToValue(Signal &sig, const RATIONAL_T &rational)
{
	long numerator = Gura_UnpackInt32(rational.numerator);
	long denominator = Gura_UnpackInt32(rational.denominator);
	if (denominator == 0) {
		if (numerator != 0) {
			sig.SetError(ERR_ValueError, "rational denominator can't be zero");
			return Value::Nil;
		}
		denominator = 1;
	}
	return Value(Rational(numerator, denominator));
}

template<typename IFDHeader_T, typename TagRaw_T, typename ValueRaw_T, typename SHORT_T,
		typename LONG_T, typename RATIONAL_T, typename SLONG_T, typename SRATIONAL_T>
Object_ifd *ParseIFD_T(Environment &env, Signal &sig, const Symbol *pSymbolOfIFD,
					char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	if (offset + SIZE_IFDHeader >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return nullptr;
	}
	IFDHeader_T *pIFDHeader = reinterpret_cast<IFDHeader_T *>(buff + offset);
	size_t nTags = Gura_UnpackUInt16(pIFDHeader->TagCount);
	offset += SIZE_IFDHeader;
	if (offset + nTags * SIZE_TagRaw >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return nullptr;
	}
	if (pOffsetNext == nullptr) {
		// nothing to do
	} else if (offset + nTags * SIZE_TagRaw + UNITSIZE_LONG <= bytesAPP1) {
		LONG_T *pLong = reinterpret_cast<LONG_T *>(buff + offset + nTags * SIZE_TagRaw);
		*pOffsetNext = Gura_UnpackUInt32(pLong->num);
	} else {
		*pOffsetNext = 0;
	}
	AutoPtr<Object_ifd> pObjIFD(new Object_ifd(pSymbolOfIFD));
	for (size_t iTag = 0; iTag < nTags; iTag++, offset += SIZE_TagRaw) {
		TagRaw_T *pTagRaw = reinterpret_cast<TagRaw_T *>(buff + offset);
		unsigned short tagId = Gura_UnpackUInt16(pTagRaw->Id);
		unsigned short type = Gura_UnpackUInt16(pTagRaw->Type);
		unsigned long count = Gura_UnpackUInt32(pTagRaw->Count);
		ValueRaw_T *pValueRaw = reinterpret_cast<ValueRaw_T *>(&pTagRaw->ValueRaw);
		const TagInfo *pTagInfo = TagIdToInfo(pSymbolOfIFD, tagId);
#if 0
		do {
			const TypeInfo *pTypeInfo = TypeToInfo(type);
			::printf("%s [%04x], %s [%04x], %08x, %08x\n",
					(pTagInfo == nullptr)? "(unknown)" : pTagInfo->name, tagId,
					(pTypeInfo == nullptr)? "(unknown)" : pTypeInfo->name, type,
					count, Gura_UnpackUInt32(pValueRaw->LONG.num));
		} while (0);
#endif
		if (pTagInfo != nullptr && pTagInfo->nameForIFD != nullptr) {
			size_t offsetSub = Gura_UnpackUInt32(pValueRaw->LONG.num);
			size_t offsetNext = 0;
			const Symbol *pSymbolOfIFDSub = Symbol::Add(pTagInfo->nameForIFD);
			AutoPtr<Object_ifd> pObjIFDSub(ParseIFD_T<IFDHeader_T, TagRaw_T,
					ValueRaw_T, SHORT_T,
					LONG_T, RATIONAL_T, SLONG_T, SRATIONAL_T>(env, sig, pSymbolOfIFDSub,
									buff, bytesAPP1, offsetSub, &offsetNext));
			if (pObjIFDSub.IsNull()) return nullptr;
			const Symbol *pSymbol = Symbol::Add(pTagInfo->name);
			pObjIFD->GetTagOwner().push_back(new Object_tag(tagId, type, pSymbol, pObjIFDSub.release()));
		} else {
			Value value, valueCooked;
			switch (type) {
			case TYPE_BYTE: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					p = buff + offset;
				}
				value = Value(new Object_binary(env, p, count, false));
				valueCooked = value;
				break;
			}
			case TYPE_ASCII: {
				char *p = pValueRaw->ASCII;
				if (count > 4) {
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					p = buff + offset;
				}
				if (count == 0) {
					value = Value(p);
				} else {
					value = Value(p, count - 1);
				}
				valueCooked = value;
				break;
			}
			case TYPE_SHORT: {
				if (count == 1) {
					unsigned short num = Gura_UnpackUInt16(pValueRaw->SHORT.num);
					const Symbol *pSymbol = g_symbolAssocOwner.NumToSymbol(tagId, num);
					value = Value(num);
					if (pSymbol == nullptr) {
						valueCooked = value;
					} else {
						valueCooked = Value(pSymbol);
					}
				} else if (count == 2) {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					pObjList->Add(Value(Gura_UnpackUInt16(pValueRaw->SHORT.num)));
					pObjList->Add(Value(Gura_UnpackUInt16(pValueRaw->SHORT.second)));
					valueCooked = value;
				} else {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SHORT * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SHORT) {
						SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset);
						pObjList->Add(Value(Gura_UnpackUInt16(pShort->num)));
					}
					valueCooked = value;
				}
				break;
			}
			case TYPE_LONG: {
				if (count == 1) {
					value = Value(Gura_UnpackUInt32(pValueRaw->LONG.num));
				} else {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + UNITSIZE_LONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_LONG) {
						LONG_T *pLong = reinterpret_cast<LONG_T *>(buff + offset);
						pObjList->Add(Value(Gura_UnpackUInt32(pLong->num)));
					}
				}
				valueCooked = value;
				break;
			}
			case TYPE_RATIONAL: {
				size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
				if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return nullptr;
				}
				if (count == 1) {
					RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
					value = RationalToValue(sig, *pRational);
					if (value.IsInvalid()) return nullptr;
				} else {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_RATIONAL) {
						RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return nullptr;
						pObjList->Add(valueItem);
					}
				}
				valueCooked = value;
				break;
			}
			case TYPE_UNDEFINED: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					p = buff + offset;
				}
				value = Value(new Object_binary(env, p, count, false));
				valueCooked = value;
				break;
			}
			case TYPE_SLONG: {
				if (count == 1) {
					value = Value(Gura_UnpackInt32(pValueRaw->SLONG.num));
				} else {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					size_t offset = Gura_UnpackInt32(pValueRaw->SLONG.num);
					if (offset + UNITSIZE_SLONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SLONG) {
						SLONG_T *pLong = reinterpret_cast<SLONG_T *>(buff + offset);
						pObjList->Add(Value(Gura_UnpackUInt32(pLong->num)));
					}
				}
				valueCooked = value;
				break;
			}
			case TYPE_SRATIONAL: {
				size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
				if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return nullptr;
				}
				if (count == 1) {
					SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
					value = SRationalToValue(sig, *pRational);
					if (value.IsInvalid()) return nullptr;
				} else {
					Object_list *pObjList = value.InitAsList(env);
					pObjList->Reserve(count);
					size_t offset = Gura_UnpackUInt32(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return nullptr;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SRATIONAL) {
						SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
						Value valueItem = SRationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return nullptr;
						pObjList->Add(valueItem);
					}
				}
				valueCooked = value;
				break;
			}
			default: {
				
				break;
			}
			}
			const Symbol *pSymbol = (pTagInfo == nullptr)?
								Symbol::Empty : Symbol::Add(pTagInfo->name);
			pObjIFD->GetTagOwner().push_back(new Object_tag(tagId, type, pSymbol, value, valueCooked));
		}
	}
	return pObjIFD.release();
}

Object_ifd *ParseIFD_BE(Environment &env, Signal &sig, const Symbol *pSymbolOfIFD,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_BE, TagRaw_BE, ValueRaw_BE, SHORT_BE,
		LONG_BE, RATIONAL_BE, SLONG_BE, SRATIONAL_BE>(env, sig, pSymbolOfIFD, buff, bytesAPP1, offset, pOffsetNext);
}

Object_ifd *ParseIFD_LE(Environment &env, Signal &sig, const Symbol *pSymbolOfIFD,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_LE, TagRaw_LE, ValueRaw_LE, SHORT_LE,
		LONG_LE, RATIONAL_LE, SLONG_LE, SRATIONAL_LE>(env, sig, pSymbolOfIFD, buff, bytesAPP1, offset, pOffsetNext);
}

//-----------------------------------------------------------------------------
// IteraorTag
//-----------------------------------------------------------------------------
IteratorTag::IteratorTag(Object_ifd *pObjIFD) :
						Iterator(Finite), _pObjIFD(pObjIFD), _idx(0)
{
}

Iterator *IteratorTag::GetSource()
{
	return nullptr;
}

bool IteratorTag::DoNext(Environment &env, Value &value)
{
	TagOwner &tagOwner = _pObjIFD->GetTagOwner();
	if (_idx >= tagOwner.size()) return false;
	Object_tag *pObjTag = tagOwner[_idx++];
	value = Value(Object_tag::Reference(pObjTag));
	return true;
}

String IteratorTag::ToString() const
{
	return String("<iterator:re.exif.tag>");
}

void IteratorTag::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_ifd implementation
//-----------------------------------------------------------------------------
Object_ifd::Object_ifd(const Symbol *pSymbolOfIFD) :
						Object(Gura_UserClass(ifd)), _pSymbol(pSymbolOfIFD)
{
}

Object_ifd::~Object_ifd()
{
}

Object *Object_ifd::Clone() const
{
	return nullptr;
}

Value Object_ifd::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (valueIdx.Is_number()) {
		unsigned short tagId = valueIdx.GetUInt16();
		Object_tag *pObjTag = GetTagOwner().FindById(tagId);
		if (pObjTag == nullptr) {
			sig.SetError(ERR_IndexError, "can't find tag ID 0x%04x", tagId);
			return Value::Nil;
		}
		return Value(Object_tag::Reference(pObjTag));
	} else if (valueIdx.Is_symbol()) {
		const Symbol *pSymbol = valueIdx.GetSymbol();
		Object_tag *pObjTag = GetTagOwner().FindBySymbol(pSymbol);
		if (pObjTag == nullptr) {
			sig.SetError(ERR_IndexError, "can't find tag `%s", pSymbol->GetName());
			return Value::Nil;
		}
		return Value(Object_tag::Reference(pObjTag));
	}
	sig.SetError(ERR_IndexError, "invalid type for index of ifd");
	return Value::Nil;
}

bool Object_ifd::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	foreach (TagOwner, ppObjTag, GetTagOwner()) {
		Object_tag *pObjTag = *ppObjTag;
		symbols.insert(pObjTag->GetSymbol());
		if (pObjTag->IsIFDPointer()) {
			Object_ifd *pObjIFD = pObjTag->GetObjectIFD();
			symbols.insert(pObjIFD->GetSymbol());
		}
	}
	return true;
}

Value Object_ifd::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	foreach (TagOwner, ppObjTag, GetTagOwner()) {
		Object_tag *pObjTag = *ppObjTag;
		if (pObjTag->GetSymbol() == pSymbol) {
			return Value(Object_tag::Reference(pObjTag));
		} else if (pObjTag->IsIFDPointer()) {
			Object_ifd *pObjIFD = pObjTag->GetObjectIFD();
			if (pObjIFD->GetSymbol() == pSymbol) {
				return Value(Object_ifd::Reference(pObjIFD));
			}
		}
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_ifd::ToString(bool exprFlag)
{
	return String("<jpeg.ifd>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// jpeg.ifd#name
Gura_DeclareProperty_R(ifd, name)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ifd, name)
{
	Object_ifd *pObjThis = Object_ifd::GetObject(valueThis);
	return Value(pObjThis->GetSymbol()->GetName());
}

// jpeg.ifd#symbol
Gura_DeclareProperty_R(ifd, symbol)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ifd, symbol)
{
	Object_ifd *pObjThis = Object_ifd::GetObject(valueThis);
	return Value(pObjThis->GetSymbol());
}

//-----------------------------------------------------------------------------
// Gura interfaces for jpeg.ifd
//-----------------------------------------------------------------------------
// jpeg.ifd#each() {block?}
Gura_DeclareMethod(ifd, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns `jpeg.tag` values as elements\n"
		"that are stored in the target `jpeg.ifd` instance.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(ifd, each)
{
	Object_ifd *pThis = Object_ifd::GetObjectThis(arg);
	return ReturnIterator(env, arg, new IteratorTag(Object_ifd::Reference(pThis)));
}

// implementation of class ifd
Gura_ImplementUserClass(ifd)
{
	// Assignment of properties
	Gura_AssignProperty(ifd, name);
	Gura_AssignProperty(ifd, symbol);
	// Assignment of value
	Gura_AssignValue(ifd, Value(Reference()));
	// Assignment of method
	Gura_AssignMethod(ifd, each);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Gura_EndModuleScope(jpeg)
