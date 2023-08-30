#include "color.h"
#include <cmath>
#include <iostream>
Color::Color(int r, int g, int b) : r{r}, g{g}, b{b}, id(-1) {}

std::string Color::asHex() {

  char hex[8];
  std::snprintf(hex, sizeof hex, "#%02x%02x%02x", r, g, b);

  std::string hexString;

  for (char i : hex) {
    hexString += i;
  }

  return hexString;
}


#ifdef USE_CUDA
Color& Color::operator=(const Color& other) {
    if (this != &other) {
        // Copy the members from 'other' to 'this'
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        this->id = other.id;
    }
    return *this;
}
#endif


/* *
 * Sets the RGB values for this color.
 * */
void Color::setRGB(int r, int g, int b) {
  this->r = r;
  this->g = g;
  this->b = b;
}

int Color::getClusterId() { return id; }
void Color::setClusterId(int i) { id = i; }
int Color::Red() { return r; }
int Color::Green() { return g; }
int Color::Blue() { return b; }
