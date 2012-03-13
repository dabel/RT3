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

