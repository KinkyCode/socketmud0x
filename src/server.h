/*
*Socketmud0x
*/
// ****************************************************************************
// SocketMud II Copyright 2004 Brian Graversen
// ****************************************************************************
// Revision History
// ----------------
// 19/01/04) Initial server code released
// ****************************************************************************
// This product can be used freely as long as this copyright header remains
// intact. This header may not be removed or changed, and any work released
// based on this code must contain this header information in all files.
// ****************************************************************************

#ifndef SERVER_H
#define SERVER_H
#include <list>
#include <arpa/inet.h>
#include <sys/time.h>
#include "socket.h"

class Server
{
    void                 Accept           ();
    void                 CloseSocket      ( Socket *pSocket );
    std::list<Socket*>   socketList;
    int                  control;
    fd_set               fSet;
    fd_set               rSet;
    sockaddr_in          my_addr;
    struct timeval       lastSleep;
public:
    Server  ();
    ~Server ();

    bool                 Connect          ( int port );
    void                 FlushSockets     ();
    bool                 PollSockets      ();
    void                 Sleep            ( int pps );
    std::list<Socket*>   GetSocketList    ();
};
#endif
