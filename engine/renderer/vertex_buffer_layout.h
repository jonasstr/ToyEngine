#pragma once

#include <vector>

#include <glad/glad.h>
#include "../core.h"

struct VertexBufferAttribute {

    unsigned int type;
    unsigned int count;
    bool normalized;

    static unsigned int getSizeOfType(unsigned int type) {

        switch (type) {
            case GL_FLOAT:
                return 4;
            default:
                ASSERT(false);//static_assert(false, "VertexBufferAttribute/GetSizeOfType: Attribute type not supported!");
                return 0;
        }
    }
};

class VertexBufferLayout {

private:

    unsigned int stride;
    std::vector<VertexBufferAttribute> attributes;

public:

    VertexBufferLayout() : stride(0) {}

    template<typename T>
    void addAttribute(unsigned int count) {
        ASSERT(false);//"VertexBufferLayout/AddAttribute: Attribute type not supported!"
    }

    inline unsigned int getStride() const { return stride; }

    inline const std::vector<VertexBufferAttribute> getAttributes() const &{ return attributes; }
};

template<>
inline void VertexBufferLayout::addAttribute<float>(unsigned int count) {
    attributes.push_back({GL_FLOAT, count, false});
    stride += sizeof(float) * count;
}

