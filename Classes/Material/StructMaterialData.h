#pragma once


struct MaterialData {
    float ra; // ambient
    float rd; // diffuse
    float rs; // specular
    float h;  // shininess
    MaterialData(float ra, float rd, float rs, float h) : ra(ra), rd(rd), rs(rs), h(h) {};
};