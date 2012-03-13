/* 
 * File: PacketFactory.h
 * Description: Packet Factory header
 * Author: t4
 * 
 */

#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_

class PacketFactory {
	public:
		
		PacketFactory(char* b);
		
		~PacketFactory();
		
		char* getBuffer();
				
		void putByte(char val);
		
		void putByteA(char val);
		
		void putByteC(char val);
		
		void putByteS(char val);
		
		void putBytes(int offset, int length, char* b);
		
		void putBytesReverse(int offset, int length, char* b);
		
		void putBytesReverseA(int offset, int length, char* b);
		
		void putShort(short val);
		
		void putShortA(short val);
		
		void putShortLE(short val);
		
		void putShortLEA(short val);
		
		void putSmart(short val);
				
		void putTryte(int val);		
		
		void putInt(int val);
		
		void putIntME1(int val);
		
		void putIntME2(int val);
		
		void putLong(long val);
	
		void putRS2String(char* cstr);
		
		void initBitAccess();
		
		void writeBits(int num, int val);	
		
		void finishBitAccess();	
		
	private:
		int pos;
		int bitpos;
		char* buffer;	
		int* bitMasks;
};


#endif

