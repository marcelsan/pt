#pragma once

#include "vec3.hpp"

class ray
{
	public: 
		ray() {}
		ray(const vec3& a, const vec3& b, float ti = 0.0) { A = a; B = b; time_ = ti;}
		inline vec3 origin() const { return A; }
		inline vec3 direction() const { return B; }
		inline float time() const { return time_; }
		inline vec3 at(const float t) const { return A + t * B; }

		vec3 A;
		vec3 B;
		float time_;
};
