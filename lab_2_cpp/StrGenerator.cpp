//
// Created by Алоев Артем on 18.02.2025.
//

#include "StrGenerator.h"

wstring StrGenerator::generateRandomString(int length) {
    wstring result;
    for (int i = 0; i < length; ++i) {
        result += static_cast<wchar_t>('a' + rand() % 26);
    }
    return result;
}