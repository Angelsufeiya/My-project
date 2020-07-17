#pragma once
#include <string>
#include "BigInt.h"

namespace dg
{
	typedef BigInt rsaDataType;
	constexpr int BUFFERSIZE = 256;

	struct RsaKey
	{
		// (e, n) (d, n)
		rsaDataType m_eKey;	// 公钥：加密密钥（不唯一）
		rsaDataType m_dKey;	// 私钥：解密密钥（不唯一）
		rsaDataType m_pKey;	// 公用的n
	};

	class Rsa
	{
	private:
		RsaKey m_key;
	private:
		static bool isPrime(rsaDataType num);
		static rsaDataType getRandom();
		static rsaDataType getPrime();
		static rsaDataType getPKey(rsaDataType prime1, rsaDataType prime2);
		static rsaDataType getOrla(rsaDataType prime1, rsaDataType prime2);
		static rsaDataType getEKey(rsaDataType orla);
		static rsaDataType getDKey(rsaDataType eKey, rsaDataType orla);
		static rsaDataType extendGcd(rsaDataType a, rsaDataType b, rsaDataType& x, rsaDataType& y);
		static rsaDataType getGcd(rsaDataType num1, rsaDataType num2);
		rsaDataType dealData(rsaDataType data, rsaDataType e, rsaDataType n);

	public:
		Rsa();
		Rsa(const RsaKey& key);

		static RsaKey getRsaKey();
		rsaDataType ecrept(rsaDataType data);
		rsaDataType ecrept(rsaDataType data, rsaDataType eKey, rsaDataType pKey);
		rsaDataType decrept(rsaDataType data);
		rsaDataType decrept(rsaDataType data, rsaDataType dKey, rsaDataType pKey);
		bool ecreptFile(const std::string filename, const std::string e_filename);
		bool decreptFile(const std::string e_filename, const std::string d_filename);

		void show() const;
	};
}