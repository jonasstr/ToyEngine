#pragma once

#include "core/core.h"

class Texture {

private:

    unsigned int id;
    std::string filePath;
    unsigned char *localBuffer;
    int width, height, bpp;

public:

    Texture(const std::string &path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline unsigned int getWidth() const { return width; }
    inline unsigned int getHeight() const { return height; }

};


