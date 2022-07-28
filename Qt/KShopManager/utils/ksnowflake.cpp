#include "ksnowflake.h"

#define MAX_NEXT 0b1111111111111111L
#define OFFSET 946656000L

using namespace std;

KSnowFlake::KSnowFlake()
{
    m_offset = 0;
    m_last = 0;
    m_shareid = getServerIdAsLong();
    m_shareid &= 0x1f;
}

KSnowFlake::~KSnowFlake()
{

}

superlong KSnowFlake::getServerIdAsLong()
{
    struct hostent *host = NULL;
    char name[256];
    char szIp[32];
    superlong lIp;
    const char *ret = NULL;

    gethostname(name, sizeof(name));
    host = gethostbyname(name);
    ret = inet_ntop(host->h_addrtype, host->h_addr_list[0], szIp, sizeof(szIp));
    if(ret == NULL)
    {
        cout << "hostname transform to ip failed" << endl;
        return -1;
    }
    lIp = htonl(inet_addr(szIp));
    return lIp;
}

superlong KSnowFlake::getNextId(superlong epoch)
{
    superlong next;
    if(epoch < m_last)
    {
        cout << "clock is back: " << epoch << " from previous: " << m_last << endl;
        epoch = m_last;
    }
    if(m_last != epoch)
    {
        m_last = epoch;
        m_offset = 0;
    }
    m_offset++;
    next = m_offset & MAX_NEXT;
    if(next == 0)
    {
        cout << "maximum id reached in 1 second in epoch: " << endl;
        return getNextId(epoch+1);
    }
    superlong res = generateId(epoch, next, m_shareid);
    if(res < 0)
        res = -res;
    return res;
}

superlong KSnowFlake::generateId(superlong epoch, superlong next, superlong shareid)
{
    return ((epoch-OFFSET) << 21 | (next << 5) | shareid);
}
