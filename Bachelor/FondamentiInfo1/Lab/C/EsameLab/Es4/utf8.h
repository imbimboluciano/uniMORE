#pragma once
#include<stdint.h>
#include<stdlib.h>

extern size_t utf8_encode(uint32_t codepoint, uint8_t seq[4]);