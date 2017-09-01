//=============================================================================
// Operator.cpp
// Implementation of operators for array class.
//=============================================================================
#include "stdafx.h"

#define ImplementUnaryFuncTable(op, func)	\
Array::UnaryFuncTable g_unaryFuncTable_##op = { \
	{ \
		nullptr, \
		&func<Boolean,	Boolean,	Operator_##op::Calc>,	\
		&func<Int8,		Int8,		Operator_##op::Calc>,	\
		&func<UInt8,	UInt8,		Operator_##op::Calc>,	\
		&func<Int16,	Int16,		Operator_##op::Calc>,	\
		&func<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&func<Int32,	Int32,		Operator_##op::Calc>,	\
		&func<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&func<Int64,	Int64,		Operator_##op::Calc>,	\
		&func<UInt64,	UInt64,		Operator_##op::Calc>,	\
		&func<Half,		Half,		Operator_##op::Calc>,	\
		&func<Float,	Float,		Operator_##op::Calc>,	\
		&func<Double,	Double,		Operator_##op::Calc>,	\
		&func<Complex,	Complex,	Operator_##op::Calc>,	\
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
			&funcPrefix##_array_array<Int8,		Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Half,		Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Complex,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, \
	&funcPrefix##_number_number<Operator_##op::Calc>, \
	&funcPrefix##_complex_complex<Operator_##op::Calc>, \
}

#define ImplementBinaryFuncTable_Cmp(op, funcPrefix)	\
Array::BinaryFuncTable g_binaryFuncTable_##op = { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, \
	&funcPrefix##_number_number<Operator_##op::Calc>, \
	&funcPrefix##_complex_complex<Operator_##op::Calc>, \
}

#define ImplementBinaryFuncTable_BitOp(op)	 \
Array::BinaryFuncTable g_binaryFuncTable_##op = { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Boolean,	UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Boolean,	Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Boolean,	UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		Operator_##op::Calc>, \
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
		&BinaryFuncTmpl_array_number<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt64,	UInt64,		Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_number_array<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt64,	UInt64,		Operator_##op::Calc>,	\
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
// DotFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_1d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const T_ElemR *pElemR, size_t size)
{
	T_ElemRtn elemRtn = 0;
	for (size_t i = 0; i < size; i++, pElemL++, pElemR++) {
		elemRtn += static_cast<T_ElemRtn>(*pElemL) * static_cast<T_ElemRtn>(*pElemR);
	}
	*pElemRtn = elemRtn;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_2d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Array::Dimension &dimColL,
					   const T_ElemR *pElemR, const Array::Dimension &dimRowR, const Array::Dimension &dimColR)
{
	const T_ElemR *pElemColR = pElemR;
	for (size_t iColR = 0; iColR < dimColR.GetSize(); iColR++,
			 pElemColR += dimColR.GetStrides()) {
		const T_ElemL *pElemColL = pElemL;
		const T_ElemR *pElemRowR = pElemColR;
		T_ElemRtn elemRtn = 0;
		for (size_t iRowR = 0; iRowR < dimRowR.GetSize(); iRowR++,
				 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
			elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
		}
		*pElemRtn++ = elemRtn;
	}
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_1d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Array::Dimension &dimRowL, const Array::Dimension &dimColL,
					   const T_ElemR *pElemR, const Array::Dimension &dimRowR)
{
	const T_ElemL *pElemRowL = pElemL;
	for (size_t iRowL = 0; iRowL < dimRowL.GetSize(); iRowL++,
			 pElemRowL += dimRowL.GetStrides()) {
		const T_ElemL *pElemColL = pElemRowL;
		const T_ElemR *pElemRowR = pElemR;
		T_ElemRtn elemRtn = 0;
		for (size_t iColL = 0; iColL < dimColL.GetSize(); iColL++,
				 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
			elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
		}
		*pElemRtn++ = elemRtn;
	}
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_2d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Array::Dimension &dimRowL, const Array::Dimension &dimColL,
					   const T_ElemR *pElemR, const Array::Dimension &dimRowR, const Array::Dimension &dimColR)
{
	const T_ElemL *pElemRowL = pElemL;
	for (size_t iRowL = 0; iRowL < dimRowL.GetSize(); iRowL++,
			 pElemRowL += dimRowL.GetStrides()) {
		const T_ElemR *pElemColR = pElemR;
		for (size_t iColR = 0; iColR < dimColR.GetSize(); iColR++,
				 pElemColR += dimColR.GetStrides()) {
			const T_ElemL *pElemColL = pElemRowL;
			const T_ElemR *pElemRowR = pElemColR;
			T_ElemRtn elemRtn = 0;
			for (size_t iColL = 0; iColL < dimColL.GetSize(); iColL++,
					 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
				elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
			}
			*pElemRtn++ = elemRtn;
		}
	}
}

void SetError_CantCalcuateDotProduct(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	sig.SetError(ERR_ValueError,
				 "failed in array calculation: (%s) |.| (%s)",
				 pArrayL->GetDimensions().ToString().c_str(),
				 pArrayR->GetDimensions().ToString().c_str());
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
Array *BinaryFuncTmpl_Dot(Signal &sig, Array *pArrayRtn,
						  const Array *pArrayL, const Array *pArrayR)
{
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn;
	const Array::Dimensions &dimsL = pArrayL->GetDimensions();
	const Array::Dimensions &dimsR = pArrayR->GetDimensions();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	if (dimsL.size() == 1 && dimsR.size() == 1) {
		const Array::Dimension &dimL = dimsL.GetCol();
		const Array::Dimension &dimR = dimsR.GetCol();
		if (dimL.GetSize() != dimR.GetSize()) {
			SetError_CantCalcuateDotProduct(sig, pArrayL, pArrayR);
			return nullptr;
		}
		pArrayTRtn.reset((pArrayRtn == nullptr)?
						 ArrayT<T_ElemRtn>::CreateScalar(0) :
						 dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		DotFuncTmpl_1d_1d(pElemRtn, pElemL, pElemR, dimL.GetSize());
	} else if (dimsL.size() == 1 && dimsR.size() >= 2) {
		const Array::Dimension &dimColL = dimsL.GetCol();
		const Array::Dimension &dimRowR = dimsR.GetRow();
		const Array::Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) {
			SetError_CantCalcuateDotProduct(sig, pArrayL, pArrayR);
			return nullptr;
		}
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatR = dimRowR.GetSize() * dimColR.GetSize();
		size_t elemNumRtn = dimColR.GetSize();
		size_t offsetR = 0;
		pArrayTRtn.reset((pArrayRtn == nullptr)?
						 ArrayT<T_ElemRtn>::Create(
							 dimsR.begin(), dimsR.begin() + dimsR.size() - 2, elemNumRtn) :
						 dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		while (offsetR < elemNumR) {
			DotFuncTmpl_1d_2d(pElemRtn, pElemL, dimColL, pElemR + offsetR, dimRowR, dimColR);
			pElemRtn += elemNumRtn;
			offsetR += elemNumMatR;
		}
	} else if (dimsL.size() >= 2 && dimsR.size() == 1) {
		const Array::Dimension &dimRowL = dimsL.GetRow();
		const Array::Dimension &dimColL = dimsL.GetCol();
		const Array::Dimension &dimRowR = dimsR.GetCol();	// takes a column as a row
		if (dimColL.GetSize() != dimRowR.GetSize()) {
			SetError_CantCalcuateDotProduct(sig, pArrayL, pArrayR);
			return nullptr;
		}
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumMatL = dimRowL.GetSize() * dimColL.GetSize();
		size_t elemNumRtn = dimRowL.GetSize();
		size_t offsetL = 0;
		pArrayTRtn.reset((pArrayRtn == nullptr)?
						 ArrayT<T_ElemRtn>::Create(
							 dimsL.begin(), dimsL.begin() + dimsL.size() - 2, elemNumRtn, 1) :
						 dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		while (offsetL < elemNumL) {
			DotFuncTmpl_2d_1d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR, dimRowR);
			pElemRtn += elemNumRtn;
			offsetL += elemNumMatL;
		}
	} else if (dimsL.size() == 2 && dimsR.size() == 2) {
		const Array::Dimension &dimRowL = dimsL.GetRow();
		const Array::Dimension &dimColL = dimsL.GetCol();
		const Array::Dimension &dimRowR = dimsR.GetRow();
		const Array::Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) {
			SetError_CantCalcuateDotProduct(sig, pArrayL, pArrayR);
			return nullptr;
		}
		pArrayTRtn.reset((pArrayRtn == nullptr)?
						 ArrayT<T_ElemRtn>::Create(dimRowL.GetSize(), dimColR.GetSize()) :
						 dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		DotFuncTmpl_2d_2d(pElemRtn, pElemL, dimRowL, dimColL, pElemR, dimRowR, dimColR);
	} else { // dimsL.size() >= 2 && dimsR.size() >= 2
		const Array::Dimension &dimRowL = dimsL.GetRow();
		const Array::Dimension &dimColL = dimsL.GetCol();
		const Array::Dimension &dimRowR = dimsR.GetRow();
		const Array::Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) {
			SetError_CantCalcuateDotProduct(sig, pArrayL, pArrayR);
			return nullptr;
		}
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatRtn = dimRowL.GetSize() * dimColR.GetSize();
		size_t elemNumMatL = dimRowL.GetSize() * dimColL.GetSize();
		size_t elemNumMatR = dimRowR.GetSize() * dimColR.GetSize();
		size_t offsetL = 0, offsetR = 0;
		if (dimsL.size() < dimsR.size()) {
			pArrayTRtn.reset((pArrayRtn == nullptr)?
							 ArrayT<T_ElemRtn>::Create(
								 dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
								 dimRowL.GetSize(), dimColR.GetSize()) :
							 dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
			T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
			while (offsetR < elemNumR) {
				DotFuncTmpl_2d_2d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR + offsetR, dimRowR, dimColR);
				pElemRtn += elemNumMatRtn;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetL >= elemNumL) offsetL = 0;
			}
		} else { // dimsL.size() >= dimsR.size()
			pArrayTRtn.reset((pArrayRtn == nullptr)? ArrayT<T_ElemRtn>::Create(
									dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
									dimRowL.GetSize(), dimColR.GetSize()) :
								dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
			T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
			while (offsetL < elemNumL) {
				DotFuncTmpl_2d_2d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR + offsetR, dimRowR, dimColR);
				pElemRtn += elemNumMatRtn;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetR >= elemNumR) offsetR = 0;
			}
		}
	}
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, void (*op)(T_ElemRtn &, const T_Elem &)>
Array *UnaryFuncTmpl(Signal &sig, Array *pArrayRtn, const Array *pArray)
{
	const Array::Dimensions &dims = pArray->GetDimensions();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(
		(pArrayRtn == nullptr)? ArrayT<T_ElemRtn>::Create(dims) :
		dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			op(*pElemRtn, *pElem);
			pElemRtn++;
		}
	} else { // pArray->IsColMajor()
#if 0
		const Array::Dimension &dim
		const T_ElemR *pElemRow = pElem;
		for (size_t iRow = 0; iRow < dimColR.GetSize(); iColR++,
				 pElemColR += dimColR.GetStrides()) {
			const T_ElemL *pElemColL = pElemL;
			const T_ElemR *pElemRowR = pElemColR;
			T_ElemRtn elemRtn = 0;
			for (size_t iRowR = 0; iRowR < dimRowR.GetSize(); iRowR++,
					 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
				elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
			}
			*pElemRtn++ = elemRtn;
		}
#endif
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_Elem, void (*op)(T_ElemRtn &, const T_Elem &)>
Array *UnaryFuncTmpl_ExcludeZero(Signal &sig, Array *pArrayRtn, const Array *pArray)
{
	if (pArray->DoesContainZero()) {
		sig.SetError(ERR_MathError, "the array contains zero as its element");
		return nullptr;
	}
	return UnaryFuncTmpl<T_ElemRtn, T_Elem, op>(sig, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_array_array(Signal &sig, Array *pArrayRtn,
								  const Array *pArrayL, const Array *pArrayR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn;
	if (nElemsL == nElemsR) {
		pArrayTRtn.reset(
			(pArrayRtn == nullptr)?
			ArrayT<T_ElemRtn>::Create(pArrayL->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		for (size_t offset = 0; offset < nElemsL; offset++) {
			op(*pElemRtn, *(pElemL + offset), *(pElemR + offset));
			pElemRtn++;
		}
	} else if (nElemsL < nElemsR) {
		pArrayTRtn.reset(
			(pArrayRtn == nullptr)?
			ArrayT<T_ElemRtn>::Create(pArrayR->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		size_t offsetL = 0;
		for (size_t offsetR = 0; offsetR < nElemsR; offsetR++) {
			op(*pElemRtn, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetL++;
			if (offsetL >= nElemsL) offsetL = 0;
			pElemRtn++;
		}
	} else { // nElemsL > nElemsR
		pArrayTRtn.reset(
			(pArrayRtn == nullptr)?
			ArrayT<T_ElemRtn>::Create(pArrayL->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
		T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
		size_t offsetR = 0;
		for (size_t offsetL = 0; offsetL < nElemsL; offsetL++) {
			op(*pElemRtn, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetR++;
			if (offsetR >= nElemsR) offsetR = 0;
			pElemRtn++;
		}
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_array_array(Signal &sig, Array *pArrayRtn,
									  const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_array<T_ElemRtn, T_ElemL, T_ElemR, op>(sig, pArrayRtn, pArrayL, pArrayR);
}

template<typename T_ElemRtn, typename T_ElemL,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_array_number(Signal &sig, Array *pArrayRtn,
								   const Array *pArrayL, Double numberR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(
		(pArrayRtn == nullptr)?
		ArrayT<T_ElemRtn>::Create(pArrayL->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemL++) {
		op(*pElemRtn, *pElemL, numberR);
		pElemRtn++;
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_ElemL,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_Div_array_number(Signal &sig, Array *pArrayRtn,
									   const Array *pArrayL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_number<T_ElemRtn, T_ElemL, op>(sig, pArrayRtn, pArrayL, numberR);
}

template<typename T_ElemRtn, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_number_array(Signal &sig, Array *pArrayRtn,
								   Double numberL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(
		(pArrayRtn == nullptr)?
		ArrayT<T_ElemRtn>::Create(pArrayR->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemR++) {
		op(*pElemRtn, numberL, *pElemR);
		pElemRtn++;
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_number_array(Signal &sig, Array *pArrayRtn,
									   Double numberL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_array<T_ElemRtn, T_ElemR, op>(sig, pArrayRtn, numberL, pArrayR);
}

template<typename T_ElemRtn, typename T_ElemL,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_array_complex(Signal &sig, Array *pArrayRtn,
									const Array *pArrayL, const Complex &complexR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(
		(pArrayRtn == nullptr)?
		ArrayT<T_ElemRtn>::Create(pArrayL->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemL++) {
		op(*pElemRtn, *pElemL, complexR);
		pElemRtn++;
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_ElemL,
		 void (*op)(T_ElemRtn &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_Div_array_complex(Signal &sig, Array *pArrayRtn,
										const Array *pArrayL, const Complex &complexR)
{
	if (complexR == Complex::Zero) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_complex<T_ElemRtn, T_ElemL, op>(sig, pArrayRtn, pArrayL, complexR);
}

template<typename T_ElemRtn, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_complex_array(Signal &sig, Array *pArrayRtn,
									const Complex &complexL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(
		(pArrayRtn == nullptr)?
		ArrayT<T_ElemRtn>::Create(pArrayR->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn->Reference()));
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemR++) {
		op(*pElemRtn, complexL, *pElemR);
		pElemRtn++;
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_ElemR,
		 void (*op)(T_ElemRtn &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_complex_array(Signal &sig, Array *pArrayRtn,
										const Complex &complexL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_complex_array<T_ElemRtn, T_ElemR, op>(sig, pArrayRtn, complexL, pArrayR);
}

template<void (*op)(Double &, const Double &, const Double &)>
Array *BinaryFuncTmpl_number_number(Signal &sig, Array *pArrayRtn, Double numberL, Double numberR)
{
	AutoPtr<ArrayT<Double> > pArrayTRtn;
	pArrayTRtn.reset(
		(pArrayRtn == nullptr)?
		ArrayT<Double>::CreateScalar(0) :
		dynamic_cast<ArrayT<Double> *>(pArrayRtn->Reference()));
	op(*pArrayTRtn->GetPointer(), numberL, numberR);
	return pArrayTRtn.release();
}

template<void (*op)(Double &, const Double &, const Double &)>
Array *BinaryFuncTmpl_Div_number_number(Signal &sig, Array *pArrayRtn, Double numberL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_number<op>(sig, pArrayRtn, numberL, numberR);
}

template<void (*op)(Complex &, const Complex &, const Complex &)>
Array *BinaryFuncTmpl_complex_complex(Signal &sig, Array *pArrayRtn, const Complex &complexL, const Complex &complexR)
{
	AutoPtr<ArrayT<Complex> > pArrayTRtn;
	pArrayTRtn.reset(
		(pArrayRtn == nullptr)?
		ArrayT<Complex>::CreateScalar(0) :
		dynamic_cast<ArrayT<Complex> *>(pArrayRtn->Reference()));
	op(*pArrayTRtn->GetPointer(), complexL, complexR);
	return pArrayTRtn.release();
}

template<void (*op)(Complex &, const Complex &, const Complex &)>
Array *BinaryFuncTmpl_Div_complex_complex(Signal &sig, Array *pArrayRtn, const Complex &complexL, const Complex &complexR)
{
	if (complexR.IsZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_complex_complex<op>(sig, pArrayRtn, complexL, complexR);
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv1d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
Array *FilterFuncTmpl_Conv1d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Conv1d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dims));
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv2d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
Array *FilterFuncTmpl_Conv2d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Conv2d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dims));
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv3d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
Array *FilterFuncTmpl_Conv3d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Conv3d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dims));
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool1d
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_MaxPool1d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_MaxPool1d *pFilter)
{
	size_t sizeFilter = pFilter->GetSize();
	size_t strides = pFilter->GetStrides();
	Filter::PaddingType paddingType = pFilter->GetPaddingType();
	Filter::ChannelAt channelAt = pFilter->GetChannelAt();
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	size_t nDims = dims.size();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn;
	if (channelAt == Filter::CHANNELAT_First || nDims < 2) {
		const Array::Dimension &dimCol = dims[nDims - 1];
		size_t sizeIn = dimCol.GetSize();
		size_t sizeOut = 0, sizePadHead = 0, sizePadTail = 0;
		Filter::CalcPadding(sizeIn, sizeFilter, strides, paddingType, &sizeOut, &sizePadHead, &sizePadTail);
		if (nDims < 2) {
			pArrayTRtn.reset(ArrayT<T_Elem>::Create(sizeOut));
		} else {
			pArrayTRtn.reset(ArrayT<T_Elem>::Create(dims.begin(), dims.begin() + nDims - 1, sizeOut));
		}
		const T_Elem *pElemSrc = pArrayT->GetPointer();
		T_Elem *pElemRtn = pArrayTRtn->GetPointer();
		size_t cnt = pArray->GetElemNum() / sizeIn;
		for (size_t j = 0; j < cnt; j++) {
			for (size_t i = 0; i < sizeOut; i++) {
				size_t colBegin = i * strides;
				size_t colEnd = colBegin + sizeFilter;
				if (colBegin < sizePadHead) {
					colBegin = 0;
					colEnd -= sizePadHead - colBegin;
				} else {
					colBegin -= sizePadHead;
					colEnd -= sizePadHead;
				}
				if (colEnd > sizeIn) colEnd = sizeIn;
				const T_Elem *pElemSrcWk = pElemSrc + colBegin;
				bool firstFlag = true;
				T_Elem numMax = 0;
				for (size_t col = colBegin; col < colEnd; col++, pElemSrcWk++) {
					if (firstFlag || numMax < *pElemSrcWk) {
						firstFlag = false;
						numMax = *pElemSrcWk;
					}
				}
				*(pElemRtn + i) = numMax;
			}
			pElemSrc += sizeIn;
			pElemRtn += sizeOut;
		}
	} else {
		const Array::Dimension &dimChannel = dims[nDims - 1];
		const Array::Dimension &dimCol = dims[nDims - 2];
		size_t sizeIn = dimCol.GetSize();
		size_t sizeChannel = dimChannel.GetSize();
		size_t sizeOut = 0, sizePadHead = 0, sizePadTail = 0;
		Filter::CalcPadding(sizeIn, sizeFilter, strides, paddingType, &sizeOut, &sizePadHead, &sizePadTail);
		pArrayTRtn.reset(ArrayT<T_Elem>::Create(dims.begin(), dims.begin() + nDims - 2, sizeOut, sizeChannel));
		const T_Elem *pElemSrc = pArrayT->GetPointer();
		T_Elem *pElemRtn = pArrayTRtn->GetPointer();
		size_t cnt = pArray->GetElemNum() / (sizeIn * sizeChannel);
		for (size_t j = 0; j < cnt; j++) {
			for (size_t i = 0; i < sizeOut; i++) {
				size_t colBegin = i * strides;
				size_t colEnd = colBegin + sizeFilter;
				if (colBegin < sizePadHead) {
					colBegin = 0;
					colEnd -= sizePadHead - colBegin;
				} else {
					colBegin -= sizePadHead;
					colEnd -= sizePadHead;
				}
				if (colEnd > sizeIn) colEnd = sizeIn;
				for (size_t iChannel = 0; iChannel < sizeChannel; iChannel++) {
					const T_Elem *pElemSrcWk = pElemSrc + colBegin * sizeChannel + iChannel;
					bool firstFlag = true;
					T_Elem numMax = 0;
					for (size_t col = colBegin; col < colEnd; col++, pElemSrcWk += sizeChannel) {
						if (firstFlag || numMax < *pElemSrcWk) {
							firstFlag = false;
							numMax = *pElemSrcWk;
						}
					}
					*(pElemRtn + i * sizeChannel + iChannel) = numMax;
				}
			}
			pElemSrc += sizeIn * sizeChannel;
			pElemRtn += sizeOut * sizeChannel;
		}
	}		
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool2d
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_MaxPool2d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_MaxPool2d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dims));
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool3d
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_MaxPool3d(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_MaxPool3d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dims));
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Relu
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_Relu(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Relu *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_relu, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Sigmoid
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_Sigmoid(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Sigmoid *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_sigmoid, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Softmax
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_Softmax(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Softmax *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	size_t axis = pFilter->GetAxis();
	if (axis > dims.size() - 1) axis = dims.size() - 1;
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
		(pArrayRtn == nullptr)? ArrayT<T_Elem>::Create(dims) :
		dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn->Reference()));
	pArrayTRtn->FillZero();
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_Elem *pElemRtn = pArrayTRtn->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t axisSize = pDimAxis->GetSize();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += axisSize) {
			const T_Elem *pElemHead = pElemTop + offset;
			T_Elem *pElemRtnHead = pElemRtn + offset;
			T_Elem numMax = 0;
			do {
				const T_Elem *pElemWk = pElemHead;
				numMax = *pElemWk;
				pElemWk++;
				for (size_t i = 1; i < axisSize; i++, pElemWk++) {
					if (numMax < *pElemWk) numMax = *pElemWk;
				}
			} while (0);
			T_Elem numSum = 0;
			do {
				const T_Elem *pElemWk = pElemHead;
				T_Elem *pElemRtnWk = pElemRtnHead;
				for (size_t i = 0; i < axisSize; i++, pElemWk++, pElemRtnWk++) {
					//T_Elem num = *pElemWk;
					T_Elem num = static_cast<T_Elem>(::exp(static_cast<Double>(*pElemWk - numMax)));
					*pElemRtnWk = num;
					numSum += num;
				}
			} while (0);
			do {
				const T_Elem *pElemWk = pElemHead;
				T_Elem *pElemRtnWk = pElemRtnHead;
				for (size_t i = 0; i < axisSize; i++, pElemWk++, pElemRtnWk++) {
					*pElemRtnWk /= numSum;
				}
			} while (0);
		}
	} else {
		size_t strides = pDimAxis->GetStrides();
		size_t axisSize = pDimAxis->GetSize();
		size_t stepSize = pDimAxis->GetSize() * strides;
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += stepSize) {
			for (size_t j = 0; j < strides; j++) {
				const T_Elem *pElemHead = pElemTop + offset + j;
				T_Elem *pElemRtnHead = pElemRtn + offset + j;
				T_Elem numMax = 0;
				do {
					const T_Elem *pElemWk = pElemHead;
					numMax = *pElemWk;
					pElemWk += strides;
					for (size_t i = 1; i < axisSize; i++, pElemWk += strides) {
						if (numMax < *pElemWk) numMax = *pElemWk;
					}
				} while (0);
				T_Elem numSum = 0;
				do {
					const T_Elem *pElemWk = pElemHead;
					T_Elem *pElemRtnWk = pElemRtnHead;
					for (size_t i = 0; i < axisSize; i++, pElemWk += strides, pElemRtnWk += strides) {
						//T_Elem num = *pElemWk;
						T_Elem num = static_cast<T_Elem>(::exp(static_cast<Double>(*pElemWk - numMax)));
						*pElemRtnWk = num;
						numSum += num;
					}
				} while (0);
				do {
					const T_Elem *pElemWk = pElemHead;
					T_Elem *pElemRtnWk = pElemRtnHead;
					for (size_t i = 0; i < axisSize; i++, pElemWk += strides, pElemRtnWk += strides) {
						*pElemRtnWk /= numSum;
					}
				} while (0);
			}
		}
	}
	return pArrayTRtn.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Tanh
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *FilterFuncTmpl_Tanh(Signal &sig, Array *pArrayRtn, const Array *pArray, const Filter_Tanh *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_tanh, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
ImplementUnaryFuncTable(Pos,			UnaryFuncTmpl);
ImplementUnaryFuncTable(Neg,			UnaryFuncTmpl);

ImplementBinaryFuncTable(Add,			BinaryFuncTmpl);
ImplementBinaryFuncTable(Sub,			BinaryFuncTmpl);
ImplementBinaryFuncTable(Mul,			BinaryFuncTmpl);
ImplementBinaryFuncTable(Div,			BinaryFuncTmpl_Div);
ImplementBinaryFuncTable(Mod,			BinaryFuncTmpl_Div);
ImplementBinaryFuncTable(Pow,			BinaryFuncTmpl);

ImplementBinaryFuncTable_Cmp(Eq,		BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Ne,		BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Gt,		BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Lt,		BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Ge,		BinaryFuncTmpl);
ImplementBinaryFuncTable_Cmp(Le,		BinaryFuncTmpl);

ImplementBinaryFuncTable_BitOp(And);
ImplementBinaryFuncTable_BitOp(Or);
ImplementBinaryFuncTable_BitOp(Xor);
ImplementBinaryFuncTable_BitOp(Shl);
ImplementBinaryFuncTable_BitOp(Shr);

ImplementUnaryFuncTable(Math_abs,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_acos,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_arg,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_asin,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_atan,		UnaryFuncTmpl);
ImplementBinaryFuncTable(Math_atan2,	BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_ceil,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_conj,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_cos,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_cosh,		UnaryFuncTmpl);
//ImplementBinaryFuncTable(Math_covariance,	BinaryFuncTmpl);
//ImplementBinaryFuncTable(Math_cross,	BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_delta,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_exp,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_floor,		UnaryFuncTmpl);
ImplementBinaryFuncTable(Math_hypot,	BinaryFuncTmpl);
ImplementUnaryFuncTable(Math_imag,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_log,		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncTable(Math_log10,		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncTable(Math_norm,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_real,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_relu,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sigmoid,	UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sin,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sinh,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_sqrt,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_tan,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_tanh,		UnaryFuncTmpl);
ImplementUnaryFuncTable(Math_unitstep,	UnaryFuncTmpl);

//ImplementBinaryFuncTable(Dot)
Array::BinaryFuncTable g_binaryFuncTable_Dot = {
	{
		{ // None
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Int8,		Boolean,	Boolean	>,
			&BinaryFuncTmpl_Dot<Int8,		Boolean,	Int8	>,
			&BinaryFuncTmpl_Dot<UInt8,		Boolean,	UInt8	>,
			&BinaryFuncTmpl_Dot<Int16,		Boolean,	Int16	>,
			&BinaryFuncTmpl_Dot<UInt16,		Boolean,	UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		Boolean,	Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		Boolean,	UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		Boolean,	Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		Boolean,	UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Boolean,	Half	>,
			&BinaryFuncTmpl_Dot<Float,		Boolean,	Float	>,
			&BinaryFuncTmpl_Dot<Double,		Boolean,	Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Boolean,	Complex	>,
			nullptr,
		}, { // Int8 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Int8,		Int8,		Boolean	>,
			&BinaryFuncTmpl_Dot<Int8,		Int8,		Int8	>,
			&BinaryFuncTmpl_Dot<UInt8,		Int8,		UInt8	>,
			&BinaryFuncTmpl_Dot<Int16,		Int8,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt16,		Int8,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		Int8,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		Int8,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		Int8,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		Int8,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Int8,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		Int8,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Int8,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Int8,		Complex	>,
			nullptr,
		}, { // UInt8 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<UInt8,		UInt8,		Boolean	>,
			&BinaryFuncTmpl_Dot<UInt8,		UInt8,		Int8	>,
			&BinaryFuncTmpl_Dot<UInt8,		UInt8,		UInt8	>,
			&BinaryFuncTmpl_Dot<Int16,		UInt8,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt16,		UInt8,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		UInt8,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt8,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		UInt8,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt8,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		UInt8,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		UInt8,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		UInt8,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	UInt8,		Complex	>,
			nullptr,
		}, { // Int16 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Int16,		Int16,		Boolean	>,
			&BinaryFuncTmpl_Dot<Int16,		Int16,		Int8	>,
			&BinaryFuncTmpl_Dot<Int16,		Int16,		UInt8	>,
			&BinaryFuncTmpl_Dot<Int16,		Int16,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt16,		Int16,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		Int16,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		Int16,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		Int16,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		Int16,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Int16,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		Int16,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Int16,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Int16,		Complex	>,
			nullptr,
		}, { // UInt16 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<UInt16,		UInt16,		Boolean	>,
			&BinaryFuncTmpl_Dot<UInt16,		UInt16,		Int8	>,
			&BinaryFuncTmpl_Dot<UInt16,		UInt16,		UInt8	>,
			&BinaryFuncTmpl_Dot<UInt16,		UInt16,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt16,		UInt16,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		UInt16,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt16,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		UInt16,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt16,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		UInt16,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		UInt16,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		UInt16,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	UInt16,		Complex	>,
			nullptr,
		}, { // Int32 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		Boolean	>,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		Int8	>,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		UInt8	>,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		Int16	>,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int32,		Int32,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		Int32,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		Int32,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		Int32,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Int32,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		Int32,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Int32,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Int32,		Complex	>,
			nullptr,
		}, { // UInt32 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		Boolean	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int8	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt8	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt16	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt32,		UInt32,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		UInt32,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt32,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		UInt32,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		UInt32,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		UInt32,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	UInt32,		Complex	>,
			nullptr,
		}, { // Int64 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		Boolean	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		Int8	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		UInt8	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		Int16	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		UInt16	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		Int32	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		UInt32	>,
			&BinaryFuncTmpl_Dot<Int64,		Int64,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		Int64,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Int64,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		Int64,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Int64,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Int64,		Complex	>,
			nullptr,
		}, { // UInt64 |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		Boolean	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int8	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt8	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int16	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt16	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int32	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt32	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		Int64	>,
			&BinaryFuncTmpl_Dot<UInt64,		UInt64,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		UInt64,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		UInt64,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		UInt64,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	UInt64,		Complex	>,
			nullptr,
		}, { // Half |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Half,		Half,		Boolean	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Int8	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		UInt8	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Int16	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		UInt16	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Int32	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		UInt32	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Int64	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		UInt64	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Half	>,
			&BinaryFuncTmpl_Dot<Half,		Half,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Half,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Half,		Complex	>,
			nullptr,
		}, { // Float |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Float,		Float,		Boolean	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Int8	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		UInt8	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Int16	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		UInt16	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Int32	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		UInt32	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Int64	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		UInt64	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Half	>,
			&BinaryFuncTmpl_Dot<Float,		Float,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Float,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Float,		Complex	>,
			nullptr,
		}, { // Double |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Double,		Double,		Boolean	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Int8	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		UInt8	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Int16	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		UInt16	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Int32	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		UInt32	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Int64	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		UInt64	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Half	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Float	>,
			&BinaryFuncTmpl_Dot<Double,		Double,		Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Double,		Complex	>,
			nullptr,
		}, { // Complex |.| any
			nullptr,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Boolean	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Int8	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	UInt8	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Int16	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	UInt16	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Int32	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	UInt32	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Int64	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	UInt64	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Half	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Float	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Double	>,
			&BinaryFuncTmpl_Dot<Complex,	Complex,	Complex	>,
			nullptr,
		}, { // reserved1 |.| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		},
	}, {
		nullptr,
		BinaryFuncTmpl_array_number<Int8,		Boolean,	Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Int8,		Int8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<UInt8,		UInt8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Int16,		Int16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<UInt16,		UInt16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Int32,		Int32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<UInt32,		UInt32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Int64,		Int64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<UInt64,		UInt64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Half,		Half,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Float,		Float,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Double,		Double,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_number<Complex,	Complex,	Operator_Mul::Calc>,
		nullptr,
	}, {
		nullptr,
		BinaryFuncTmpl_number_array<Int8,		Boolean,	Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Int8,		Int8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<UInt8,		UInt8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Int16,		Int16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<UInt16,		UInt16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Int32,		Int32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<UInt32,		UInt32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Int64,		Int64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<UInt64,		UInt64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Half,		Half,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Float,		Float,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Double,		Double,		Operator_Mul::Calc>,
		BinaryFuncTmpl_number_array<Complex,	Complex,	Operator_Mul::Calc>,
		nullptr,
	}, {
		nullptr,
		BinaryFuncTmpl_array_complex<Complex,	Boolean,	Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Int8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	UInt8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Int16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	UInt16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Int32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	UInt32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Int64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	UInt64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Half,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Float,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Double,		Operator_Mul::Calc>,
		BinaryFuncTmpl_array_complex<Complex,	Complex,	Operator_Mul::Calc>,
		nullptr,
	}, {
		nullptr,
		BinaryFuncTmpl_complex_array<Complex,	Boolean,	Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Int8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	UInt8,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Int16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	UInt16,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Int32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	UInt32,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Int64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	UInt64,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Half,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Float,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Double,		Operator_Mul::Calc>,
		BinaryFuncTmpl_complex_array<Complex,	Complex,	Operator_Mul::Calc>,
		nullptr,
	},
	BinaryFuncTmpl_number_number<Operator_Mul::Calc>,
	BinaryFuncTmpl_complex_complex<Operator_Mul::Calc>,
};

Filter_Conv1d::FilterFuncTable g_FilterFuncTable_Conv1d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_Conv2d::FilterFuncTable g_FilterFuncTable_Conv2d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_Conv3d::FilterFuncTable g_FilterFuncTable_Conv3d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_MaxPool1d::FilterFuncTable g_FilterFuncTable_MaxPool1d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool1d<Boolean>,
		&FilterFuncTmpl_MaxPool1d<Int8>,
		&FilterFuncTmpl_MaxPool1d<UInt8>,
		&FilterFuncTmpl_MaxPool1d<Int16>,
		&FilterFuncTmpl_MaxPool1d<UInt16>,
		&FilterFuncTmpl_MaxPool1d<Int32>,
		&FilterFuncTmpl_MaxPool1d<UInt32>,
		&FilterFuncTmpl_MaxPool1d<Int64>,
		&FilterFuncTmpl_MaxPool1d<UInt64>,
		&FilterFuncTmpl_MaxPool1d<Half>,
		&FilterFuncTmpl_MaxPool1d<Float>,
		&FilterFuncTmpl_MaxPool1d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_MaxPool2d::FilterFuncTable g_FilterFuncTable_MaxPool2d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool2d<Boolean>,
		&FilterFuncTmpl_MaxPool2d<Int8>,
		&FilterFuncTmpl_MaxPool2d<UInt8>,
		&FilterFuncTmpl_MaxPool2d<Int16>,
		&FilterFuncTmpl_MaxPool2d<UInt16>,
		&FilterFuncTmpl_MaxPool2d<Int32>,
		&FilterFuncTmpl_MaxPool2d<UInt32>,
		&FilterFuncTmpl_MaxPool2d<Int64>,
		&FilterFuncTmpl_MaxPool2d<UInt64>,
		&FilterFuncTmpl_MaxPool2d<Half>,
		&FilterFuncTmpl_MaxPool2d<Float>,
		&FilterFuncTmpl_MaxPool2d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_MaxPool3d::FilterFuncTable g_FilterFuncTable_MaxPool3d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool3d<Boolean>,
		&FilterFuncTmpl_MaxPool3d<Int8>,
		&FilterFuncTmpl_MaxPool3d<UInt8>,
		&FilterFuncTmpl_MaxPool3d<Int16>,
		&FilterFuncTmpl_MaxPool3d<UInt16>,
		&FilterFuncTmpl_MaxPool3d<Int32>,
		&FilterFuncTmpl_MaxPool3d<UInt32>,
		&FilterFuncTmpl_MaxPool3d<Int64>,
		&FilterFuncTmpl_MaxPool3d<UInt64>,
		&FilterFuncTmpl_MaxPool3d<Half>,
		&FilterFuncTmpl_MaxPool3d<Float>,
		&FilterFuncTmpl_MaxPool3d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Relu::FilterFuncTable g_FilterFuncTable_Relu = {
	{
		nullptr,
		&FilterFuncTmpl_Relu<Boolean>,
		&FilterFuncTmpl_Relu<Int8>,
		&FilterFuncTmpl_Relu<UInt8>,
		&FilterFuncTmpl_Relu<Int16>,
		&FilterFuncTmpl_Relu<UInt16>,
		&FilterFuncTmpl_Relu<Int32>,
		&FilterFuncTmpl_Relu<UInt32>,
		&FilterFuncTmpl_Relu<Int64>,
		&FilterFuncTmpl_Relu<UInt64>,
		&FilterFuncTmpl_Relu<Half>,
		&FilterFuncTmpl_Relu<Float>,
		&FilterFuncTmpl_Relu<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Sigmoid::FilterFuncTable g_FilterFuncTable_Sigmoid = {
	{
		nullptr,
		&FilterFuncTmpl_Sigmoid<Boolean>,
		&FilterFuncTmpl_Sigmoid<Int8>,
		&FilterFuncTmpl_Sigmoid<UInt8>,
		&FilterFuncTmpl_Sigmoid<Int16>,
		&FilterFuncTmpl_Sigmoid<UInt16>,
		&FilterFuncTmpl_Sigmoid<Int32>,
		&FilterFuncTmpl_Sigmoid<UInt32>,
		&FilterFuncTmpl_Sigmoid<Int64>,
		&FilterFuncTmpl_Sigmoid<UInt64>,
		&FilterFuncTmpl_Sigmoid<Half>,
		&FilterFuncTmpl_Sigmoid<Float>,
		&FilterFuncTmpl_Sigmoid<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Softmax::FilterFuncTable g_FilterFuncTable_Softmax = {
	{
		nullptr,
		&FilterFuncTmpl_Softmax<Boolean>,
		&FilterFuncTmpl_Softmax<Int8>,
		&FilterFuncTmpl_Softmax<UInt8>,
		&FilterFuncTmpl_Softmax<Int16>,
		&FilterFuncTmpl_Softmax<UInt16>,
		&FilterFuncTmpl_Softmax<Int32>,
		&FilterFuncTmpl_Softmax<UInt32>,
		&FilterFuncTmpl_Softmax<Int64>,
		&FilterFuncTmpl_Softmax<UInt64>,
		&FilterFuncTmpl_Softmax<Half>,
		&FilterFuncTmpl_Softmax<Float>,
		&FilterFuncTmpl_Softmax<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Tanh::FilterFuncTable g_FilterFuncTable_Tanh = {
	{
		nullptr,
		&FilterFuncTmpl_Tanh<Boolean>,
		&FilterFuncTmpl_Tanh<Int8>,
		&FilterFuncTmpl_Tanh<UInt8>,
		&FilterFuncTmpl_Tanh<Int16>,
		&FilterFuncTmpl_Tanh<UInt16>,
		&FilterFuncTmpl_Tanh<Int32>,
		&FilterFuncTmpl_Tanh<UInt32>,
		&FilterFuncTmpl_Tanh<Int64>,
		&FilterFuncTmpl_Tanh<UInt64>,
		&FilterFuncTmpl_Tanh<Half>,
		&FilterFuncTmpl_Tanh<Float>,
		&FilterFuncTmpl_Tanh<Double>,
		nullptr,
		nullptr,
	}
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
	Filter_Conv1d::filterFuncTable =			g_FilterFuncTable_Conv1d;
	Filter_Conv2d::filterFuncTable =			g_FilterFuncTable_Conv2d;
	Filter_Conv3d::filterFuncTable =			g_FilterFuncTable_Conv3d;
	Filter_MaxPool1d::filterFuncTable =			g_FilterFuncTable_MaxPool1d;
	Filter_MaxPool2d::filterFuncTable =			g_FilterFuncTable_MaxPool2d;
	Filter_MaxPool3d::filterFuncTable =			g_FilterFuncTable_MaxPool3d;
	Filter_Relu::filterFuncTable =				g_FilterFuncTable_Relu;
	Filter_Sigmoid::filterFuncTable =			g_FilterFuncTable_Sigmoid;
	Filter_Softmax::filterFuncTable =			g_FilterFuncTable_Softmax;
	Filter_Tanh::filterFuncTable =				g_FilterFuncTable_Tanh;
}

Gura_EndModuleScope(arrayt)
