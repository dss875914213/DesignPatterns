#include <iostream>
#include "Expression.h"
#include "PlayContext.h"

using namespace std;

typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_(char const* str)
{
	hash_t ret{ basis };

	while (*str) {
		ret ^= *str;
		ret *= prime;
		str++;
	}

	return ret;
}

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

constexpr unsigned long long operator ""_hash(char const* p, size_t)
{
	return hash_compile_time(p);
}

int main()
{
	PlayContext* context = new PlayContext();
	cout << "ÉÏº£Ì²: " << endl;
	context->SetText("O 2 E 0.5 G 0.5 A 3 ");
	Expression* expression = nullptr;
	try
	{
		while (context->GetText().size() > 0)
		{
			string str = context->GetText().substr(0, 1);
			switch (hash_(str.c_str()))
			{
			case "O"_hash:
				expression = new Scale();
				break;
			case "C"_hash:
			case "D"_hash:
			case "E"_hash:
			case "F"_hash:
			case "G"_hash:
				expression = new Note();
				break;
			}
			expression->Interpret(context);
		}
	}
	catch (...)
	{
		cout << endl;
	}
}
