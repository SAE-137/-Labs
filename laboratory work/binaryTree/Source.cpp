#include <iostream>
#include<random>
#include<vector>



#include "searchTreeTester.h"
#include "binaryTreeTester.h"
#include "binarySearchTree.h"


int randomValue(int min = 0, int max = 1000)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	
		return dist(gen);
	
}

void vectorShow(std::vector<int> sortedKeys)
{
	for (int key : sortedKeys)
		std::cout << key << " ";
}

void space(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		std::cout << std::endl;
	}
}

#include <iostream>
#include "SearchTreeTester.h"

#include <iostream>
#include "SearchTreeTester.h"

int main() {
    // Создаем объект тестера с выводом в консоль и включенными всеми тестами
    SearchTreeTester tester(true, true);

    // Запускаем все тесты с максимальным размером дерева 10
    std::cout << "=== Running all tests ===" << std::endl;
    tester.test(10);

    // Дополнительные тесты (опционально)
    std::cout << "\n=== Running additional tests ===" << std::endl;

    // Тест на добавление и удаление
    binarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Tree after insertions:" << std::endl;
    tree.printByLevels();

    tree.deleteNode(3);
    std::cout << "\nTree after removing key 3:" << std::endl;
    tree.printByLevels();

    
    std::cout << "\nMin key: " << tree.getMin() << std::endl;
    std::cout << "Max key: " << tree.getMax() << std::endl;

    
    int searchKey = 6;
    if (tree.search(searchKey)) {
        std::cout << "Key " << searchKey << " found in the tree." << std::endl;
    }
    else {
        std::cout << "Key " << searchKey << " not found in the tree." << std::endl;
    }

  

    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}



