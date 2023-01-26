//Arthur Cardani Saraiva	32011334
//Gabriel Woo Hyun Kim	32009968
//Lucas Ellery Viana	42005541
//Thiago Henrique Quadrado Estacio	42012740

#include "NodeBST.h"
#include "NodeBST.cpp"
#include "BST.h"
#include "Utils.h"
#include <sstream>

BST::BST()
	: m_Root(nullptr)
{
}

BST::~BST()
{
	Clear();
}

NodeBST* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void BST::Destroy(NodeBST* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::string BST::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

std::string BST::TraverseInOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetSalario() << '(' << node->GetNome() << ") ";
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	return "";
}

std::string BST::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string BST::TraversePreOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetSalario() << '(' << node->GetNome() << ") ";
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	return "";
}

std::string BST::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string BST::TraversePostOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetSalario() << '(' << node->GetNome() << ") ";
		return oss.str();
	}

	return "";
}

NodeBST* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeBST* BST::FindMinInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeBST* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeBST* BST::FindMaxInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeBST* BST::Predecessor(float salario) const
{
	NodeBST* node = SearchInternal(m_Root, salario);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeBST* BST::PredecessorInternal(NodeBST* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::Successor(float salario) const
{
	NodeBST* node = SearchInternal(m_Root, salario);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeBST* BST::SuccessorInternal(NodeBST* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::SearchIterative(float salario) const
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetSalario() != salario)
	{
		if (current->GetSalario() > salario)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

NodeBST* BST::Search(float salario) const
{
	return SearchInternal(m_Root, salario);
}

NodeBST* BST::SearchInternal(NodeBST* node, float &salario) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetSalario() == salario)
		return node;
	else if (node->GetSalario() > salario)
		return SearchInternal(node->GetLeft(), salario);
	else
		return SearchInternal(node->GetRight(), salario);
}

NodeBST* BST::InsertIterative(float salario, const std::string& nome, const std::string& cargob, const std::string& cargoc, const std::string& unidade)
{
	NodeBST* newNode = new NodeBST(salario, nome, cargob, cargoc, unidade);
	if (IsEmpty())
	{
		m_Root = newNode;
	}
	else
	{
		NodeBST* current = m_Root;
		NodeBST* currentParent = nullptr;
		while (current != nullptr)
		{
			currentParent = current;

			if (current->GetSalario() == salario)
			{
				delete newNode;
				return nullptr;
			}

			if (current->GetSalario() > salario)
				current = current->GetLeft();
			else
				current = current->GetRight();
		}

		if (currentParent != nullptr)
		{
			if (currentParent->GetSalario() > salario)
				currentParent->SetLeft(newNode);
			else
				currentParent->SetRight(newNode);
		}
	}

	return newNode;
}

NodeBST* BST::Insert(float salario, const std::string& nome, const std::string& cargob, const std::string& cargoc, const std::string& unidade)
{
	if (IsEmpty())
	{
		m_Root = new NodeBST(salario, nome, cargob, cargoc, unidade);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, salario, nome, cargob, cargoc, unidade);
}

NodeBST* BST::InsertInternal(NodeBST* node, NodeBST* parent, float salario, const std::string& nome, const std::string& cargob, const std::string& cargoc, const std::string& unidade)
{
	if (node == nullptr)
		node = new NodeBST(salario, nome, cargob, cargoc, unidade,  parent);
	else if (node->GetSalario() == salario)
		return nullptr;
	else if (node->GetSalario() > salario)
		node->SetLeft(InsertInternal(node->GetLeft(), node, salario, nome, cargob, cargoc, unidade));
	else if (node->GetSalario() < salario)
		node->SetRight(InsertInternal(node->GetRight(), node, salario, nome, cargob, cargoc, unidade));

	return node;
}

bool BST::RemoveIterative(float salario)
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetSalario() != salario)
	{
		if (current->GetSalario() > salario)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	if (current == nullptr)
		return false;

	RemoveNode(current);
	return true;
}

void BST::Remove(float salario)
{
	RemoveInternal(m_Root, salario);
}

NodeBST* BST::RemoveInternal(NodeBST* node, float salario)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetSalario() == salario)
		node = RemoveNode(node);
	else if (node->GetSalario() > salario)
		node->SetLeft(RemoveInternal(node->GetLeft(), salario));
	else
		node->SetRight(RemoveInternal(node->GetRight(), salario));
	
	return node;
}

NodeBST* BST::RemoveNode(NodeBST* node)
{
	NodeBST* parent = node->GetParent();

	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	else if (node->GetLeft() == nullptr)
	{
		NodeBST* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	else if (node->GetRight() == nullptr)
	{
		NodeBST* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	else
	{
		NodeBST* predecessor = Predecessor(node->GetSalario());
		node->CopyNomeFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetSalario()));
	}

	return node;
}

void BST::UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}
