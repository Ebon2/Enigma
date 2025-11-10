/**
 * @file structures.h
 * @brief This file contains the enums and data structures.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for data structures used throughout the program.
 * It includes definitions for barrel and reflector configurations, file paths, and
 * other program-wide settings.
 */

#ifndef structures_H
#define structures_H

/**
 * @brief Enumerates different levels of encryption or decryption.
 */
typedef enum {
    ENCRYPT, /**< Encryption mode. */
    DECRYPT, /**< Decryption mode. */
} mod_t;

/**
 * @brief Enumerates different levels of encryption or decryption.
 */
typedef enum {
    NONE = -1, /**< None encryption mode*/
    LOW = 1, /**< Low encryption level. */
    HIGH = 2, /**< High encryption level. */
    EXTREME = 3, /**< Extreme encryption level. */
} level_t;

/**
 * @brief Represents a character combination for encryption or decryption.
 */
typedef struct {
    char input; /**< Represents a single character input to be processed. */
    char output; /**< Represents a single character output resulting from processing. */
} comb_t;

/**
 * @brief Represents a character combination for encryption or decryption in format int.
 */
typedef struct {
    int input; /**< Represents a single character input to be processed. */
    int output; /**< Represents a single character output resulting from processing. */
} int_comb_t;

#endif
