//
// Created by Professional on 08.10.2021.
//

#ifndef COLUMNAR_SSE2_NEON_H
#define COLUMNAR_SSE2_NEON_H
    typedef int64x2_t __m128i; /* 128-bit vector containing integers */

    // Loads 128-bit value. :
    // https://msdn.microsoft.com/zh-cn/library/f4k12ae8(v=vs.90).aspx
    FORCE_INLINE __m128i _mm_loadu_si128(const __m128i *p)
    {
        return vreinterpretq_m128i_s32(vld1q_s32((const int32_t *) p));
    }

    // Stores four 32-bit integer values as (as a __m128i value) at the address p.
    // https://msdn.microsoft.com/en-us/library/vstudio/edk11s13(v=vs.100).aspx
    FORCE_INLINE void _mm_store_si128(__m128i *p, __m128i a)
    {
        vst1q_s32((int32_t *) p, vreinterpretq_s32_m128i(a));
    }

    // Adds the 4 signed or unsigned 32-bit integers in a to the 4 signed or
    // unsigned 32-bit integers in b.
    //
    //   r0 := a0 + b0
    //   r1 := a1 + b1
    //   r2 := a2 + b2
    //   r3 := a3 + b3
    //
    // https://msdn.microsoft.com/en-us/library/vstudio/09xs4fkk(v=vs.100).aspx
    FORCE_INLINE __m128i _mm_add_epi32(__m128i a, __m128i b)
    {
        return vreinterpretq_m128i_s32(
        vaddq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
    }

    // Adds the 4 signed or unsigned 64-bit integers in a to the 4 signed or
    // unsigned 32-bit integers in b.
    // https://msdn.microsoft.com/en-us/library/vstudio/09xs4fkk(v=vs.100).aspx
    FORCE_INLINE __m128i _mm_add_epi64(__m128i a, __m128i b)
    {
        return vreinterpretq_m128i_s64(
        vaddq_s64(vreinterpretq_s64_m128i(a), vreinterpretq_s64_m128i(b)));
    }
#endif //COLUMNAR_SSE2_NEON_H
