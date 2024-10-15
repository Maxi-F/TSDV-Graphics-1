#pragma once
#include <glm/mat4x4.hpp>
#include <string>

namespace GuichernoEngine {
    class Shader
    {
    public:
        unsigned int ID;

        Shader();
        Shader(const char* vertexPath, const char* fragmentPath);
        void Use();
        void SetMat4(const std::string& name, const glm::mat4& mat);
        void SetVec4(const std::string& name, const glm::vec4& vec);

    private:
        void CreateShader(const char* vertexPath, const char* fragmentPath);
        void CheckCompileErrors(unsigned int shader, std::string type);
    };
}
