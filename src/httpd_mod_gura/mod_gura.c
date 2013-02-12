/*
  Add the following content into Apache's configuration file httpd.conf.

    LoadModule gura_module modules/mod_gura.so
    <Location "/gura">
      SetHandler gura
    </Location>
*/
#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

#include <stdarg.h>

module AP_MODULE_DECLARE_DATA gura_module;

typedef struct {
	int dummy;
} gura_dir_config;

typedef struct {
	int dummy;
} gura_request_config;

typedef struct {
	int dummy;
} gura_server_config;

static void *create_dir_config(apr_pool_t *p, char *dir)
{
	gura_dir_config *cfg = (gura_dir_config *)apr_pcalloc(p, sizeof(gura_dir_config));
	return cfg;
}

static void *merge_dir_config(apr_pool_t *p, void *base_conf, void *new_conf)
{
	gura_dir_config *cfg = (gura_dir_config *)apr_pcalloc(p, sizeof(gura_dir_config));
	gura_dir_config *cfg_base = (gura_dir_config *)base_conf;
	gura_dir_config *cfg_new = (gura_dir_config *)new_conf;
    return cfg;
}

static void *create_server_config(apr_pool_t *p, server_rec *s)
{
	gura_server_config *cfg = (gura_server_config *)apr_pcalloc(p, sizeof(gura_server_config));
	//apr_thread_rwlock_create(&cfg->vm_reslists_lock, p);
    return cfg;
}

static int create_request_config(request_rec *r)
{
    gura_request_config *cfg = (gura_request_config *)apr_palloc(r->pool, sizeof(gura_request_config));
    ap_set_module_config(r->request_config, &gura_module, cfg);
    return OK;
}

static const char *handler_GuraPath(cmd_parms *cmd, void *cfgv, const char *arg)
{
	gura_dir_config *cfg = (gura_dir_config *)cfgv;
    return NULL;
}

static command_rec cmds[] = {
	AP_INIT_TAKE1("GuraPath", (cmd_func)handler_GuraPath, NULL, OR_ALL,
				"Set a directory in which Gura searches modules"),
	{ NULL }
};

static int gura_handler(request_rec *r)
{
	if (strcmp(r->handler, "gura") != 0) return DECLINED;
	r->content_type = "text/html";
	if (r->header_only) return OK;
	ap_rprintf(r, "<html><body>\n");
	ap_rprintf(r, "<table border=\"1\">\n");
	ap_rprintf(r, "<tr><td>r->handler</td><td>%s</td>\n", r->handler);
	ap_rprintf(r, "<tr><td>r->uri</td><td>%s</td>\n", r->uri);
	ap_rprintf(r, "<tr><td>r->args</td><td>%s</td>\n", r->args);
	ap_rprintf(r, "</table>\n");
	ap_rprintf(r, "</body></html>\n");
	return OK;
}

static void register_hooks(apr_pool_t *p)
{
	ap_hook_handler(gura_handler, NULL, NULL, APR_HOOK_MIDDLE);
}
 
AP_DECLARE_MODULE(gura) = {
	STANDARD20_MODULE_STUFF,
	create_dir_config,		/* create per-dir config structures */
	merge_dir_config,		/* merge per-dir config structures */
	create_server_config,	/* create per-server config structures */
	NULL,					/* merge per-server config structures */
	cmds,					/* table of config file commands */
	register_hooks			/* register hooks */
};
