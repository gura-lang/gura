#include "mod_gura.h"
#undef strcasecmp
#undef strtoul
#include <gura.h>

class Context {
private:
	Gura::EnvironmentRoot _env;
	Gura::Signal _sig;
public:
	inline Context() { _env.Initialize(_sig, 0, NULL); }
	inline Gura::Environment &GetEnv() { return _env; }
	inline Gura::Signal &GetSignal() { return _sig; }
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

namespace Gura {

class StreamAPR : public Stream {
private:
	request_rec *_r;
public:
	inline StreamAPR(Signal sig, request_rec *r) : Stream(sig, ATTR_Writable), _r(r) {}
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

int Handler(request_rec *r)
{
	if (::strcmp(r->handler, "gura") != 0) return DECLINED;
	r->content_type = "text/html";
	if (r->header_only) return OK;
	Context *pContext = reinterpret_cast<gura_server_config *>(
		ap_get_module_config(r->server->module_config, &gura_module))->pContext;
	Environment &env = pContext->GetEnv();
	Signal &sig = pContext->GetSignal();
	env.AssignValue(Symbol::Add("apr"), Value(new Object_stream(env, new StreamAPR(sig, r))), false);
	AutoPtr<Expr> pExpr(Parser().ParseStream(env, sig, "C:/Users/yutaka/gura/src/httpd_mod_gura/test.gura", NULL));
	if (pExpr.IsNull()) {
		ap_rprintf(r, "<html>\n");
		ap_rprintf(r, "<body>\n");
		ap_rprintf(r, "%s\n", EscapeHtml(sig.GetErrString().c_str(), true));
		ap_rprintf(r, "</body>\n");
		ap_rprintf(r, "</html>\n");
	} else {
		pExpr->Exec(env, sig);
		if (sig.IsSignalled()) {
			ap_rprintf(r, "<html>\n");
			ap_rprintf(r, "<body>\n");
			ap_rprintf(r, "<pre>\n");
			ap_rputs(sig.GetErrString().c_str(), r);
			ap_rputs("\n", r);
			ap_rputs(sig.GetErrTrace().c_str(), r);
			ap_rprintf(r, "</pre>\n");
			ap_rprintf(r, "</body>\n");
			ap_rprintf(r, "</html>\n");
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
