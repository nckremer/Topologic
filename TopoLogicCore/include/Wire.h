#pragma once

#include "Topology.h"
#include "Utilities.h"

#include <list>

#include <TopoDS_Wire.hxx>

class BRepBuilderAPI_MakeWire;

namespace TopologicCore
{
	class Vertex;
	class Edge;
	class Face;

	class Wire : public Topology
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkOcctWire"></param>
		/// <param name="rkOcctLabel"></param>
		Wire(const TopoDS_Wire& rkOcctWire, const TDF_Label& rkOcctLabel = TDF_Label());

		virtual ~Wire();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rEdges"></param>
		void TOPOLOGIC_API Edges(std::list<std::shared_ptr<Edge>>& rEdges) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="kpParentTopology"></param>
		/// <param name="rFaces"></param>
		/// <returns></returns>
		void TOPOLOGIC_API Faces(const std::shared_ptr<Topology>& kpParentTopology, std::list<std::shared_ptr<Face>>& rFaces) const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		bool TOPOLOGIC_API IsClosed() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rVertices"></param>
		void TOPOLOGIC_API Vertices(std::list<std::shared_ptr<Vertex>>& rVertices) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkEdges"></param>
		/// <returns></returns>
		static TOPOLOGIC_API std::shared_ptr<Wire> ByEdges(const std::list<std::shared_ptr<Edge>>& rkEdges);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rOcctGeometries"></param>
		virtual void Geometry(std::list<Handle(Geom_Geometry)>& rOcctGeometries) const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual TopoDS_Shape& GetOcctShape();

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual const TopoDS_Shape& GetOcctShape() const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual TopoDS_Wire& GetOcctWire();

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual const TopoDS_Wire& GetOcctWire() const;

		virtual TopologyType GetType() const { return TOPOLOGY_WIRE; }

	protected:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="rkOcctMakeWire"></param>
		static void Throw(const BRepBuilderAPI_MakeWire& rkOcctMakeWire);

		/// <summary>
		/// The underlying OCCT wire.
		/// </summary>
		TopoDS_Wire m_occtWire;
	};
}
