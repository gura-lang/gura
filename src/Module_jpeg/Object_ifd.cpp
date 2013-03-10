#include "Module_jpeg.h"
#include "Object_ifd.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
template<typename RATIONAL_T>
Value RationalToValue(Signal sig, const RATIONAL_T &rational)
{
	unsigned long numerator = XUnpackULong(rational.numerator);
	unsigned long denominator = XUnpackULong(rational.denominator);
	if (denominator == 0) {
		sig.SetError(ERR_ValueError, "rational denominator can't be zero");
		return Value::Null;
	}
	return Value(Fraction(numerator, denominator));
}

template<typename IFDHeader_T, typename TagRaw_T, typename ValueRaw_T, typename SHORT_T,
		typename LONG_T, typename RATIONAL_T, typename SLONG_T, typename SRATIONAL_T>
Object_ifd *ParseIFD_T(Environment &env, Signal sig,
					char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	if (offset + SIZE_IFDHeader >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return NULL;
	}
	IFDHeader_T *pIFDHeader = reinterpret_cast<IFDHeader_T *>(buff + offset);
	size_t nTags = XUnpackUShort(pIFDHeader->TagCount);
	offset += SIZE_IFDHeader;
	if (offset + nTags * SIZE_TagRaw + UNITSIZE_SHORT >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return NULL;
	}
	if (pOffsetNext != NULL) {
		SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset + nTags * SIZE_TagRaw);
		*pOffsetNext = XUnpackUShort(pShort->num);
	}
	AutoPtr<Object_ifd> pObjIFD(new Object_ifd());
	for (size_t iTag = 0; iTag < nTags; iTag++, offset += SIZE_TagRaw) {
		TagRaw_T *pTagRaw = reinterpret_cast<TagRaw_T *>(buff + offset);
		unsigned short tag = XUnpackUShort(pTagRaw->Tag);
		unsigned short type = XUnpackUShort(pTagRaw->Type);
		unsigned long count = XUnpackULong(pTagRaw->Count);
		ValueRaw_T *pValueRaw = reinterpret_cast<ValueRaw_T *>(&pTagRaw->ValueRaw);
		const TagInfo *pTagInfo = TagToInfo(tag);
#if 0
		do {
			const TypeInfo *pTypeInfo = TypeToInfo(type);
			::printf("%s [%04x], %s [%04x], %08x, %08x\n",
					(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, tag,
					(pTypeInfo == NULL)? "(unknown)" : pTypeInfo->name, type,
					count, XUnpackULong(pValueRaw->LONG.num));
		} while (0);
#endif
		if (pTagInfo != NULL && pTagInfo->nameForIFD != NULL) {
			size_t offsetSub = XUnpackULong(pValueRaw->LONG.num);
			size_t offsetNext = 0;
			AutoPtr<Object_ifd> pObjIFDSub(ParseIFD_T<IFDHeader_T, TagRaw_T,
					ValueRaw_T, SHORT_T,
					LONG_T, RATIONAL_T, SLONG_T, SRATIONAL_T>(env, sig,
									buff, bytesAPP1, offsetSub, &offsetNext));
			if (pObjIFDSub.IsNull()) return NULL;
			const Symbol *pSymbol = Symbol::Add(pTagInfo->name);
			pObjIFD->GetTagOwner().push_back(new Object_Tag(tag, type, pSymbol, pObjIFDSub.release()));
		} else {
			Value value;
			switch (type) {
			case TYPE_BYTE: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					p = buff + offset;
				}
				value.InitAsBinary(env, p, count, false);
				break;
			}
			case TYPE_ASCII: {
				char *p = pValueRaw->ASCII;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					p = buff + offset;
				}
				value = Value(env, p, count - 1);
				break;
			}
			case TYPE_SHORT: {
				if (count == 1) {
					value = Value(XUnpackUShort(pValueRaw->SHORT.num));
				} else if (count == 2) {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					valList.push_back(Value(XUnpackUShort(pValueRaw->SHORT.num)));
					valList.push_back(Value(XUnpackUShort(pValueRaw->SHORT.second)));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SHORT * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SHORT) {
						SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset);
						valList.push_back(Value(XUnpackUShort(pShort->num)));
					}
				}
				break;
			}
			case TYPE_LONG: {
				if (count == 1) {
					value = Value(XUnpackULong(pValueRaw->LONG.num));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_LONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_LONG) {
						LONG_T *pLong = reinterpret_cast<LONG_T *>(buff + offset);
						valList.push_back(Value(XUnpackULong(pLong->num)));
					}
				}
				break;
			}
			case TYPE_RATIONAL: {
				size_t offset = XUnpackULong(pValueRaw->LONG.num);
				if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return NULL;
				}
				if (count == 1) {
					RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
					value = RationalToValue(sig, *pRational);
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_RATIONAL) {
						RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return NULL;
						valList.push_back(valueItem);
					}
				}
				break;
			}
			case TYPE_UNDEFINED: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					p = buff + offset;
				}
				value.InitAsBinary(env, p, count, false);
				break;
			}
			case TYPE_SLONG: {
				if (count == 1) {
					value = Value(XUnpackLong(pValueRaw->SLONG.num));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackLong(pValueRaw->SLONG.num);
					if (offset + UNITSIZE_SLONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SLONG) {
						SLONG_T *pLong = reinterpret_cast<SLONG_T *>(buff + offset);
						valList.push_back(Value(XUnpackULong(pLong->num)));
					}
				}
				break;
			}
			case TYPE_SRATIONAL: {
				size_t offset = XUnpackULong(pValueRaw->LONG.num);
				if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return NULL;
				}
				if (count == 1) {
					SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
					value = RationalToValue(sig, *pRational);
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SRATIONAL) {
						SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return NULL;
						valList.push_back(valueItem);
					}
				}
				break;
			}
			default: {
				
				break;
			}
			}
			const Symbol *pSymbol = (pTagInfo == NULL)?
					Gura_Symbol(Str_Empty) : Symbol::Add(pTagInfo->name);
			pObjIFD->GetTagOwner().push_back(new Object_Tag(tag, type, pSymbol, value));
		}
	}
	return pObjIFD.release();
}

Object_ifd *ParseIFD_BE(Environment &env, Signal sig,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_BE, TagRaw_BE, ValueRaw_BE, SHORT_BE,
		LONG_BE, RATIONAL_BE, SLONG_BE, SRATIONAL_BE>(env, sig, buff, bytesAPP1, offset, pOffsetNext);
}

Object_ifd *ParseIFD_LE(Environment &env, Signal sig,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_LE, TagRaw_LE, ValueRaw_LE, SHORT_LE,
		LONG_LE, RATIONAL_LE, SLONG_LE, SRATIONAL_LE>(env, sig, buff, bytesAPP1, offset, pOffsetNext);
}

//-----------------------------------------------------------------------------
// IteraorTag
//-----------------------------------------------------------------------------
IteratorTag::IteratorTag(Object_ifd *pObjIFD) :
						Iterator(false), _pObjIFD(pObjIFD), _idx(0)
{
}

bool IteratorTag::DoNext(Environment &env, Signal sig, Value &value)
{
	TagOwner &tagOwner = _pObjIFD->GetTagOwner();
	if (_idx >= tagOwner.size()) return false;
	Object_Tag *pObjTag = tagOwner[_idx++];
	value = Value(Object_Tag::Reference(pObjTag));
	return true;
}

String IteratorTag::ToString(Signal sig) const
{
	return String("<iterator:re.exif.tag>");
}

void IteratorTag::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_ifd implementation
//-----------------------------------------------------------------------------
Object_ifd::Object_ifd() : Object(Gura_UserClass(ifd))
{
}

Object_ifd::~Object_ifd()
{
}

Object *Object_ifd::Clone() const
{
	return NULL;
}

Value Object_ifd::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (valueIdx.IsNumber()) {
		unsigned short tag = valueIdx.GetUShort();
		foreach (TagOwner, ppObjTag, GetTagOwner()) {
			Object_Tag *pObjTag = *ppObjTag;
			if (pObjTag->GetTag() == tag) {
				return Value(Object_Tag::Reference(pObjTag));
			}
		}
		sig.SetError(ERR_IndexError, "can't find tag 0x%04x", tag);
	} else if (valueIdx.IsSymbol()) {
		const Symbol *pSymbol = valueIdx.GetSymbol();
		foreach (TagOwner, ppObjTag, GetTagOwner()) {
			Object_Tag *pObjTag = *ppObjTag;
			if (pObjTag->GetSymbol() == pSymbol) {
				return Value(Object_Tag::Reference(pObjTag));
			}
		}
		sig.SetError(ERR_IndexError, "can't find tag `%s", pSymbol->GetName());
	}
	sig.SetError(ERR_IndexError, "invalid type for index of ifd");
	return Value::Null;
}

bool Object_ifd::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	foreach (SymbolList, ppSymbol, g_symbolTagList) {
		const Symbol *pSymbol = *ppSymbol;
		symbols.insert(pSymbol);
	}
	return true;
}

Value Object_ifd::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	foreach (TagOwner, ppObjTag, GetTagOwner()) {
		Object_Tag *pObjTag = *ppObjTag;
		if (pObjTag->GetSymbol() == pSymbol) {
			return Value(Object_Tag::Reference(pObjTag));
		}
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_ifd::ToString(Signal sig, bool exprFlag)
{
	return String("<jpeg.ifd>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for ifd
//-----------------------------------------------------------------------------
// jpeg.ifd#each() {block?}
Gura_DeclareMethod(ifd, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(ifd, each)
{
	Object_ifd *pThis = Object_ifd::GetThisObj(args);
	return ReturnIterator(env, sig, args,
						new IteratorTag(Object_ifd::Reference(pThis)));
}

// implementation of class ifd
Gura_ImplementUserClass(ifd)
{
	Gura_AssignMethod(ifd, each);
}

}}
