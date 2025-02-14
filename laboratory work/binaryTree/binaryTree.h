#pragma once
#include "node.h"

class binaryTree
{
public:
	binaryTree();
	~binaryTree();

	int getAmountOfNodes(node* newNode);
	int getNodeLvl(int key);
	int getDepth(node* newNode);
	int findNodeLevel(node* root, int key, int level);
	int findNodeLevel(int key);
	int getMin();
	int getMax();

	void setRoot(node* newRoot);
	void show(node* root, int space = 0, int indentv = 4);
	void printLeafs(node* newNode);
	void deleteTree();
	void deleteSubTree(node* newNode);
	void deleteNode(int key);
	void insert(int key);


	node* search(node* root, int key);
	node* insertRec(node* newNode, int value);
	node* getRoot();

	node* copy(node* currentNode);
	binaryTree* copy(binaryTree* newTree);
	bool isEmpty();

	

private:

	node* m_root ;
};


/*- конструкторы (по умолчанию, копирования);
- деструктор;

- очистка дерева (удаление всех узлов);
- удаление поддеревьев узла;

- копирование поддерева узла (возвращает новый объект класса);


- получение минимального/максимального ключа дерева;
- добавление узла в дерево (методом случайного выбора поддерева);
- удаление узла из дерева по ключу (возвращает true, если узел был удалён);

- проверка дерева на сбалансированность (возвращает true, если дерево является сбалансированным: высоты правого и левого поддеревьев отличаются не более, чем на единицу, и сами поддеревья также являются сбалансированными);

- получение вектора (std::vector<int>), содержащего все ключи дерева по возрастанию (обход вершин производить любым способом);

- вывод в консоль дерева по уровням (на форму (в этом случае данный метод принадлежит классу GUI, а не дерева) или в консоль при помощи итератора);

- оператор присваивания.*/