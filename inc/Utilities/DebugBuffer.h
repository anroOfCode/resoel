#pragma once

#include <base.h>

namespace ReSoel {
    namespace Utilities {
        // Think of the DebugBuffer as a write-only contiguous output buffer file
        // that we flush to from our intermediate buffer, m_buffer.
        class DebugBuffer :
            public std::basic_streambuf<char, std::char_traits<char>>
        {
        public:
            explicit DebugBuffer()
                : m_buffer(256)
            {
                setg(nullptr, nullptr, nullptr);
                setp(m_buffer.data(), m_buffer.data(), m_buffer.data() + m_buffer.size());
            }

        private:
            int sync() override try {
                // This allocates, which isn't ideal, but probably alright for our purposes.
                OutputDebugStringA(std::string(pbase(), pptr()).c_str());
                setp(m_buffer.data(), m_buffer.data(), m_buffer.data() + m_buffer.size());
                return 0;
            }
            // We'd really just catch a bad alloc.. 
            catch (...) {
                return -1;
            }

            int_type overflow(int_type c = std::char_traits<char>::eof()) override {
                auto s = sync();
                if (c != std::char_traits<char>::eof()) {
                    m_buffer[0] = c;
                    setp(m_buffer.data(), m_buffer.data() + 1, m_buffer.data() + m_buffer.size());
                }
                return s == -1 ? std::char_traits<char>::eof() : std::char_traits<char>::to_int_type(c);
            }

            std::vector<char> m_buffer;
        };
    }
}


