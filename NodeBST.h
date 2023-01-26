//Arthur Cardani Saraiva	32011334
//Gabriel Woo Hyun Kim	32009968
//Lucas Ellery Viana	42005541
//Thiago Henrique Quadrado Estacio	42012740

#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include <string>

class NodeBST
{
public:
	NodeBST(float salario, const std::string& nome, const std::string& cargob, const std::string& cargoc, const std::string& unidade, NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST();

	void CopyNomeFrom(const NodeBST* node);

	float GetSalario() const;
	void SetSalario(float salario);
	
	std::string GetNome() const;
	void SetNome(const std::string& nome);
	
	std::string GetCargoB() const;
	void SetCargoB(const std::string& cargob);
	
	std::string GetCargoC() const;
	void SetCargoC(const std::string& cargoc);
	
	std::string GetUnidade() const;
	void SetUnidade(const std::string& unidade);

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	float m_Salario;
	std::string m_Nome;
	std::string m_CargoB;
	std::string m_CargoC;
	std::string m_Unidade;
	
	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
