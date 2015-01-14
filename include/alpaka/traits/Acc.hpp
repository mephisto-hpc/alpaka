/**
* \file
* Copyright 2014-2015 Benjamin Worpitz
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

namespace alpaka
{
    //-----------------------------------------------------------------------------
    //! The traits.
    //-----------------------------------------------------------------------------
    namespace traits
    {
        //#############################################################################
        //! The compile-time accelerator trait.
        //#############################################################################
        template<typename T, typename TSfinae = void>
        struct GetAcc;
    }

    //#############################################################################
    //! The compile-time accelerator trait alias template to remove the ::type.
    //#############################################################################
    template<typename T>
    using GetAccT = typename traits::GetAcc<T>::type;
}