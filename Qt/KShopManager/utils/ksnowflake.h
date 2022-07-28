#ifndef KSNOWFLAKE_H
#define KSNOWFLAKE_H

#include <string>
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

typedef long long superlong;

class KSnowFlake {
public:
    KSnowFlake();
    ~KSnowFlake();
    superlong getServerIdAsLong();
    superlong getNextId(superlong epoch);

private:
    superlong generateId(superlong epoch, superlong next, superlong shareid);
    superlong m_offset;
    superlong m_last;
    superlong m_shareid;
};

#endif // KSNOWFLAKE_H
