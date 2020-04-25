#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include <algorithm>
#include <chrono>
#include <unordered_map>

#include <Windows.h>
#define WIN32_LEAN_AND_MEAN
#define DETOURS_INTERNAL
#include "detours.hpp"

using namespace std::chrono_literals;
using namespace std::string_literals;


// thx  rekti
#ifdef DEBUG
#define PRINT(__FMT__, ...) printf("[D][plutoisnipe][" __FUNCTION__ "]: " __FMT__ "\n", __VA_ARGS__)
#else
#define PRINT(__FMT__, ...) printf("[plutoisnipe]: " __FMT__ "\n", __VA_ARGS__)
#endif
