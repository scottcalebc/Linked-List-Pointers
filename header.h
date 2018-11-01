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
typedef struct Node{
	int iInfo;					//information to store into the array
	struct Node *pNext;	//Pointer for next item in array
} Node;



/***** constants ******/
//return codes
#define ERROR_PROCESSING  3			//required for exitError function to work




/****prototypes*****/

//linked list prototypes
void initializeFreeLL(Node nodeM[], int iNumElem, int *piFree);
Node *searchLL(Node *pHead, int iMatch, Node **ppPrecedes);
void printLL(Node *pHead);
Node *insertLL(Node **pHead, int iNewInfo);
Node *allocateNode(int iNewInfo);
void removeLL(Node **pHead, int iMatch);
void freeNode(Node *p);
int sumLL(Node *pHead);
int countNodes(Node *pHead);


//other prototypes
void exitError(char *pszMessage, char *pszDiagnosticInfo);
