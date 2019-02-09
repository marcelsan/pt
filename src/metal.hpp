#pragma once

#include "material.hpp"

class metal : public material {
public:
	metal(const vec3& a, const float f) : albedo(a) { if(f < 1) fuzz = f; else fuzz = 1;}
	bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const override;

private:
	vec3 albedo;
	float fuzz;
};
