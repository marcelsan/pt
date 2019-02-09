#pragma once

#include <cmath>
#include <fstream>
#include <iostream>

#include "camera.hpp"
#include "hitable.hpp"
#include "material.hpp"

namespace raytrace {
	void render(std::ofstream& out, hitable* world, camera& cam, const int nx, const int ny, const int spp);
}