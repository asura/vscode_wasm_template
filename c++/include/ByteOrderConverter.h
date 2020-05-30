#ifndef BYTEORDERCONVERTER_H
#define BYTEORDERCONVERTER_H

#include <climits>

template <typename T>
void swapEndian(T& u)
{
    static_assert(CHAR_BIT == 8, "CHAR_BIT != 8");

    union U {
        T u;
        unsigned char u8[sizeof(T)];
    };

    U dest;
    U* source = reinterpret_cast<U*>(&u);

    for (size_t k = 0; k < sizeof(T); k++)
    {
        dest.u8[k] = source->u8[sizeof(T) - k - 1];
    }

    u = dest.u;
}

#endif  // BYTEORDERCONVERTER_H
