#include "stdafx.h"

namespace Gura {

const void *GetArrayPointer(Signal sig, GLenum type, const Value &value)
{
	const void *p = NULL;
	if (value.IsType(VTYPE_array_char)) {
		if (type != GL_BYTE) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<char>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_uchar)) {
		if (type != GL_BITMAP &&
			type != GL_UNSIGNED_BYTE &&
			type != GL_UNSIGNED_BYTE_3_3_2 && 
			type != GL_UNSIGNED_BYTE_2_3_3_REV) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<UChar>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_short)) {
		if (type != GL_SHORT) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<short>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_ushort)) {
		if (type != GL_UNSIGNED_SHORT &&
			type != GL_UNSIGNED_SHORT_5_6_5 &&
			type != GL_UNSIGNED_SHORT_5_6_5_REV &&
			type != GL_UNSIGNED_SHORT_4_4_4_4 &&
			type != GL_UNSIGNED_SHORT_4_4_4_4_REV &&
			type != GL_UNSIGNED_SHORT_5_5_5_1 &&
			type != GL_UNSIGNED_SHORT_1_5_5_5_REV) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<ushort>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_long)) {
		if (type != GL_INT) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<long>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_ulong)) {
		if (type != GL_UNSIGNED_INT &&
			type != GL_UNSIGNED_INT_8_8_8_8 &&
			type != GL_UNSIGNED_INT_8_8_8_8_REV &&
			type != GL_UNSIGNED_INT_10_10_10_2 &&
			type != GL_UNSIGNED_INT_2_10_10_10_REV) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<ULong>::GetObject(value)->GetArray()->GetPointer();
	} else if (value.IsType(VTYPE_array_float)) {
		if (type != GL_FLOAT) {
			sig.SetError(ERR_TypeError, "invalid argument type");
			return NULL;			
		}
		p = Object_array<float>::GetObject(value)->GetArray()->GetPointer();
	} else {
		sig.SetError(ERR_TypeError, "invalid argument type");
		return NULL;
	}
	return p;
}

}
