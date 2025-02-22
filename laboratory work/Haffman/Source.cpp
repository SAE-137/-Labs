

#include <fstream>

#include "set.h"

struct Node
{
	Set set;

	int frequency;

	Node* l;
	Node* r;

	Node* next;
};

class HTree
{
public:
	~HTree();

	void Insert(Node* node);

	void Init(int* tab);

	void Transform();

	void Encode(string& str, ofstream& out);
	void Decode(ifstream& in, string& str, int length);

	//private:
	Node* front_ = nullptr;
};

HTree::~HTree()
{
	Node* tmp;

	for (Node* p = front_; p != nullptr; p = tmp)
	{
		tmp = p->next;

		delete p;
	}
}

void HTree::Insert(Node* node)
{
	Node** p = &front_;

	while (*p != nullptr && (*p)->frequency < node->frequency)
	{
		p = &(*p)->next;
	}

	node->next = *p;

	*p = node;
}

void HTree::Init(int* tab)
{
	for (int i = 255; i >= 0; i--)
	{
		if (tab[i] != 0)
		{
			Insert(new Node{ Set() + i, tab[i] });
		}
	}
}

void HTree::Transform()
{
	Node* l, * r;

	while (front_->next != nullptr)
	{
		l = front_;
		r = l->next;

		front_ = r->next;

		l->next = nullptr;
		r->next = nullptr;

		Insert(new Node{ l->set | r->set, l->frequency + r->frequency, l, r });
	}
}

void HTree::Encode(string& str, ofstream& out)
{
	uint8_t byte = 0;
	uint8_t mask = 0b10000000;

	for (uint8_t ch : str)
	{
		Node* p = front_;

		while (p->r != nullptr)
		{
			if (mask == 0)
			{
				out << byte;

				byte = 0;
				mask = 0b10000000;
			}

			if (p->r->set + ch == p->r->set)
			{
				byte |= mask;

				p = p->r;
			}
			else
			{
				p = p->l;
			}

			mask >>= 1;
		}
	}

	out << byte;
}

void HTree::Decode(ifstream& in, string& str, int length)
{
	uint8_t byte = 0;
	uint8_t mask = 0;

	for (int i = 0; i < length; i++)
	{
		Node* p = front_;

		while (p->r != nullptr)
		{
			if (mask == 0)
			{
				byte = in.get();
				mask = 0b10000000;
			}

			if (byte & mask)
			{
				p = p->r;
			}
			else
			{
				p = p->l;
			}

			mask >>= 1;
		}

		str += (char)p->set.Min();
	}
}

void Init()
{
	string str = "карл у клары украл кораллы, а клара у карла украла кларнет";
	string res;

	//
	int tab[256]{ 0 };

	for (uint8_t ch : str)
	{
		tab[ch]++;
	}

	//
	HTree tree;

	tree.Init(tab);

	tree.Transform();

	//
	ofstream out("output", ios::binary);

	tree.Encode(str, out);

	out.close();

	//
	ifstream in("output", ios::binary);

	tree.Decode(in, res, str.length());

	in.close();

	//
	cout << str << endl;
	cout << res << endl;
}

int main()
{
	Init();

	return 0;
}