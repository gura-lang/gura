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

/* The sample content handler */
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
 
static void gura_register_hooks(apr_pool_t *p)
{
	ap_hook_handler(gura_handler, NULL, NULL, APR_HOOK_MIDDLE);
}
 
/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA gura_module = {
	STANDARD20_MODULE_STUFF,
	NULL,				/* create per-dir config structures */
	NULL,				/* merge per-dir config structures */
	NULL,				/* create per-server config structures */
	NULL,				/* merge per-server config structures */
	NULL,				/* table of config file commands */
	gura_register_hooks /* register hooks */
};
