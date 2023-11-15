/**
 * \file config-tfm.h
 *
 * \brief TF-M medium profile, adapted to work on other platforms.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/* TF-M medium profile: mbedtls legacy configuration */
#include "../configs/ext/tfm_mbedcrypto_config_profile_medium.h"

/* TF-M medium profile: PSA crypto configuration */
#define MBEDTLS_PSA_CRYPTO_CONFIG_FILE "../configs/ext/crypto_config_profile_medium.h"

/***********************************************************/
/* Tweak the configuration to remove dependencies on TF-M. */
/***********************************************************/

/* MBEDTLS_PSA_CRYPTO_SPM needs third-party files, so disable it. */
#undef MBEDTLS_PSA_CRYPTO_SPM

/* Use built-in platform entropy functions (TF-M provides its own). */
#undef MBEDTLS_NO_PLATFORM_ENTROPY

/* Disable buffer-based memory allocator. This isn't strictly required,
 * but using the native allocator is faster and works better with
 * memory management analysis frameworks such as ASan. */
#undef MBEDTLS_MEMORY_BUFFER_ALLOC_C

// This macro is enabled in TFM Medium but is disabled here because it is
// incompatible with baremetal builds in Mbed TLS.
#undef MBEDTLS_PSA_CRYPTO_STORAGE_C

// This macro is enabled in TFM Medium but is disabled here because it is
// incompatible with baremetal builds in Mbed TLS.
#undef MBEDTLS_ENTROPY_NV_SEED

// These platform-related TF-M settings are not useful here.
#undef MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#undef MBEDTLS_PLATFORM_STD_MEM_HDR
#undef MBEDTLS_PLATFORM_SNPRINTF_MACRO
#undef MBEDTLS_PLATFORM_PRINTF_ALT
#undef MBEDTLS_PLATFORM_STD_EXIT_SUCCESS
#undef MBEDTLS_PLATFORM_STD_EXIT_FAILURE

// We expect TF-M to pick this up soon
#define MBEDTLS_BLOCK_CIPHER_NO_DECRYPT

/***********************************************************************
 * Local changes to crypto config below this delimiter
 **********************************************************************/

/* Between Mbed TLS 3.4 and 3.5, the PSA_WANT_KEY_TYPE_RSA_KEY_PAIR macro
 * (commented-out above) has been replaced with the following new macros: */
//#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC      1
//#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT     1
//#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_EXPORT     1
//#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE   1
//#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_DERIVE     1 /* Not supported */

/* Between Mbed TLS 3.4 and 3.5, the following macros have been added: */
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_BASIC       1
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_IMPORT    1
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_EXPORT    1
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_GENERATE  1
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_DERIVE    1 // Not supported
