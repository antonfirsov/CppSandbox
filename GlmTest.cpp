#include <iostream>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <catch.hpp>
#include "TestUtils.hpp"
#include "glm/gtc/type_aligned.hpp"

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

TEST_CASE("hello aligned")
{
    glm::aligned_vec4 a(1, 2, 3, 4);
    glm::aligned_vec4 b(5, 6, 7, 8);

    glm::aligned_vec4 c = a + b;
    
    REQUIRE(c == glm::aligned_vec4(7, 8, 10, 12));

    glm::dvec4 foo = c;

    REQUIRE(foo == glm::dvec4(6, 8, 10, 12));
}