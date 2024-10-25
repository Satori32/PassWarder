#include "PassWarder.h"

PassWarder ConstructPassWarder(char* Name, char* Pass) {
	PassWarder P;
	P.Name = ConstructFixedString<16>(Name, strlen(Name));
	P.Pass = ConstructFixedString<32>(Pass, strlen(Pass));
}

int IsNameValid(PassWarder& In, FixedString<16>& B) {
	return strcmp(In.Name.S, B.S);
}
int IsPassWardValid(PassWarder& In, FixedString<32>& B) {
	return strcmp(In.Pass.S, B.S);
}
int IsPassWarderValid(PassWarder& In, PassWarder& B) {
	int X = strcmp(In.Name.S, B.Name.S);
	if (X != 0) { return X; }
	X = strcmp(In.Pass.S, B.Pass.S);
	return X;
}