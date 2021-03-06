#pragma once

#include <Core Rendering/Shader.h>
#include <Core/Core.h>

const Matrix4f CubeProjection = glm::perspective(glm::radians(90.0f), 1.0f, 0.01f, 10.0f);
const Matrix4f CubeViews[] =
{
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f), glm::vec3(0.0f, -1.0f,  0.0f)),
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, -1.0f,  0.0f)),
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec3(0.0f,  0.0f, -1.0f)),
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec3(0.0f, -1.0f,  0.0f)),
	glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec3(0.0f, -1.0f,  0.0f))
};

namespace LDEngine {
	namespace Rendering {
		namespace Core {
			struct Texture2D {
				unsigned int ID;
				glm::ivec2 resolution;
				~Texture2D();
				Texture2D(unsigned int id = 4294967295, glm::ivec2 res = glm::ivec2(0));
				void Bind(unsigned int target);
			};
			struct Texture3D {
				unsigned int ID;
				glm::ivec3 resolution;
				~Texture3D();
				Texture3D(unsigned int id = 4294967295, glm::ivec3 res = glm::ivec3(0));
				void Bind(unsigned int target);
			};
			struct TextureCubeMap {
				unsigned int ID;
				glm::ivec2 Resolution;
				TextureCubeMap(unsigned int id = 4294967295, glm::ivec2 res = glm::ivec2(0));
				void Bind(unsigned int target);
			};
			struct Texture2DArray {
				unsigned int ID;
				unsigned char Length; 
				glm::ivec2 Resolution; 
				Texture2DArray(unsigned id = 4294967295, unsigned char Length = 0, glm::ivec2 Res = glm::ivec2(0));
				void Bind(unsigned int Target); 
			};
			Texture2D LoadTexture2D(const char *name, bool linear, bool mipmaps);
			Texture3D EmptyTexture3D(glm::ivec3 resolution, bool linear, bool mipmaps);
			Texture3D LoadTexture3D(const char *name, bool linear, bool mipmaps);
			TextureCubeMap LoadHDRI(const char *name, bool linear, bool mipmaps, Core::Shader & EquirectangularToCubeMapShader);
			TextureCubeMap LoadTextureCubeMap(const char *name);
			Texture2DArray Load2DAnimation(const char *Name, unsigned char Length, Vector2i Resolution); 
		}
	}
}