#pragma once


struct ShaderPair {
    const char* vertex;
    const char* fragment;
};

struct ShaderSources
{
    static const ShaderPair Constant;
    static const ShaderPair Lamb;
    static const ShaderPair Phong;
    static const ShaderPair Bling;

};
