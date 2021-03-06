//
// Created by jaime on 18-11-15.
//

#include <cstdio>
#include <cstdlib>
#include "ceph.h"


ceph::ceph()
{

}

ceph::~ceph()
{

}

void ceph::connectCeph(const char* clustername)
{
    rados_t cluster;
    char cluster_name[] = "ceph";
    char user_name[] = "client.admin";
    uint64_t flags;

    int err = rados_create2(&cluster,cluster_name,user_name,flags);
    if ( err < 0 )
    {
        fprintf(stderr,"%s:couldn't create the cluster handler %s\n",clustername,strerror(-err));
        exit(-1);
    }
    else
    {
        printf("\nCreate a cluster handle\n");
    }

    err = rados_conf_read_file(cluster,"/etc/ceph/ceph.conf");
    if ( err < 0 )
    {
        fprintf(stderr,"%s:couldn't read config file:%s\n",clustername,strerror(-err));
        exit(-1);
    }
    else
    {
        printf("\nRead the config file \n");
    }

    err = rados_conf_parse_argv(cluster,argc,argv);
    if (err < 0 )
    {
        fprintf(stderr,"%s:cannot parse comand line arguments:%s\n",argv[0],strerror(-err));
        exit(-1);
    }
    else
    {
        printf("\nRead the comand line arguments\n");
    }

    err = rados_connect(cluster);
    if ( err < 0 )
    {
        fprintf(stderr,"%s:cannot parse comand line arguments:%s\n",argv[0],strerror(-err));
        exit(-1);
    }
    else
    {
        printf("\nConnected to the cluster");
    }
}