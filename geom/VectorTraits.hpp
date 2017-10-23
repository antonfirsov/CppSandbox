#pragma once
#include "glm/glm.hpp"
#include "glm/vec4.hpp"

namespace mums
{
    template<typename T, typename Enabler = void>
    struct VectorTraits
    {
        static const bool IsVector = false;

        static constexpr bool IsVectorOfDim(const glm::length_t dim)
        {
            return false;
        }
    };

    template<
        template <glm::length_t, typename, glm::qualifier> class TVector, 
        glm::length_t L, 
        typename T, 
        glm::qualifier Q
    >
    struct VectorTraits<
        TVector<L, T, Q>, 
        std::enable_if_t<
            std::is_same_v< TVector<L, T, Q>, typename glm::vec<L,T,Q>::type >
        >
    >
    {
        static const bool IsVector = true;        

        typedef glm::vec<L, T, Q> TVector;

        typedef typename TVector::value_type TScalar;

        static constexpr glm::length_t Dim()
        {
            return TVector::length();
        }

        static constexpr bool IsVectorOfDim(const glm::length_t dim)
        {
            return Dim() == dim;
        }
    };
}
