#include "Tile.h"
#include <map>

static std::map<int, String> color_by_value = {{0,    "#ffffff"},
                                               {2,    "#d2f1a1"},
                                               {4,    "#94e2ba"},
                                               {8,    "#00d2d0"},
                                               {16,   "#1cb8dd"},
                                               {32,   "#2799ea"},
                                               {64,   "#af90d6"},
                                               {128,  "#d48bcb"},
                                               {256,  "#f486c0"},
                                               {512,  "#f99d9b"},
                                               {1024, "#fdb16b"},
                                               {2048, "#000000"}};

Tile::Tile() = default;

Tile::~Tile() = default;

int32_t Tile::GetValue() const {
    return value;
}

String Tile::GetColor() const {
    return color;
}

void Tile::SetValue(int32_t value_) {
    value = value_;
    color = color_by_value[value_];
}
