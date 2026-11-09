#pragma once

typedef enum {
	ERR_OK = 0,		// No error
	ERR_OUT_OF_MEMORY,	// Segfault
	ERR_FILE_NOT_FOUND,
	ERR_INVALID_FORMAT,
	ERR_INVALID_ARGUMENT,	// Invalid argument (often when NULL)
	ERR_INVALID_TYPE,
	ERR_UNEXPECTED_RESULT,	// When a value returned by a function isn't expected
	ERR_NOT_IMPLEMENTED,
	ERR_INTENTIONAL_STOP
} Error;

const char *errorString(int err);
