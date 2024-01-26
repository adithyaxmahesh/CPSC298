#include <iostream>

class Node {
public:
    Node(int iData) : m_iData(iData), mp_nodeNext(nullptr) { }
    ~Node() { }

public:
    int m_iData;
    Node* mp_nodeNext;

public:
    static void displayList(Node* p_nodeHead)
    {
        Node* p_node = p_nodeHead;
        while (p_node != nullptr) {
            std::cout << p_node->m_iData << std::endl;
            p_node = p_node->mp_nodeNext;
        }
        return;
    }
};

int main()
{
    Node* p_node1 = new Node(10);
    Node* p_node2 = new Node(20);
    Node* p_node3 = new Node(30);

    Node* p_nodeHead = p_node1;
    p_node1->mp_nodeNext = p_node2;
    p_node2->mp_nodeNext = p_node3;
    p_node3->mp_nodeNext = nullptr;

    Node::displayList(p_nodeHead);

    // Free up the allocated memory
    delete p_node1;
    delete p_node2;
    delete p_node3;

    return 0;
}
