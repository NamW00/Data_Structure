﻿#include <iostream>

using namespace std;

#define SIZE 10

template <typename T>
class AdjacencyMatrix
{
private:
	int size; // 정점의 개수
	T vertex[SIZE]; // 정점의 집합
	int matrix[SIZE][SIZE]; // 인접 행렬

public:
	AdjacencyMatrix()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = NULL;
			}
		}
	}

	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency Matrix is Full" << endl;
			return;
		}

		vertex[size++] = data;
	}

	void Insert(int i, int j, int value = 1)
	{
		if (size <= 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}

		if (i >= size || j >= size)
		{
			cout << "Out of Range" << endl;
			return;
		}

		matrix[i][j] = value;
		matrix[j][i] = value;
	}

	void Show()
	{
		if (size <= 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}

		cout << "    ";

		for (int i = 0; i < size; i++)
		{
			cout << vertex[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << vertex[i] << " : ";

			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << " ";
			}

			cout << endl;
		}
	}
};

int main()
{
#pragma region 그래프
	// 요소들이 서로 복잡하게 연결되어 있는 관계를
	// 표현하는 자료구조이며, 정점과 간석들의 집합으로 구성되어 있습니다.

	// 정점 (Vertex)
	// 노드(Node) 데이터가 저장되는 그래프의 기본 원소입니다.

	// 간선 (Edge)
	// 노드들을 연결하는 선입니다.

	// 인접 정점 (Adjacent Vertex)
	// 간선으로 직접 연결된 정점을 의미합니다.

	// 차수 (Degree)
	// 정점에 연결된 간선의 수를 의미합니다.

	// 경로 (Path)
	// 정점들을 연결하는 간선들의 순서입니다.

	// 그래프의 종류

	// 1. 무방향 그래프 (Undirected Graph)											
	// 간선에 방향이 없는 그래프입니다.

	// 2. 방향 그래프 (Directed Graph)
	// 간선에 방향이 있는 그래프입니다.

	// 3. 가중치 그래프 (Weighted Graph)
	// 간선에 가중치가 있는 그래프입니다.
#pragma endregion

#pragma region 인접 행렬(Adjacency Materix)

	// 인접 행렬(Adjacency Materix)
	// 정점들 간의 연결 관계를 이차원 배열로 표현하는 방식입니다.
	// 정점의 개수가 V일 때, V x V 크기의 이차원 배열을 사용합니다.

	// 장점
	// 1. 두 정점이 연결되어 있는지 확인하기 쉽습니다.
	// 2. 두 정점 사이의 간선의 가중치를 쉽게 확인할 수 있습니다.

	// 단점
	// 1. 정점의 개수가 많을 때 메모리 낭비가 심합니다.
	// 2. 특정 정점과 연결된 정점을 찾을 때 시간이 오래 걸립니다.

	AdjacencyMatrix<char> graph;

	graph.Insert('A');
	graph.Insert('B');
	graph.Insert('C');
	graph.Insert('D');

	graph.Insert(0, 1);
	graph.Insert(0, 2);
	graph.Insert(0, 3);
	graph.Insert(2, 3);

	graph.Show();




#pragma endregion



	return 0;
}