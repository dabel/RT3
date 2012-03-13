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

