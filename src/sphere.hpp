#pragma once

#include "hitable.hpp"

class sphere : public hitable {
public:
	sphere() {}
	sphere(vec3 cen, float r, material* mat) : center(cen), radius(r), mat_ptr(mat) {}
	bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;
	vec3 center;
	float radius;
	material* mat_ptr;
};