/*
  Add the following content into Apache's configuration file httpd.conf.

    LoadModule gura_module modules/mod_gura.so
    <Location "/gura">
      SetHandler gura
    </Location>
*/
#include "mod_gura.h"

static void register_hooks(apr_pool_t *p)
{
	ap_hook_handler(gura_handler, NULL, NULL, APR_HOOK_MIDDLE);
}
 
AP_DECLARE_MODULE(gura) = {
	STANDARD20_MODULE_STUFF,
	gura_create_dir_config,		/* create per-dir config structures */
	gura_merge_dir_config,		/* merge per-dir config structures */
	gura_create_server_config,	/* create per-server config structures */
	NULL,						/* merge per-server config structures */
	gura_cmds,					/* table of config file commands */
	register_hooks				/* register hooks */
};
