#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include"set.h"

struct Node {
    Set set;
    int frequency;
    Node* l;
    Node* r;
    Node* next;
};

class HTree {
public:
    ~HTree();

    void Insert(Node* node);
    void Init(int* tab);
    void Transform();

    void Encode(const std::string& inputFile, const std::string& outputFile);
    void Decode(const std::string& inputFile, const std::string& outputFile);

private:
    Node* front_ = nullptr;

    std::string ReadFromFile(const std::string& filename);
    void WriteToFile(const std::string& filename, const std::string& data);
};

HTree::~HTree() {
    Node* tmp;
    for (Node* p = front_; p != nullptr; p = tmp) {
        tmp = p->next;
        delete p;
    }
}

void HTree::Insert(Node* node) {
    Node** p = &front_;
    while (*p != nullptr && (*p)->frequency < node->frequency) {
        p = &(*p)->next;
    }
    node->next = *p;
    *p = node;
}

void HTree::Init(int* tab) {
    for (int i = 255; i >= 0; i--) {
        if (tab[i] != 0) {
            Insert(new Node{ Set() + i, tab[i], nullptr, nullptr, nullptr });
        }
    }
}

void HTree::Transform() {
    Node* l, * r;
    while (front_->next != nullptr) {
        l = front_;
        r = l->next;
        front_ = r->next;
        l->next = nullptr;
        r->next = nullptr;
        Insert(new Node{ l->set | r->set, l->frequency + r->frequency, l, r, nullptr });
    }
}

void HTree::Encode(const std::string& inputFile, const std::string& outputFile) {
    std::string str = ReadFromFile(inputFile);

    std::ofstream out(outputFile, std::ios::binary);
    if (!out) {
        throw std::runtime_error("Не удалось открыть файл для записи: " + outputFile);
    }

    uint8_t byte = 0;
    uint8_t mask = 0b10000000;

    for (uint8_t ch : str) {
        Node* p = front_;
        while (p->r != nullptr) {
            if (mask == 0) {
                out << byte;
                byte = 0;
                mask = 0b10000000;
            }

            if (p->r->set + ch == p->r->set) {
                byte |= mask;
                p = p->r;
            }
            else {
                p = p->l;
            }

            mask >>= 1;
        }
    }

    if (mask != 0b10000000) {
        out << byte;
    }

    out.close();
}

void HTree::Decode(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    if (!in) {
        throw std::runtime_error("Не удалось открыть файл для чтения: " + inputFile);
    }

    std::string str;
    uint8_t byte = 0;
    uint8_t mask = 0;

    in.seekg(0, std::ios::end);
    int length = in.tellg();
    in.seekg(0, std::ios::beg);

    for (int i = 0; i < length; i++) {
        Node* p = front_;
        while (p->r != nullptr) {
            if (mask == 0) {
                byte = in.get();
                mask = 0b10000000;
            }

            if (byte & mask) {
                p = p->r;
            }
            else {
                p = p->l;
            }

            mask >>= 1;
        }

        str += (char)p->set.Min();
    }

    in.close();
    WriteToFile(outputFile, str);
}

std::string HTree::ReadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Не удалось открыть файл для чтения: " + filename);
    }

    std::string str;
    std::getline(in, str);
    in.close();

    return str;
}

void HTree::WriteToFile(const std::string& filename, const std::string& data) {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Не удалось открыть файл для записи: " + filename);
    }

    out << data;
    out.close();
}