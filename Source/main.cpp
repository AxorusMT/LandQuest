/**
 * @mainpage LandQuest 
 * 
 * A Open World Exploration Game.
 * 
 * Uses the custom **Magnetar** game engine, a high 
 * performance 2D game engine
 * 
 */

#include "Magnetar/Core/Logger.hpp"
#include "Magnetar/Core/Platform.hpp"
#include "Magnetar/Graphics/Window.hpp"


using namespace Magnetar;
int main() {    
    Graphics::WindowProperties props;
    props.center_x = true;
    props.center_y = true;
    props.maximized = true;
    props.fullscreen = false;
    props.width = 1600;
    props.height = 900;

    Graphics::Window win(props);
    win.run();
    return 0;
}