#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <list>
#include <vector>
#include <algorithm>
#include <cassert>

class GraphNode;
typedef std::list<GraphNode*> AdjList;


class GraphNode
{
public:
	GraphNode(unsigned int id, float value) :
		mId(id), mValue(value)
	{
	}

	AdjList getAdjacents() const
	{
		return mAdjacents;
	}

	void insertAdj(const GraphNode* neighbour)
	{
		AdjList::iterator insertPos =
		std::lower_bound(mAdjacents.begin(), mAdjacents.end(), neighbour, [] (const GraphNode* lhs, const GraphNode* rhs) {
				return lhs->mId < rhs->mId;
			});
		mAdjacents.insert(insertPos, const_cast< GraphNode* >(neighbour));
	}

	unsigned int mId;
	float mValue;
	AdjList mAdjacents;
};

class Graph
{
public:
	Graph(unsigned int size) :
		mNodes(size)
	{
		for (unsigned int i = 0; i < size; ++i)
			mNodes[i] = new GraphNode(i, (float)i);
	}

	~Graph()
	{
		for (unsigned int i = 0; i < mNodes.size(); ++i)
			delete mNodes[i];
	}

	AdjList adjacent(unsigned int nodeId) const
	{
		assert(nodeId < mNodes.size());
		return mNodes[nodeId]->getAdjacents();
	}

	void addLink(unsigned int nodeId, unsigned int adjNodes[], unsigned int numAdjNodes)
	{
		assert(nodeId < mNodes.size() && mNodes[nodeId] != 0);
		GraphNode* n = mNodes[nodeId];

		unsigned int i = 0;
		while (i < numAdjNodes)
		{
			GraphNode* neighbour = mNodes[ adjNodes[i] ];
			n->mAdjacents.push_back(neighbour);
			neighbour->insertAdj(n);
			++i;
		}
	}

	// Directed
	//bool addNode(int nondeId, float nodeValue, int upNodes[], int numUpNodes, int downNodes[], int numDownNodes)
	//{
	//	return false;
	//}

	// Undirected
	//bool addNode(int nondeId, float nodeValue, int adjNodes[], int numAdjNodes)
	//{
	//	return false;
	//}

private:
	std::vector<GraphNode*> mNodes;
};

#endif