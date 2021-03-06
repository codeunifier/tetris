#include "piece.h"
#include "draw.h"

int random(int min, int max)
{
	int num = (rand() % (max - min)) + min;
	return num;
}

/********************************************
* piece configuration list
*    code taken from http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/
*********************************************/
int pieceConfigList[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] =
{
	// Square
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// I
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 1 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 1, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	}
	,
	// L
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// L mirrored
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// N
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},



		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// N mirrored
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// T
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	}
};

// Displacement of the piece to the position where it is first drawn in the board when it is created
int pieceInitialDisplacement[7 /*kind */][4 /* rotation */][2 /* position */] =
{
	/* Square */
	{
		{ -3, 3 },
		{ -3, 3 },
		{ -3, 3 },
		{ -3, 3 }
	},
	/* I */
	{
		{ -3, 4 },
		{ -3, 2 },
		{ -3, 3 },
		{ -2, 2 }
	},
	/* L */
	{
		{ -2, 3 },
		{ -3, 3 },
		{ -2, 2 },
		{ -2, 3 }
	},
	/* L mirrored */
	{
		{ -2, 2 },
		{ -2, 3 },
		{ -2, 3 },
		{ -3, 3 }
	},
	/* N */
	{
		{ -2, 3 },
		{ -3, 3 },
		{ -2, 2 },
		{ -2, 1 }
	},
	/* N mirrored */
	{
		{ -2, 3 },
		{ -3, 3 },
		{ -2, 2 },
		{ -2, 3 }
	},
	/* T */
	{
		{ -2, 3 },
		{ -3, 3 },
		{ -2, 2 },
		{ -2, 3 }
	},
};

/*************************
* PIECE
*    constructor for piece class
**************************/
Piece::Piece(int boardWidth)
{
	kind = random(0, 6);
	rotation = random(0, 3);
	position.setX(boardWidth / 2 + getXInitialPosition());
	position.setY(getYInitialPosition());
	//std::cerr << "Piece created: " << position.getX() << ", " << position.getY() << std::endl;
}

/*********************************************************
* PIECE getBlockType
*    returns the block type (center or not) of the piece
**********************************************************/
int Piece::getBlockType(int xBlock, int yBlock)
{
	return pieceConfigList[kind][rotation][xBlock][yBlock];
}

/**********************************************************
* PIECE getXInitialPosition
*    horizontal displacement of piece upon initialization
***********************************************************/
int Piece::getXInitialPosition()
{
	return pieceInitialDisplacement[kind][rotation][0];
}

/**********************************************************
* PIECE getYInitialPosition
*    vertical displacement of piece upon initialization
***********************************************************/
int Piece::getYInitialPosition()
{
	return pieceInitialDisplacement[kind][rotation][1];
}

/*******************************************************************
* PIECE draw
*    draw the piece
*    topLeftPiecePixels - top left position of the piece in pixels
********************************************************************/
void Piece::draw(Point topLeftPiecePixels)
{	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (pieceConfigList[kind][rotation][i][j] != 0)
				drawRect(Point(topLeftPiecePixels.getX() + i * BLOCK_SIZE, topLeftPiecePixels.getY() + j * BLOCK_SIZE), BLOCK_SIZE);
		}
	}
}

bool Piece::canMoveLeft()
{
	int left = 100; //randomly large number
	for (int i = 0, x = position.getX(); i < 5; i++, x++)
		for (int j = 0; j < 5; j++)
			if (pieceConfigList[kind][rotation][i][j] != 0)
				if (x < left)
					left = x;	//find the x coordinate of the left-most block in the piece
	
	if (left > 0)
		return true;
	else
		return false;
}

bool Piece::canMoveRight(int boardWidth)
{
	int right = -1; //less than 0
	for (int i = 0, x = position.getX(); i < 5; i++, x++)
		for (int j = 0; j < 5; j++)
			if (pieceConfigList[kind][rotation][i][j] != 0)
				if (right < x)
					right = x;
	
	if (right < boardWidth - 1)
		return true;
	else
		return false;
}