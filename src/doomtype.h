/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Simple basic typedefs, isolated here to make it easier
 *       separating modules.
 *
 *-----------------------------------------------------------------------------*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
   extern "C" {
#endif /* __cplusplus */

/*+----------------------------------------------------------------------------------------------+*/
typedef uint8_t u8;					///< 8bit unsigned integer
typedef uint16_t u16;				///< 16bit unsigned integer
typedef uint32_t u32;				///< 32bit unsigned integer
typedef uint64_t u64;				///< 64bit unsigned integer
/*+----------------------------------------------------------------------------------------------+*/
typedef int8_t s8;					///< 8bit signed integer
typedef int16_t s16;				///< 16bit signed integer
typedef int32_t s32;				///< 32bit signed integer
typedef int64_t s64;				///< 64bit signed integer
/*+----------------------------------------------------------------------------------------------+*/
typedef volatile u8 vu8;			///< 8bit unsigned volatile integer
typedef volatile u16 vu16;			///< 16bit unsigned volatile integer
typedef volatile u32 vu32;			///< 32bit unsigned volatile integer
typedef volatile u64 vu64;			///< 64bit unsigned volatile integer
/*+----------------------------------------------------------------------------------------------+*/
typedef volatile s8 vs8;			///< 8bit signed volatile integer
typedef volatile s16 vs16;			///< 16bit signed volatile integer
typedef volatile s32 vs32;			///< 32bit signed volatile integer
typedef volatile s64 vs64;			///< 64bit signed volatile integer
/*+----------------------------------------------------------------------------------------------+*/
// fixed point math typedefs
typedef s16 sfp16;					///< signed 8:8 fixed point
typedef s32 sfp32;					///< signed 20:8 fixed point
typedef u16 ufp16;					///< unsigned 8:8 fixed point
typedef u32 ufp32;					///< unsigned 24:8 fixed point
/*+----------------------------------------------------------------------------------------------+*/
typedef float f32;
typedef double f64;
/*+----------------------------------------------------------------------------------------------+*/
typedef volatile float vf32;
typedef volatile double vf64;
/*+----------------------------------------------------------------------------------------------+*/


typedef unsigned int BOOL;
/*+----------------------------------------------------------------------------------------------+*/
// alias type typedefs
#define FIXED s32					///< Alias type for sfp32
/*+----------------------------------------------------------------------------------------------+*/
#ifndef TRUE
#define TRUE	1					///< True
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef FALSE
#define FALSE	0					///< False
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef NULL
#define NULL	0					///< Pointer to 0
#endif
/*+----------------------------------------------------------------------------------------------+*/
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN  3412
#endif /* LITTLE_ENDIAN */
/*+----------------------------------------------------------------------------------------------+*/
#ifndef BIG_ENDIAN
#define BIG_ENDIAN     1234
#endif /* BIGE_ENDIAN */
/*+----------------------------------------------------------------------------------------------+*/
#ifndef BYTE_ORDER
#define BYTE_ORDER     BIG_ENDIAN
#endif /* BYTE_ORDER */
/*+----------------------------------------------------------------------------------------------+*/


//!	argv structure
/*!	\struct __argv

	structure used to set up argc/argv

*/
/*
struct __argv {
	int argvMagic;		//!< argv magic number, set to 0x5f617267 ('_arg') if valid 
	char *commandLine;	//!< base address of command line, set of null terminated strings
	int length;//!< total length of command line
	int argc;
	char **argv;
	char **endARGV;
};
*/

//!	Default location for the system argv structure.
extern struct __argv *__system_argv;

// argv struct magic number
#define ARGV_MAGIC 0x5f617267

#ifdef __cplusplus
   }
#endif /* __cplusplus */

//#########################################################################################




#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
/* Fixed to use builtin bool type with C++. */
#ifdef __cplusplus
typedef bool bool;
#else
//typedef enum {false, true} bool;
#endif
typedef unsigned char byte;
#endif

/* cph - Wrapper for the long long type, as Win32 used a different name.
 * Except I don't know what to test as it's compiler specific
 * Proff - I fixed it */
#ifndef _MSC_VER
typedef signed long long int_64_t;
typedef unsigned long long uint_64_t;
// define compiled-specific long-long contstant notation here
#define LONGLONG(num)   (uint_64_t)num ## ll
#else
typedef __int64 int_64_t;
typedef unsigned __int64 uint_64_t;
// define compiled-specific long-long contstant notation here
#define LONGLONG(num) (uint_64_t)num
#undef PATH_MAX
#define PATH_MAX 1024
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define S_ISDIR(x) (((sbuf.st_mode & S_IFDIR)==S_IFDIR)?1:0)
#endif

#ifdef __GNUC__
#define CONSTFUNC __attribute__((const))
#define PUREFUNC __attribute__((pure))
#define NORETURN __attribute__ ((noreturn))
#else
#define CONSTFUNC
#define PUREFUNC
#define NORETURN
#endif

/* CPhipps - use limits.h instead of depreciated values.h */
#include <limits.h>

/* cph - move compatibility levels here so we can use them in d_server.c */
typedef enum {
  doom_12_compatibility,   /* Doom v1.2 */
  doom_1666_compatibility, /* Doom v1.666 */
  doom2_19_compatibility,  /* Doom & Doom 2 v1.9 */
  ultdoom_compatibility,   /* Doom 2 v1.9 */
  finaldoom_compatibility,     /* Final & Ultimate Doom v1.9, and Doom95 */
  dosdoom_compatibility,     /* Early dosdoom & tasdoom */
  tasdoom_compatibility,     /* Early dosdoom & tasdoom */
  boom_compatibility_compatibility,      /* Boom's compatibility mode */
  boom_201_compatibility,                /* Compatible with Boom v2.01 */
  boom_202_compatibility,                /* Compatible with Boom v2.01 */
  lxdoom_1_compatibility,                /* LxDoom v1.3.2+ */
  mbf_compatibility,                     /* MBF */
  prboom_1_compatibility,                /* PrBoom 2.03beta? */
  prboom_2_compatibility,                /* PrBoom 2.1.0-2.1.1 */
  prboom_3_compatibility,                /* PrBoom 2.2.x */
  prboom_4_compatibility,                /* PrBoom 2.3.x */
  prboom_5_compatibility,                /* PrBoom 2.4.0 */
  prboom_6_compatibility,                /* Latest PrBoom */
  MAX_COMPATIBILITY_LEVEL,               /* Must be last entry */
  /* Aliases follow */
  boom_compatibility = boom_201_compatibility, /* Alias used by G_Compatibility */
  best_compatibility = prboom_6_compatibility,
} complevel_t;

/* cph - from v_video.h, needed by gl_struct.h */
enum patch_translation_e {
  VPT_NONE    = 0, // Normal
  VPT_FLIP    = 1, // Flip image horizontally
  VPT_TRANS   = 2, // Translate image via a translation table
  VPT_STRETCH = 4, // Stretch to compensate for high-res
};

#endif
