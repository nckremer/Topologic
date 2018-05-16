#include "Cluster.h"

#include <Vertex.h>
#include <Edge.h>
#include <Wire.h>
#include <Face.h>
#include <Shell.h>
#include <Cell.h>
#include <CellComplex.h>

#include <assert.h>

namespace Topologic
{
	Cluster^ Cluster::ByTopology(List<Topology^>^ topology)
	{
		std::list<std::shared_ptr<TopologicCore::Topology>> coreTopologies;
		for each(Topology^ pTopology in topology)
		{
			std::shared_ptr<TopologicCore::Topology> pCoreTopology = TopologicCore::TopologicalQuery::Downcast<TopologicCore::Topology>(pTopology->GetCoreTopologicalQuery());
			if(pCoreTopology != nullptr)
			{
				coreTopologies.push_back(pCoreTopology);
			}
		}
		
		return gcnew Cluster(TopologicCore::Cluster::ByTopology(coreTopologies));
	}

	Cluster^ Cluster::AddTopology(Topology^ topology)
	{
		std::shared_ptr<TopologicCore::Topology> pCoreTopology = TopologicCore::TopologicalQuery::Downcast<TopologicCore::Topology>(topology->GetCoreTopologicalQuery());
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		if (!pCoreCluster->AddTopology(pCoreTopology.get()))
		{
			throw gcnew Exception("Cluster::Add(): fails to add topology");
		}
		return this;
	}

	Cluster^ Cluster::RemoveTopology(Topology^ topology)
	{
		std::shared_ptr<TopologicCore::Topology> pCoreTopology = TopologicCore::TopologicalQuery::Downcast<TopologicCore::Topology>(topology->GetCoreTopologicalQuery());
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());
		if (!pCoreCluster->RemoveTopology(pCoreTopology.get()))
		{
			throw gcnew Exception("Cluster::Remove(): fails to remove topology");
		}
		return this;
	}

	Object^ Cluster::Geometry::get()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());
		std::list<std::shared_ptr<TopologicCore::Topology>> immediateCoreMembers;
		pCoreCluster->ImmediateMembers(immediateCoreMembers);

		List<Object^>^ pTopologies = gcnew List<Object^>();

		for (std::list<std::shared_ptr<TopologicCore::Topology>>::const_iterator kCoreIterator = immediateCoreMembers.begin();
			kCoreIterator != immediateCoreMembers.end();
			kCoreIterator++)
		{
			pTopologies->Add(Topology::ByCoreTopology(*kCoreIterator)->Geometry);
		}
		return pTopologies;
	}

	Cluster::Cluster(const std::shared_ptr<TopologicCore::Cluster>& kpCoreCluster)
		: Topology()
		, m_pCoreCluster(new std::shared_ptr<TopologicCore::Cluster>(kpCoreCluster))
	{

	}

	Cluster::Cluster()
		: Topology()
		, m_pCoreCluster(nullptr)
	{
		
	}

	std::shared_ptr<TopologicCore::TopologicalQuery> Cluster::GetCoreTopologicalQuery()
	{
		assert(m_pCoreCluster != nullptr && "Cluster::m_pCoreCluster is null.");
		if (m_pCoreCluster == nullptr)
		{
			throw gcnew Exception("Cluster::m_pCoreCluster is null.");
		}

		return *m_pCoreCluster;
	}

	Cluster::~Cluster()
	{
		delete m_pCoreCluster;
	}


	List<Shell^>^ Cluster::Shells()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Shell>> coreShells;
		pCoreCluster->Shells(coreShells);

		List<Shell^>^ pShells = gcnew List<Shell^>();
		for (std::list<std::shared_ptr<TopologicCore::Shell>>::const_iterator kShellIterator = coreShells.begin();
			kShellIterator != coreShells.end();
			kShellIterator++)
		{
			Shell^ pShell = gcnew Shell(*kShellIterator);
			pShells->Add(pShell);
		}

		return pShells;
	}

	List<Face^>^ Cluster::Faces()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Face>> coreFaces;
		pCoreCluster->Faces(coreFaces);

		List<Face^>^ pFaces = gcnew List<Face^>();
		for (std::list<std::shared_ptr<TopologicCore::Face>>::const_iterator kFaceIterator = coreFaces.begin();
			kFaceIterator != coreFaces.end();
			kFaceIterator++)
		{
			Face^ pFace = gcnew Face(*kFaceIterator);
			pFaces->Add(pFace);
		}

		return pFaces;
	}

	List<Wire^>^ Cluster::Wires()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Wire>> coreWires;
		pCoreCluster->Wires(coreWires);

		List<Wire^>^ pWires = gcnew List<Wire^>();
		for (std::list<std::shared_ptr<TopologicCore::Wire>>::const_iterator kWireIterator = coreWires.begin();
			kWireIterator != coreWires.end();
			kWireIterator++)
		{
			Wire^ pWire = gcnew Wire(*kWireIterator);
			pWires->Add(pWire);
		}

		return pWires;
	}

	List<Edge^>^ Cluster::Edges()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Edge>> coreEdges;
		pCoreCluster->Edges(coreEdges);

		List<Edge^>^ pEdges = gcnew List<Edge^>();
		for (std::list<std::shared_ptr<TopologicCore::Edge>>::const_iterator kEdgeIterator = coreEdges.begin();
			kEdgeIterator != coreEdges.end();
			kEdgeIterator++)
		{
			Edge^ pEdge = gcnew Edge(*kEdgeIterator);
			pEdges->Add(pEdge);
		}

		return pEdges;
	}

	List<Vertex^>^ Cluster::Vertices()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Vertex>> coreVertices;
		pCoreCluster->Vertices(coreVertices);

		List<Vertex^>^ pVertices = gcnew List<Vertex^>();
		for (std::list<std::shared_ptr<TopologicCore::Vertex>>::const_iterator kVertexIterator = coreVertices.begin();
			kVertexIterator != coreVertices.end();
			kVertexIterator++)
		{
			Vertex^ pVertex = gcnew Vertex(*kVertexIterator);
			pVertices->Add(pVertex);
		}

		return pVertices;
	}

	List<Cell^>^ Cluster::Cells()
	{
		std::shared_ptr<TopologicCore::Cluster> pCoreCluster = TopologicCore::Topology::Downcast<TopologicCore::Cluster>(GetCoreTopologicalQuery());

		std::list<std::shared_ptr<TopologicCore::Cell>> coreCells;
		pCoreCluster->Cells(coreCells);

		List<Cell^>^ pCells = gcnew List<Cell^>();
		for (std::list<std::shared_ptr<TopologicCore::Cell>>::const_iterator kCellIterator = coreCells.begin();
			kCellIterator != coreCells.end();
			kCellIterator++)
		{
			Cell^ pCell = gcnew Cell(*kCellIterator);
			pCells->Add(pCell);
		}

		return pCells;
	}

}