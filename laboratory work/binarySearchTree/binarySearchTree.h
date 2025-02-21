
#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\node.h"
#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTree.h"

class binarySearchTree 
{
public:
	binarySearchTree();


	void insert(int key) ;

	int getMin() const ;
	int getMax() const;

	

	node* insertRec(node* node, int key);
private:
	node* m_root;
};

