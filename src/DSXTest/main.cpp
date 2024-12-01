/*
 * Copyright (C) 2024 Thanasis Petsas <thanpetsas@gmail.com>
 * Licence: MIT Licence
 */

#include <iostream>
#include "DSX++.h"

#include <string>  // for basic_string, string, allocator
#include <vector>  // for vector
#include <unordered_map>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Dropdown, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/dom/elements.hpp"  // for gauge, separator, text, vbox, operator|, Element, border
#include "ftxui/screen/color.hpp"  // for Color, Color::Blue, Color::Green, Color::Red

using namespace ftxui;

const std::vector<std::string> modes = {
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

    // DSX V3.1+

    "VibrateTrigger10Hz",
    "TriggerOff",
    "Feedback",
    "Weapon",
    "Vibration",
    "SlopeFeedback",
    "MultiplePositionFeedback",
    "MultiplePositionVibration",
};


const std::vector<std::string> customModes  = {
    "OFF",
    "Rigid",
    "RigidA",
    "RigidB",
    "RigidAB",
    "Pulse",
    "PulseA",
    "PulseB",
    "PulseAB",
    "VibrateResistance",
    "VibrateResistanceA",
    "VibrateResistanceB",
    "VibrateResistanceAB",
    "VibratePulse",
    "VibratePulseA",
    "VibratePulsB",
    "VibratePulseAB",
 };

struct Extra
{
    const std::string name;
    Component component;
    int &value;

    Extra(std::string name, Component component, int &value) :
    name(name), component(component), value(value) {}
};

std::unordered_map<std::string, std::vector<Extra>> modeExtras;
bool hasExtras(std::string mode)
{
    return modeExtras.find(mode) != modeExtras.end();
}

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

int freq = 100;
int start = 4;
int end = 4;
int force = 4;
int snapforce = 4;
int customMode = 0;

#define DEFAULT_FORCE 128
int force1 = DEFAULT_FORCE;
int force2 = DEFAULT_FORCE;
int force3 = DEFAULT_FORCE;
int force4 = DEFAULT_FORCE;
int force5 = DEFAULT_FORCE;
int force6 = DEFAULT_FORCE;
int force7 = DEFAULT_FORCE;

int startFoot = 4;
int secondFoot = 4;

int strengthA = 3;
int strengthB = 3;

// v3.1+
int startPosition = 5;
int resistanceStrength = 4;


int main (void)
{
    using namespace ftxui;

    int L2 = 0;
    int R2 = 0;

    std::unordered_map<std::string, std::vector<Component>> modeComponents;

    if ( DSX::init() != DSX::Success ) {
        std::cerr << "* DSX++ client failed to initialize!" << std::endl;
        return -1;
    }

    auto frequencySlider = Slider("Frequency: ", &freq, 0, 256, 1);
    auto startSlider = Slider("Start: ", &start, 0, 8, 1);
    auto endSlider = Slider("End: ", &end, 0, 8, 1);
    auto startFootSlider = Slider("StartFoot: ", &startFoot, 0, 8, 1);
    auto secondFootSlider = Slider("secondFoot: ", &secondFoot, 0, 8, 1);
    auto forceSlider = Slider("Force: ", &force, 0, 8, 1);
    auto snapforceSlider = Slider("SnapForce: ", &snapforce, 0, 8, 1);
    auto force1Slider = Slider("Force #1: ", &force1, 0, 256, 1);
    auto force2Slider = Slider("Force #2: ", &force2, 0, 256, 1);
    auto force3Slider = Slider("Force #3: ", &force3, 0, 256, 1);
    auto force4Slider = Slider("Force #4: ", &force4, 0, 256, 1);
    auto force5Slider = Slider("Force #5: ", &force5, 0, 256, 1);
    auto force6Slider = Slider("Force #6: ", &force6, 0, 256, 1);
    auto force7Slider = Slider("Force #7: ", &force7, 0, 256, 1);
    auto strengthASlider = Slider("Strength A: ", &strengthA, 0, 7, 1);
    auto strengthBSlider = Slider("Strength B: ", &strengthB, 0, 7, 1);


    auto startPositionSlider = Slider("StartPos: ", &startPosition, 1, 9, 1);
    auto resistanceStrengthSlider = Slider("Resistance: ", &resistanceStrength, 1, 8, 1);

    std::vector<Extra> automaticGun =
    {
        Extra("Start", startSlider, start),
        Extra("End", endSlider, end),
        Extra("Force", forceSlider, force),
    };


    modeExtras = {
        {
            "VibrateTrigger", {
                Extra("Frequency", frequencySlider, freq)
            }
        },
        {
            "Resistance", {
                Extra("Start", startSlider, start),
                Extra("Force", forceSlider, force),
            }
        },
        {
            "CustomTriggerValue", {
                Extra("Force #1", force1Slider, force1),
                Extra("Force #2", force2Slider, force2),
                Extra("Force #3", force3Slider, force3),
                Extra("Force #4", force4Slider, force4),
                Extra("Force #5", force5Slider, force5),
                Extra("Force #6", force6Slider, force6),
                Extra("Force #7", force7Slider, force7),
            }
        },
        {
            "Bow", {
                Extra("Start", startSlider, start),
                Extra("End", endSlider, end),
                Extra("Force", forceSlider, force),
                Extra("SnapForce", snapforceSlider, snapforce),
            }
        },
        {
            "Galloping", {
                Extra("Start", startSlider, start),
                Extra("End", endSlider, end),
                Extra("StartFoot", startFootSlider, startFoot),
                Extra("SecondFoot", secondFootSlider, secondFoot),
                Extra("Frequency", frequencySlider, freq)
            }
        },
        // NOTE: the following is used for SemiAutomaticGun too
        {
            "AutomaticGun", automaticGun
        },
        {
            "SemiAutomaticGun", automaticGun
        },
        {
            "Machine", {
                Extra("Start", startSlider, start),
                Extra("End", endSlider, end),
                Extra("StrengthA", strengthASlider, strengthA),
                Extra("StrengthB", strengthBSlider, strengthB),
                Extra("Frequency", frequencySlider, freq)
            }
        },
        {
            "Feedback", {
                Extra("StartPos", startPositionSlider, startPosition),
                Extra("Resistance", resistanceStrengthSlider,
                                                    resistanceStrength),
            }
        },

    };


	auto menu = Menu(&customModes, &customMode, MenuOption());

    auto extrasL2Container = Container::Vertical({
        menu,
		frequencySlider,
        startSlider,
        endSlider,
        strengthASlider,
        strengthBSlider,
        startFootSlider,
        secondFootSlider,
        forceSlider,
        snapforceSlider,
        force1Slider,
        force2Slider,
        force3Slider,
        force4Slider,
        force5Slider,
        force6Slider,
        force7Slider,
        startPositionSlider,
        resistanceStrengthSlider,
    });

    auto extrasL2 = Renderer(extrasL2Container, [&] {

        if (hasExtras( modes[L2] )) {
            std::vector<Element> elements;

            if (modes[L2] == "CustomTriggerValue")
                elements.push_back(menu->Render());

            elements.push_back(text(modes[L2] + " extras:          "));
            elements.push_back(text(""));
            auto extrasVector = modeExtras.at( modes[L2] );
            for (const auto &extra : extrasVector) {
                elements.push_back (
                    hbox(extra.component->Render(),
                    text("(" + std::to_string(extra.value) +")"))

                );
            }
            elements.push_back(text(""));
            return window(text("L2 Extras"),
                    vbox(elements)
            ) | flex;
        }

        return window(text("L2 Extras"),
            vbox({
                text(modes[L2] + " ( no extras )"),
            })
        ) | flex;
    });

    auto settings = Renderer([&] {
        std::vector<Element> elements;
        elements.push_back( text("⯍ L2 addaptive trigger  = " + modes[L2]) );

        if (hasExtras( modes[L2] )) {
            std::string extrasAllValues = "   ⯌ extras: {";
            auto extrasVector = modeExtras.at( modes[L2] );
            for (const auto &extra : extrasVector) {
                extrasAllValues += std::to_string(extra.value);
                if (&extra != &extrasVector.back())
                    extrasAllValues += ", ";
            }
            extrasAllValues += "}";
            elements.push_back(text(extrasAllValues.c_str()));
        }

        elements.push_back( text("⯍ R2 addaptive trigger  = " + modes[R2]) );

        return window(text("Settings"),
            vbox(elements)
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
            extrasL2,
            Dropdown(&modes, &R2),
            settings,
            Button("🚀 Send", [&] { sendTriggers(L2, R2); }, ButtonOption::Animated(Color::Blue)),
            Button("💥 Reset", [&] { resetTriggers(L2, R2); }, ButtonOption::Animated(Color::Red)),
        }),
        Renderer([]{ return text(L"");}),
        Renderer([]{ return text(L"");}),
    });

    auto screen = ScreenInteractive::Fullscreen();

    //auto screen = ScreenInteractive::FullScreen();
    //auto screen = ScreenInteractive::FitComponent();
    //auto screen = ScreenInteractive::FullscreenAlternateScreen();
    screen.Loop(layout);

    if ( DSX::terminate() != DSX::Success ) {
        std::cerr << "* DSX++ client failed to terminate!" << std::endl;
        return -3;
    }

    return 0;
}
