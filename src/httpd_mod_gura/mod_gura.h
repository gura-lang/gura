#ifndef __MOD_GURA_H__
#define __MOD_GURA_H__
#include <httpd.h>
#include <http_config.h>
#include <http_protocol.h>
#include <ap_config.h>

#ifdef __cplusplus
extern "C" {
#endif

extern module AP_MODULE_DECLARE_DATA gura_module;
extern command_rec gura_cmds[];

void *gura_create_dir_config(apr_pool_t *p, char *dir);
void *gura_merge_dir_config(apr_pool_t *p, void *base_conf, void *new_conf);
void *gura_create_server_config(apr_pool_t *p, server_rec *s);
int gura_handler(request_rec *r);

#ifdef __cplusplus
};
#endif

#endif
