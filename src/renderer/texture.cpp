
#include "texture.h"

#include <stb/stb_image.h>

Texture::Texture(const std::string &path) : filePath(path), localBuffer(nullptr), width(0), height(0), bpp(0) {

    stbi_set_flip_vertically_on_load(true);
    localBuffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);

    if (localBuffer) {
        GL_CALL(glGenTextures(1, &id));
        GL_CALL(glBindTexture(GL_TEXTURE_2D, id));
        GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
        GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
        unbind();
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(localBuffer);
}

Texture::~Texture() {
    GL_CALL(glDeleteTextures(1, &id));
}

void Texture::bind(unsigned int slot) const {
    GL_CALL(glActiveTexture(GL_TEXTURE0 + slot));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, id));
}

void Texture::unbind() const {
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}
