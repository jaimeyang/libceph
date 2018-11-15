//
// Created by jaime on 18-11-15.
//

#ifndef CEPH_CLIENT_CEPH_H
#define CEPH_CLIENT_CEPH_H

#include <rados/librados.h>

class ceph {
public:
    ceph();
    ~ceph();
    void connectCeph(const char* clustername);

};


#endif //CEPH_CLIENT_CEPH_H
