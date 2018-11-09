/************************************************************
header.h - Linked List As Pointers
Purpose:
	Defines typedef for
	    Node
		includes information to store as well as
		location of next item in array


	Defines constants for
		boolean values

	Prototypes
		all required for Linked List
Notes:

************************************************************/



/***** typedefs *****/
//Node
typedef struct NodeT{
	int iInfo;					//information to store into the array
	struct NodeT *pLeft;				//Pointer for next item in array
	struct NodeT *pRight;
} NodeT;



/***** constants ******/
//return codes
#define ERROR_PROCESSING  3			//required for exitError function to work




/****prototypes*****/

//linked list prototypes
NodeT *searchT(NodeT *pRoot, int iMatch);
void printT(NodeT *pRoot, int iIndent);
NodeT *insertT(NodeT *p, int iNewInfo);
NodeT *allocateNodeT(int iNewInfo);
int sumT(NodeT *pHead);
int countT(NodeT *pHead);


//other prototypes
void exitError(char *pszMessage, char *pszDiagnosticInfo);
