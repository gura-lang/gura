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
	typedef std::string elem;
	typedef std::vector<elem> sequence;
	typedef std::pair<elem, dtl::elemInfo> sesElem;
	
	bool includeEOLFlag = true;
	sequence seq1, seq2;
	for (;;) {
		String str;
		if (!args.GetStream(0).ReadLine(sig, str, includeEOLFlag)) break;
		seq1.push_back(str.c_str());
	}
	for (;;) {
		String str;
		if (!args.GetStream(1).ReadLine(sig, str, includeEOLFlag)) break;
		seq2.push_back(str.c_str());
	}
	dtl::Diff<elem, sequence> diff(seq1, seq2);
	diff.onHuge();
	diff.compose();
	diff.composeUnifiedHunks();
	diff.printUnifiedFormat();
	foreach_const (dtl::Diff<elem>::uniHunkVec, pUniHunk, diff.getUniHunks()) {
		::printf("@@ -%d,%d +%d,%d @@\n", pUniHunk->a, pUniHunk->b, pUniHunk->c, pUniHunk->d);
		foreach_const (std::vector<sesElem>, pSesElem, pUniHunk->common[0]) {
			::printf("%s\n", pSesElem->first.c_str());
		}
		foreach_const (std::vector<sesElem>, pSesElem, pUniHunk->change) {
			::printf("%s\n", pSesElem->first.c_str());
		}
		foreach_const (std::vector<sesElem>, pSesElem, pUniHunk->common[1]) {
			::printf("%s\n", pSesElem->first.c_str());
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
