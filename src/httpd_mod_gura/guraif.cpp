//=============================================================================
// guraif.cpp
//=============================================================================
#include "mod_gura.h"
#undef strcasecmp
#undef strtoul
#include <gura.h>

//-----------------------------------------------------------------------------
// Context
//-----------------------------------------------------------------------------
class Context {
private:
	Gura::AutoPtr<Gura::Environment> _pEnv;
	Gura::Signal _sig;
public:
	Context();
	inline Gura::Environment &GetEnv() { return *_pEnv; }
	inline Gura::Signal &GetSignal() { return _sig; }
	bool Initialize();
};

struct gura_dir_config {
	int dummy;
};

struct gura_server_config {
	Context *pContext;
};

void *gura_create_dir_config(apr_pool_t *p, char *dir)
{
	gura_dir_config *cfg = reinterpret_cast<gura_dir_config *>(
								apr_pcalloc(p, sizeof(gura_dir_config)));
	return cfg;
}

void *gura_merge_dir_config(apr_pool_t *p, void *base_conf, void *new_conf)
{
	gura_dir_config *cfg = reinterpret_cast<gura_dir_config *>(
									apr_pcalloc(p, sizeof(gura_dir_config)));
	gura_dir_config *cfg_base = reinterpret_cast<gura_dir_config *>(base_conf);
	gura_dir_config *cfg_new = reinterpret_cast<gura_dir_config *>(new_conf);
    return cfg;
}

void *gura_create_server_config(apr_pool_t *p, server_rec *s)
{
	gura_server_config *cfg = reinterpret_cast<gura_server_config *>(
									apr_pcalloc(p, sizeof(gura_server_config)));
	cfg->pContext = new Context();
	cfg->pContext->Initialize();
	//apr_thread_rwlock_create(&cfg->vm_reslists_lock, p);
    return cfg;
}

static const char *handler_GuraPath(cmd_parms *cmd, void *cfgv, const char *arg)
{
	gura_dir_config *cfg = reinterpret_cast<gura_dir_config *>(cfgv);
    return NULL;
}

command_rec gura_cmds[] = {
	AP_INIT_TAKE1("GuraPath", (cmd_func)handler_GuraPath, NULL, OR_ALL,
				"Set a directory in which Gura searches modules"),
	{ NULL }
};

//-----------------------------------------------------------------------------
// Context
//-----------------------------------------------------------------------------
Context::Context() : _pEnv(new Gura::Environment())
{
}

bool Context::Initialize()
{
	int argc = 0;
	return _pEnv->InitializeAsRoot(_sig, argc, NULL, 0, NULL);
}

namespace Gura {

class StreamAPR : public Stream {
private:
	request_rec *_r;
public:
	inline StreamAPR(Environment &env, Signal sig, request_rec *r) :
									Stream(env, sig, ATTR_Writable), _r(r) {}
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

const char *StreamAPR::GetName() const
{
	return "Apache";
}

const char *StreamAPR::GetIdentifier() const
{
	return NULL;
}

size_t StreamAPR::DoRead(Signal sig, void *buff, size_t len)
{
	return 0;
}

size_t StreamAPR::DoWrite(Signal sig, const void *buff, size_t len)
{
	ap_rwrite(buff, static_cast<int>(len), _r);
	return len;
}

bool StreamAPR::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	return false;
}

bool StreamAPR::DoFlush(Signal sig)
{
	return true;
}

bool StreamAPR::DoClose(Signal sig)
{
	return Stream::DoClose(sig);
}

size_t StreamAPR::DoGetSize()
{
	return 0;
}

void OutputErrorMessage(request_rec *r, Signal &sig)
{
	ap_rprintf(r, "<html>\n");
	ap_rprintf(r, "<body>\n");
	ap_rprintf(r, "<pre>\n");
	ap_rputs(sig.GetError().MakeText().c_str(), r);
	ap_rputs("\n", r);
	ap_rprintf(r, "</pre>\n");
	AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
	sig.GetError().GetExprCauseOwner().ExtractTrace(*pExprOwner);
	if (!pExprOwner->empty()) {
		ap_rprintf(r, "<p>Traceback:</p>\n");
		ap_rprintf(r, "<table border=\"1\">\n");
		foreach_const (ExprOwner, ppExpr, *pExprOwner) {
			Expr *pExpr = *ppExpr;
			ap_rprintf(r, "<tr>");
			ap_rprintf(r, "<td><code>%s</code></td>",
					EscapeHtml(pExpr->MakePosText().c_str(), false).c_str());
			ap_rprintf(r, "<td><code>%s</code></td>",
					EscapeHtml(pExpr->ToString(Expr::SCRSTYLE_Brief).c_str(), false).c_str());
			ap_rprintf(r, "</tr>\n");
		}
		ap_rprintf(r, "</table>\n");
	}
	ap_rprintf(r, "</body>\n");
	ap_rprintf(r, "</html>\n");
}

int Handler(request_rec *r)
{
	if (::strcmp(r->handler, "gura") != 0) return DECLINED;
	r->content_type = "text/html";
	if (r->header_only) return OK;
	Context *pContext = reinterpret_cast<gura_server_config *>(
		ap_get_module_config(r->server->module_config, &gura_module))->pContext;
	Environment &env = pContext->GetEnv();
	Signal &sig = pContext->GetSignal();
	env.AssignValue(Symbol::Add("apr"), Value(new Object_stream(env, new StreamAPR(env, sig, r))), false);
	const char *fileName = "C:/Users/yutaka/gura/src/httpd_mod_gura/test.gura";
	AutoPtr<Expr_Root> pExprRoot(Parser().ParseStream(env, sig, fileName, NULL));
	if (pExprRoot.IsNull()) {
		OutputErrorMessage(r, sig);
		sig.ClearSignal();
	} else {
		AutoPtr<Processor> pProcessor(new Processor());
		pProcessor->PushSequence(new Expr::SequenceRoot(env.Reference(),
									pExprRoot->GetExprOwner().Reference()));
		pProcessor->Run(sig);
		if (sig.IsSignalled()) {
			OutputErrorMessage(r, sig);
			sig.ClearSignal();
		}
	}
	return OK;
}

};

int gura_handler(request_rec *r)
{
	return Gura::Handler(r);
}
