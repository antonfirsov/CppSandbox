#include <iostream>
#define GLM_FORCE_MESSAGES

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <catch.hpp>
#include "TestUtils.hpp"
#include "glm/gtc/type_aligned.hpp"
#include "glm/gtc/constants.inl"

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

TEST_CASE("print and fail")
{
    using namespace glm;
    
    SECTION("vec2")
    {
        vec2 v(1, 2);
        CAPTURE(v);
        FAIL();
    }

    SECTION("vec4")
    {
        vec4 v;
        CAPTURE(v);
        FAIL();
    }

    SECTION("dvec4")
    {
        dvec4 v;
        CAPTURE(v);
        FAIL();
    }

    SECTION("aligned_vec4")
    {
        aligned_vec4 v;
        CAPTURE(v);
        FAIL();
    }

    SECTION("aligned_dvec4")
    {
        aligned_dvec4 v;
        CAPTURE(v);
        FAIL();
    }
}

TEST_CASE("hello aligned")
{
    SECTION("4 x float")
    {
        glm::aligned_vec4 a(1.f, 2.f, 3.f, 4.f);
        glm::aligned_vec4 b(5.f, 6.f, 7.f, 8.f);

        CAPTURE(a);
        CAPTURE(b);

        glm::aligned_vec4 c = a + b;

        REQUIRE(c == glm::aligned_vec4(7.0, 8, 10, 12));

        glm::dvec4 foo = c;

        REQUIRE(foo == glm::dvec4(6, 8, 10, 12));
    }
    
    SECTION("2 x double")
    {
        glm::aligned_dvec2 a(1.0, 2);
        glm::aligned_dvec2 b(5.0, 6);

        glm::aligned_dvec2 c = a + b;
        REQUIRE(c == glm::aligned_dvec2(6.0, 8));
    }

    SECTION("4 x double")
    {
        glm::aligned_dvec4 a(1.0, 2, 3, 4);
        glm::aligned_dvec4 b(5.0, 6, 7, 8);

        glm::aligned_dvec4 c = a + b;
        REQUIRE(c == glm::aligned_dvec4(6.0, 8, 10, 12));
    }
}

namespace VectorTests
{
    template<typename TVector>
    struct Vector4TestFixture
    {
        typedef typename TVector::value_type TScalar;

        void TestAddition() const
        {
            TVector a(static_cast<TScalar>(1), static_cast<TScalar>(2), static_cast<TScalar>(3), static_cast<TScalar>(4));
            TVector b(static_cast<TScalar>(1), static_cast<TScalar>(2), static_cast<TScalar>(3), static_cast<TScalar>(4));

            TVector c = a + b;

            REQUIRE(c.x == a.x + b.x);
            REQUIRE(c.y == a.y + b.y);
            REQUIRE(c.z == a.z + b.z);
            REQUIRE(c.w == a.w + b.w);
        }
    };

    namespace add
    {
        TEST_CASE_METHOD(Vector4TestFixture<glm::vec4>, "vec4")
        {
            TestAddition();
        }

        TEST_CASE_METHOD(Vector4TestFixture<glm::dvec4>, "dvec4")
        {
            TestAddition();
        }

        TEST_CASE_METHOD(Vector4TestFixture<glm::aligned_vec4>, "aligned_vec4")
        {
            TestAddition();
        }

        TEST_CASE_METHOD(Vector4TestFixture<glm::aligned_dvec4>, "aligned_dvec4")
        {
            TestAddition();
        }   
    }

    namespace ComparePlz
    {
        TEST_CASE("vec4 lt")
        {
            glm::vec4 a(1, 2, 3, 4);

            glm::vec4 b(1.1, 2.2, 3.3, 4.4);
        }
    }
}
