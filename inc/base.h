#pragma once 

#include <windows.h>
#include <winnt.h>
#include <winternl.h>

#include <cassert>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <mutex>
#include <memory>
#include <thread>
#include <array>
#include <tuple>

#define ENSURE_NTSUCCESS(f) \
    { if (!SUCCEEDED(f)) assert(false); }