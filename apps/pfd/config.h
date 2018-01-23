#ifndef __PFD_CONFIG_H__
#define __PFD_CONFIG_H__

#include <ela_carrier.h>
#include <ela_session.h>
#include <linkedhashtable.h>

#define MODE_CLIENT     1
#define MODE_SERVER     2

typedef struct {
    HashEntry he;
    char *name;
    char *host;
    char *port;
} PFService;

typedef struct {
    HashEntry he;
    char *userid;
    char *services[0];
} PFUser;

typedef struct {
   bool udp_enabled;

    int bootstraps_size;
    BootstrapNode **bootstraps;

    int loglevel;
    char *logfile;

    char *datadir;

    int mode;
    char *serverid;
    char *server_address;

    Hashtable *services;
    Hashtable *users;
} PFConfig;

PFConfig *load_config(const char *config_file);

#endif /* __PFD_CONFIG_H__ */
