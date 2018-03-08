/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * soup-version.h: Version information
 *
 * Copyright (C) 2012 Igalia S.L.
 */

#ifndef SOUP_VERSION_H
#define SOUP_VERSION_H

#include <glib.h>

G_BEGIN_DECLS

#define SOUP_MAJOR_VERSION (2)
#define SOUP_MINOR_VERSION (53)
#define SOUP_MICRO_VERSION (2)

#define SOUP_CHECK_VERSION(major, minor, micro) \
    (SOUP_MAJOR_VERSION > (major) || \
    (SOUP_MAJOR_VERSION == (major) && SOUP_MINOR_VERSION > (minor)) || \
    (SOUP_MAJOR_VERSION == (major) && SOUP_MINOR_VERSION == (minor) && \
     SOUP_MICRO_VERSION >= (micro)))

#ifndef _SOUP_EXTERN
#define _SOUP_EXTERN extern
#endif

/* We prefix variable declarations so they can
 * properly get exported in Windows DLLs.
 */
#ifndef SOUP_VAR
#  ifdef G_PLATFORM_WIN32
#    ifdef LIBSOUP_COMPILATION
#      ifdef DLL_EXPORT
#        define SOUP_VAR __declspec(dllexport)
#      else /* !DLL_EXPORT */
#        define SOUP_VAR extern
#      endif /* !DLL_EXPORT */
#    else /* !SOUP_COMPILATION */
#      define SOUP_VAR extern __declspec(dllimport)
#    endif /* !LIBSOUP_COMPILATION */
#  else /* !G_PLATFORM_WIN32 */
#    define SOUP_VAR _SOUP_EXTERN
#  endif /* !G_PLATFORM_WIN32 */
#endif /* SOUP_VAR */

/* Deprecation / Availability macros */

#define SOUP_VERSION_2_24 (G_ENCODE_VERSION (2, 24))
#define SOUP_VERSION_2_26 (G_ENCODE_VERSION (2, 26))
#define SOUP_VERSION_2_28 (G_ENCODE_VERSION (2, 28))
#define SOUP_VERSION_2_30 (G_ENCODE_VERSION (2, 30))
#define SOUP_VERSION_2_32 (G_ENCODE_VERSION (2, 32))
#define SOUP_VERSION_2_34 (G_ENCODE_VERSION (2, 34))
#define SOUP_VERSION_2_36 (G_ENCODE_VERSION (2, 36))
#define SOUP_VERSION_2_38 (G_ENCODE_VERSION (2, 38))
#define SOUP_VERSION_2_40 (G_ENCODE_VERSION (2, 40))
#define SOUP_VERSION_2_42 (G_ENCODE_VERSION (2, 42))
#define SOUP_VERSION_2_44 (G_ENCODE_VERSION (2, 44))
#define SOUP_VERSION_2_46 (G_ENCODE_VERSION (2, 46))
#define SOUP_VERSION_2_48 (G_ENCODE_VERSION (2, 48))
#define SOUP_VERSION_2_50 (G_ENCODE_VERSION (2, 50))
#define SOUP_VERSION_2_52 (G_ENCODE_VERSION (2, 52))
#define SOUP_VERSION_2_54 (G_ENCODE_VERSION (2, 54))

/* evaluates to the current stable version; for development cycles,
 * this means the next stable target
 */
#if (SOUP_MINOR_VERSION % 2)
#define SOUP_VERSION_CUR_STABLE (G_ENCODE_VERSION (SOUP_MAJOR_VERSION, SOUP_MINOR_VERSION + 1))
#else
#define SOUP_VERSION_CUR_STABLE (G_ENCODE_VERSION (SOUP_MAJOR_VERSION, SOUP_MINOR_VERSION))
#endif

/* evaluates to the previous stable version */
#if (SOUP_MINOR_VERSION % 2)
#define SOUP_VERSION_PREV_STABLE (G_ENCODE_VERSION (SOUP_MAJOR_VERSION, SOUP_MINOR_VERSION - 1))
#else
#define SOUP_VERSION_PREV_STABLE (G_ENCODE_VERSION (SOUP_MAJOR_VERSION, SOUP_MINOR_VERSION - 2))
#endif

#ifndef SOUP_VERSION_MIN_REQUIRED
# define SOUP_VERSION_MIN_REQUIRED (SOUP_VERSION_CUR_STABLE)
#elif SOUP_VERSION_MIN_REQUIRED == 0
# undef  SOUP_VERSION_MIN_REQUIRED
# define SOUP_VERSION_MIN_REQUIRED (SOUP_VERSION_CUR_STABLE + 2)
#endif

#if !defined (SOUP_VERSION_MAX_ALLOWED) || (SOUP_VERSION_MAX_ALLOWED == 0)
# undef SOUP_VERSION_MAX_ALLOWED
# define SOUP_VERSION_MAX_ALLOWED (SOUP_VERSION_CUR_STABLE)
#endif

/* sanity checks */
#if SOUP_VERSION_MIN_REQUIRED > SOUP_VERSION_CUR_STABLE
#error "SOUP_VERSION_MIN_REQUIRED must be <= SOUP_VERSION_CUR_STABLE"
#endif
#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_MIN_REQUIRED
#error "SOUP_VERSION_MAX_ALLOWED must be >= SOUP_VERSION_MIN_REQUIRED"
#endif
#if SOUP_VERSION_MIN_REQUIRED < SOUP_VERSION_2_24
#error "SOUP_VERSION_MIN_REQUIRED must be >= SOUP_VERSION_2_24"
#endif

#define SOUP_AVAILABLE_IN_2_4                   _SOUP_EXTERN

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_24
# define SOUP_DEPRECATED_IN_2_24                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_24_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_24
# define SOUP_DEPRECATED_IN_2_24_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_24
# define SOUP_AVAILABLE_IN_2_24                 G_UNAVAILABLE(2, 24) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_24                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_26
# define SOUP_DEPRECATED_IN_2_26                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_26_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_26
# define SOUP_DEPRECATED_IN_2_26_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_26
# define SOUP_AVAILABLE_IN_2_26                 G_UNAVAILABLE(2, 26) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_26                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_28
# define SOUP_DEPRECATED_IN_2_28                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_28_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_28
# define SOUP_DEPRECATED_IN_2_28_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_28
# define SOUP_AVAILABLE_IN_2_28                 G_UNAVAILABLE(2, 28) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_28                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_30
# define SOUP_DEPRECATED_IN_2_30                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_30_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_30
# define SOUP_DEPRECATED_IN_2_30_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_30
# define SOUP_AVAILABLE_IN_2_30                 G_UNAVAILABLE(2, 30) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_30                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_32
# define SOUP_DEPRECATED_IN_2_32                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_32_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_32
# define SOUP_DEPRECATED_IN_2_32_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_32
# define SOUP_AVAILABLE_IN_2_32                 G_UNAVAILABLE(2, 32) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_32                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_34
# define SOUP_DEPRECATED_IN_2_34                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_34_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_34
# define SOUP_DEPRECATED_IN_2_34_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_34
# define SOUP_AVAILABLE_IN_2_34                 G_UNAVAILABLE(2, 34) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_34                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_36
# define SOUP_DEPRECATED_IN_2_36                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_36_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_36
# define SOUP_DEPRECATED_IN_2_36_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_36
# define SOUP_AVAILABLE_IN_2_36                 G_UNAVAILABLE(2, 36) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_36                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_38
# define SOUP_DEPRECATED_IN_2_38                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_38_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_38
# define SOUP_DEPRECATED_IN_2_38_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_38
# define SOUP_AVAILABLE_IN_2_38                 G_UNAVAILABLE(2, 38) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_38                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_40
# define SOUP_DEPRECATED_IN_2_40                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_40_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_40
# define SOUP_DEPRECATED_IN_2_40_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_40
# define SOUP_AVAILABLE_IN_2_40                 G_UNAVAILABLE(2, 40) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_40                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_42
# define SOUP_DEPRECATED_IN_2_42                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_42_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_42
# define SOUP_DEPRECATED_IN_2_42_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_42
# define SOUP_AVAILABLE_IN_2_42                 G_UNAVAILABLE(2, 42) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_42                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_44
# define SOUP_DEPRECATED_IN_2_44                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_44_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_44
# define SOUP_DEPRECATED_IN_2_44_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_44
# define SOUP_AVAILABLE_IN_2_44                 G_UNAVAILABLE(2, 44) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_44                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_46
# define SOUP_DEPRECATED_IN_2_46                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_46_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_46
# define SOUP_DEPRECATED_IN_2_46_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_46
# define SOUP_AVAILABLE_IN_2_46                 G_UNAVAILABLE(2, 46) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_46                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_48
# define SOUP_DEPRECATED_IN_2_48                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_48_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_48
# define SOUP_DEPRECATED_IN_2_48_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_48
# define SOUP_AVAILABLE_IN_2_48                 G_UNAVAILABLE(2, 48) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_48                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_50
# define SOUP_DEPRECATED_IN_2_50                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_50_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_50
# define SOUP_DEPRECATED_IN_2_50_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_50
# define SOUP_AVAILABLE_IN_2_50                 G_UNAVAILABLE(2, 50) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_50                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_52
# define SOUP_DEPRECATED_IN_2_52                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_52_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_52
# define SOUP_DEPRECATED_IN_2_52_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_52
# define SOUP_AVAILABLE_IN_2_52                 G_UNAVAILABLE(2, 52) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_52                 _SOUP_EXTERN
#endif

#if SOUP_VERSION_MIN_REQUIRED >= SOUP_VERSION_2_54
# define SOUP_DEPRECATED_IN_2_54                G_DEPRECATED
# define SOUP_DEPRECATED_IN_2_54_FOR(f)         G_DEPRECATED_FOR(f)
#else
# define SOUP_DEPRECATED_IN_2_54
# define SOUP_DEPRECATED_IN_2_54_FOR(f)
#endif

#if SOUP_VERSION_MAX_ALLOWED < SOUP_VERSION_2_54
# define SOUP_AVAILABLE_IN_2_54                 G_UNAVAILABLE(2, 54) _SOUP_EXTERN
#else
# define SOUP_AVAILABLE_IN_2_54                 _SOUP_EXTERN
#endif

SOUP_AVAILABLE_IN_2_42
guint    soup_get_major_version (void);

SOUP_AVAILABLE_IN_2_42
guint    soup_get_minor_version (void);

SOUP_AVAILABLE_IN_2_42
guint    soup_get_micro_version (void);

SOUP_AVAILABLE_IN_2_42
gboolean soup_check_version     (guint major,
				 guint minor,
				 guint micro);

G_END_DECLS

#endif /* SOUP_VERSION_H */