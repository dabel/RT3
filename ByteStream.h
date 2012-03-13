/* 
 * File: ByteStream.h
 * Description: RS2 Codec header
 * Author: t4
 * 
 */

#ifndef BYTESTREAM_H_
#define BYTESTREAM_H_

class ByteStream {
	public:
		
		ByteStream(char* b);
		
		~ByteStream();
		
		char* getBuffer();
				
		char getByte();
		
		unsigned char getByteUnsigned();
		
		char getByteA();
		
		char getByteC();
		
		char getByteS();
		
		void getBytes(int offset, int length, char* b);
		
		void getBytesReverse(int offset, int length, char* b);
		
		void getBytesReverseA(int offset, int length, char* b);
		
		short getShort();
		
		short getShortA();
		
		short getShortLE();
		
		short getShortLEA();
		
		short getSmart();
				
		int getTryte();		
		
		int getInt();
		
		int getIntME1();
		
		int getIntME2();
		
		long getLong();
	
		char* getRS2String();
		
	private:
		int pos;
		char* buffer;	
};
#endif

