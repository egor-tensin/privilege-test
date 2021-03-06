// Copyright (c) 2016 Egor Tensin <Egor.Tensin@gmail.com>
// This file is part of the "Privilege check" project.
// For details, see https://github.com/egor-tensin/privilege-check.
// Distributed under the MIT License.

#pragma once

#include "error.hpp"

#include <windows.h>

namespace os
{
    inline OSVERSIONINFOW get_version_info()
    {
        OSVERSIONINFOW info;
        ZeroMemory(&info, sizeof(info));
        info.dwOSVersionInfoSize = sizeof(info);

        if (!GetVersionExW(&info))
            error::raise("GetVersionExW");

        return info;
    }

    inline bool is_vista_or_later(const OSVERSIONINFOW& info)
    {
        return info.dwMajorVersion >= 6;
    }

    inline bool is_vista_or_later()
    {
        return is_vista_or_later(get_version_info());
    }
}
