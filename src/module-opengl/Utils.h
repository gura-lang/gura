#ifndef __GURA_OPENGL_UTILS_H__
#define __GURA_OPENGL_UTILS_H__
#include <gura.h>

namespace Gura {

template<typename T_Elem>
Array<T_Elem> *MakeMatrix(Environment &env, const Value &value)
{
	AutoPtr<Array<T_Elem> > rtn(new Array<T_Elem>(16));
	if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		if (valList.size() != 16) {
			env.SetError(ERR_ValueError, "list must contain 16 elements");
			goto done;
		}
		T_Elem *p = rtn->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			if (!pValue->Is_number()) {
				env.SetError(ERR_ValueError, "element must be a number");
				goto done;
			}
			*p++ = static_cast<T_Elem>(pValue->GetDouble());
		}
	} else if (value.Is_matrix()) {
		const Matrix *pMat = Object_matrix::GetObject(value)->GetMatrix();
		if (pMat->GetCols() != 4 && pMat->GetRows() != 4) {
			env.SetError(ERR_ValueError, "matrix must contain 4x4 elements");
			goto done;
		}
		T_Elem *p = rtn->GetPointer();
		for (size_t iRow = 0; iRow < 4; iRow++) {
			for (size_t iCol = 0; iCol < 4; iCol++) {
				const Value &value = pMat->GetElement(iRow, iCol);
				if (!value.Is_number()) {
					env.SetError(ERR_ValueError, "element must be a number");
					goto done;
				}
				*p++ = static_cast<T_Elem>(value.GetDouble());
			}
		}
	} else {
		env.SetError(ERR_ValueError, "list or matrix must be specified");
	}
done:
	return rtn.release();
}

const void *GetArrayPointer(Environment &env, GLenum type, const Value &value);
	
}

#endif
