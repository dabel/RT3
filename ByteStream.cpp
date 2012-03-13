/* 
 * File: ByteStream.cpp
 * Description: RS2 Codec impl
 * Author: t4
 * 
 */
 
#include "ByteStream.h"

ByteStream::ByteStream(char* b) : pos(0), buffer(b) {

}

ByteStream::~ByteStream() {
	delete [] buffer;
}

char* ByteStream::getBuffer() {
	return buffer;
}

char ByteStream::getByte() {
	return buffer[pos++];
}

unsigned char ByteStream::getByteUnsigned() {
	return (unsigned) buffer[pos++];
}

char ByteStream::getByteA() {
	return buffer[pos++] - 128;
}

char ByteStream::getByteC() {
	return -buffer[pos++];
}

char ByteStream::getByteS() {
	return 128 - buffer[pos++];
}

void ByteStream::getBytes(int offset, int length, char* b) {
	for(int i = 0; i < length; ++i, ++pos)
		b[i] = buffer[pos + offset];
}

void ByteStream::getBytesReverse(int offset, int length, char* b) {
	for(int i = (offset + length - 1); i >= offset; i--)
		b[i] = getByte();
}

void ByteStream::getBytesReverseA(int offset, int length, char* b) {
	for(int i = (offset + length - 1); i >= offset; i--)
		b[i] = getByteA();
}

short ByteStream::getShort() {
	pos += 2;
	return ((buffer[pos - 2] & 0xff) << 8) + (buffer[pos - 1] & 0xff);
}

short ByteStream::getShortA() {
	int i = (getByteUnsigned() << 8) | ((getByte() - 128) & 0xff);
	if(i > 32767)
		i -= 0x10000;
	return i;
}

short ByteStream::getShortLE() {
	int i = (getByte() & 0xff) | ((getByte() & 0xff) << 8);
	if(i > 32767)
		i -= 0x10000;
	return i;
}

short ByteStream::getShortLEA() {
	int i = ((getByte() - 128) & 0xff) | ((getByte() & 0xff) << 8);
	if(i > 32767)
		i -= 0x10000;
	return i;
}

short ByteStream::getSmart() {
	int peek = buffer[pos];
	if(peek < 128)
		return (getByte() & 0xff);
	else
		return (getShort() & 0xffff) - 32768;
}


int ByteStream::getTryte() {
	pos += 3;
	return ((buffer[pos - 3] & 0xff) << 16) + 
			((buffer[pos - 2] & 0xff) << 8) + 
			(buffer[pos - 1] & 0xff);
}

int ByteStream::getInt() {
	pos += 4;
	return ((buffer[pos - 4] & 0xff) << 24) + 
			((buffer[pos - 3] & 0xff) << 16) + 
			((buffer[pos - 2] & 0xff) << 8) + 
			(buffer[pos - 1] & 0xff);
}

int ByteStream::getIntME1() {
	char b1 = getByte();
	char b2 = getByte();
	char b3 = getByte();
	char b4 = getByte();
	return ((b3 << 24) & 0xff) | 
			((b4 << 16) & 0xff) | 
			((b1 << 8) & 0xff) | 
			(b2 & 0xff);
}

int ByteStream::getIntME2() {
	char b1 = getByte();
	char b2 = getByte();
	char b3 = getByte();
	char b4 = getByte();
	return ((b2 << 24) & 0xff) | 
			((b1 << 16) & 0xff) | 
			((b4 << 8) & 0xff) | 
			(b3 & 0xff);
}

long ByteStream::getLong() {
	long pt0 = (long) getInt() & 0xffffffffL;
	long pt1 = (long) getInt() & 0xffffffffL;
	return (pt0 << 32) + pt1;
}
	
char* ByteStream::getRS2String() {
	int start = pos;
	while(buffer[pos++] != 10);
	int len = pos - start;
	char* cstr = new char[len];
	for(int i = 0; i < len; ++i)
		cstr[i] = buffer[start + i];
	return cstr;
}


