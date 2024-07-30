#include "Platform.hpp"

// Platform specific
#if defined(_WIN32) || defined(__USE_W32_SOCKETS)
    #include <ws2tcpip.h>
    #ifdef _MSC_VER
        #pragma comment(lib, "Ws2_32.lib")
    #endif
#else
    #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
        #include <netinet/in.h>
    #endif
    #include <arpa/inet.h>
#endif

#ifdef __linux__
    #include <pthread.h>
#endif

#if defined(_WIN32) || defined(__USE_W32_SOCKETS)
    #include <windows.h>
#endif

#ifndef _WIN32
    #include <unistd.h>
#endif

namespace dai {
namespace platform {

uint32_t getIPv4AddressAsBinary(std::string address) {
    uint32_t binary = 0;
    if(address == "") {
        // inet_addr returns 0xFFFFFFFF if addr is ""
        return 0;
    }

#if defined(_WIN32) || defined(__USE_W32_SOCKETS)
    #if(_WIN32_WINNT <= 0x0501)
    binary = inet_addr(address.c_str());  // for XP
    #else
    inet_pton(AF_INET, address.c_str(), &binary);  // for Vista or higher
    #endif
#else
    inet_pton(AF_INET, address.c_str(), &binary);
#endif

    return binary;
}

std::string getIPv4AddressAsString(std::uint32_t binary) {
    char address[INET_ADDRSTRLEN] = {0};

#if defined(_WIN32) || defined(__USE_W32_SOCKETS)
    InetNtopA(AF_INET, &binary, address, sizeof(address));
#else
    inet_ntop(AF_INET, &binary, address, sizeof(address));
#endif

    return {address};
}

void setThreadName(JoiningThread& thread, const std::string& name) {
#ifdef __linux__
    auto handle = thread.native_handle();
    pthread_setname_np(handle, name.c_str());
#endif
    return;
}

void setThreadPriority(JoiningThread& thread, int priority) {
#ifdef __linux__
    auto handle = thread.native_handle();
    int policy;
    struct sched_param param;
    pthread_getschedparam(handle, &policy, &param);
    param.sched_priority = priority;
    pthread_setschedparam(handle, policy, &param);
#endif
    return;
}

int getThreadPriority(JoiningThread& thread) {
#ifdef __linux__
    auto handle = thread.native_handle();
    int policy;
    struct sched_param param;
    pthread_getschedparam(handle, &policy, &param);
    return param.sched_priority;
#endif
    return -1;
}

int getMinThreadPriority(JoiningThread& thread) {
#ifdef __linux__
    auto handle = thread.native_handle();
    int policy;
    struct sched_param param;
    pthread_getschedparam(handle, &policy, &param);
    int minPriority = sched_get_priority_min(policy);
    return minPriority;
#endif
    return -1;
}

int getMaxThreadPriority(JoiningThread& thread) {
#ifdef __linux__
    auto handle = thread.native_handle();
    int policy;
    struct sched_param param;
    pthread_getschedparam(handle, &policy, &param);
    int maxPriority = sched_get_priority_max(policy);
    return maxPriority;
#endif
    return -1;
}

std::string getTempPath() {
    std::string tmpPath;
#if defined(_WIN32) || defined(__USE_W32_SOCKETS)
    char tmpPathBuffer[MAX_PATH];
    GetTempPathA(MAX_PATH, tmpPathBuffer);
    tmpPath = tmpPathBuffer;
#else
    char tmpTemplate[] = "/tmp/depthai_XXXXXX";
    char* tmpName = mkdtemp(tmpTemplate);
    if(tmpName == nullptr) {
        tmpPath = "/tmp";
    } else {
        tmpPath = tmpName;
        tmpPath += '/';
    }
#endif
    return tmpPath;
}

}  // namespace platform
}  // namespace dai
