#include "debug.hpp"

std::streamsize SWOStreamBuffer::xsputn(const char_type *s, std::streamsize n)
{
    printString(std::string(s, n));
    return n;
}

int SWOStreamBuffer::overflow(int c)
{
    if (c != EOF)
    {
        char_type ch = c;
        printString(std::string(1, ch));
    }
    return c;
}

SWOStream::SWOStream() : std::ostream(&buffer) {}

SWOStream swoTerminal;
