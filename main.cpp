/Arthur Cardani Saraiva	32011334
//Gabriel Woo Hyun Kim	32009968
//Lucas Ellery Viana	42005541
//Thiago Henrique Quadrado Estacio	42012740

#include <vector> 
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "BST.h"
#include "BST.cpp"
#include "NodeBST.h"

using namespace std;

void NovoNode(BST* bst)
{
	string Funcionario[6], line, Temp;
	ifstream Dados;
		
	Dados.open("renumeracao12-2021_vt.csv", fstream::in);
	while(!Dados.eof())
	{
		getline(Dados, line);
		istringstream stream(line);
		
		int i = 0;
		while(getline(stream, Temp, ','))
		
		NodeBST* node = bst->Insert(stof(Funcionario[4]), Funcionario[1], Funcionario[2], Funcionario[3], Funcionario[5]);
	}
}

void Print(NodeBST* node)
{
	cout << "Salario: " << node->GetSalario() << end;
	cout << "Nome: " << node->GetNome() << endl;
	cout << "Cargo Base: " << node->GetCargoB() << endl;
	cout << "Cargo em Comissao: " << node->GetCargoC() << endl;
	cout << "Unidade: " << node->GetUnidade() << endl;
}

int main()
{
	BST* bst = new BST();
	NovoNode(bst);
	int Escolha;
	cout << "1. Buscar a pessoa com o maior salario" << endl;
	cout << "2. Buscar a pessoa com o menor salario" << endl;
	cout << "3. Buscar cargo base com o maior salario" << endl;
	cout << "4. Buscar cargo em comissao com o maior salario" << endl;
	cout << "5. Buscar unidade com o maior salario" << endl;
	cout << "6. Terminar" << endl;;
	cout << "Escolha entre 1 a 6 das opcoes acima" << endl;
	cin >> Escolha;
	while(Escolha<1 || Escolha>6)
	{
		cout << "Opcao invalida, digite novamente" << endl;
		cin >> Escolha;
	}
	if(Escolha == 1)
	{
    return 0;
	}
}


//Nome completo/Cargo Base/Cargo em Comissão/Salario/Unidade
