#pragma once

#include <SDKDDKVer.h>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <cassert>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <objbase.h>
#include <cstdint>
#include <functional>
#include <chrono>
#include <iterator>
#include <istream>

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Point.h"
#include "Node.h"
#include "Graph.h"
#include "GridHelper.h"
#include "Utility.h"
#include "StopWatch.h"
#include "IPathFinder.h"
