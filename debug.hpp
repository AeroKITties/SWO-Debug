#pragma once

#include <iostream>
#include <streambuf>
#include <vector>
#include <string>
#include <type_traits>
#include "swo.hpp"

class SWOStreamBuffer : public std::streambuf
{
public:
    virtual std::streamsize xsputn(const char_type *s, std::streamsize n) override;
    virtual int overflow(int c) override;
};

class SWOStream : public std::ostream
{
public:
    SWOStream();

    template <typename T>
    SWOStream &operator<<(const T &val)
    {
        print(val);
        return *this;
    }

    SWOStream &operator<<(std::ostream &(*manip)(std::ostream &))
    {
        static_cast<std::ostream &>(*this) << manip;
        return *this;
    }

private:
    SWOStreamBuffer buffer;

    // Перегрузка для числовых типов
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value>::type
    print(const T &val)
    {
        static_cast<std::ostream &>(*this) << std::to_string(val);
    }

    // Перегрузка для std::string
    void print(const std::string &val)
    {
        static_cast<std::ostream &>(*this) << val;
    }

    // Перегрузка для const char*
    void print(const char *val)
    {
        static_cast<std::ostream &>(*this) << val;
    }

    // Обработка векторов с элементами, поддерживающими operator<<
    template <typename T>
    typename std::enable_if<!std::is_same<T, char>::value && !std::is_same<T, wchar_t>::value && !std::is_same<T, char16_t>::value && !std::is_same<T, char32_t>::value>::type
    print(const std::vector<T> &vec)
    {
        *this << "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            *this << vec[i];
            if (i != vec.size() - 1)
            {
                *this << ", ";
            }
        }
        *this << "]";
    }

    // Add more overloads if needed
};

extern SWOStream swoTerminal;
