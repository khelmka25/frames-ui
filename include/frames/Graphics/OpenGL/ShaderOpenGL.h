#pragma once

#include <string_view>
#include <filesystem>

namespace frames {

class ShaderOpenGL {
 public:
  // load from file
  ShaderOpenGL(std::filesystem::path vertexPath, std::filesystem::path fragmentPath);
  ~ShaderOpenGL();

  unsigned int getProgramHandle(void);

  static std::string loadShaderCode(std::string path) noexcept(false);

  void enable();
  void disable();

  void setBool(const std::string& name, bool value) const;
  void setInt(const std::string& name, int value) const;
  void setFloat(const std::string& name, float value) const;

 private:
  unsigned int shaderProgramHandle, vertexShaderHandle, fragmentShaderHandle;
};

};  // namespace frames