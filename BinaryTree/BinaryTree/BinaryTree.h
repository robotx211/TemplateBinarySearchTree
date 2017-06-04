#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <vector>

template <class T> struct BinaryTreeNode
{
	T m_data;
	
	BinaryTreeNode* m_leftPath;
	BinaryTreeNode* m_rightPath;
};

/*
template <class T> struct BinarySearchTree
{
	BinaryTreeNode<T>* CreateNewNode(T _data);
	T Lookup(T _target, BinaryTreeNode<T> *_node);
	BinaryTreeNode<T>* Insert(T _data, BinaryTreeNode<T> *_node = NULL);
};
*/

template <typename T> BinaryTreeNode<T>* CreateNewNode(T _data);
template <typename T> bool LookupData(T _target, BinaryTreeNode<T> *_node);
template <typename T> BinaryTreeNode<T>* LookupNode(T _target, BinaryTreeNode<T> *_node);
template <typename T> BinaryTreeNode<T>* Insert(T _data, BinaryTreeNode<T> *_node = NULL);

//insert all data from a vector, calls insert for each element in vector
template <typename T> void InsertFromVector(std::vector<T> *_dataVector, BinaryTreeNode<T> *_node);

template <typename T> void PrintBST(BinaryTreeNode<T> *_node);
template <typename T> int GetNumberOfData(T _data, BinaryTreeNode<T> *_node);


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
bool LookupData(T _targetData, BinaryTreeNode<T> *_node)
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
BinaryTreeNode<T>* LookupNode(T _targetData, BinaryTreeNode<T> *_node)
{
	//if no node on that branch, return false (0)
	if (_node == nullptr)
	{
		return nullptr;
	}
	//if current node contains target data, return true (1)
	else if (_node->m_data == _targetData)
	{
		return BinaryTreeNode<T>*;
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

template <typename T> 
void InsertFromVector(std::vector<T> *_dataVector, BinaryTreeNode<T> *_node)
{
	for (int i = 0; i < _dataVector->size(); i++)
	{
		Insert(_dataVector->at(i), _node);
	}
}

template <typename T> 
void PrintBST(BinaryTreeNode<T> *_node)
{
	if (_node->m_leftPath != nullptr)
	{
		PrintBST(_node->m_leftPath);
	}

	std::cout << _node->m_data << " ";

	if (_node->m_rightPath != nullptr)
	{
		PrintBST(_node->m_rightPath);
	}

	std::cout << _node->m_data << " ";
}

template <typename T> int GetNumberOfData(T _data, BinaryTreeNode<T> *_node)
{
	int counter = 0;

	if (_node == nullptr)
	{
		return -1;
	}

	//check left path
	if (_node->m_leftPath != nullptr)
	{
		counter = counter + GetNumberOfData(_data, _node->m_leftPath);
	}

	//check right path
	if (_node->m_rightPath != nullptr)
	{
		counter = counter + GetNumberOfData(_data, _node->m_rightPath);
	}

	if (_node->m_data == _data)
	{
		counter++;
	}

	return counter;

}

#endif // !_BINARY_TREE_H_
