/* 
 * File: PacketFactory.cpp
 * Description: Packet Factory impl
 * Author: t4
 * 
 */
 
#include <math.h>

#include "PacketFactory.h"

PacketFactory::PacketFactory(char* b) : pos(0), buffer(b) {
	bitMasks[32];
	for(int i = 0; i < 32; ++i)	
		bitMasks[i] = pow(2, i) - 1;
}

PacketFactory::~PacketFactory() {
	delete [] buffer;
}

char* PacketFactory::getBuffer() {
	return buffer;
}

void PacketFactory::putByte(char val) {
	buffer[pos++] = val;
}

void PacketFactory::putByteA(char val) {
	buffer[pos++] = val + 128;
}

void PacketFactory::putByteC(char val) {
	buffer[pos++] = -val;
}

void PacketFactory::putByteS(char val) {
	buffer[pos++] = 128 - val;
}

void PacketFactory::putBytes(int offset, int length, char* b) {
	for(int i = 0; i < length; ++i, ++pos)
		buffer[pos] = b[i + offset];
}

void PacketFactory::putBytesReverse(int offset, int length, char* b) {
	for(int i = (offset + length - 1); i >= offset; i--)
		putByte(b[i]);
}

void PacketFactory::putBytesReverseA(int offset, int length, char* b) {
	for(int i = (offset + length - 1); i >= offset; i--)
		putByteA(b[i]);
}

void PacketFactory::putShort(short val) {
	buffer[pos++] = val >> 8;
	buffer[pos++] = val;
}

void PacketFactory::putShortA(short val) {
	buffer[pos++] = val >> 8;
	buffer[pos++] = val + 128;
}

void PacketFactory::putShortLE(short val) {
	buffer[pos++] = val;
	buffer[pos++] = val >> 8;
}

void PacketFactory::putShortLEA(short val) {
	buffer[pos++] = val + 128;
	buffer[pos++] = val >> 8;
}

void PacketFactory::putSmart(short val) {
	if(val >= 128)
		putShort(val + 32768);
	else
		putByte(val);
}

void PacketFactory::putTryte(int val) {
	buffer[pos++] = val >> 16;
	buffer[pos++] = val >> 8;
	buffer[pos++] = val;
}

void PacketFactory::putInt(int val) {
	buffer[pos++] = val >> 24;
	buffer[pos++] = val >> 16;
	buffer[pos++] = val >> 8;
	buffer[pos++] = val;
}

void PacketFactory::putIntME1(int val) {
	buffer[pos++] = val >> 8;
	buffer[pos++] = val;
	buffer[pos++] = val >> 24;
	buffer[pos++] = val >> 16;
}

void PacketFactory::putIntME2(int val) {
	buffer[pos++] = val >> 16;
	buffer[pos++] = val >> 24;
	buffer[pos++] = val;
	buffer[pos++] = val >> 8;
}

void PacketFactory::putLong(long val) {
	buffer[pos++] = val >> 56;
	buffer[pos++] = val >> 48;
	buffer[pos++] = val >> 40;
	buffer[pos++] = val >> 32;
	buffer[pos++] = val >> 24;
	buffer[pos++] = val >> 16;
	buffer[pos++] = val >> 8;
	buffer[pos++] = val;
}
	
void PacketFactory::putRS2String(char* cstr) {
	for(int i = 0; cstr[i] != 0; ++i)
		buffer[pos++] = cstr[i];
	buffer[pos++] = 10;
}

void PacketFactory::initBitAccess() {
	bitpos = pos * 8;
}
		
void PacketFactory::writeBits(int num, int val) {
	int bytePos = bitpos >> 3;
	int bitOffset = 8 - (bitpos & 7);
	bitpos += num;

	for(; num > bitOffset; bitOffset = 8) {
		buffer[bytePos] &= ~ bitMasks[bitOffset];
		buffer[bytePos++] |= (val >> (num - bitOffset)) & bitMasks[bitOffset];
		num -= bitOffset;
	}
	if(num == bitOffset) {
		buffer[bytePos] &= ~bitMasks[bitOffset];
		buffer[bytePos] |= val & bitMasks[bitOffset];
	}
	else {
		buffer[bytePos] &= ~ (bitMasks[num] << (bitOffset - num));
		buffer[bytePos] |= (val & bitMasks[num]) << (bitOffset - num);
	}
}	
		
void PacketFactory::finishBitAccess() {
	pos = (bitpos + 7) / 8;
}	


