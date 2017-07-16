#pragma once

// Windows
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <SDKDDKVer.h>
#include <windows.h>

// CLR
#include <msclr\marshal_cppstd.h>

// Standard
#include <cstdint>
#include <memory>

// Pathfinding.Library
#include "Point.h"
#include "Node.h"
#include "Graph.h"
#include "GridHelper.h"