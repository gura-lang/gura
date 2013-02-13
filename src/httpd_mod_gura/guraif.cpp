#include "guraif.h"
#undef strcasecmp
#undef strtoul
#include <gura.h>

typedef struct {
	int dummy;
} gura_dir_config;

typedef struct {
	int dummy;
} gura_server_config;

void *gura_create_dir_config(apr_pool_t *p, char *dir)
{
	gura_dir_config *cfg = (gura_dir_config *)apr_pcalloc(p, sizeof(gura_dir_config));
	return cfg;
}

void *gura_merge_dir_config(apr_pool_t *p, void *base_conf, void *new_conf)
{
	gura_dir_config *cfg = (gura_dir_config *)apr_pcalloc(p, sizeof(gura_dir_config));
	gura_dir_config *cfg_base = (gura_dir_config *)base_conf;
	gura_dir_config *cfg_new = (gura_dir_config *)new_conf;
    return cfg;
}

void *gura_create_server_config(apr_pool_t *p, server_rec *s)
{
	gura_server_config *cfg = (gura_server_config *)apr_pcalloc(p, sizeof(gura_server_config));
	//apr_thread_rwlock_create(&cfg->vm_reslists_lock, p);
    return cfg;
}

static const char *handler_GuraPath(cmd_parms *cmd, void *cfgv, const char *arg)
{
	gura_dir_config *cfg = (gura_dir_config *)cfgv;
    return NULL;
}

command_rec gura_cmds[] = {
	AP_INIT_TAKE1("GuraPath", (cmd_func)handler_GuraPath, NULL, OR_ALL,
				"Set a directory in which Gura searches modules"),
	{ NULL }
};

int gura_handler(request_rec *r)
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
