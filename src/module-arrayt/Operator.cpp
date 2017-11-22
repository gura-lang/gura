//=============================================================================
// Operator.cpp
// Implementation of operators for array class.
//=============================================================================
#include "stdafx.h"

#define ImplementUnaryFuncTable(op, func)	\
Array::UnaryFuncTable g_unaryFuncTable_##op = { \
	{ \
		nullptr, \
		&func<Boolean,	Boolean,	Operator_##op>,	\
		&func<Int8,		Int8,		Operator_##op>,	\
		&func<UInt8,	UInt8,		Operator_##op>,	\
		&func<Int16,	Int16,		Operator_##op>,	\
		&func<UInt16,	UInt16,		Operator_##op>,	\
		&func<Int32,	Int32,		Operator_##op>,	\
		&func<UInt32,	UInt32,		Operator_##op>,	\
		&func<Int64,	Int64,		Operator_##op>,	\
		&func<UInt64,	UInt64,		Operator_##op>,	\
		&func<Half,		Half,		Operator_##op>,	\
		&func<Float,	Float,		Operator_##op>,	\
		&func<Double,	Double,		Operator_##op>,	\
		&func<Complex,	Complex,	Operator_##op>,	\
		nullptr, \
	} \
}

#define ImplementBinaryFuncTable(op, funcPrefix)	\
Array::BinaryFuncTable g_binaryFuncTable_##op = { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Boolean,	Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Int8,		Boolean,	Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt8,	Boolean,	UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int16,	Boolean,	Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	Boolean,	UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Boolean,	Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	Boolean,	UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Boolean,	Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	Boolean,	UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Boolean,	Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Boolean,	Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Boolean,	Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Boolean,	Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Int8,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Int8,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		UInt8,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	UInt8,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Int16,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Int16,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		UInt16,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	UInt16,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Int32,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Int32,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		UInt32,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	UInt32,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Int64,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Int64,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		UInt64,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	UInt64,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Half,		Half,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Half,		Half,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Half,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Half,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Half,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Float,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Double,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Complex,	Complex,	Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Half,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Float,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Double,		Operator_##op>, \
			&funcPrefix##_array_array<Complex,	Complex,	Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_scalar<Int8,		Boolean,	Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Int8,		Int8,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<UInt8,		UInt8,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Int16,		Int16,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<UInt16,		UInt16,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Int32,		Int32,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<UInt32,		UInt32,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Int64,		Int64,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<UInt64,		UInt64,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Half,		Half,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Float,		Float,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Double,		Double,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Complex,	Double,		Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_scalar_array<Int8,		Double,		Boolean,	Operator_##op>, \
		&funcPrefix##_scalar_array<Int8,		Double,		Int8,		Operator_##op>, \
		&funcPrefix##_scalar_array<UInt8,		Double,		UInt8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Int16,		Double,		Int16,		Operator_##op>, \
		&funcPrefix##_scalar_array<UInt16,		Double,		UInt16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Int32,		Double,		Int32,		Operator_##op>, \
		&funcPrefix##_scalar_array<UInt32,		Double,		UInt32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Int64,		Double,		Int64,		Operator_##op>, \
		&funcPrefix##_scalar_array<UInt64,		Double,		UInt64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Half,		Double,		Half,		Operator_##op>, \
		&funcPrefix##_scalar_array<Float,		Double,		Float,		Operator_##op>, \
		&funcPrefix##_scalar_array<Double,		Double,		Double,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Double,		Complex,	Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_scalar<Complex,		Boolean,	Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Int8,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		UInt8,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Int16,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		UInt16,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Int32,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		UInt32,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Int64,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		UInt64,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Half,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Float,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Double,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Complex,		Complex,	Complex,	Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Boolean,	Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Int8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	UInt8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Int16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	UInt16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Int32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	UInt32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Int64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	UInt64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Half,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Float,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Double,		Operator_##op>, \
		&funcPrefix##_scalar_array<Complex,		Complex,	Complex,	Operator_##op>, \
		nullptr, \
	}, \
	&funcPrefix##_scalar_scalar<Double,			Double,		Double,		Operator_##op>, \
	&funcPrefix##_scalar_scalar<Complex,		Complex,	Complex,	Operator_##op>, \
}

#define ImplementBinaryFuncTable_Cmp(op, funcPrefix)	\
Array::BinaryFuncTable g_binaryFuncTable_##op = { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int8,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int16,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int32,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int64,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Half,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Half,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Float,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Float,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Double,		Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Double,		Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Complex,	Boolean,	Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt8,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt16,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt32,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt64,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Half,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Float,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Double,		Operator_##op>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Complex,	Operator_##op>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_scalar<Boolean,		Boolean,	Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int8,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt8,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int16,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt16,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int32,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt32,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int64,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt64,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Half,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Float,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Double,		Double,		Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Complex,	Double,		Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Boolean,	Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Int8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		UInt8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Int16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		UInt16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Int32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		UInt32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Int64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		UInt64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Half,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Float,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Double,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Double,		Complex,	Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_scalar<Boolean,		Boolean,	Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int8,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt8,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int16,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt16,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int32,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt32,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Int64,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		UInt64,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Half,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Float,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Double,		Complex,	Operator_##op>, \
		&funcPrefix##_array_scalar<Boolean,		Complex,	Complex,	Operator_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Boolean,	Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Int8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	UInt8,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Int16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	UInt16,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Int32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	UInt32,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Int64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	UInt64,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Half,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Float,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Double,		Operator_##op>, \
		&funcPrefix##_scalar_array<Boolean,		Complex,	Complex,	Operator_##op>, \
		nullptr, \
	}, \
	&funcPrefix##_scalar_scalar<Double,			Double,		Double,		Operator_##op>, \
	&funcPrefix##_scalar_scalar<Complex,		Complex,	Complex,	Operator_##op>, \
}

#define ImplementBinaryFuncTable_BitOp(op)	 \
Array::BinaryFuncTable g_binaryFuncTable_##op = { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<Boolean,		Boolean,	Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int8,		Boolean,	Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt8,		Boolean,	UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Boolean,	Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		Boolean,	UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Boolean,	Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Boolean,	UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Boolean,	Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Boolean,	UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<Int8,		Int8,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<UInt8,		UInt8,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Int16,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt16,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		Boolean,	Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		Operator_##op>, \
			&Array::BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		Operator_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&Array::BinaryFuncTmpl_array_scalar<Int8,		Boolean,	Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<Int8,		Int8,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<UInt8,		UInt8,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<Int16,		Int16,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<UInt16,		UInt16,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<Int32,		Int32,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<UInt32,		UInt32,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<Int64,		Int64,		Double,		Operator_##op>, \
		&Array::BinaryFuncTmpl_array_scalar<UInt64,		UInt64,		Double,		Operator_##op>, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&Array::BinaryFuncTmpl_scalar_array<Int8,		Double,		Boolean,	Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<Int8,		Double,		Int8,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<UInt8,		Double,		UInt8,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<Int16,		Double,		Int16,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<UInt16,		Double,		UInt16,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<Int32,		Double,		Int32,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<UInt32,		Double,		UInt32,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<Int64,		Double,		Int64,		Operator_##op>, \
		&Array::BinaryFuncTmpl_scalar_array<UInt64,		Double,		UInt64,		Operator_##op>, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	}, \
	nullptr, \
	nullptr, \
}

Gura_BeginModuleScope(arrayt)

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
ImplementUnaryFuncTable(Pos,			Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Neg,			Array::UnaryFuncTmpl);

ImplementBinaryFuncTable(Add,			Array::BinaryFuncTmpl);
ImplementBinaryFuncTable(Sub,			Array::BinaryFuncTmpl);
ImplementBinaryFuncTable(Mul,			Array::BinaryFuncTmpl);
ImplementBinaryFuncTable(Div,			Array::BinaryFuncTmpl_Div);
ImplementBinaryFuncTable(Mod,			Array::BinaryFuncTmpl_Div);
ImplementBinaryFuncTable(Pow,			Array::BinaryFuncTmpl);

ImplementBinaryFuncTable_Cmp(Eq,		Array::BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Ne,		Array::BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Gt,		Array::BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Lt,		Array::BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Ge,		Array::BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Le,		Array::BinaryFuncTmpl);

ImplementBinaryFuncTable_BitOp(And);
ImplementBinaryFuncTable_BitOp(Or);
ImplementBinaryFuncTable_BitOp(Xor);
ImplementBinaryFuncTable_BitOp(Shl);
ImplementBinaryFuncTable_BitOp(Shr);

ImplementUnaryFuncTable(Math_abs,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_acos,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_arg,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_asin,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_atan,		Array::UnaryFuncTmpl);
ImplementBinaryFuncTable(Math_atan2,	Array::BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_ceil,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_conj,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_cos,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_cosh,		Array::UnaryFuncTmpl);
//ImplementBinaryFuncTable(Math_covariance,	Array::BinaryFuncTmpl);
//ImplementBinaryFuncTable(Math_cross,	Array::BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_delta,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_exp,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_floor,		Array::UnaryFuncTmpl);
ImplementBinaryFuncTable(Math_hypot,	Array::BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_imag,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_log,		Array::UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncTable(Math_log10,		Array::UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncTable(Math_norm,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_real,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_relu,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sigmoid,	Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sin,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sinh,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sqrt,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_tan,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_tanh,		Array::UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_unitstep,	Array::UnaryFuncTmpl);

//ImplementBinaryFuncTable(Dot)
Array::BinaryFuncTable g_binaryFuncTable_Dot = {
	{
		{ // None
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Int8,		Boolean,	Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Int8,		Boolean,	Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt8,		Boolean,	UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		Boolean,	Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		Boolean,	UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Boolean,	Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		Boolean,	UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Boolean,	Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		Boolean,	UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Boolean,	Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Boolean,	Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Boolean,	Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Boolean,	Complex	>,
			nullptr,
		}, { // Int8 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Int8,		Int8,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Int8,		Int8,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt8,		Int8,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		Int8,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		Int8,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int8,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		Int8,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int8,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		Int8,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Int8,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Int8,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Int8,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Int8,		Complex	>,
			nullptr,
		}, { // UInt8 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<UInt8,		UInt8,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<UInt8,		UInt8,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt8,		UInt8,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		UInt8,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt8,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		UInt8,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt8,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		UInt8,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt8,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		UInt8,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		UInt8,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		UInt8,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,	UInt8,		Complex	>,
			nullptr,
		}, { // Int16 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Int16,		Int16,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		Int16,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		Int16,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int16,		Int16,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		Int16,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int16,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		Int16,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int16,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		Int16,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Int16,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Int16,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Int16,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Int16,		Complex	>,
			nullptr,
		}, { // UInt16 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt16,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt16,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt16,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt16,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt16,		UInt16,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		UInt16,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt16,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		UInt16,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt16,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		UInt16,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		UInt16,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		UInt16,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		UInt16,		Complex	>,
			nullptr,
		}, { // Int32 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int32,		Int32,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		Int32,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int32,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		Int32,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Int32,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Int32,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Int32,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Int32,		Complex	>,
			nullptr,
		}, { // UInt32 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		UInt32,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt32,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		UInt32,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		UInt32,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		UInt32,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		UInt32,		Complex	>,
			nullptr,
		}, { // Int64 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Int64,		Int64,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		Int64,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Int64,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Int64,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Int64,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Int64,		Complex	>,
			nullptr,
		}, { // UInt64 |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		UInt64,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		UInt64,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		UInt64,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		UInt64,		Complex	>,
			nullptr,
		}, { // Half |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Half,		Half,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Half,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Half,		Complex	>,
			nullptr,
		}, { // Float |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Float,		Float,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Float,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Float,		Complex	>,
			nullptr,
		}, { // Double |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Int8	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Int16	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Int32	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Int64	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Half	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Float	>,
			&Array::BinaryFuncTmpl_Dot<Double,		Double,		Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Double,		Complex	>,
			nullptr,
		}, { // Complex |.| any
			nullptr,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Boolean	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Int8	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	UInt8	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Int16	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	UInt16	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Int32	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	UInt32	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Int64	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	UInt64	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Half	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Float	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Double	>,
			&Array::BinaryFuncTmpl_Dot<Complex,		Complex,	Complex	>,
			nullptr,
		}, { // reserved1 |.| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		},
	}, {
		nullptr,
		Array::BinaryFuncTmpl_array_scalar<Int8,	Boolean,	Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Int8,	Int8,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<UInt8,	UInt8,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Int16,	Int16,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<UInt16,	UInt16,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Int32,	Int32,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<UInt32,	UInt32,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Int64,	Int64,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<UInt64,	UInt64,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Half,	Half,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Float,	Float,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Double,	Double,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Complex,	Double,		Operator_Mul>,
		nullptr,
	}, {
		nullptr,
		Array::BinaryFuncTmpl_scalar_array<Int8,	Double,		Boolean,	Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Int8,	Double,		Int8,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<UInt8,	Double,		UInt8,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Int16,	Double,		Int16,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<UInt16,	Double,		UInt16,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Int32,	Double,		Int32,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<UInt32,	Double,		UInt32,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Int64,	Double,		Int64,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<UInt64,	Double,		UInt64,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Half,	Double,		Half,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Float,	Double,		Float,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Double,	Double,		Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Double,		Complex,	Operator_Mul>,
		nullptr,
	}, {
		nullptr,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Boolean,	Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Int8,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	UInt8,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Int16,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	UInt16,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Int32,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	UInt32,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Int64,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	UInt64,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Half,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Float,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Double,		Complex,	Operator_Mul>,
		Array::BinaryFuncTmpl_array_scalar<Complex,	Complex,	Complex,	Operator_Mul>,
		nullptr,
	}, {
		nullptr,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Boolean,	Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Int8,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	UInt8,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Int16,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	UInt16,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Int32,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	UInt32,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Int64,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	UInt64,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Half,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Float,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Double,		Operator_Mul>,
		Array::BinaryFuncTmpl_scalar_array<Complex,	Complex,	Complex,	Operator_Mul>,
		nullptr,
	},
	Array::BinaryFuncTmpl_scalar_scalar<Double,		Double,		Double,		Operator_Mul>,
	Array::BinaryFuncTmpl_scalar_scalar<Complex,	Complex,	Complex,	Operator_Mul>,
};

void AssignOperators(Environment &env)
{
	// register function table
	Array::unaryFuncPack_Pos.table =			g_unaryFuncTable_Pos;
	Array::unaryFuncPack_Neg.table = 			g_unaryFuncTable_Neg;
	Array::binaryFuncPack_Add.table =			g_binaryFuncTable_Add;
	Array::binaryFuncPack_Sub.table =			g_binaryFuncTable_Sub;
	Array::binaryFuncPack_Mul.table =			g_binaryFuncTable_Mul;
	Array::binaryFuncPack_Div.table =			g_binaryFuncTable_Div;
	Array::binaryFuncPack_Mod.table =			g_binaryFuncTable_Mod;
	Array::binaryFuncPack_Pow.table =			g_binaryFuncTable_Pow;
	Array::binaryFuncPack_Dot.table =			g_binaryFuncTable_Dot;
	Array::binaryFuncPack_Eq.table =			g_binaryFuncTable_Eq;
	Array::binaryFuncPack_Ne.table =			g_binaryFuncTable_Ne;
	Array::binaryFuncPack_Gt.table =			g_binaryFuncTable_Gt;
	Array::binaryFuncPack_Lt.table =			g_binaryFuncTable_Lt;
	Array::binaryFuncPack_Ge.table =			g_binaryFuncTable_Ge;
	Array::binaryFuncPack_Le.table =			g_binaryFuncTable_Le;
	Array::binaryFuncPack_And.table =			g_binaryFuncTable_And;
	Array::binaryFuncPack_Or.table =			g_binaryFuncTable_Or;
	Array::binaryFuncPack_Xor.table =			g_binaryFuncTable_Xor;
	Array::binaryFuncPack_Shl.table =			g_binaryFuncTable_Shl;
	Array::binaryFuncPack_Shr.table =			g_binaryFuncTable_Shr;
	Array::unaryFuncPack_Math_abs.table =		g_unaryFuncTable_Math_abs;
	Array::unaryFuncPack_Math_acos.table =		g_unaryFuncTable_Math_acos;
	Array::unaryFuncPack_Math_arg.table =		g_unaryFuncTable_Math_arg;
	Array::unaryFuncPack_Math_asin.table =		g_unaryFuncTable_Math_asin;
	Array::unaryFuncPack_Math_atan.table =		g_unaryFuncTable_Math_atan;
	Array::unaryFuncPack_Math_ceil.table =		g_unaryFuncTable_Math_ceil;
	Array::unaryFuncPack_Math_conj.table =		g_unaryFuncTable_Math_conj;
	Array::unaryFuncPack_Math_cos.table =		g_unaryFuncTable_Math_cos;
	Array::unaryFuncPack_Math_cosh.table =		g_unaryFuncTable_Math_cosh;
	Array::unaryFuncPack_Math_delta.table =		g_unaryFuncTable_Math_delta;
	Array::unaryFuncPack_Math_exp.table =		g_unaryFuncTable_Math_exp;
	Array::unaryFuncPack_Math_floor.table =		g_unaryFuncTable_Math_floor;
	Array::unaryFuncPack_Math_imag.table =		g_unaryFuncTable_Math_imag;
	Array::unaryFuncPack_Math_log.table =		g_unaryFuncTable_Math_log;
	Array::unaryFuncPack_Math_log10.table =		g_unaryFuncTable_Math_log10;
	Array::unaryFuncPack_Math_norm.table =		g_unaryFuncTable_Math_norm;
	Array::unaryFuncPack_Math_real.table =		g_unaryFuncTable_Math_real;
	Array::unaryFuncPack_Math_relu.table =		g_unaryFuncTable_Math_relu;
	Array::unaryFuncPack_Math_sigmoid.table =	g_unaryFuncTable_Math_sigmoid;
	Array::unaryFuncPack_Math_sin.table =		g_unaryFuncTable_Math_sin;
	Array::unaryFuncPack_Math_sinh.table =		g_unaryFuncTable_Math_sinh;
	Array::unaryFuncPack_Math_sqrt.table =		g_unaryFuncTable_Math_sqrt;
	Array::unaryFuncPack_Math_tan.table =		g_unaryFuncTable_Math_tan;
	Array::unaryFuncPack_Math_tanh.table =		g_unaryFuncTable_Math_tanh;
	Array::unaryFuncPack_Math_unitstep.table =	g_unaryFuncTable_Math_unitstep;
}

Gura_EndModuleScope(arrayt)
