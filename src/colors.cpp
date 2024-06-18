#include "colors.h"
#include <raylib.h>

const Color grey = {211, 211, 211, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color blue = {13, 64, 216, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

/**
 * Return a vector with all the colors allowed for the shapes.
 */
std::vector<Color> GetCellColors()
{
    return {grey, green, red, blue, orange, yellow, purple, cyan};
}