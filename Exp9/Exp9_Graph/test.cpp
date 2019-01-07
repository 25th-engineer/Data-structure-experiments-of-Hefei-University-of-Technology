#include "pch.h"

#include "graph.cpp"

//#define DEBUG

#ifdef DEBUG
int deBug1(void);
#else
int menu(const char *str, graph &G);
int c_graph(char str[64], graph &G);
int menu_c_graph(void);
#endif // DEBUG

int main()
{
	char ch;
	char str[64];
	graph G;

#ifdef DEBUG
	std::cin >> ch;
	deBug1();
#else
	menu(str, G);
	std::cin >> ch;
	while (ch != '0')
	{
		system("CLS");
		switch (ch)
		{
		case 'a':
			c_graph(str, G);
			break;
		case 'b':
			G.delete_G();
			std::cout << "The graph has been destroyed." << std::endl;
			break;
		case '1':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.dfsTraversal_l();
				G.bfsTraversal_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '2':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				std::cout << "该图中边(弧)的数量为:" << G.get_Enum_l() << std::endl;
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '3':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.dfsTraversal_t_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '4':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.bfsTraversal_t_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '5':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.Prim_l(G.getNode_for_ID(0));
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '6':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.Kruskal_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '7':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.Dijkstra_l(G.getNode_for_ID(0));
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '8':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.Floyd_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case '9':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.AOV_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		case 'e':
			if (!G.empty())
			{
				std::cout << str << std::endl;
				G.AOE_l();
			}
			else
			{
				std::cout << "Graph not created." << std::endl;
			}
			break;
		default:
			break;
		}
		std::cout << "Press any key to return." << std::endl;
		std::cin >> ch;
		system("CLS");
		menu(str, G);
		std::cin >> ch;
	}
#endif // DEBUG

    return 0; 
}

#ifdef DEBUG

int deBug1(void)
{
	char ch;
	char str[64];

	strcpy_s(str, "grpData\\udg115.grp");
	graph G1(str);
	std::cout << str << std::endl;
	G1.dfsTraversal_l();
	G1.bfsTraversal_l();
	std::cout << "Graph Enum:" << G1.get_Enum_l() << std::endl;
	G1.Prim_l(G1.getNode_for_data('a'));
	G1.Prim_l(G1.getNode_for_data('h'));
	G1.Prim_l(G1.getNode_for_data('k'));
	G1.Kruskal_l();

	strcpy_s(str, "grpData\\dg6.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.Prim_l(G1.getNode_for_data('e'));
	G1.Kruskal_l();

	strcpy_s(str, "grpData\\udn6.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.Prim_l(G1.getNode_for_data('1'));
	G1.Kruskal_l();
	G1.Dijkstra_l(G1.getNode_for_data('1'));
	G1.Floyd_l();

	strcpy_s(str, "grpData\\un8.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.Prim_l(G1.getNode_for_data('A'));
	G1.Kruskal_l();
	G1.Dijkstra_l(G1.getNode_for_data('A'));
	G1.Floyd_l();

	strcpy_s(str, "grpData\\dn8.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.Dijkstra_l(G1.getNode_for_data('1'));
	G1.Floyd_l();
	G1.AOV_l();
	G1.AOE_l();

	strcpy_s(str, "grpData\\dn10.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.Dijkstra_l(G1.getNode_for_data('a'));
	G1.Floyd_l();
	G1.AOV_l();
	G1.AOE_l();

	strcpy_s(str, "grpData\\top6dg1.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.AOV_l();
	G1.AOE_l();

	strcpy_s(str, "grpData\\top7dg1.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.AOV_l();
	G1.AOE_l();

	strcpy_s(str, "grpData\\kPath91.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.AOV_l();
	G1.AOE_l();

	strcpy_s(str, "grpData\\kPath101.grp");
	G1.coverGraph(str);
	std::cout << str << std::endl;
	G1.AOV_l();
	G1.AOE_l();

	std::cin >> ch;
	return 0;
}

#else

int menu(const char * str, graph & G)
{
	if(!G.empty())
	{
		std::cout << str << std::endl;
	}
	else
	{
		std::cout << "Graph not created." << std::endl;
	}
	std::cout << "Please select the operation by input the very character." << std::endl;
	std::cout << "0 for quiting." << std::endl;
	std::cout << "a for creating or modifying graph.Attention, the original graph will be overwritten!" << std::endl;
	std::cout << "b for destroying the graph." << std::endl;
	std::cout << "1 for Exp1, traversing the graph." << std::endl;
	std::cout << "2 for Exp2, counting the number of edges in the graph." << std::endl;
	std::cout << "3 for Exp3, depth-first traversal of the spanning tree on the current graph." << std::endl;
	std::cout << "4 for Exp4, breadth-first traversal of the spanning tree on the current graph." << std::endl;
	std::cout << "5 for Exp5, executing the Prim algorithm on the current graph." << std::endl;
	std::cout << "6 for Exp6, executing the Kruskal algorithm on the current graph." << std::endl;
	std::cout << "7 for Exp7, executing the Dijkstra algorithm on the current graph." << std::endl;
	std::cout << "8 for Exp8, executing the Floyd algorithm on the current graph." << std::endl;
	std::cout << "9 for Exp9, performing a topological sort on the current graph." << std::endl;
	std::cout << "e for Exp10, finding a critical path on the current graph." << std::endl;
	return 0;
}

int c_graph(char str[64], graph & G)
{
	char ch;
	menu_c_graph();
	std::cin >> ch;
	switch (ch)
	{
	case '1':
		strcpy(str, "grpData\\dg6.grp");
		break;
	case '2':
		strcpy(str, "grpData\\dg8.grp");
		break;
	case '3':
		strcpy(str, "grpData\\dn8.grp");
		break;
	case '4':
		strcpy(str, "grpData\\dn10.grp");
		break;
	case '5':
		strcpy(str, "grpData\\dn61.grp");
		break;
	case '6':
		strcpy(str, "grpData\\f14.grp");
		break;
	case '7':
		strcpy(str, "grpData\\kPath91.grp");
		break;
	case '8':
		strcpy(str, "grpData\\kPath101.grp");
		break;
	case '9':
		strcpy(str, "grpData\\Top6dg1.grp");
		break;
	case 'a':
		strcpy(str, "grpData\\Top7dg1.grp");
		break;
	case 'b':
		strcpy(str, "grpData\\udg4.grp");
		break;
	case 'c':
		strcpy(str, "grpData\\udg8.grp");
		break;
	case 'd':
		strcpy(str, "grpData\\udg10.grp");
		break;
	case 'e':
		strcpy(str, "grpData\\udg114.grp");
		break;
	case 'f':
		strcpy(str, "grpData\\udg115.grp");
		break;
	case 'g':
		strcpy(str, "grpData\\udn6.grp");
		break;
	case 'h':
		strcpy(str, "grpData\\udTree11.grp");
		break;
	case 'i':
		strcpy(str, "grpData\\un8.grp");
		break;
	default:
		break;
	}
	if (ch > '0' && ch <= '9')
	{
		std::cout << "Creating." << str << std::endl;
		G.coverGraph(str);
		std::cout << "Has been created!" << std::endl;
	}
	else if (ch >= 'a' && ch <= 'j')
	{
		std::cout << "Creating." << str << std::endl;
		G.coverGraph(str);
		std::cout << "Has been created!" << std::endl;
	}
	return 0;
}

int menu_c_graph(void)
{
	std::cout << "Please select the graph you want to create:" << std::endl;
	std::cout << "Other:quit!" << std::endl;
	std::cout << "1 for dg6.grp" << std::endl;
	std::cout << "2 for dg8.grp" << std::endl;
	std::cout << "3 for dn8.grp" << std::endl;
	std::cout << "4 for dn10.grp" << std::endl;
	std::cout << "5 for dn61.grp" << std::endl;
	std::cout << "6 for f14.grp" << std::endl;
	std::cout << "7 for kPath91.grp" << std::endl;
	std::cout << "8 for kPath101.grp" << std::endl;
	std::cout << "9 for Top6dg1.grp" << std::endl;
	std::cout << "a for Top7dg1.grp" << std::endl;
	std::cout << "b for udg4.grp" << std::endl;
	std::cout << "c for udg8.grp" << std::endl;
	std::cout << "d for udg10.grp" << std::endl;
	std::cout << "e for udg114.grp" << std::endl;
	std::cout << "f for udg115.grp" << std::endl;
	std::cout << "g for udn6.grp" << std::endl;
	std::cout << "h for udTree11.grp" << std::endl;
	std::cout << "i for un8.grp" << std::endl;
	return 0;
}

#endif // DEBUG
