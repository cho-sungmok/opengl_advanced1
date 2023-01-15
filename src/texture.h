#pragma once

#include "image.h"

#define FBO_MSAA 0

CLASS_PTR(Texture)
class Texture {
public:

#if FBO_MSAA
    static TextureUPtr CreateMSAA(int width, int height, uint32_t format);
    void CreateTextureMSAA(int width, int height, uint32_t format);
#endif

    static TextureUPtr Create(int width, int height, uint32_t format);
    static TextureUPtr CreateFromImage(const Image* image);
    ~Texture();

    const uint32_t Get() const { return m_texture; }
    void Bind() const;
    void SetFilter(uint32_t minFilter, uint32_t magFilter) const;
    void setWrap(uint32_t sWrap, uint32_t tWrap) const;

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    uint32_t GetFormat() const { return m_format; }

private:
    Texture() {}
    void CreateTexture();
    void SetTextureFormat(int width, int height, uint32_t format);
    void SetTextureFromImage(const Image* image);

    uint32_t m_texture { 0 };
    int m_width { 0 };
    int m_height { 0 };
    uint16_t m_format { GL_RGBA };
};

CLASS_PTR(CubeTexture)
class CubeTexture {
public:
    static CubeTextureUPtr CreateFromImages(const std::vector<Image*>& images);
    ~CubeTexture();

    const uint32_t Get() const { return m_texture; }
    void Bind() const;

private:
    CubeTexture() {}
    bool InitFromImages(const std::vector<Image*>& images);
    uint32_t m_texture { 0 };
};
