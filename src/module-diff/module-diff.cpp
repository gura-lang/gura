//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// diff.diff(stream1:stream, stream2:stream)
Gura_DeclareFunction(diff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream1", VTYPE_stream);
	DeclareArg(env, "stream2", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function adds two numbers and returns the result.");
}

Gura_ImplementFunction(diff)
{
	typedef dtl::Diff<String> DiffString;
	bool includeEOLFlag = true;
	StringList seq1, seq2;
	args.GetStream(0).ReadLines(sig, seq1, includeEOLFlag);
	args.GetStream(1).ReadLines(sig, seq2, includeEOLFlag);
	DiffString diff(seq1, seq2);
	diff.onHuge();
	diff.compose();
	/*
	foreach_const (DiffString::sesElemVec, pSesElem, diff.getSes().getSequence()) {
		::printf("%c %lld %lld %s",
				 (pSesElem->second.type == dtl::SES_ADD)? '+' :
				 (pSesElem->second.type == dtl::SES_DELETE)? '-' :
				 (pSesElem->second.type == dtl::SES_COMMON)? ' ' : ' ',
				 pSesElem->second.beforeIdx,
				 pSesElem->second.afterIdx,
				 pSesElem->first.c_str());
	}
	*/
	diff.composeUnifiedHunks();
	foreach_const (DiffString::uniHunkVec, pUniHunk, diff.getUniHunks()) {
		::printf("@@ -%lld,%lld +%lld,%lld @@\n", pUniHunk->a, pUniHunk->b, pUniHunk->c, pUniHunk->d);
		foreach_const (DiffString::sesElemVec, pSesElem, pUniHunk->common[0]) {
			::printf(" %s", pSesElem->first.c_str());
		}
		foreach_const (DiffString::sesElemVec, pSesElem, pUniHunk->change) {
			::printf("%c%s",
					 (pSesElem->second.type == dtl::SES_ADD)? '+' :
					 (pSesElem->second.type == dtl::SES_DELETE)? '-' :
					 (pSesElem->second.type == dtl::SES_COMMON)? ' ' : ' ',
					 pSesElem->first.c_str());
		}
		foreach_const (DiffString::sesElemVec, pSesElem, pUniHunk->common[1]) {
			::printf(" %s", pSesElem->first.c_str());
		}
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(diff);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
