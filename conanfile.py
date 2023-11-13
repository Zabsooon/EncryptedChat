from conan import ConanFile
from conan.tools.cmake import cmake_layout

class EncryptedChatRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("imgui/1.89.9")
        self.requires("glfw/[>=3.3.4]")
        self.requires("glew/2.2.0")
        self.requires("asio/1.28.2")
        self.requires("openssl/3.1.4")

    def build_requirements(self):
        self.tool_requires("cmake/[>3.11]")

    def imports(self):
        self.copy("imgui_impl_glfw.cpp", dst="../src", src="./res/bindings")
        self.copy("imgui_impl_opengl3.cpp", dst="../src", src="./res/bindings")
        self.copy("imgui_impl_glfw.h*", dst="../include", src="./res/bindings")
        self.copy("imgui_impl_opengl3.h*", dst="../include", src="./res/bindings")

    def layout(self):
        cmake_layout(self)
