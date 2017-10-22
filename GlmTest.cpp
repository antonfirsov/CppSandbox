#include <iostream>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/constants.hpp> // glm::pi

glm::mat4 camera(float translate, glm::vec2 const& rotate)
{
    const glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -translate));
    view = glm::rotate(view, rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    const glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    return projection * view * model;
}

#include "catch.hpp"

namespace Catch {
    template<> struct StringMaker< glm::vec2> {
        static std::string convert(glm::vec2 const& v) {
            std::ostringstream s;
            s << '(' << v.x << ',' << v.y << ')';
            return s.str();
        }
    };
}

TEST_CASE("hello GLM")
{
    INFO("lol");

    glm::vec2 a(1, 2);;
    glm::vec2 b(3, 4);
    glm::vec2 q{ 666, 777 };

    CAPTURE(q);

    auto c = a + b;

    REQUIRE(c == glm::vec2(4, 6));
    FAIL();
}