#ifndef AVL_H
#define AVL_H

#include "node.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

template<typename T>
class AVL
{
    public:
        AVL() : root(nullptr) {}
        ~AVL();

        //Mutators
        bool insert(const T&);
        bool remove(const T&);

        // Accessors
        Node<T>* getRoot() const;
        Node<T>* find(const T&, Node<T>*) const;
        Node<T>* previous(Node<T>*) const;
        Node<T>* next(Node<T>*) const;
        Node<T>* min(Node<T>*) const;
        Node<T>* max(Node<T>*) const;

        //Print Functions
        std::string printData() const;
        std::string printHeights() const;

        //Static Functions
        static int getHeight(const Node<T>*);

    private:
        //Helpers
        bool isBalanced(Node<T>*) const;
        void rebalanceNode(Node<T>*);
        void rotateLeft(Node<T>*);
        void rotateRight(Node<T>*);
        void transplant(Node<T>*, Node<T>*);
        void deleteTree(Node<T>*);

        Node<T>* root;
};

template<typename T>
AVL<T>::~AVL<T>()
{
    deleteTree(root);
}

template<typename T>
bool AVL<T>::insert(const T& data)
{
    Node<T>* tempNode;
    Node<T>* insertNode = new Node<T>(data);

    if(((tempNode = find(data, root)) != nullptr) && (*tempNode == *insertNode))
    {
        std::cout << "Value already inserted\n";
        return false;
    }
    else if(tempNode == nullptr)
    {
        root = new Node<T>(data);
    }
    else if(*insertNode < *tempNode)
    {
        tempNode->setLeft(insertNode);
        insertNode->setParent(tempNode);
    }
    else
    {
        tempNode->setRight(insertNode);
        insertNode->setParent(tempNode);
    }

    while(tempNode != nullptr)
    {
        rebalanceNode(tempNode);
        tempNode = tempNode->getParent();
    }

    return true;
}

template<typename T>
bool AVL<T>::remove(const T& data)
{
    Node<T>* findNode = find(data, root);

    if(findNode == nullptr || findNode->getData() != data)
    {
        std::cout << "Value to remove not found\n";
        return false;
    }

    if(findNode->getLeft() == nullptr)
    {
        transplant(findNode, findNode->getRight());
    }
    else if(findNode->getRight() == nullptr)
    {
        transplant(findNode, findNode->getLeft());
    }
    else
    {
        Node<T>* minNode = min(findNode->getRight());

        if(minNode != findNode->getRight())
        {
            transplant(minNode, minNode->getRight());
            minNode->setRight(findNode->getRight());
            minNode->getRight()->setParent(minNode);
        }

        transplant(findNode, minNode);
        minNode->setLeft(findNode->getLeft());
        minNode->getLeft()->setParent(minNode);
    }

    return true;
}

template<typename T>
Node<T>* AVL<T>::getRoot() const
{
    return root;
}

template<typename T>
Node<T>* AVL<T>::find(const T& value, Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    Node<T>* findNode = new Node<T>(value);

    while(*findNode != *node)
    {
        if(*findNode < *node)
        {
            if(node->getLeft() != nullptr)
            {
                node = node->getLeft();
            }
            else
            {
                break;
            }

        }
        else
        {
            if(node->getRight() != nullptr)
            {
                node = node->getRight();
            }
            else
            {
                break;
            }
        }
    }

    return node;
}

template<typename T>
Node<T>* AVL<T>::previous(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(node->getLeft() != nullptr)
    {
        return max(node->getLeft());
    }

    Node<T>* tempParent = node->getParent();

    while(tempParent != nullptr && node == tempParent->getLeft())
    {
        node = tempParent;
        tempParent = node->getParent();
    }

    return tempParent;
}

template<typename T>
Node<T>* AVL<T>::next(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(node->getRight() != nullptr)
    {
        return min(node->getRight());
    }

    Node<T>* tempParent = node->getParent();

    while(tempParent != nullptr && node == tempParent->getRight())
    {
        node = tempParent;
        tempParent = node->getParent();
    }

    return tempParent;
}

template<typename T>
Node<T>* AVL<T>::min(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    while(node->getLeft())
    {
        node = node->getLeft();
    }

    return node;
}

template<typename T>
Node<T>* AVL<T>::max(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    while(node->getRight())
    {
        node = node->getRight();
    }

    return node;
}

template<typename T>
std::string AVL<T>::printData() const
{
    if (root == nullptr) {
        return "<empty tree>";
    }

    std::function<std::tuple<std::vector<std::string>, int, int>(const Node<T>*)> recurse =
        [this, &recurse](const Node<T>* node) -> std::tuple<std::vector<std::string>, int, int> {
        if (node == nullptr) {
            return {{}, 0, 0};
        }

        std::string label = std::to_string(node->getData());
        auto [left_lines, left_pos, left_width] = recurse(node->getLeft());
        auto [right_lines, right_pos, right_width] = recurse(node->getRight());

        int middle = std::max(right_pos + left_width - left_pos + 1, static_cast<int>(label.length()));
        middle = std::max(middle, 2);
        int pos = left_pos + middle / 2;
        int width = left_pos + middle + right_width - right_pos;

        while (left_lines.size() < right_lines.size()) {
            left_lines.push_back(std::string(left_width, ' '));
        }

        while (right_lines.size() < left_lines.size()) {
            right_lines.push_back(std::string(right_width, ' '));
        }

        if ((middle - label.length()) % 2 == 1 && node->getParent() != nullptr &&
            node == node->getParent()->getLeft() && label.length() < middle) {
            label += ".";
        }

        int padding_left = (middle - label.length()) / 2;
        int padding_right = middle - label.length() - padding_left;

        label = std::string(padding_left, '.') + label + std::string(padding_right, '.');

        if (label[0] == '.') label = ' ' + label.substr(1);
        if (label[label.length() - 1] == '.') label = label.substr(0, label.length() - 1) + ' ';

        std::vector<std::string> lines{
            std::string(left_pos, ' ') + label + std::string(right_width - right_pos, ' '),
            std::string(left_pos, ' ') + '/' + std::string(middle - 2, ' ') + '\\' + std::string(right_width - right_pos, ' ')
        };

        for (size_t i = 0; i < left_lines.size(); ++i) {
            std::string left_line = left_lines[i];
            std::string right_line = right_lines[i];
            lines.push_back(left_line + std::string(width - left_width - right_width, ' ') + right_line);
        }

        return {lines, pos, width};
    };

    auto [result, _, __] = recurse(root);
    return std::accumulate(result.begin(), result.end(), std::string{}, [](const std::string& a, const std::string& b) { return a + '\n' + b; });
}

template<typename T>
std::string AVL<T>::printHeights() const
{
    if (root == nullptr) {
        return "<empty tree>";
    }

    std::function<std::tuple<std::vector<std::string>, int, int>(const Node<T>*)> recurse =
        [this, &recurse](const Node<T>* node) -> std::tuple<std::vector<std::string>, int, int> {
        if (node == nullptr) {
            return {{}, 0, 0};
        }

        std::string label = std::to_string(AVL<T>::getHeight(node));
        auto [left_lines, left_pos, left_width] = recurse(node->getLeft());
        auto [right_lines, right_pos, right_width] = recurse(node->getRight());

        int middle = std::max(right_pos + left_width - left_pos + 1, static_cast<int>(label.length()));
        middle = std::max(middle, 2);
        int pos = left_pos + middle / 2;
        int width = left_pos + middle + right_width - right_pos;

        while (left_lines.size() < right_lines.size()) {
            left_lines.push_back(std::string(left_width, ' '));
        }

        while (right_lines.size() < left_lines.size()) {
            right_lines.push_back(std::string(right_width, ' '));
        }

        if ((middle - label.length()) % 2 == 1 && node->getParent() != nullptr &&
            node == node->getParent()->getLeft() && label.length() < middle) {
            label += ".";
        }

        int padding_left = (middle - label.length()) / 2;
        int padding_right = middle - label.length() - padding_left;

        label = std::string(padding_left, '.') + label + std::string(padding_right, '.');

        if (label[0] == '.') label = ' ' + label.substr(1);
        if (label[label.length() - 1] == '.') label = label.substr(0, label.length() - 1) + ' ';

        std::vector<std::string> lines{
            std::string(left_pos, ' ') + label + std::string(right_width - right_pos, ' '),
            std::string(left_pos, ' ') + '/' + std::string(middle - 2, ' ') + '\\' + std::string(right_width - right_pos, ' ')
        };

        for (size_t i = 0; i < left_lines.size(); ++i) {
            std::string left_line = left_lines[i];
            std::string right_line = right_lines[i];
            lines.push_back(left_line + std::string(width - left_width - right_width, ' ') + right_line);
        }

        return {lines, pos, width};
    };

    auto [result, _, __] = recurse(root);
    return std::accumulate(result.begin(), result.end(), std::string{}, [](const std::string& a, const std::string& b) { return a + '\n' + b; });
}

template<typename T>
int AVL<T>::getHeight(const Node<T>* node)
{
    if(node == nullptr || (node->getLeft() == nullptr && node->getRight() == nullptr))
    {
        return 0;
    }

    return 1 + std::max(AVL<T>::getHeight(node->getLeft()), AVL<T>::getHeight(node->getRight()));
}

template<typename T>
bool AVL<T>::isBalanced(Node<T>* node) const
{
    return (std::abs(AVL<T>::getHeight(node->getLeft()) - AVL<T>::getHeight(node->getRight()))) <= 1;
}

template<typename T>
void AVL<T>::rebalanceNode(Node<T>* node)
{
    if(isBalanced(node))
    {
        return;
    }

    if(AVL<T>::getHeight(node->getLeft()) > AVL<T>::getHeight(node->getRight()))
    {
        if(AVL<T>::getHeight(node->getLeft()->getLeft()) > AVL<T>::getHeight(node->getLeft()->getRight()))
        {
            rotateRight(node);
        }
        else
        {
            rotateLeft(node->getLeft());
            rotateRight(node);
        }
    }
    else
    {
        if(AVL<T>::getHeight(node->getRight()->getRight()) > AVL<T>::getHeight(node->getRight()->getLeft()))
        {
            rotateLeft(node);
        }
        else
        {
            rotateRight(node->getRight());
            rotateLeft(node);
        }
    }
}

template<typename T>
void AVL<T>::rotateLeft(Node<T>* node)
{
    Node<T>* temp = node->getRight();
    Node<T>* tempParent;

    temp->setParent(node->getParent());
    tempParent = temp->getParent();

    if(tempParent == nullptr)
    {
        root = temp;
    }
    else
    {
        if(tempParent->getLeft() == node)
        {
            tempParent->setLeft(temp);
        }
        else if(tempParent->getRight() == node)
        {
            tempParent->setRight(temp);
        }
    }

    node->setRight(temp->getLeft());

    if(node->getRight() != nullptr)
    {
        node->getRight()->setParent(node);
    }

    temp->setLeft(node);

    node->setParent(temp);
}

template<typename T>
void AVL<T>::rotateRight(Node<T>* node)
{
    Node<T>* temp = node->getLeft();
    Node<T>* tempParent;

    temp->setParent(node->getParent());
    tempParent = temp->getParent();

    if(tempParent == nullptr)
    {
        root = temp;
    }
    else
    {
        if(tempParent->getRight() == node)
        {
            tempParent->setRight(temp);
        }
        else if(tempParent->getLeft() == node)
        {
            tempParent->setLeft(temp);
        }
    }

    node->setLeft(temp->getRight());

    if(node->getLeft() != nullptr)
    {
        node->getLeft()->setParent(node);
    }

    temp->setRight(node);

    node->setParent(temp);
}

template<typename T>
void AVL<T>::transplant(Node<T>* n1, Node<T>* n2)
{
    if(n1 == nullptr)
    {
        return;
    }

    Node<T>* tempParent = n1->getParent();

    if(tempParent == nullptr)
    {
        root = n2;
    }
    else if(tempParent->getLeft() == n1)
    {
        tempParent->setLeft(n2);
    }
    else
    {
        tempParent->setRight(n2);
    }

    if(n2 != nullptr)
    {
        n2->setParent(tempParent);
    }
}

template<typename T>
void AVL<T>::deleteTree(Node<T>* node)
{
    if(node == nullptr)
    {
        return;
    }

    deleteTree(node->getLeft());
    deleteTree(node->getRight());

    delete node;
}

#endif // AVL_H
