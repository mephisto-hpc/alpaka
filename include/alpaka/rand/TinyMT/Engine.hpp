/**
* \file
* Copyright 2018 Axel Huebl
*
* This file is part of alpaka.
*
* alpaka is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* alpaka is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with alpaka.
* If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <boost/predef.h>

#include <cstdint>

#if BOOST_COMP_CLANG
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wold-style-cast"
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wsign-conversion"
#endif
#if BOOST_COMP_GNUC
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wsign-conversion"
#endif
#include <alpaka/rand/TinyMT/tinymt32.h>
#if BOOST_COMP_CLANG
#   pragma clang diagnostic pop
#   pragma clang diagnostic pop
#endif
#if BOOST_COMP_GNUC
#   pragma GCC diagnostic pop
#endif

namespace alpaka
{
namespace rand
{
namespace generator
{
namespace cpu
{
    //! Implementation of std::UniformRandomBitGenerator for TinyMT32
    struct TinyMTengine
    {
        using result_type = std::uint32_t;

        static constexpr result_type default_seed()
        {
            return 42u;
        }

        void seed( result_type value = default_seed() )
        {
            tinymt32_init( &prng, value );
        }

        TinyMTengine( std::uint32_t const & seedValue )
        {
            // parameters from TinyMT/jump/sample.c
            prng.mat1 = 0x8f7011ee;
            prng.mat2 = 0xfc78ff1f;
            prng.tmat = 0x3793fdff;

            seed( seedValue );
        }

        TinyMTengine() = delete;

        result_type operator()()
        {
            return tinymt32_generate_uint32( &prng );
        }

        static constexpr result_type min()
        {
            return 0u;
        }

        static constexpr result_type max()
        {
            return UINT32_MAX;
        }

        void discard( unsigned long long ) // z
        {
            // not implemented
            // tinymt32_jump( &prng, z, z );
        }

        tinymt32_t prng;
    };

} // namespace cpu
} // namespace generator
} // namespace rand
} // namespace alpaka