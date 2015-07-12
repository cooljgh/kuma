#ifndef __TestLoop_H__
#define __TestLoop_H__

#include "kmapi.h"

#include <thread>
#include <mutex>
#include <map>

using namespace kuma;

typedef enum {
    PROTO_TCP,
    PROTO_TCPS,
    PROTO_HTTP,
    PROTO_HTTPS,
    PROTO_WS,
    PROTO_WSS,
    PROTO_UDP,
    PROTO_AUTO
} Proto;

class LoopObject
{
public:
    virtual ~LoopObject() {}
    virtual int close() = 0;
};

class LoopPool;
class TestLoop
{
public:
    TestLoop(LoopPool* server, PollType poll_type = POLL_TYPE_NONE);

    bool init();
    void stop();
    
    void addFd(SOCKET_FD fd, Proto proto);
    void addFd(SOCKET_FD fd, HttpParser&& parser);
    
    void addObject(long conn_id, LoopObject* obj);
    void removeObject(long conn_id);
    
private:
    void cleanup();
    void run();
    
private:
    typedef std::map<long, LoopObject*> ObjectMap;
    
    EventLoop*      loop_;
    LoopPool*       server_;
    
    std::mutex      obj_mutex_;
    ObjectMap       obj_map_;
    
    std::thread     thread_;
};

#endif
