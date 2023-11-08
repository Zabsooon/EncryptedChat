from conan import ConanFile
from conan.tools.cmake import cmake_layout

class EncryptedChatRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("imgui/1.89.9")
        self.requires("asio/1.28.2")
        self.requires("openssl/3.1.4")

    def build_requirements(self):
        self.tool_requires("cmake/[>3.11]")

    def layout(self):
        cmake_layout(self)
