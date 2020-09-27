#pragma once
#include <msclr\gcroot.h>
#include <string>

using namespace std;
using namespace System;
using namespace System::Linq;

public class StrToArray
{
public:
	StrToArray() { }
	ref class StrToArrayHelper
	{
	public:
		static String^ hex01;
		static bool lambdaWhereItem(int x)
		{
			return  x % 2 == 0;
		}
		static System::Byte lambdaItem(int x)
		{
			String^ hex = hex01;
			return Convert::ToByte(hex->Substring(x, 2), 16);
		}
	};
	static msclr::gcroot<cli::array<System::Byte>^> StringToByteArray(string hex)
	{
		StrToArrayHelper::hex01 = gcnew String(hex.c_str());
		System::Collections::Generic::IEnumerable<int>^ Numbers = Enumerable::Range(0, StrToArrayHelper::hex01->Length);
		auto Where = Enumerable::Where(Numbers, gcnew Func<int, bool>(StrToArrayHelper::lambdaWhereItem));


		auto Selecteds = Enumerable::Select(Where, gcnew Func<int, System::Byte>(StrToArrayHelper::lambdaItem));
		auto ByteArray = Enumerable::ToArray(Selecteds);
		return ByteArray;
	}
};