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
            SECTION("IsVector")
            {
                static_assert(VectorTraits<int>::IsVector == false, ":(");
                static_assert(VectorTraits<glm::vec4>::IsVector == true, ":(");

                static_assert(VectorTraits<TotallyNotAVector<1, int, glm::aligned>>::IsVector == false, ":(");
                static_assert(VectorTraits<glm::vec<42, float, glm::highp>>::IsVector == false, ":(");                
            }

            SECTION("TVector")
            {
                static_assert(std::is_same_v < glm::vec4, VectorTraits<glm::vec4>::TVector>, ":(");
            }

            SECTION("TScalar")
            {
                static_assert(std::is_same_v<double, VectorTraits<glm::dvec2>::TScalar>, ":(");
            }
            
            SECTION("IsVectorOfDim")
            {
                static_assert(VectorTraits<glm::vec4>::IsVectorOfDim(4) == true, ":(");
                static_assert(VectorTraits<glm::vec4>::IsVectorOfDim(3) == false, ":(");
                static_assert(VectorTraits<glm::aligned_dvec3>::IsVectorOfDim(3) == true, ":(");
            }
        }
    }
}
