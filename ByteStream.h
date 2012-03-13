/*
	Copyright (C) 2012  rt3cpp Development Team

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

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

