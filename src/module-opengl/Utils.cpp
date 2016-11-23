#include "stdafx.h"

namespace Gura {

const void *GetArrayTPointer(Environment &env, GLenum type, const Value &value)
{
	const void *p = nullptr;
	if (value.IsType(VTYPE_array_at_int8)) {
		//if (type != GL_BYTE) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<Int8>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_uint8)) {
		//if (type != GL_BITMAP &&
		//	type != GL_UNSIGNED_BYTE &&
		//	type != GL_UNSIGNED_BYTE_3_3_2 && 
		//	type != GL_UNSIGNED_BYTE_2_3_3_REV) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<UInt8>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_int16)) {
		//if (type != GL_SHORT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<Int16>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_uint16)) {
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
		p = Object_arrayT<UInt16>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_int32)) {
		//if (type != GL_INT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<Int32>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_uint32)) {
		//if (type != GL_UNSIGNED_INT &&
		//	type != GL_UNSIGNED_INT_8_8_8_8 &&
		//	type != GL_UNSIGNED_INT_8_8_8_8_REV &&
		//	type != GL_UNSIGNED_INT_10_10_10_2 &&
		//	type != GL_UNSIGNED_INT_2_10_10_10_REV) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<UInt32>::GetObject(value)->GetArrayT()->GetPointer();
	} else if (value.IsType(VTYPE_array_at_float)) {
		//if (type != GL_FLOAT) {
		//	env.SetError(ERR_TypeError, "invalid argument type");
		//	return nullptr;
		//}
		p = Object_arrayT<Float>::GetObject(value)->GetArrayT()->GetPointer();
	} else {
		env.SetError(ERR_TypeError, "invalid argument type");
		return nullptr;
	}
	return p;
}

}
