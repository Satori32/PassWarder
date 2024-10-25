#include "FixedString.h"

bool Set(UTF8_Char& In, char a, char b, char c) {
	In.A = a;
	In.B = b;
	In.C = c;
	return true;
}
bool Clear(UTF8_Char& In) {
	In.A = 0;
	In.B = 0;
	In.C = 0;
	In.null = 0;
	return true;
}
template<size_t N>
FixedString<N> StringFormater<N>(char* Format, ...) {
	va_list V = NULL;
	char Buff[10230] = { 0, };

	va_start(V, Format);
	sprintf(Buff, Format, V);

	//va_end(V);

	FixedString<N> S = ConstrucFixedtString(Buff, strlen(Buff));


	return S;
}
template<size_t N>
bool Push(FixedUTF8<N> In, UTF8_Char& B) {
	return Push(In.S, B);
}

template<size_t N>
FixedUTF8<N> ConstructFixedUTF8<N>(char* S, size_t L) {
	FixedUTF8<N + 1> F;
	From(F, S, L);

	return F;
}
template<size_t N>
size_t Length(FixedUTF8<N>& In) {
	return Size(In.S);
}
template<size_t N>
size_t Size(FixedUTF8<N>& In) {
	return Size(In.S);
}
template <size_t A, size_t B>
FixedString<A> MakeSingle(FixedUTF8<B>& In) {
	FixedString<A> F;
	for (size_t i = 0; i < Size(In.S); i++) {
		strcat(F.S, Index(In, i)->CHAR, A);
	}
	return F;
}
template<size_t N>
UTF8_Char* Index(FixedUTF8<N>& In, size_t P) {
	if (P > Size(In.S)) { return NULL; }
	if (Index(In.S, P) == NULL) { return NULL; }
	return Index(In.S, P);
}

template<size_t N>
bool From(FixedUTF8<N>& In, const char* S, size_t L) {
	Clear(In.V);
	UTF8_Char UC;

	char A = 0;
	char B = 0;
	char C = 0;
	//size_t L = Min(L, Size(In.S));
	for (size_t i = 0; i < L; i++) {
		Clear(UC);
		A = S[i];
		if ((B & (1 << 7)) == 0) {
			i++;
			B = S[i];
		}
		B = S[i];
		if ((B & (1 << 7)) == 0) {
			i++;
			C = S[i];
		}
		Set(UC, A, B, C);
		A = 0;
		B = 0;
		C = 0;
		Push(In, UC);
		if (Size(In.S) >= N) { break; }
	}
	return true;
}
template<class T>
const T& Min(const T& A, const T& B) {
	return A < B ? A : B;
}
template<size_t N>
FixedString<N> ConstructFixedString<N>(char* S, size_t L) {
	FixedString<N> F;
	memcpy((void*)&F.S[0], S, Min(F.L, L + 1));
	return F;
}
template<size_t N>
size_t Length(FixString<N>& In) {
	return strlen(In.S);
}
template<size_t N>
char* GetPTR(FixString<N>& In) {
	return &In.S[0];
}
template<size_t A, size_t B>
FixString<A + B + 2> Add(FixString<A>& A, FixString<B>& B) {
	FixedString<A + B + 2> C = ConstructFixedString<A + B + 2>(A.S, strlen(A.S));
	strcat(GetPTR(C), C.L);

	return C;
}
template<size_t N>
size_t Capacity(FixString<N>& In) {
	return N;
}
template<size_t N>
char* Index(FixString<N>& In, size_t P) {
	if (N >= P) { return NULL: }
	return &In.S[P];
}