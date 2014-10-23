//=============================================================================
// Gura Programming Language
// Copyright (C) 2011-2014 ypsitau
//=============================================================================
#include <gura.h>

#if defined(GURA_ON_MSWIN)
#else
#include <readline/readline.h>
#include <readline/history.h>
#endif

namespace Gura {

void PrintVersion(FILE *fp);
void PrintHelp(FILE *fp);

void ReadEvalPrintLoop(Environment &env, Signal sig);

//-----------------------------------------------------------------------------
// Main entry
//-----------------------------------------------------------------------------
int Main(int argc, const char *argv[])
{
	static const Option::Info optInfoTbl[] = {
		{ "help",			'h', false	},
		{ "interactive",	't', false	},
		{ "import",			'i', true	},
		{ "import-dir",		'I', true	},	// used in sys module initialization
		{ "command",		'c', true	},
		{ "template",		'T', true	},
		{ "directory",		'C', true	},
		{ "coding",			'd', true	},
		{ "quiet",			'q', false	},
		{ "printcmdline",	'P', false	},
		{ "version",		'v', false	},
		{ "llvm",			'o', true	},
		{ "no-local-dir",	'N', false	},
	};
	Signal sig;
	AutoPtr<Environment> pEnv(new Environment());
	Environment &env = *pEnv;
	if (!env.InitializeAsRoot(sig, argc, argv, optInfoTbl, ArraySizeOf(optInfoTbl))) {
		sig.PrintSignal(*env.GetConsoleErr());
		return 1;
	}
	Option &opt = env.GetOption();
	if (opt.IsSet("version")) {
		PrintVersion(stderr);
		return 0;
	}
	if (opt.IsSet("help")) {
		PrintVersion(stderr);
		PrintHelp(stderr);
		return 0;
	}
	if (opt.IsSet("directory") && !OAL::ChangeCurDir(opt.GetString("directory", ""))) {
		::fprintf(stderr, "failed to change the current directory");
		return 1;
	}
	if (opt.IsSet("printcmdline") && argc > 1) {
		for (int i = 1; i < argc; i++) {
			::fprintf(stderr, (i == 1)? "%s" : " %s", argv[i]);
		}
		::fprintf(stderr, "\n");
	}
	bool interactiveFlag = true;
	bool versionPrintedFlag = false;
	bool quietFlag = opt.IsSet("quiet");
	if (opt.IsSet("interactive") && !quietFlag) {
		PrintVersion(stdout);
		versionPrintedFlag = true;
	}
	if (opt.IsSet("import")) {
		foreach_const (StringList, pModuleNames, opt.GetStringList("import")) {
			if (!env.ImportModules(sig, pModuleNames->c_str(), false, false)) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
		}
	}
	if (opt.IsSet("command")) {
		foreach_const (StringList, pCmd, opt.GetStringList("command")) {
			const char *cmd = pCmd->c_str();
			if (::strcmp(cmd, "") == 0) continue;
			AutoPtr<Expr_Root> pExprRoot(new Expr_Root());
			ExprOwner &exprOwner = pExprRoot->GetExprOwner();
			if (!Parser(SRCNAME_cmdline).ParseString(env, sig, exprOwner, cmd, true)) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			if (exprOwner.empty()) {
				env.GetConsoleErr()->Println(sig, "incomplete command");
			} else {
				AutoPtr<Processor> pProcessor(new Processor());
				pProcessor->PushSequence(new Expr::SequenceRoot(
									env.Reference(), exprOwner.Reference()));
				Value result = pProcessor->Run(sig);
				if (sig.IsSignalled()) {
					sig.PrintSignal(*env.GetConsoleErr());
					return 1;
				} else if (result.IsValid()) {
					env.GetConsole()->Println(sig, result.ToString().c_str());
				}
			}
		}
		interactiveFlag = false;
	}
	const char *encoding = opt.GetString("coding", "utf-8");
	if (argc >= 2) {
		String sourceName = OAL::FromNativeString(argv[1]);
		AutoPtr<Expr_Root> pExprRoot(Parser(sourceName).ParseStream(env, sig,
											sourceName.c_str(), encoding));
		if (sig.IsSignalled()) {
			sig.PrintSignal(*env.GetConsoleErr());
			return 1;
		}
		if (opt.IsSet("llvm")) {
			pExprRoot->GenerateCode(env, sig, *env.GetConsole());
		} else {
			AutoPtr<Processor> pProcessor(new Processor());
			pProcessor->PushSequence(new Expr::SequenceRoot(env.Reference(),
										pExprRoot->GetExprOwner().Reference()));
			pProcessor->Run(sig);
		}
		if (sig.IsSignalled()) {
			sig.PrintSignal(*env.GetConsoleErr());
			sig.ClearSignal();
		}
		interactiveFlag = false;
	}
	if (opt.IsSet("template")) {
		foreach_const (StringList, pPathName, opt.GetStringList("template")) {
			String pathName = OAL::FromNativeString(pPathName->c_str());
			AutoPtr<Stream> pStreamSrc(Stream::Open(env, sig,
								pathName.c_str(), Stream::ATTR_Readable));
			if (sig.IsSignalled()) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, encoding, true, false));
			if (sig.IsSignalled()) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			pStreamSrc->SetCodec(pCodec.release());
			bool autoIndentFlag = true;
			bool appendLastEOLFlag = false;
			AutoPtr<Template> pTemplate(new Template());
			if (!pTemplate->Read(env, sig, *pStreamSrc,
										autoIndentFlag, appendLastEOLFlag)) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			if (!pTemplate->Render(env, sig, env.GetConsole())) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
		}
		interactiveFlag = false;
	}
	if (interactiveFlag || opt.IsSet("interactive")) {
		if (!versionPrintedFlag && !quietFlag) PrintVersion(stdout);
		env.GetGlobal()->SetEchoFlag(true);
		ReadEvalPrintLoop(env, sig);
	}
	return 0;
}

void PrintVersion(FILE *fp)
{
	::fprintf(fp, "%s\n", Version::GetOpening());
}

void PrintHelp(FILE *fp)
{
	::fprintf(fp,
"usage: gura [option] [file] [arg] ...\n"
"available options:\n"
"-h             print this help\n"
"-t             interactive mode after running script file if specified\n"
"-i module[,..] import module(s) before parsing\n"
"-I dir         specify a directory to search for modules\n"
"-c cmd         execute program from command line\n"
"-q             suppress version printing at the beginning of interactive mode\n"
"-T template    evaluate script code embedded in template\n"
"-C dir         change directory before executing scripts\n"
"-d coding      set character coding to describe script\n"
"-v             print version string\n"
	);
}

#if defined(GURA_ON_MSWIN)
void ReadEvalPrintLoop(Environment &env, Signal sig)
{
	AutoPtr<Expr_Root> pExprRoot(new Expr_Root());
	Parser parser(SRCNAME_interactive);
	Stream *pConsole = env.GetConsole();
	pConsole->Print(sig, env.GetPrompt(parser.IsContinued()));
	for (;;) {
		int chRaw = ::fgetc(stdin);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		parser.EvalConsoleChar(env, sig, pExprRoot.get(), pConsole, ch);
		if (chRaw < 0) break;
		if (chRaw == '\n') {
			pConsole->Print(sig, env.GetPrompt(parser.IsContinued()));
		}
	}
}
#else
void ReadEvalPrintLoop(Environment &env, Signal sig)
{
	AutoPtr<Expr_Root> pExprRoot(new Expr_Root());
	Parser parser(SRCNAME_interactive);
	char *lineBuff = NULL;
	Stream *pConsole = env.GetConsole();
	while ((lineBuff = readline(env.GetPrompt(parser.IsContinued()))) != NULL) {
		for (char *p = lineBuff; ; p++) {
			char ch = (*p == '\0')? '\n' : *p;
			parser.EvalConsoleChar(env, sig, pExprRoot.get(), pConsole, ch);
			if (ch == '\n') break;
		}
		if (lineBuff[0] != '\0') {
			add_history(lineBuff);
		}
		free(lineBuff);
	}
}
#endif

}

int main(int argc, const char *argv[])
{
	return Gura::Main(argc, argv);
}
