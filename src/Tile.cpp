#include "Tile.h"

Tile::Tile() = default;

Tile::Tile(int32_t value, const ultralight::String &color) : value(value), color(color) {}

Tile::~Tile() = default;

int32_t Tile::GetValue() const {
    return value;
}

String Tile::GetColor() const {
    return color;
}

void Tile::SetValue(int32_t value_) {
    value = value_;
}

void Tile::SetColor(const ultralight::String &color_) {
    color = color_;
}