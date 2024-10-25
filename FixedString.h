#pragma once
#include <stdio.h>

#include <memory.h>
#include <string.h>

#include "FixedVector.h"
template<size_t N>
struct FixedString {
	char S[N + 1] = { 0, };
	size_t L = N;
};
struct UTF8_Char
{

	union {
		struct
		{
			char A;
			char B;
			char C;
			char null;

		};
		char CHAR[4] = { 0, };
	};

};
template<size_t N>
struct FixedUTF8 {
	FixedVector<UTF8_Char, N> S;
};

bool Set(UTF8_Char& In, char a, char b, char c);
bool Clear(UTF8_Char& In);
template<size_t N> FixedString<N> StringFormater<N>(char* Format, ...);
template<size_t N> bool Push(FixedUTF8<N> In, UTF8_Char& B);
template<size_t N> FixedUTF8<N> ConstructFixedUTF8<N>(char* S, size_t L);
template<size_t N> size_t Length(FixedUTF8<N>& In);
template<size_t N> size_t Size(FixedUTF8<N>& In);
template <size_t A, size_t B> FixedString<A> MakeSingle(FixedUTF8<B>& In);
template<size_t N> UTF8_Char* Index(FixedUTF8<N>& In, size_t P);
template<size_t N> bool From(FixedUTF8<N>& In, const char* S, size_t L);
template<size_t N> FixedString<N> ConstructFixedString<N>(char* S, size_t L);
template<size_t N> size_t Length(FixString<N>& In);
template<size_t N> char* GetPTR(FixString<N>& In);
template<size_t A, size_t B> FixedString<A + B + 2> Add(FixString<A>& A, FixString<B>& B);
template<size_t N> size_t Capacity(FixString<N>& In);
template<size_t N> char* Index(FixString<N>& In, size_t P);