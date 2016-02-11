/*
 * bits.h
 *
 *  Created on: Nov 28, 2015
 *      Author: acs
 */

#ifndef BITS_H_
#define BITS_H_

namespace bits {
typedef unsigned char TypeUC;

/*
 * What Minimum memory LedBoard
 * How: Use 2D unsigned char to maintain state.
 */
class LedBoard {
	TypeUC** data_;
	TypeUC dimX_, dimY_;
public:
	LedBoard(TypeUC x, TypeUC y);
	~LedBoard();
	void SetBit(TypeUC x, TypeUC y);
	void UnsetBit(TypeUC x, TypeUC y);
	void Reset();
	bool ReadBit(TypeUC x, TypeUC y);
	void PrintScreen();
	void DrawLine(TypeUC x1, TypeUC y1, TypeUC x2, TypeUC y2);
	void DrawRect(TypeUC x1, TypeUC y1, TypeUC x2, TypeUC y2);
};

void FixBits(unsigned char *dstBits, unsigned startBit, unsigned lenBit,
		unsigned char bits);
void FitSixBits(unsigned char *buff, unsigned index, unsigned char bits);

}
#endif /* BITS_H_ */
