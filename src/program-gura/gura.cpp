//=============================================================================
// Gura Programming Language
// Copyright (C) 2011-2017 ypsitau
//=============================================================================
#include <gura.h>

#if defined(GURA_ON_MSWIN)
#else
#include <readline/readline.h>
#include <readline/history.h>
#endif

namespace Gura {

void PrintVersion(FILE *fp, bool timeStampFlag);
void PrintHelp(FILE *fp);

//-----------------------------------------------------------------------------
// InteractiveHandlerEx
//-----------------------------------------------------------------------------
class InteractiveHandlerEx : public InteractiveHandler {
public:
	Value Exec(Environment &env);
private:
	static bool ReadLine(const char *prompt, String &strLine);
};

//-----------------------------------------------------------------------------
// Main entry
//-----------------------------------------------------------------------------
int Main(int argc, const char *argv[])
{
	static const Option::Info optInfoTbl[] = {
		{ "help",			'h', Option::TYPE_Flag	},
		{ "interactive",	't', Option::TYPE_Flag	},
		{ "import",			'i', Option::TYPE_Value	},
		{ "command",		'c', Option::TYPE_Value	},
		{ "template",		'T', Option::TYPE_Value	},
		{ "directory",		'C', Option::TYPE_Value	},
		{ "coding",			'd', Option::TYPE_Value	},
		{ "quiet",			'q', Option::TYPE_Flag	},
		{ "printcmdline",	'P', Option::TYPE_Flag	},
		{ "version",		'v', Option::TYPE_Flag	},
		{ "llvm",			'o', Option::TYPE_Value	},
		{ "debug",			'g', Option::TYPE_Flag	},
	};
	Signal sig;
	AutoPtr<Environment> pEnv(new Environment(sig));
	Environment &env = *pEnv;
	if (!env.InitializeAsRoot(argc, argv, optInfoTbl, ArraySizeOf(optInfoTbl))) {
		sig.PrintSignal(*env.GetConsoleErr());
		return 1;
	}
	env.SetInteractiveHandler(new InteractiveHandlerEx());
	Option &opt = env.GetOption();
	if (opt.IsSet("version")) {
		PrintVersion(stderr, false);
		return 0;
	}
	if (opt.IsSet("help")) {
		PrintVersion(stderr, false);
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
		PrintVersion(stdout, false);
		versionPrintedFlag = true;
	}
	if (opt.IsSet("debug")) {
		env.SetMonitor(new MonitorDebugger());
	}
	if (opt.IsSet("import")) {
		foreach_const (StringList, pModuleNames, opt.GetStringList("import")) {
			if (!env.ImportModules(pModuleNames->c_str(), false, false)) {
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
			if (!Parser(sig, SRCNAME_cmdline).ParseString(env, exprOwner, cmd, true)) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			if (exprOwner.empty()) {
				env.GetConsoleErr()->Println(sig, "incomplete command");
			} else {
				Value result = pExprRoot->Exec(env);
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
		AutoPtr<Expr_Root> pExprRoot(Parser(sig, sourceName).ParseStream(env,
											sourceName.c_str(), encoding));
		if (sig.IsSignalled()) {
			sig.PrintSignal(*env.GetConsoleErr());
			return 1;
		}
		pExprRoot->Exec(env);
		if (sig.IsSignalled()) {
			sig.PrintSignal(*env.GetConsoleErr());
			sig.ClearSignal();
		}
		interactiveFlag = false;
	}
	if (opt.IsSet("template")) {
		foreach_const (StringList, pPathName, opt.GetStringList("template")) {
			String pathName = OAL::FromNativeString(pPathName->c_str());
			AutoPtr<Stream> pStreamSrc(Stream::Open(env,
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
			if (!pTemplate->Read(env, *pStreamSrc,
										autoIndentFlag, appendLastEOLFlag)) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
			if (!pTemplate->Render(env, env.GetConsole())) {
				sig.PrintSignal(*env.GetConsoleErr());
				return 1;
			}
		}
		interactiveFlag = false;
	}
	if (interactiveFlag || opt.IsSet("interactive")) {
		if (!versionPrintedFlag && !quietFlag) PrintVersion(stdout, false);
		env.ExecInteractiveHandler();
	}
	return 0;
}

void PrintVersion(FILE *fp, bool timeStampFlag)
{
	::fprintf(fp, "%s\n", Version::GetBanner(timeStampFlag));
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
"-g             debug mode\n"
"-v             print version string\n"
	);
}

//-----------------------------------------------------------------------------
// InteractiveHandlerEx
//-----------------------------------------------------------------------------
Value InteractiveHandlerEx::Exec(Environment &env)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr_Root> pExprRoot(new Expr_Root());
	Parser parser(sig, SRCNAME_interactive);
	bool echoFlag = env.GetGlobal()->GetEchoFlag();
	env.GetGlobal()->SetEchoFlag(true);
	Stream *pConsole = env.GetConsole();
	String strLine;
	while (ReadLine(env.GetPrompt(parser.IsContinued()), strLine)) {
		if (strLine == ";") break;
		foreach_const (String, p, strLine) {
			char ch = *p;
			parser.EvalConsoleChar(env, pExprRoot.get(), pConsole, ch);
		}
		parser.EvalConsoleChar(env, pExprRoot.get(), pConsole, '\n');
	}
	env.GetGlobal()->SetEchoFlag(echoFlag);
	return Value::Nil;
}

#if defined(GURA_ON_MSWIN)
bool InteractiveHandlerEx::ReadLine(const char *prompt, String &strLine)
{
	strLine.clear();
	::printf("%s", prompt);
	for (;;) {
		int chRaw = ::fgetc(stdin);
		if (chRaw < 0) return false;
		char ch = static_cast<UChar>(chRaw);
		if (ch == '\n') break;
		strLine += ch;
	}
	return true;
}
#else
bool InteractiveHandlerEx::ReadLine(const char *prompt, String &strLine)
{
	char *lineBuff = readline(prompt);
	if (lineBuff == nullptr) return false;
	if (lineBuff[0] != '\0') add_history(lineBuff);
	strLine = lineBuff;
	::free(lineBuff);
	return true;
}
#endif

}

int main(int argc, const char *argv[])
{
	return Gura::Main(argc, argv);
}
