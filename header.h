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
typedef struct StackNode{
	char cItem;					//information to store into the array
	struct StackNode *pNext;	//Pointer for next item in array
} StackNode;



/***** constants ******/
//return codes
#define ERROR_PROCESSING  3			//required for exitError function to work

//boolean
#define TRUE 1
#define FALSE 0



/****prototypes*****/


//Stack w/ LL prototypes
void display(StackNode*);
void push(StackNode**,char);
StackNode* newNode(char);
int isEmpty(StackNode*);
char pop(StackNode**);
int stackSize(StackNode*);


//other prototypes
void exitError(char *pszMessage, char *pszDiagnosticInfo);
