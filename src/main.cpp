/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#include <iostream>
#include "DSX++.h"

#include <string>  // for basic_string, string, allocator
#include <vector>  // for vector

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Dropdown, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/dom/elements.hpp"  // for gauge, separator, text, vbox, operator|, Element, border
#include "ftxui/screen/color.hpp"  // for Color, Color::Blue, Color::Green, Color::Red

void resetTriggers(int &L2, int &R2)
{
    L2 = 0;
    R2 = 0;
    DSX::clearPayload();
}

void sendTriggers(int L2, int R2)
{
    DSX::clearPayload();
    DSX::setLeftTrigger((TriggerMode) L2);
    DSX::setRightTrigger((TriggerMode) R2);
    if (DSX::sendPayload() != DSX::Success)
        std::cerr << "* DSX++ client failed to send data!" << std::endl;
}

int main (void)
{
    using namespace ftxui;

    int L2 = 0;
    int R2 = 0;

    std::vector<std::string> modes = {
        "Normal",
        "GameCube",
        "VerySoft",
        "Soft",
        "Hard",
        "VeryHard",
        "Hardest",
        "Rigid",
        "VibrateTrigger",
        "Choppy",
        "Medium",
        "VibrateTriggerPulse",
        "CustomTriggerValue",
        "Resistance",
        "Bow",
        "Galloping",
        "SemiAutomaticGun",
        "AutomaticGun",
        "Machine",

        "VibrateTrigger10Hz",
        "TriggerOff",
        "Feedback",
        "Weapon",
        "Vibration",
        "SlopeFeedback",
        "MultiplePositionFeedback",
        "MultiplePositionVibration",
    };

    if ( DSX::init() != DSX::Success ) {
        std::cerr << "* DSX++ client failed to initialize!" << std::endl;
        return -1;
    }
    auto info = Renderer([&] {
        return window(text("Settings"),
            vbox({
                text("> L2 addaptive trigger  = " + modes[L2]),
                text("> R2 addaptive trigger  = " + modes[R2]),
            })
        ) | flex;
    });

    auto layout = Container::Vertical({
        Container::Horizontal({
            Container::Vertical({
                Renderer([]{ return text(L"");}),
                Renderer([]{ return text(L"");}),
                Renderer([]{ return text(L"");}),
                Renderer([]{ return text(L"              🎮 DSX++ Adaptive Triggers Test 🎮");}),
                Renderer([]{ return text(L"");}),
                Renderer([]{ return text(L"👉🏽 Use the dropdown menus on the left to choose the adaptive triggers");}),
                Renderer([]{ return text(L"you want to send to controller and then click on the button on the right");}),
                Renderer([]{ return text(L"");}),
            }),
        }),
        Container::Horizontal({
            Dropdown(&modes, &L2),
            Dropdown(&modes, &R2),
            info,
            Button("🚀 Send", [&] { sendTriggers(L2, R2); }, ButtonOption::Animated(Color::Blue)),
            Button("💥 Reset", [&] { resetTriggers(L2, R2); }, ButtonOption::Animated(Color::Red)),
        }),
        Renderer([]{ return text(L"");}),
        Renderer([]{ return text(L"");}),
    });


    //auto screen = ScreenInteractive::FullscreenAlternateScreen();
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);

    if ( DSX::terminate() != DSX::Success ) {
        std::cerr << "* DSX++ client failed to terminate!" << std::endl;
        return -3;
    }

    return 0;
}
