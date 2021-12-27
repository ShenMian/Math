﻿// Copyright 2021 SMS
// License(Apache-2.0)

#pragma once

#include <cstdio>
#include <string_view>
#include <source_location>

#if _MSC_VER
#    define breakpoint() __debugbreak()
#else
#    define breakpoint() __builtin_trap()
#endif

inline void assert(bool condition, const std::source_location& loc = std::source_location::current())
{
	if(condition)
		return;

	std::printf("Assertion failed %s:%s(%u:%u)\n",
		loc.file_name(), loc.function_name(), loc.line(), loc.column());
	breakpoint();
}

inline void assert(bool condition, std::string_view message, const std::source_location& loc = std::source_location::current())
{
	if(condition)
		return;

	std::printf("Assertion failed %s:%s(%u:%u): %s\n",
		loc.file_name(), loc.function_name(), loc.line(), loc.column(), message.data());
	breakpoint();
}
