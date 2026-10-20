#ifndef BASIC_TRANSFORM_H
#define BASIC_TRANSFORM_H

#include <cassert>  // vector_util.h uses assert but doesn't include it
#include <SFML/System/Vector2.hpp>
#include "vector_util.h"

struct BasicTransform {
    BasicTransform(const sf::Vector2f& scale = {1.f, 1.f}, const sf::Vector2f& translation = {0.f, 0.f})
        : scale(scale), translation(translation) {}

    // points: scale, then translate (w = 1)
    sf::Vector2f applyPoint(const sf::Vector2f& p) const {
        return p * scale + translation;
    }

    // vectors: scale only (w = 0, translation ignored)
    sf::Vector2f applyVector(const sf::Vector2f& v) const {
        return v * scale;
    }

    bool operator==(const BasicTransform& o) const {
        return scale == o.scale && translation == o.translation;
    }
    
    sf::Vector2f scale;
    sf::Vector2f translation;
};

#endif