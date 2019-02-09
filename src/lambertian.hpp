#pragma once

#include "material.hpp"

class lambertian : public material {
public:
	lambertian(const vec3& a) : albedo(a) {}
	bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const override;
	
private:
	vec3 albedo;
};
