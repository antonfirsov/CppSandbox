#include <iostream>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include "catch.hpp"

namespace Catch {
    template<> 
    struct StringMaker<glm::vec2> 
    {
        static std::string convert(glm::vec2 const& v) {
            std::ostringstream s;
            s << '(' << v.x << ',' << v.y << ')';
            return s.str();
        }
    };

    template<>
    struct StringMaker<glm::dvec4>
    {
        static std::string convert(glm::dvec4 const& v) {
            std::ostringstream s;
            s << '(' << v.x << ',' << v.y << ',' << v.z << ',' << v.w << ')';
            return s.str();
        }
    };
}