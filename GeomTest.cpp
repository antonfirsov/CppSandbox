#include "geom/VectorTraits.hpp"
#include "geom/LineSegment.hpp"

#include <catch.hpp>
#include "TestUtils.hpp"

namespace mums
{
    namespace tests
    {
        template<glm::length_t L, typename T, glm::qualifier Q>
        struct TotallyNotAVector { };

        TEST_CASE("VectorTraits")
        {
            static_assert(VectorTraits<int>::IsVector == false, ":(");
            static_assert(VectorTraits<glm::vec4>::IsVector == true, ":(");
            
            static_assert(VectorTraits<TotallyNotAVector<1, int, glm::aligned>>::IsVector == false, ":(");
            static_assert(VectorTraits<glm::vec<42, float, glm::highp>>::IsVector == false, ":(");

        }
    }
}
