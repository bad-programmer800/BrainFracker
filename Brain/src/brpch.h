#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Brain/Core/Log.h"

#include "Brain/Debug/Instrumentor.h"

#ifdef BR_PLATFORM_WINDOWS
	#include <Windows.h>
#endif