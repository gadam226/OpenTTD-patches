/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file 32bpp_sse_type.hpp Types related to SSE 32 bpp blitter. */

#ifndef BLITTER_32BPP_SSE_TYPE_HPP
#define BLITTER_32BPP_SSE_TYPE_HPP

#ifdef WITH_SSE

#include "32bpp_simple.hpp"

#define META_LENGTH 2 ///< Number of uint32 inserted before each line of pixels in a sprite.
#define MARGIN_NORMAL_THRESHOLD (zoom == ZOOM_LVL_OUT_32X ? 8 : 4) ///< Minimum width to use margins with BM_NORMAL.
#define MARGIN_REMAP_THRESHOLD 4 ///< Minimum width to use margins with BM_COLOUR_REMAP.

#define CLEAR_HIGH_BYTE_MASK        _mm_setr_epi8(-1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0)
#define ALPHA_CONTROL_MASK          _mm_setr_epi8( 6,  7,  6,  7,  6,  7, -1, -1, 14, 15, 14, 15, 14, 15, -1, -1)
#define PACK_LOW_CONTROL_MASK       _mm_setr_epi8( 0,  2,  4, -1,  8, 10, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1)
#define PACK_HIGH_CONTROL_MASK      _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1,  0,  2,  4, -1,  8, 10, 12, -1)
#define BRIGHTNESS_LOW_CONTROL_MASK _mm_setr_epi8( 1,  2,  1,  2,  1,  2,  0,  2,  3,  2,  3,  2,  3,  2,  0,  2)
#define BRIGHTNESS_DIV_CLEANER      _mm_setr_epi8(-1,  1, -1,  1, -1,  1, -1,  0, -1,  1, -1,  1, -1,  1, -1,  0)
#define OVERBRIGHT_PRESENCE_MASK    _mm_setr_epi8( 1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0)
#define OVERBRIGHT_VALUE_MASK       _mm_setr_epi8(-1,  0, -1,  0, -1,  0,  0,  0, -1,  0, -1,  0, -1,  0,  0,  0)
#define OVERBRIGHT_CONTROL_MASK     _mm_setr_epi8( 0,  1,  0,  1,  0,  1,  7,  7,  2,  3,  2,  3,  2,  3,  7,  7)
#define TRANSPARENT_NOM_BASE        _mm_setr_epi16(256, 256, 256, 256, 256, 256, 256, 256)

#endif /* WITH_SSE */
#endif /* BLITTER_32BPP_SSE_TYPE_HPP */
