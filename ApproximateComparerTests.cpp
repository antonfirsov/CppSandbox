#include <catch.hpp>
#include <cmath>
#include "TestUtils.hpp"
#include "geom/ApproximateComparer.hpp"

namespace mums
{
    namespace tests
    {
        namespace ApproximateComparerTests
        {
            template<typename TScalar>
            struct ApproximateComparerFixture
            {
                void TestConstruct(const TScalar eps) const
                {
                    ApproximateComparer<TScalar> apx(eps);

                    REQUIRE(apx.Eps() == eps);
                    REQUIRE(apx.Eps2() == eps*eps);
                }
            };

            namespace Constructor
            {
                TEST_CASE_METHOD(ApproximateComparerFixture<double>, "double")
                {
                    TestConstruct(1.0);
                    TestConstruct(0.1);
                    TestConstruct(0.01);
                    TestConstruct(0.001);

                    TestConstruct(10);
                    TestConstruct(100);
                    TestConstruct(1000);
                }
            }   
        }
    }
}