#include <iostream>

//#include "BinaryTree.h"

/*
template <typename T>
BinaryTreeNode<T>* CreateNewNode(T _data)
{
	BinaryTreeNode<T> *newNode = new(BinaryTreeNode<T>);

	newNode->m_data = _data;
	newNode->m_leftPath = nullptr;
	newNode->m_rightPath = nullptr;

	return newNode;
}

template <typename T>
T Lookup(T _targetData, BinaryTreeNode<T> *_node)
{
	//if no node on that branch, return false (0)
	if (_node == nullptr)
	{
		return false;
	}
	//if current node contains target data, return true (1)
	else if (_node->m_data == _targetData)
	{
		return true;
	}
	else
	{
		if (_node->m_data <= _targetData)
		{
			return Lookup(_node->m_leftPath, _targetData);
		}
		else
		{
			return Lookup(_node->m_rightPath, _targetData);
		}
	}
}

template <typename T>
BinaryTreeNode<T>* Insert(T _data, BinaryTreeNode<T> *_node)
{
	//if there is no node, insert a new node with entered data
	if (_node == NULL)
	{
		return (CreateNewNode(_data));
	}
	//if there is node, recur down tree (left for smaller/equal data, right for larger data
	else
	{
		if (_data <= _node->m_data)
		{
			_node->m_leftPath = Insert(_data, _node->m_leftPath);
		}
		else
		{
			_node->m_rightPath = Insert(_data, _node->m_rightPath);
		}

		return (_node);
	}
}
*/