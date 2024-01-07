#pragma once

#include <cstdint>
#include <Ultralight/String.h>

using namespace ultralight;

class Tile {
public:
    Tile();

    ~Tile();

    int32_t GetValue() const;

    String GetColor() const;

    void SetValue(int32_t value_);

private:
    int32_t value{};
    String color;
};
