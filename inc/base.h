#pragma once 

// Windows header files...
#include <windows.h>
#include <winnt.h>
#include <winternl.h>

// STL stuff...
#include <exception>
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

#define ENSURE_SUCCESS(f) \
    { if (f) assert(false); }

typedef std::shared_ptr<void> SharedHandle;