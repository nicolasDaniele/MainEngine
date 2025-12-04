#pragma once

namespace Utils
{
    template <typename T>
    void Clamp(T& value, T min, T max)
    {
        if (value < min)
            value = min;
        if (value > max)
            value = max;
    }

    enum Direction
    {
        NONE        = 0,
        FORWARD     = 1,
        BACKWARD    = 2,
        UP          = 3,
        DOWN        = 4,
        LEFT        = 5,
        RIGHT       = 6
    };
};