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
	Signal sig;
	static const Option::Info optInfoTbl[] = {
		{ "help",			'h', false	},
		{ "interactive",	't', false	},
		{ "import",			'i', true	},
		{ "import-dir",		'I', true	},
		{ "command",		'c', true	},
		{ "template",		'T', true	},
		{ "directory",		'C', true	},
		{ "coding",			'd', true	},
		{ "quiet",			'q', false	},
		{ "printcmdline",	'P', false	},
		{ "version",		'v', false	},
		{ "llvm",			'o', true	},
	};
	Option opt(optInfoTbl, ArraySizeOf(optInfoTbl));
	String strErr;
	bool rtn = opt.Parse(argc, argv, strErr);
	if (!rtn) {
		::fprintf(stderr, "%s\n", strErr.c_str());
		return 1;
	}
	if (opt.IsSet("version")) {
		PrintVersion(stderr);
		return 0;
	}
	if (opt.IsSet("help")) {
		PrintVersion(stderr);
		PrintHelp(stderr);
		return 0;
	}
	if (opt.IsSet("directory")) {
		OAL::ChangeCurDir(opt.GetString("directory", ""));
	}
	if (opt.IsSet("printcmdline") && argc > 1) {
		for (int i = 1; i < argc; i++) {
			::fprintf(stderr, (i == 1)? "%s" : " %s", argv[i]);
		}
		::fprintf(stderr, "\n");
	}
	EnvironmentRoot env;
	if (!env.Initialize(sig, argc, argv)) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		return 1;
	}
	bool interactiveFlag = true;
	if (opt.IsSet("import-dir")) {
		env.AddModuleSearchPath(sig, opt.GetStringList("import-dir"));
	}
	if (opt.IsSet("import")) {
		foreach_const (StringList, pModuleNames, opt.GetStringList("import")) {
			if (!env.ImportModules(sig, pModuleNames->c_str(), false, false)) {
				env.GetConsoleErr()->PrintSignal(sig, sig);
				return 1;
			}
		}
	}
	if (opt.IsSet("command")) {
		foreach_const (StringList, pCmd, opt.GetStringList("command")) {
			const char *cmd = pCmd->c_str();
			if (::strcmp(cmd, "") == 0) continue;
			ExprOwner exprOwner;
			if (!Parser().ParseString(env, sig, exprOwner, "<command line>", cmd)) {
				env.GetConsoleErr()->PrintSignal(sig, sig);
				return 1;
			}
			if (exprOwner.empty()) {
				env.GetConsoleErr()->Println(sig, "incomplete command");
			} else {
				Value result = exprOwner.Exec(env, sig, true);
				if (sig.IsSignalled()) {
					env.GetConsoleErr()->PrintSignal(sig, sig);
					return 1;
				} else if (result.IsValid()) {
					env.GetConsole()->Println(sig, result.ToString(sig).c_str());
				}
			}
		}
		interactiveFlag = false;
	}
	const char *encoding = opt.GetString("coding", "utf-8");
	Expr *pExprRoot = NULL;
	if (argc >= 2) {
		pExprRoot = Parser().ParseStream(env, sig, argv[1], encoding);
		if (sig.IsSignalled()) {
			env.GetConsoleErr()->PrintSignal(sig, sig);
			return 1;
		}
		if (opt.IsSet("llvm")) {
			pExprRoot->GenerateCode(env, sig, *env.GetConsole());
		} else {
			pExprRoot->Exec(env, sig);
		}
		if (sig.IsSignalled()) {
			env.GetConsoleErr()->PrintSignal(sig, sig);
			sig.ClearSignal();
		}
		interactiveFlag = false;
	}
	if (opt.IsSet("template")) {
		foreach_const (StringList, pPathName, opt.GetStringList("template")) {
			AutoPtr<Stream> pStreamSrc(Directory::OpenStream(env, sig,
								pPathName->c_str(), Stream::ATTR_Readable));
			
			// encoding
			
			if (sig.IsSignalled()) {
				env.GetConsoleErr()->PrintSignal(sig, sig);
				return 1;
			}
			TemplateEngine(true, false).EvalStream(env, sig,
										*pStreamSrc, *env.GetConsole());
			if (sig.IsSignalled()) {
				env.GetConsoleErr()->PrintSignal(sig, sig);
				return 1;
			}
		}
		interactiveFlag = false;
	}
	if (interactiveFlag || opt.IsSet("interactive")) {
		PrintVersion(stdout);
		env.SetEchoFlag(true);
		ReadEvalPrintLoop(env, sig);
	}
	Expr::Delete(pExprRoot);
	return 0;
}

void PrintVersion(FILE *fp)
{
	::fprintf(fp, "%s\n", GetOpening());
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
"-T template    evaluate script code embedded in template\n"
"-C dir         change directory before executing scripts\n"
"-d coding      set character coding to describe script\n"
"-v             print version string\n"
	);
}

#if defined(GURA_ON_MSWIN)
void ReadEvalPrintLoop(Environment &env, Signal sig)
{
	Parser parser;
	ExprOwner exprOwner;
	Stream *pConsole = env.GetConsole();
	pConsole->Print(sig, env.GetPrompt(parser.IsContinued()));
	for (;;) {
		int ch = ::fgetc(stdin);
		parser.EvalConsoleChar(env, sig, exprOwner,
								pConsole, static_cast<unsigned char>(ch));
		if (ch < 0) break;
		if (ch == '\n') {
			pConsole->Print(sig, env.GetPrompt(parser.IsContinued()));
		}
	}
}
#else
void ReadEvalPrintLoop(Environment &env, Signal sig)
{
	Parser parser;
	ExprOwner exprOwner;
	char *lineBuff = NULL;
	Stream *pConsole = env.GetConsole();
	while (lineBuff = readline(env.GetPrompt(parser.IsContinued()))) {
		for (char *p = lineBuff; ; p++) {
			char ch = (*p == '\0')? '\n' : *p;
			parser.EvalConsoleChar(env, sig, exprOwner, pConsole, ch);
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
