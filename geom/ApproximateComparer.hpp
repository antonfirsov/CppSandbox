#pragma once

namespace mums
{

    template<typename _TScalar>
    class _ApproximateComparerBase
    {
    public:
        typedef _TScalar TScalar;

    private:
        const TScalar _eps;
        const TScalar _negEps;
        const TScalar _eps2;
        const TScalar _negEps2;
        const TScalar _eps15;
        const TScalar _negEps15;
    public:

        TScalar Eps() const { return _eps; }

        TScalar Eps2() const { return _eps2; }

        _ApproximateComparerBase(TScalar eps) :
            _eps(eps),
            _negEps(-eps),
            _eps2(eps*eps),
            _negEps2(-_eps2),
            _eps15(std::pow(eps, static_cast<TScalar>(1.5))),
            _negEps15(-_eps15)
        {

        }

        bool Zero(const TScalar d) const
        {
            return d > _negEps && d < _eps;
        }
/*
        inline bool Zero(const TVEC2(TScalar)& v)
        {
            return Zero(v.x) && Zero(v.y);
        }

        inline bool Zero(const TVEC3(TScalar)& v)
        {
            return Zero(v.x) && Zero(v.y) && Zero(v.z);
        }

        inline bool Zero2(const TScalar d) const
        {
            return d > _negEps2 && d < _eps2;
        }*/

        bool Equals(const TScalar a, const TScalar b) const
        {
            TScalar d = a - b;
            return d > _negEps && d < _eps;
        }

        bool GT(const TScalar a, const TScalar b) const
        {
            return a > b + _eps;
        }

        bool LT(const TScalar a, const TScalar b) const
        {
            return a < b + _negEps;
        }

        bool GE(const TScalar a, const TScalar b) const
        {
            return a > b + _negEps;
        }

        bool LE(const TScalar a, const TScalar b) const
        {
            return b > a + _negEps;
        }

        int Sign(const TScalar a) const
        {
            if (a > _eps) return 1;
            else if (a < _negEps) return -1;
            else return 0;
        }

        //inline bool Equals(const TVEC2(TScalar)& a, const TVEC2(TScalar)& b) const
        //{
        //    return Equals(a.x, b.x) && Equals(a.y, b.y);
        //}

        //inline bool Equals(const TVEC3(TScalar)& a, const TVEC3(TScalar)& b) const
        //{
        //    return Equals(a.x, b.x) && Equals(a.y, b.y) && Equals(a.z, b.z);
        //}

        //template<typename T>
        //typename std::enable_if<
        //    hirsch::geom::GeometryTraits<T>::IsLineSegment, bool
        //>::type
        //    Equals(const T& a, const T& b) const
        //{
        //    auto aStart = SegmentStart(a);
        //    auto aEnd = SegmentEnd(a);
        //    auto bStart = SegmentStart(b);
        //    auto bEnd = SegmentEnd(b);

        //    return Equals(aStart, bStart) && Equals(aEnd, bEnd) ||
        //        Equals(aStart, bEnd) && Equals(aEnd, bStart);
        //}

        //std::ostream& Print(std::ostream& s) const
        friend std::ostream& operator <<(std::ostream& s, const _ApproximateComparerBase& apx)
        {
            return s << "(eps=" << apx._eps << ")";
        }

        //bool Horizontal(const LineSegment<TScalar, 2>& l) const
        //{
        //    TScalar d = l.Dir();
        //    return d > _negEps && d < _eps;
        //}

        //bool Vertical(const LineSegment<TScalar, 2>& l) const
        //{
        //    TScalar d = l.Dir();
        //    return d > _negEps && d < _eps;
        //}

        /// <summary>
        /// Calculate the following value:
        /// res = |a b| = a*b + c*d
        ///       |c d|
        /// Returns exactly 0.0 if IsZero15(res) is expected.
        /// 
        /// Idea taken from:
        /// http://realtimecollisiondetection.net/pubs/GDC07_Ericson_Physics_Tutorial_Numerical_Robustness.ppt
        /// (slide 42)
        /// </summary>
        TScalar MulSum(double a, double b, double c, double d)
        {
            TScalar max = Max(Abs(a), Abs(b), Abs(c), Abs(d));
            TScalar eps = max < (TScalar)1 ? _eps15 : max * _eps15;

            TScalar det = a * b + c * d;
            if (det > -eps && det < eps) det = 0;
            return det;
        }

        /// <summary>
        /// Calculate corrected 2x2 determinant:
        /// det = |a b| = a*b - c*d
        ///       |c d|
        /// Returns exactly 0.0 if IsZero15(det) is expected.
        /// 
        /// Idea taken from:
        /// http://realtimecollisiondetection.net/pubs/GDC07_Ericson_Physics_Tutorial_Numerical_Robustness.ppt
        /// (slide 42)
        /// </summary>
        TScalar MulDiff(double a, double b, double c, double d)
        {
            TScalar max = Max(Abs(a), Abs(b), Abs(c), Abs(d));
            TScalar eps = max < (TScalar)1 ? _eps15 : max * _eps15;

            TScalar det = a * b - c * d;
            if (det > -eps && det < eps) det = 0;
            return det;
        }


        ///// <summary>
        ///// "robust" dot product.
        ///// Idea taken from:
        ///// http://realtimecollisiondetection.net/pubs/GDC07_Ericson_Physics_Tutorial_Numerical_Robustness.ppt
        ///// </summary>
        //TScalar Dot(const TVEC2(TScalar)& a, const TVEC2(TScalar)&  b)
        //{
        //    return MulSum(a.x, b.x, a.y, b.y);
        //}
    };

    template<typename _TScalar>
    class ApproximateComparer : public _ApproximateComparerBase<_TScalar>
    {
    public:

        typedef _TScalar TScalar; // ostoba clang 3.0

                                  /*ApproximateComparer(TScalar eps)
                                  : _ApproximateComparerBase(eps)
                                  {
                                  }*/
        ApproximateComparer(TScalar eps);

        static inline const ApproximateComparer<_TScalar>&  DefaultComparer();
    };


    template<>
    class ApproximateComparer<double> : public _ApproximateComparerBase<double>
    {
    public:

        typedef double TScalar; // ostoba clang 3.0



        ApproximateComparer(double eps)
            : _ApproximateComparerBase(eps)
        {
        }

        ApproximateComparer()
            : _ApproximateComparerBase(1e-5)
        {
        }

        static inline const ApproximateComparer<double>&  DefaultComparer()
        {
            static const ApproximateComparer<double> cmp;
            return cmp;
        }
    };

    template<>
    class ApproximateComparer<float> : public _ApproximateComparerBase<float>
    {
    public:

        typedef float TScalar; // ostoba clang 3.0

        ApproximateComparer(float eps)
            : _ApproximateComparerBase(eps)
        {
        }

        ApproximateComparer()
            : _ApproximateComparerBase(1e-5f)
        {
        }

        static inline const ApproximateComparer<float>&  DefaultComparer()
        {
            static const ApproximateComparer<float> cmp;
            return cmp;
        }
    };
}