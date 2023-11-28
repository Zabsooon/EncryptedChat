#include "../src/gui/UseImGui.hpp"

class CustomImGui : public UseImGui
{
public:
    virtual void Update() override
    {
        // render your GUI
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("CustomImGui Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

        bool clear_color_changed = ImGui::ColorEdit3("clear color", (float*)clear_color);

        if(ImGui::Button("Button"))
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);
        ImGui::Text("Application avarage %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

        if(clear_color_changed)
        {
            change_clear_color(clear_color[0], clear_color[1], clear_color[2]);
        }
    }
private:
    float clear_color[3] = { .0f, .0f, .0f };
    void change_clear_color(float r, float g, float b)
    {
        glClearColor(r, g, b, 1.0f);
    }
};

int main()
{
    // Setup window
    if(!glfwInit())
        return 1;

    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Dear ImGui - Example", NULL, NULL);
    if(window == nullptr)
        return 1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);

    CustomImGui myimgui;
    myimgui.Init(window, glsl_version);
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        myimgui.NewFrame();
        myimgui.Update();
        myimgui.Render();
        glfwSwapBuffers(window);
    }
    myimgui.Shutdown();
    
    return 0;
}
