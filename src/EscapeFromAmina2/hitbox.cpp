#include <EscapeFromAmina2/hitbox.hpp>
  
Hitbox::Hitbox(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {} 

float Hitbox::clipXCollide(Hitbox& other, float xa) {
    if (other.y + other.height <= y || other.y >= y + height) {
        return xa;
    }

    if (xa > 0.0f && other.x + other.width <= x)
        xa = std::min(x - (other.x + other.width), xa);

    if (xa < 0.0f && other.x >= x + width)
        xa = std::max(xa, (x + width) - other.x);

    return xa;
}

float Hitbox::clipZCollide(Hitbox& other, float ya) {
    if (other.x + other.width <= x || other.x >= x + width) {
        return ya;
    }

    if (ya > 0.0f && other.y + other.height <= y)
        ya = std::min(ya, y - (other.y + other.height));

    if (ya < 0.0f && other.y >= y + height)
        ya = std::max(ya, (y + height) - other.y);

    return ya;
}
void Hitbox::move(float x, float y) {
    this->x += x;
    this->y += y;
}