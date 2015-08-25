//=============================================================================
// Args
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
Args::~Args()
{
}

bool Args::ShouldGenerateIterator(const DeclarationList &declList) const
{
	if (IsThisIterator()) return true;
	ValueList::const_iterator pValue = _valListArg.begin();
	DeclarationList::const_iterator ppDecl = declList.begin();
	for ( ; pValue != _valListArg.end() && ppDecl != declList.end(); pValue++) {
		const Declaration *pDecl = *ppDecl;
		if (pValue->Is_iterator() &&
						pDecl->GetValueType() != VTYPE_iterator) return true;
		if (!pDecl->IsVariableLength()) ppDecl++;
	}
	return false;
}

const Expr_Block *Args::GetBlock(Environment &env) const
{
	Signal &sig = env.GetSignal();
	// check if the block parameter specifies a delegated block information
	// like "g() {|block|}"
	// scope problem remains: 2010.11.02
	const Expr_Block *pExprBlock = _pExprBlock.get();
	while (pExprBlock != nullptr) {
		const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
		if (pExprOwnerParam == nullptr || !pExprBlock->GetExprOwner().empty()) {
			break;
		}
		const ExprList &exprList = *pExprOwnerParam;
		if (exprList.size() != 1 || !exprList.front()->IsIdentifier()) {
			break;
		}
		const Expr_Identifier *pExprIdentifier =
							dynamic_cast<const Expr_Identifier *>(exprList.front());
		const Value *pValue = env.LookupValue(pExprIdentifier->GetSymbol(), ENVREF_Escalate);
		if (pValue == nullptr) {
			break;
		} else if (pValue->Is_expr()) {
			const Expr *pExpr = pValue->GetExpr();
			if (!pExpr->IsBlock()) {
				sig.SetError(ERR_ValueError, "invalid value for block delegation");
				return nullptr;
			}
			pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
		} else if (pValue->IsInvalid()) {
			return nullptr;
		} else {
			break;
		}
	}
	return pExprBlock;
}

// return nullptr without error if block is not specified
const Function *Args::GetBlockFunc(Environment &env, const Symbol *pSymbol)
{
	const Expr_Block *pExprBlock = GetBlock(env);
	if (pExprBlock == nullptr || pSymbol == nullptr) return nullptr;
	if (_pFuncBlock.IsNull()) {
		_pFuncBlock.reset(FunctionCustom::CreateBlockFunc(env,
										pSymbol, pExprBlock, FUNCTYPE_Block));
	}
	return _pFuncBlock.get();
}

String Args::MakeAttrForFlags(ULong flagsToSet, ULong flagsToClear)
{
	struct Item {
		ULong flag;
		const char *attrName;
	};
	static const Item itemsSet[] = {
		{ FLAG_Map,				":map"				},
		{ FLAG_NoMap,			":nomap"			},
		{ FLAG_NoNamed,			":nonamed"			},
		{ FLAG_Flat,			":flat"				},
		{ FLAG_DynamicScope,	":dynamic_scope"	},
		{ FLAG_SymbolFunc,		":symbol_func"		},
		{ FLAG_Leader,			":leader"			},
		{ FLAG_Trailer,			":trailer"			},
		{ FLAG_Finalizer,		":finalizer"		},
		{ FLAG_EndMarker,		":end_marker"		},
		{ FLAG_Public,			":public"			},
		{ FLAG_Private,			":private"			},
	};
	static const Item itemsClear[] = {
		{ FLAG_Flat,			":noflat"			},
	};
	String str;
	for (size_t i = 0; i < ArraySizeOf(itemsSet); i++) {
		const Item &item = itemsSet[i];
		if (flagsToSet & item.flag) {
			str += item.attrName;
		}
	}
	for (size_t i = 0; i < ArraySizeOf(itemsClear); i++) {
		const Item &item = itemsClear[i];
		if (flagsToClear & item.flag) {
			str += item.attrName;
		}
	}
	return str;
}

String Args::MakeAttrForResultMode(ResultMode resultMode)
{
	struct Item {
		ResultMode resultMode;
		const char *attrName;
	};
	static const Item items[] = {
		{ RSLTMODE_List,		":list"			},
		{ RSLTMODE_XList,		":xlist"		},
		{ RSLTMODE_Set,			":set"			},
		{ RSLTMODE_XSet,		":xset"			},
		{ RSLTMODE_Iterator,	":iter"			},
		{ RSLTMODE_XIterator,	":xiter"	 	},
		{ RSLTMODE_Void,		":void"			},
		{ RSLTMODE_Reduce,		":reduce"		},
		{ RSLTMODE_XReduce,		":xreduce"		},
	};
	for (size_t i = 0; i < ArraySizeOf(items); i++) {
		const Item &item = items[i];
		if (resultMode == item.resultMode) return String(item.attrName);
	}
	return String("");
}

}
