#pragma once

#include "material.hpp"

class dielectric : public material {
public:
	dielectric(float ri) : ref_idx(ri) {};
	bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const override;

private:
	float ref_idx;
};

bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted);
float schlick(float cosine, float ref_idx);