// An integer binary search tree

struct TreeNode {
  struct TreeNode *leftPtr;  // pointer to left subtree
  int data;                  // node value
  struct TreeNode *rightPtr; // pointer to right subtree
};                           // end structure treeNode

typedef struct TreeNode *TreeNodePtr; // synonym for TreeNode*

typedef struct {
  int size;
  TreeNodePtr root;
} BST;

// prototypes

void insertNode(BST *, int);
/*
void insertNode_R(TreeNodePtr * t,int value){
  if(*t==NULL){
  *t = (TreeNodePtr)malloc(sizeof(struct TreeNode)); //mallocเมื่อมีที่ว่างแล้ว
   //t=new TreeNode;
         if(*t){
                (*t)->leftPtr=NULL;
                (*t)->rightPtr=NULL;
                (*t)->data=value;
   }
  }
  else{
     if((*t)->data>=value) //left
      inserNode_R(&(*t)->leftPtr,value);
     else
      inserNode_R(&(*t)->rightPtr,value);//right

   }
}
*/
void insertNode(BST *b, int value) {
  TreeNodePtr t = b->root, new_node;
  int inserted = 0;
  new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
  if (new_node) { //เชคว่าเมมเตมไหม
    new_node->leftPtr = NULL;
    new_node->rightPtr = NULL;
    new_node->data = value;
    /*First Node*/
    if (!b->root)
      b->root = new_node; // NULL
    else {
      while (!inserted) {
        if (t->data >= value) {
          /* move/insert to the left*/
          if (t->leftPtr == NULL) {
            t->leftPtr = new_node;
            inserted = 1;
          } else
            t = t->leftPtr;

        } else {
          /* move/ insert to the right*/
          if (t->rightPtr == NULL) {
            t->rightPtr = new_node;
            inserted = 1;
          } else
            t = t->rightPtr;
        }

      } // end while
    }   // end else;
    b->size++;
  }

} // end function

void inOrder(TreeNodePtr treePtr) { // recursion เรียกตัวเอง
  // if tree is not empty, then traverse
  if (treePtr != NULL) {

    inOrder(treePtr->leftPtr); // Recursion to the left ไปให้สุดซ้าย

    printf("%5d", treePtr->data); // print the value

    inOrder(treePtr->rightPtr); // Recursion to the right
  }                             // end if
} // end

void preOrder(TreeNodePtr treePtr) { // recursion เรียกตัวเอง
  // if tree is not empty, then traverse
  if (treePtr != NULL) {

    printf("%5d", treePtr->data); // print the value
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr); // Recursion to the right
  }                              // end if
} // end

void postOrder(TreeNodePtr treePtr) { // recursion เรียกตัวเอง
  // if tree is not empty, then traverse
  if (treePtr != NULL) {

    postOrder(treePtr->leftPtr); // Recursion to the left ไปให้สุดซ้าย

    // print the value

    postOrder(treePtr->rightPtr); // Recursion to the right
    printf("%5d", treePtr->data);
  } // end if
} // end

void printTree(TreeNodePtr treePtr, int x){
  if (treePtr != NULL) {
    int i;
    printTree(treePtr->rightPtr,x+1); // Recursion to the left ไปให้สุดซ้าย
    
    for(i=0; i<x; i++){
       printf("    ");
    }
     printf("%5d\n", treePtr->data); // print the value
     
    printTree(treePtr->leftPtr,x+1); // Recursion to the right
    
  } 
}