#pragma once
#include <stdio.h>

#include "FixedString.h"

struct PassWarder {
	FixedString<16> Name;
	FixedString<32> Pass;
};

PassWarder ConstructPassWarder(char* Name, char* Pass);
int IsNameValid(PassWarder& In, FixedString<16>& B);
int IsPassWardValid(PassWarder& In, FixedString<32>& B);
int IsPassWarderValid(PassWarder& In, PassWarder& B);
