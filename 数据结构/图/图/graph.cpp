#include"Graph_AdjMatrix.h"
int main()
{
	MGraph G;
	VertexType v="k";
	CreateGraph(G);
	Display(G);
	InsertVex(G, v);
	Display(G);
	InsertArc(G, v, "a");
	Display(G);
	DeleteVex(G,v);
	Display(G);
	
	cout << "----------------------------------------------------------------------------" << endl;
	BFSTraverse(G);
	return 0;
}