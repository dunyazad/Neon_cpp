#include <Neon/ECS/Component/TextureComponent.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

NeTextureComponent::NeTextureComponent()
    : NeComponentBase()
{
    glGenTextures(1, &this->textureID);
}

NeTextureComponent::~NeTextureComponent()
{
	glDeleteTextures(1, &this->textureID);
}

void NeTextureComponent::Bind()
{
    glBindTexture(this->textureTargetID, this->textureID);
}

void NeTextureComponent::Unbind()
{
    glBindTexture(this->textureTargetID, 0);
}

void NeTextureComponent::LoadFromFile(const string& filePath, int width, int height, GLenum textureTarget)
{
    this->textureTargetID = textureTarget;

    int channels = 0;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
    if (data != nullptr)
    {
        this->Bind();

        // set the texture wrapping parameters
        glTexParameteri(this->textureTargetID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(this->textureTargetID, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(this->textureTargetID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(this->textureTargetID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (channels == 3)
        {
            glTexImage2D(this->textureTargetID, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else if (channels == 4)
        {
            glTexImage2D(this->textureTargetID, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        glGenerateMipmap(this->textureTargetID);
    }
}
