#pragma once

#include "vec3.hpp"

class ray
{
	public: 
		ray() {}
		ray(const vec3& a, const vec3& b) { A = a; B = b; }
		inline vec3 origin() const { return A; }
		inline vec3 direction() const { return B; }
		inline vec3 at(const float t) const { return A + t * B; }

		vec3 A;
		vec3 B;
};
