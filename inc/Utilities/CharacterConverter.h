#pragma once

#include <base.h>

namespace ReSoel {
    namespace Utilities {
        std::wstring Utf8ToWindowsString(const std::string& in)
        {
            size_t charsToAllocate = 
                MultiByteToWideChar(CP_UTF8, 0, in.data(), static_cast<int>(in.size()), nullptr, 0);
            std::wstring asWide(charsToAllocate, 0);
            // By using basic_string's size() member we keep MultiByteToWideChar from
            // dealing with the NULL terminiator, which is implicitly tacked on the end of
            // the string for use when calling .c_str().
            MultiByteToWideChar(CP_UTF8, 0, in.data(), static_cast<int>(in.size()), 
                &asWide[0], static_cast<int>(asWide.size()));
            return asWide;
        }
    }
}