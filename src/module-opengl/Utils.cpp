#include "stdafx.h"

namespace Gura {

const void *GetArrayTPointer(Environment &env, GLenum type, const Array *pArray)
{
	const void *p = nullptr;
	if (pArray->GetElemType() == Array::ETYPE_Int8) {
		//if (type != GL_BYTE) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<Int8> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_UInt8) {
		//if (type != GL_BITMAP &&
		//	type != GL_UNSIGNED_BYTE &&
		//	type != GL_UNSIGNED_BYTE_3_3_2 && 
		//	type != GL_UNSIGNED_BYTE_2_3_3_REV) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<UInt8> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_Int16) {
		//if (type != GL_SHORT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<Int16> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_UInt16) {
		//if (type != GL_UNSIGNED_SHORT &&
		//	type != GL_UNSIGNED_SHORT_5_6_5 &&
		//	type != GL_UNSIGNED_SHORT_5_6_5_REV &&
		//	type != GL_UNSIGNED_SHORT_4_4_4_4 &&
		//	type != GL_UNSIGNED_SHORT_4_4_4_4_REV &&
		//	type != GL_UNSIGNED_SHORT_5_5_5_1 &&
		//	type != GL_UNSIGNED_SHORT_1_5_5_5_REV) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<UInt16> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_Int32) {
		//if (type != GL_INT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<Int32> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_UInt32) {
		//if (type != GL_UNSIGNED_INT &&
		//	type != GL_UNSIGNED_INT_8_8_8_8 &&
		//	type != GL_UNSIGNED_INT_8_8_8_8_REV &&
		//	type != GL_UNSIGNED_INT_10_10_10_2 &&
		//	type != GL_UNSIGNED_INT_2_10_10_10_REV) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<UInt32> *>(pArray)->GetPointer();
	} else if (pArray->GetElemType() == Array::ETYPE_Float) {
		//if (type != GL_FLOAT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = dynamic_cast<const ArrayT<Float> *>(pArray)->GetPointer();
	} else {
		env.SetError(ERR_TypeError, "invalid argument type");
		return nullptr;
	}
	return p;
}

}
