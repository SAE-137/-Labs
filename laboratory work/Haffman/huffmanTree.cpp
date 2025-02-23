#include"huffmanTree.h"


huffman::huffman()
{
	m_head = nullptr;
}

void huffman::insert(int frequency, const char* ch)
{
    
    node* newNode = new node;
    newNode->setFrequency(frequency);
    
    newNode->setNext(nullptr); 
    
    if (m_head == nullptr)
    {
        m_head = newNode;
        return;
    }

   
    if (frequency > m_head->getFrequency())
    {
        newNode->setNext(m_head);
        m_head = newNode;
        return;
    }

 
    node* current = m_head;
    while (current->getNext() != nullptr && current->getNext()->getFrequency() >= frequency)
    {
        current = current->getNext();
    }

    
    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

void huffman::build(std::string str)
{
	node* newNode = new node;

}

