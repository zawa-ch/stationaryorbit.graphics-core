# stationaryorbit.graphics-core:/src/CMakeLists.txt
# Copyright 2020-2021 zawa-ch.
# GPLv3 (or later) license
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#

add_library(stationaryorbit.graphics-core SHARED
    ${Include_Dir}/stationaryorbit/graphics-core.color.hpp
    ${Include_Dir}/stationaryorbit/graphics-core.deformation.hpp
    ${Include_Dir}/stationaryorbit/graphics-core.image.hpp
    channelvalue.cpp
    cmycolor.cpp
    cmykcolor.cpp
    colorblending.cpp
    colorconvert.cpp
    colorfillimage.cpp
    fundamental.cpp
    grayscalecolor.cpp
    imagealign.cpp
    imageclamp.cpp
    imagecropping.cpp
    imageflip.cpp
    imagescaling.cpp
    imageshift.cpp
    imageturn.cpp
    interpolation.cpp
    opacity.cpp
    pixarray.cpp
    pixmap.cpp
    rgbcolor.cpp
    xyzcolor.cpp
    yuvcolor.cpp
)
