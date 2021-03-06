#pragma once

#include <utility>
#include <vector>


using Position = std::pair<double, double>;	// Landmark or Robot position
using Positions = std::vector<Position>;

using Displacement = std::pair<double, double>;	// (dx from previous x, dy from previous y)
using Displacements = std::vector<Displacement>;
