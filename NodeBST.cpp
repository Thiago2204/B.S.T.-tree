//Arthur Cardani Saraiva	32011334
//Gabriel Woo Hyun Kim	32009968
//Lucas Ellery Viana	42005541
//Thiago Henrique Quadrado Estacio	42012740

#include "NodeBST.h"
#include "Utils.h"

NodeBST::NodeBST(float salario, const std::string& nome, const std::string& cargob, const std::string& cargoc, const std::string& unidade, NodeBST* parent, NodeBST* left, NodeBST* right)
	: m_Salario(salario)
	, m_Nome(nome)
	, m_CargoB(cargob)
	, m_CargoC(cargoc)
	, m_Unidade(unidade)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
{
}

NodeBST::~NodeBST()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

void NodeBST::CopyNomeFrom(const NodeBST* node)
{
	m_Salario = node->GetSalario();
	m_Nome = node->GetNome();
}

float NodeBST::GetSalario() const
{
	return m_Salario;
}

void NodeBST::SetSalario(float salario)
{
	m_Salario = salario;
}

std::string NodeBST::GetNome() const
{
	return m_Nome;
}

void NodeBST::SetNome(const std::string& nome)
{
	m_Nome = nome;
}

std::string NodeBST::GetCargoB() const
{
	return m_CargoB;
}

void NodeBST::SetCargoB(const std::string& cargob)
{
	m_CargoB = cargob;
}

std::string NodeBST::GetCargoC() const
{
	return m_CargoC;
}

void NodeBST::SetCargoC(const std::string& cargoc)
{
	m_CargoC = cargoc;
}

std::string NodeBST::GetUnidade() const
{
	return m_Unidade;
}

void NodeBST::SetUnidade(const std::string& unidade)
{
	m_Unidade = unidade;
}

NodeBST* NodeBST::GetParent() const
{
	return m_Parent;
}

void NodeBST::SetParent(NodeBST* parent)
{
	m_Parent = parent;
}

NodeBST* NodeBST::GetLeft() const
{
	return m_Left;
}

void NodeBST::SetLeft(NodeBST* left)
{
	m_Left = left;
}

NodeBST* NodeBST::GetRight() const
{
	return m_Right;
}

void NodeBST::SetRight(NodeBST* right)
{
	m_Right = right;
}

bool NodeBST::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeBST::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeBST::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeBST::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeBST::GetDepthInternal(const NodeBST* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeBST::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeBST::GetHeightInternal(const NodeBST* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}
