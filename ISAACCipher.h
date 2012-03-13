/* 
 * File: ISAACCipher.h
 * Description: ISAAC Cipher header
 * Author: t4
 * 
 */

#ifndef ISAACCIPHER_H_
#define ISAACCIPHER_H_

class ISAACCipher {
	public:
		static const int SEED_LEN = 4;
		static const int RATIO = 0x9e3779b9;
		static const int SIZE_LOG = 8;
		static const int SIZE = 1 << SIZE_LOG;
		static const int MASK = (SIZE - 1) << 2;
	
		ISAACCipher(int seedv[]);
	
		~ISAACCipher();
	
		int getNextValue();
	
		void isaac();	
	
		void init(bool flag);
	
	private:
		int count;
		int a, b, c;
		int* results;
		int* memory;
};	
#endif

