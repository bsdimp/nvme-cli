/* Copyright here */

/*
 * Linux / glibc compatibility iterface for <endian.h> which differs from 
 * the BSD standard in a number of trivial and annoying ways, plus provides
 * a few extras not found in BSD.
 *
 * The implementation also name-pollutes __bswap* and __*_identity, which we
 * do not. We have our out namespace pollution instead. Should those be required
 * they can be provided.
 */
#ifndef __ENDIAN_H__
#define __ENDIAN_H__ 1

/* FreeBSD defines most things in sys/endian.h */

#include <sys/endian.h>

/* Linux / glibc compatible interfaces */

#define __BYTE_ORDER	_BYTE_ORDER
#define __LITTLE_ENDIAN	_LITTLE_ENDIAN
#define __BIG_ENDIAN	_BIG_ENDIAN
#define __PDP_ENDIAN	_PDP_ENDIAN

/* Linux / glibc expects a float order too, FreeBSD doesn't have one, so assume smame */

#define __FLOAT_WORD_ORDER _BYTE_ORDER

/* Linux / glibc also allows people to use non-underscore prefixed versions */

#ifdef	__USE_MISC
#define LITTLE_ENDIAN	_LITTLE_ENDIAN
#define BIG_ENDIAN	_BIG_ENDIAN
#define PDP_ENDIAN	_PDP_ENDIAN
#define BYTE_ORDER	_BYTE_ORDER
#endif

/* long long pair interface */
#if _BYTE_ORDER == _LITTLE_ENDIAN
#define __LONG_LONG_PAIR(HI, LO) LO, HI
#elif _BYTE_ORDER == _BIG_ENDIAN
#define __LONG_LONG_PAIR(HI, LO) HI, LO
#endif

#endif /* __ENDIAN_H__ */
